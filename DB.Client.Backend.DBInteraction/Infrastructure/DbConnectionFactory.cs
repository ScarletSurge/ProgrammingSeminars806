using Microsoft.Extensions.Options;
using Npgsql;

using DB.Client.Backend.DBInteraction.Settings;
using DB.Client.Core.Interfaces;

namespace DB.Client.Backend.DBInteraction.Infrastructure;

/// <summary>
/// 
/// </summary>
public sealed class DbConnectionFactory:
    IAbstractFactory<NpgsqlConnection>,
    IDisposable
{
    
    #region Fields
    
    /// <summary>
    /// 
    /// </summary>
    private readonly IOptions<ConnectionStringSettings> _connectionStringSettingsOptions;
    
    #endregion
    
    #region Constructors

    public DbConnectionFactory(
        IOptions<ConnectionStringSettings> connectionStringSettingsOptions)
    {
        _connectionStringSettingsOptions = connectionStringSettingsOptions ?? throw new ArgumentNullException(nameof(connectionStringSettingsOptions));
    }
    
    #endregion
    
    #region DB.Client.Core.Interfaces.IAbstractFactory<out NpgSqlConnection> implementation
    
    /// <inheritdoc cref="IAbstractFactory{T}.Create" />
    NpgsqlConnection IAbstractFactory<NpgsqlConnection>.Create()
    {
        return new NpgsqlConnection(_connectionStringSettingsOptions.Value.ConnectionString);
    }
    
    #endregion
    
    #region System.IDisposable implementation
    
    /// <inheritdoc cref="IDisposable.Dispose" />
    public void Dispose()
    {
        // TODO: dispose some resources here...
        GC.SuppressFinalize(this);
    }
    
    /// <summary>
    /// 
    /// </summary>
    ~DbConnectionFactory()
    {
        // TODO: dispose some resources here...
    }
    
    #endregion
    
}