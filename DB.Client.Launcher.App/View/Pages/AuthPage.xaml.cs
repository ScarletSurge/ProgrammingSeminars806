using System.Windows;
using DryIoc;
using System.Windows.Controls;

using DB.Client.Launcher.App.ViewModel.Pages;

namespace DB.Client.Launcher.App.View.Pages;

/// <summary>
/// 
/// </summary>
public partial class AuthPage:
    Page
{
    
    #region Constructors
    
    /// <summary>
    /// 
    /// </summary>
    public AuthPage()
    {
        InitializeComponent();
        DataContext = App.Container.Resolve<AuthPageViewModel>();
    }
    
    #endregion
    
}