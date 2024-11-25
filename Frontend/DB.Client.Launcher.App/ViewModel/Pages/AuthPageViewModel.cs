using System.Windows.Input;

using DB.Client.Launcher.App.Interaction;
using DB.Client.Launcher.App.Utils;
using DB.Client.WPF.MVVM.Command;

namespace DB.Client.Launcher.App.ViewModel.Pages;

/// <summary>
/// 
/// </summary>
internal sealed class AuthPageViewModel:
    PageViewModelBase
{
    
    #region Fields
    
    /// <summary>
    /// 
    /// </summary>
    private readonly HostMediator _hostMediator;
    
    #region Command
    
    /// <summary>
    /// 
    /// </summary>
    private readonly Lazy<ICommand> _initializeDBRequestCommand;

    #endregion
    
    #endregion
    
    #region Constructors
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="navigationManager"></param>
    /// <param name="hostMediator"></param>
    public AuthPageViewModel(
        NavigationManager navigationManager,
        HostMediator hostMediator):
            base(navigationManager)
    {
        //_hostMediator = hostMediator ?? throw new ArgumentNullException(nameof(hostMediator));
        
        _initializeDBRequestCommand =
            new Lazy<ICommand>(() => new RelayCommand(async _ => await InitializeDBRequestAsync()));
    }
    
    #endregion
    
    #region Properties
    
    #region Command
    
    /// <summary>
    /// 
    /// </summary>
    public ICommand InitializeDBRequestCommand =>
        _initializeDBRequestCommand.Value;

    #endregion

    #endregion

    #region Methods

    #region Command
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="cancellationToken"></param>
    private async Task InitializeDBRequestAsync(
        CancellationToken cancellationToken = default)
    {
        var response = await _hostMediator.GetProductsFromDbAsync(cancellationToken);
    }
    
    #endregion

    #endregion

}