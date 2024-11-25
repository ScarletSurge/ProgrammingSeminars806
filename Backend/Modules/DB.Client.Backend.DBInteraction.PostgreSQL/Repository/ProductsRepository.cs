using Npgsql;
using System.Data;
using System.Text;

using DB.Client.Core.Interfaces;
using DB.Client.Domain;
using DB.Client.Domain.Infrastructure;

namespace DB.Client.Backend.DBInteraction.PostgreSQL.Repository;

/// <summary>
/// 
/// </summary>
public sealed class ProductsRepository:
    IRepository<Product>
{
    
    #region Constants
    
    /// <summary>
    /// 
    /// </summary>
    private const string TableSchemaAndName = "\"public\".\"product\"";
    
    #endregion
    
    #region Fields
    
    /// <summary>
    /// 
    /// </summary>
    private readonly IAbstractFactory<NpgsqlConnection> _dbConnectionFactory;
    
    #endregion
    
    #region Constructors
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="dbConnectionFactory"></param>
    /// <exception cref="ArgumentNullException"></exception>
    public ProductsRepository(
        IAbstractFactory<NpgsqlConnection> dbConnectionFactory)
    {
        _dbConnectionFactory = dbConnectionFactory ?? throw new ArgumentNullException(nameof(dbConnectionFactory));
    }
    
    #endregion
    
    #region DB.Client.Domain.Infrastructure.IRepository<Product> implementation
    
    /// <inheritdoc cref="IRepository{TEntity}.CreateAsync" />
    public async Task CreateAsync(
        Product entity,
        CancellationToken cancellationToken = default)
    {
        
    }
    
    /// <inheritdoc cref="IRepository{TEntity}.SelectEntityAsync" />
    public async Task<Product?> SelectEntityAsync(
        object entityKey, 
        CancellationToken cancellationToken = default)
    {
        ArgumentNullException.ThrowIfNull(entityKey, nameof(entityKey));
        
        var query = $"SELECT * FROM f_get_all_products('{entityKey}');";
        
        // var rawSqlQuery = new StringBuilder("SELECT * FROM ")
        //     .Append(TableSchemaAndName)
        //     .Append(" WHERE \"id\"=")
        //     .Append(entityKey)
        //     .Append(';')
        //     .ToString();

        await using var dbConnection = _dbConnectionFactory.Create();
        await dbConnection.OpenAsync(cancellationToken).ConfigureAwait(false);
        await using var dbCommand = new NpgsqlCommand(query, dbConnection);
        dbCommand.CommandType = CommandType.Text;
        // dbCommand.Parameters.Add(new NpgsqlParameter("param", 13));

        await using var dataSetReader = await dbCommand.ExecuteReaderAsync(cancellationToken);
        if (!await dataSetReader.ReadAsync(cancellationToken))
        {
            return null;
        }
        
        return new Product
        {
            Barcode = dataSetReader.GetString("barcode"),
            Name = dataSetReader.GetString("name"),
            PackageSize = dataSetReader.GetString("package_size"),
            Weight = dataSetReader.GetDouble("weight")
        };
    }
    
    /// <inheritdoc cref="IRepository{TEntity}.SelectEntitiesAsync" />
    public async Task<IEnumerable<Product>> SelectEntitiesAsync(
        CancellationToken cancellationToken = default)
    {
        var rawSqlQuery = new StringBuilder("SELECT * FROM ")
            .Append(TableSchemaAndName)
            .Append(';')
            .ToString();

        await using var dbConnection = _dbConnectionFactory.Create();
        await dbConnection.OpenAsync(cancellationToken);
        await using var dbCommand = new NpgsqlCommand(rawSqlQuery, dbConnection);

        await using var dataSetReader = await dbCommand.ExecuteReaderAsync(cancellationToken);
        var queryResults = new List<Product>();
        while (await dataSetReader.ReadAsync(cancellationToken))
        {
            queryResults.Add(new Product
            {
                Barcode = dataSetReader.GetString("barcode"),
                Name = dataSetReader.GetString("name"),
                PackageSize = dataSetReader.GetString("package_size"),
                Weight = dataSetReader.GetDouble("weight")
            });
        }

        return queryResults;
    }
    
    /// <inheritdoc cref="IRepository{TEntity}.UpdateEntityAsync"/>
    public async Task UpdateEntityAsync(
        Product entityToUpdate,
        CancellationToken cancellationToken = default)
    {
        
    }
    
    /// <inheritdoc cref="IRepository{TEntity}.DeleteEntityAsync" />
    public async Task DeleteEntityAsync(
        Product entityToDelete,
        CancellationToken cancellationToken = default)
    {
        
    }
    
    #endregion
    
    #region System.IDisposable implementation
    
    /// <inheritdoc cref="IDisposable.Dispose" />
    public void Dispose()
    {
        GC.SuppressFinalize(this);
    }
    
    /// <summary>
    /// 
    /// </summary>
    ~ProductsRepository()
    {
        
    }
    
    #endregion
    
}