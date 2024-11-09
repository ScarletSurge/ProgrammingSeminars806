using System.Collections.ObjectModel;
using System.Globalization;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Threading;
using DB.Client.WPF.MVVM.Converter;
using DB.Client.WPF.MVVM.ViewModel;

namespace DB.Client.Launcher.App.View.Controls;

/// <summary>
/// 
/// </summary>
public partial class Spinner:
    UserControl
{
    
    #region Nested

    public sealed class SpinnerItemViewModel:
        ViewModelBase
    {

        #region Fields
        
        /// <summary>
        /// 
        /// </summary>
        private double _radiusCoefficient;
        
        /// <summary>
        /// 
        /// </summary>
        private double _phiInDegrees;

        #endregion
        
        #region Constructors
        
        /// <summary>
        /// 
        /// </summary>
        /// <param name="radiusCoefficient"></param>
        /// <param name="phi"></param>
        public SpinnerItemViewModel(
            double radiusCoefficient,
            double phi)
        {
            // TODO: validate

            RadiusCoefficient = radiusCoefficient;
            Phi = phi;
        }

        #endregion
        
        #region Properties
        
        /// <summary>
        /// 
        /// </summary>
        public double RadiusCoefficient
        {
            get =>
                _radiusCoefficient;

            set
            {
                _radiusCoefficient = value;
                RaisePropertiesChanged(nameof(RadiusCoefficient));
            }
        }
        
        /// <summary>
        /// 
        /// </summary>
        public double Phi
        {
            get =>
                _phiInDegrees;

            set
            {
                _phiInDegrees = value;
                RaisePropertyChanged(nameof(Phi));
            }
        }
        
        #endregion

    }
    
    /// <summary>
    /// 
    /// </summary>
    public sealed class PositioningConverter:
        MultiValueConverterBase<PositioningConverter>
    {
        
        #region Nested
        
        /// <summary>
        /// 
        /// </summary>
        public enum Coord
        {
            X,
            Y
        }
        
        #endregion
        
        #region DB.Client.WPF.MVVM.MultiValueConverterBase<ArithmeticConverter> overrides
    
        /// <inheritdoc cref="MultiValueConverterBase{TMultiValueConverter}.Convert" />
        public override object? Convert(
            object?[] values,
            Type targetType,
            object? parameter,
            CultureInfo culture)
        {
            if (parameter is not Coord coord)
            {
                throw new ArgumentException("Invalid parameter passed", nameof(parameter));
            }
            
            if ((values?.Length ?? 0) != 4)
            {
                throw new ArgumentException("Invalid values count", nameof(values));
            }

            if (values[0] is not double contextWidth)
            {
                throw new ArgumentException("Invalid value passed", nameof(values));
            }
            
            if (values[1] is not double contextHeight)
            {
                throw new ArgumentException("Invalid value passed", nameof(values));
            }

            if (values[2] is not double radius)
            {
                throw new ArgumentException("Invalid value passed", nameof(values));
            }

            if (values[3] is not double angle)
            {
                throw new ArgumentException("Invalid value passed", nameof(values));
            }

            Matrix transformationMatrix;
            transformationMatrix.Translate(contextWidth - radius, contextHeight / 2.0);
            transformationMatrix.RotateAt(angle, contextWidth / 2.0, contextHeight / 2.0);
            transformationMatrix.Translate(-radius, -radius);
            
            var transformed = transformationMatrix.Transform(new Point(0.0, 0.0));

            return coord == Coord.X
                ? transformed.X
                : transformed.Y;
        }
    
        #endregion
        
    }
    
    /// <summary>
    /// 
    /// </summary>
    public enum RotationDirection
    {
        Clockwise,
        Counterclockwise
    }

    #endregion
    
    #region Fields
    
    /// <summary>
    /// 
    /// </summary>
    private DispatcherTimer _rotationTimer;
    
    #endregion

    #region Constructors
    
    /// <summary>
    /// 
    /// </summary>
    public Spinner()
    {
        InitializeComponent();
        Items = new ObservableCollection<SpinnerItemViewModel>();
        _rotationTimer = new DispatcherTimer(RotationInterval, DispatcherPriority.Normal, (sender, eventArgs) =>
        {
            foreach (var item in Items)
            {
                item.Phi = (item.Phi + 5.0 * (Direction == RotationDirection.Clockwise
                    ? 1.0
                    : -1.0)) % 360.0;
            }
        }, Dispatcher.CurrentDispatcher);
        _rotationTimer.Start();
    }
    
    #endregion
    
    #region Properties

    /// <summary>
    /// 
    /// </summary>
    public ObservableCollection<SpinnerItemViewModel> Items
    {
        get;
    }
    
    #endregion
    
    #region Dependency properties
    
    /// <summary>
    /// 
    /// </summary>
    public int ItemsCount
    {
        get =>
            (int)GetValue(ItemsCountProperty);
        
        set =>
            SetValue(ItemsCountProperty, value);
    }
    
    /// <summary>
    /// 
    /// </summary>
    public static readonly DependencyProperty ItemsCountProperty = DependencyProperty.Register(nameof(ItemsCount), typeof(int), typeof(Spinner), new PropertyMetadata(ItemsCountPropertyChangedCallback));
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="dependencyObject"></param>
    /// <param name="eventArgs"></param>
    private static void ItemsCountPropertyChangedCallback(
        DependencyObject dependencyObject,
        DependencyPropertyChangedEventArgs eventArgs)
    {
        if (dependencyObject is not Spinner spinner)
        {
            // TODO: throw an exception

            return;
        }

        var itemsNewCount = (int)eventArgs.NewValue;

        var newItems = new SpinnerItemViewModel[itemsNewCount];

        for (var i = 0; i < itemsNewCount; ++i)
        {
            newItems[i] = new SpinnerItemViewModel(
                // TODO: get value from DP
                spinner.RadiusCoefficient, 360.0 / itemsNewCount * i);
        }

        spinner.Items.Clear();

        foreach (var newItem in newItems)
        {
            spinner.Items.Add(newItem);
        }
    }

    public Brush ItemsBrush
    {
        get =>
            (Brush)GetValue(ItemsBrushProperty);

        set =>
            SetValue(ItemsBrushProperty, value);
    }
    
    /// <summary>
    /// 
    /// </summary>
    public static readonly DependencyProperty ItemsBrushProperty = DependencyProperty.Register(nameof(ItemsBrush), typeof(Brush), typeof(Spinner), new PropertyMetadata(Brushes.Black));
    
    /// <summary>
    /// 
    /// </summary>
    public TimeSpan RotationInterval
    {
        get =>
            (TimeSpan)GetValue(RotationIntervalProperty);

        set =>
            SetValue(RotationIntervalProperty, value);
    }
    
    /// <summary>
    /// 
    /// </summary>
    public static readonly DependencyProperty RotationIntervalProperty = DependencyProperty.Register(nameof(RotationInterval), typeof(TimeSpan), typeof(Spinner), new PropertyMetadata(TimeSpan.FromMilliseconds(40)));
    
    /// <summary>
    /// 
    /// </summary>
    public RotationDirection Direction
    {
        get =>
            (RotationDirection)GetValue(RotationDirectionProperty);

        set =>
            SetValue(RotationDirectionProperty, value);
    }
    
    /// <summary>
    /// 
    /// </summary>
    public static readonly DependencyProperty RotationDirectionProperty = DependencyProperty.Register(nameof(Direction), typeof(RotationDirection), typeof(Spinner), new PropertyMetadata(RotationDirection.Clockwise));
    
    /// <summary>
    /// 
    /// </summary>
    public double RadiusCoefficient
    {
        get =>
            (double)GetValue(RadiusCoefficientProperty);

        set =>
            SetValue(RadiusCoefficientProperty, value);
    }
    
    /// <summary>
    /// 
    /// </summary>
    public static DependencyProperty RadiusCoefficientProperty = DependencyProperty.Register(nameof(RadiusCoefficient), typeof(double), typeof(Spinner), new PropertyMetadata(0.1, RadiusCoefficientPropertyChangedCallback, RadiusCoefficientPropertyCoerceValueCallback));
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="dependencyObject"></param>
    /// <param name="eventArgs"></param>
    private static void RadiusCoefficientPropertyChangedCallback(
        DependencyObject dependencyObject,
        DependencyPropertyChangedEventArgs eventArgs)
    {
        if (dependencyObject is not Spinner spinner)
        {
            // TODO: throw an exception

            return;
        }
        
        foreach (var item in spinner.Items)
        {
            item.RadiusCoefficient = (double)eventArgs.NewValue;
        }
    }
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="dependencyObject"></param>
    /// <param name="value"></param>
    public static object RadiusCoefficientPropertyCoerceValueCallback(
        DependencyObject dependencyObject,
        object value)
    {
        if (dependencyObject is not Spinner)
        {
            // TODO: throw an exception

            return value;
        }

        if (value is not double radiusCoefficientCandidate)
        {
            // TODO: throw an exception

            return value;
        }

        if (radiusCoefficientCandidate < 0.05)
        {
            return 0.05;
        }

        if (radiusCoefficientCandidate > 0.3)
        {
            return 0.3;
        }
        
        // value was correct
        return radiusCoefficientCandidate;
    }
    
    #endregion
    
}