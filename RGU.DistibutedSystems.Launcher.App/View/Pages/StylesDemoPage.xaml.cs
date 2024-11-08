using DryIoc;
using System.Windows.Controls;

using RGU.DistibutedSystems.Launcher.App.ViewModel.Pages;

namespace RGU.DistibutedSystems.Launcher.App.View.Pages;

/// <summary>
/// 
/// </summary>
public partial class StylesDemoPage:
    Page
{
    
    #region Constructors
    
    /// <summary>
    /// 
    /// </summary>
    public StylesDemoPage()
    {
        InitializeComponent();
        DataContext = App.Container.Resolve<StylesDemoPageViewModel>();
    }
    
    #endregion
    
}