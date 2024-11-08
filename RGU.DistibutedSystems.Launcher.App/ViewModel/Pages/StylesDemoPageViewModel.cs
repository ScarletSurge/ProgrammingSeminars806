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
    public ICommand ClickBrownCircleCommand =>
        _clickBrownCircleCommand.Value;

    #endregion
    
    #region Methods
    
    /// <summary>
    /// 
    /// </summary>
    private void ClickBrownCircle()
    {
        NavigationManager.Navigate(NavigationContext.Builder.Create()
            .From<StylesDemoPageViewModel>()
            .To<HelloWPFPageViewModel>()
            .Build());
    }
    
    #endregion

}