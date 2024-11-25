using DryIoc;
using Microsoft.Extensions.Configuration;

using DB.Client.Backend.DBInteraction.PostgreSQL.Infrastructure;
using DB.Client.Backend.DBInteraction.PostgreSQL.Repository;
using DB.Client.Backend.DBInteraction.PostgreSQL.Settings;
using DB.Client.Backend.Host.Core;
using DB.Client.Backend.Host.Core.Extensions;

namespace DB.Client.Backend.DBInteraction.PostgreSQL;

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
        registrator.Configure<ConnectionStringSettings>(configuration.GetSection(nameof(ConnectionStringSettings)));
        registrator.RegisterMany<DbConnectionFactory>(Reuse.Singleton);
        registrator.RegisterMany<ProductsRepository>(Reuse.Singleton);
    }
    
    #endregion
    
}