using System.Windows.Input;
using RGU.DistibutedSystems.Launcher.App.Utils;
using RGU.DistributedSystems.WPF.MVVM.Command;
using RGU.DistributedSystems.WPF.MVVM.Navigation;

namespace RGU.DistibutedSystems.Launcher.App.ViewModel.Pages;

/// <summary>
/// 
/// </summary>
internal class StylesDemoPageViewModel:
    PageViewModelBase
{
    
    #region Fields
    
    /// <summary>
    /// 
    /// </summary>
    private bool _dataTriggerDemoBool;
    
    /// <summary>
    /// 
    /// </summary>
    private int _multiDataTriggerDemoInt;
    
    /// <summary>
    /// 
    /// </summary>
    private readonly Lazy<ICommand> _clickBrownCircleCommand;
    
    #endregion
    
    #region Constructors
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="navigationManager"></param>
    public StylesDemoPageViewModel(
        NavigationManager navigationManager):
            base(navigationManager)
    {
        _clickBrownCircleCommand = new Lazy<ICommand>(() => new RelayCommand(_ => ClickBrownCircle()));
    }
    
    #endregion
    
    #region Properties
    
    /// <summary>
    /// 
    /// </summary>
    public bool DataTriggerDemoBool
    {
        get =>
            _dataTriggerDemoBool;

        set
        {
            _dataTriggerDemoBool = value;
            RaisePropertyChanged(nameof(DataTriggerDemoBool));
        }
    }
    
    /// <summary>
    /// 
    /// </summary>
    public int MultiDataTriggerDemoInt
    {
        get =>
            _multiDataTriggerDemoInt;

        set
        {
            _multiDataTriggerDemoInt = value;
            RaisePropertyChanged(nameof(MultiDataTriggerDemoInt));
        }
    }
    
    #region Command
    
    /// <summary>
    /// 
    /// </summary>
    public ICommand ClickBrownCircleCommand =>
        _clickBrownCircleCommand.Value;
    
    #endregion

    #endregion
    
    #region Methods
    
    /// <summary>
    /// 
    /// </summary>
    private void ClickBrownCircle()
    {
        DataTriggerDemoBool = !DataTriggerDemoBool;

        //NavigationManager.Navigate(NavigationContext.Builder.Create()
        //  .From<StylesDemoPageViewModel>()
        //  .To<HelloWPFPageViewModel>()
        //  .Build());
    }
    
    #endregion

}