using DryIoc;
using Microsoft.Extensions.Configuration;

using DB.Client.Backend.Host.Core;
using DB.Client.Backend.Host.Core.Extensions;
using DB.Client.Backend.Grpc.Settings;

namespace DB.Client.Backend.Grpc;

/// <summary>
/// 
/// </summary>
public sealed class ServiceRegistrator:
    IServiceRegistrator
{
    
    #region DB.Client.Backend.Host.Core.IServiceRegistrator implementation
    
    /// <inheritdoc cref="IServiceRegistrator.Register" />
    public void Register(
        IRegistrator registrator,
        IConfiguration configuration)
    {
        registrator
            .Configure<ServerSettings>(configuration.GetSection(nameof(ServerSettings)))
            .RegisterMany<ApplicationConfigurator>();
    }
    
    #endregion
    
}