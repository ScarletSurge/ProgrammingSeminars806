using System.Collections.ObjectModel;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using RGU.DistributedSystems.WPF.MVVM.ViewModel;

namespace RGU.DistibutedSystems.Launcher.App.View.Controls;

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
    
    #endregion
    
    #region Fields
    
    
    
    #endregion

    #region Constructors
    
    /// <summary>
    /// 
    /// </summary>
    public Spinner()
    {
        InitializeComponent();
        Items = new ObservableCollection<SpinnerItemViewModel>();
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
                0.15, 360.0 / itemsNewCount * i);
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
    
    #endregion
    
}