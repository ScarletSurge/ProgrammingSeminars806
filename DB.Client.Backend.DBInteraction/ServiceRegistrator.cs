using DryIoc;
using Microsoft.Extensions.Configuration;

using DB.Client.Backend.DBInteraction.Infrastructure;
using DB.Client.Backend.DBInteraction.Repository;
using DB.Client.Backend.DBInteraction.Settings;
using DB.Client.Backend.Host.Core;
using DB.Client.Backend.Host.Core.Extensions;

namespace DB.Client.Backend.Grpc.Service.DBInteraction;

/// <summary>
/// 
/// </summary>
public sealed class ServiceRegistrator
{
    
    #region RGU.WebProgramming.Server.Core.IServiceRegistrator implementation
    
    /// <inheritdoc cref="IServiceRegistrator.Register" />
    public void Register(
        IRegistrator registrator,
        IConfiguration configuration)
    {
        registrator.Configure<ConnectionStringSettings>(configuration.GetSection(nameof(ConnectionStringSettings)));
        registrator.RegisterMany<DbConnectionFactory>(Reuse.Singleton);
        registrator.RegisterMany<ProductsRepository>(Reuse.Singleton);
    }
    
    #endregion
    
}