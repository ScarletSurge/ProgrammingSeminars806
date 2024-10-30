using DryIoc;
using Microsoft.Extensions.Configuration;

using RGU.WebProgramming.Server.Core;

namespace RGU.WebProgramming.Server.REST.API;

/// <summary>
/// 
/// </summary>
public sealed class ServiceRegistrator:
    IServiceRegistrator
{
    
    #region RGU.WebProgramming.Server.Core.IServiceRegistrator implementation
    
    /// <inheritdoc cref="IServiceRegistrator.Register" />
    public void Register(
        IRegistrator registrator,
        IConfiguration configuration)
    {
        registrator.Register<ApplicationConfigurator>(Reuse.Singleton);
        registrator.Register<WebHostConfigurator>(Reuse.Singleton);
        registrator.Register<Cont>

        // TODO: maybe some other types will be registered
    }
    
    #endregion
    
}