using DryIoc; // Autofac Unity WindsorCastle SimpleInject Ninject
using System.Windows;

using DB.Client.Launcher.App.Interaction;
using DB.Client.Launcher.App.Utils;
using DB.Client.Launcher.App.View;
using DB.Client.Launcher.App.View.Pages;
using DB.Client.Launcher.App.ViewModel;
using DB.Client.Launcher.App.ViewModel.Pages;

namespace DB.Client.Launcher.App;

/// <summary>
/// 
/// </summary>
public partial class App:
    Application
{
    
    #region Fields
    
    /// <summary>
    /// 
    /// </summary>
    private static readonly Lazy<IContainer> _container;
    
    #endregion
    
    #region Constructors
    
    /// <summary>
    /// 
    /// </summary>
    static App()
    {
        _container = new Lazy<IContainer>(() => new Container());
    }
    
    #endregion
    
    #region Properties
    
    /// <summary>
    /// 
    /// </summary>
    public static IContainer Container =>
        _container.Value;
    
    #endregion
    
    #region Methods
    
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    private App RegisterLogging()
    {
        // TODO
        
        return this;
    }
    
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    private App RegisterConfiguration()
    {
        // TODO
        
        return this;
    }
    
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    private App RegisterInfrastructure()
    {
        Container.Register<HostMediator>(Reuse.Singleton);

        return this;
    }
    
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    private App RegisterWindowsViews()
    {
        Container.Register<MainWindow>(Reuse.Singleton);
        
        return this;
    }
    
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    private App RegisterPagesViews()
    {
        Container.Register<AuthPage>(Reuse.Singleton);

        return this;
    }
    
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    private App RegisterDialogsViews()
    {
        // TODO: 

        return this;
    }
    
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    private App RegisterViews()
    {
        return RegisterWindowsViews()
            .RegisterPagesViews()
            .RegisterDialogsViews();
    }
    
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    private App RegisterWindowsViewModels()
    {
        Container.Register<MainWindowViewModel>(Reuse.Singleton);
        
        return this;
    }
    
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    private App RegisterPagesViewModels()
    {
        Container.Register<AuthPageViewModel>(Reuse.Singleton);

        return this;
    }
    
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    private App RegisterDialogsViewModels()
    {
        // TODO: 

        return this;
    }
    
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    private App RegisterViewModels()
    {
        return RegisterWindowsViewModels()
            .RegisterPagesViewModels()
            .RegisterDialogsViewModels();
    }
    
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    private App RegisterNavigation()
    {
        var navigationManager = new NavigationManager();
        Container.RegisterInstance(navigationManager);

        navigationManager
            .AddMapping<AuthPage, AuthPageViewModel>();

        return this;
    }
    
    #endregion
    
    #region System.Windows.Application overrides
    
    /// <inheritdoc cref="Application.OnStartup" />
    protected override void OnStartup(
        StartupEventArgs e)
    {
        this.RegisterLogging()
            .RegisterConfiguration()
            .RegisterInfrastructure()
            .RegisterViews()
            .RegisterViewModels()
            .RegisterNavigation();

        Container.Resolve<MainWindow>().Show();
    }
    
    #endregion
    
}