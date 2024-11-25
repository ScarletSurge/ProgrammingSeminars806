﻿using DB.Client.Launcher.App.Utils;
using DB.Client.WPF.MVVM.Navigation;
using DB.Client.WPF.MVVM.ViewModel;

namespace DB.Client.Launcher.App.ViewModel.Pages;

/// <summary>
/// 
/// </summary>
internal abstract class PageViewModelBase:
    ViewModelBase,
    INavigatable
{

    #region Constructors

    /// <summary>
    /// 
    /// </summary>
    /// <param name="navigationManager"></param>
    /// <exception cref="ArgumentNullException"></exception>
    protected PageViewModelBase(
        NavigationManager navigationManager)
    {
        NavigationManager = navigationManager ?? throw new ArgumentNullException(nameof(navigationManager));
    }

    #endregion

    #region Propeties

    /// <summary>
    /// 
    /// </summary>
    protected NavigationManager NavigationManager
    {
        get;
    }

    #endregion

    #region Kostoev.PhDThesis.Launcher.App.Navigation.INavigatable implementation

    /// <inheritdoc cref="INavigatable.OnNavigatingFrom(NavigationContext)" />
    public virtual void OnNavigatingFrom(
        NavigationContext navigationContext)
    {

    }

    /// <inheritdoc cref="INavigatable.OnNavigatedFrom(NavigationContext)" />
    public virtual void OnNavigatedFrom(
        NavigationContext navigationContext)
    {

    }

    /// <inheritdoc cref="INavigatable.OnNavigatedTo(NavigationContext)" />
    public virtual void OnNavigatedTo(
        NavigationContext navigationContext)
    {

    }

    #endregion

}