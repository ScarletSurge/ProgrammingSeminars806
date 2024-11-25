namespace DB.Client.Domain.Infrastructure;

/// <summary>
/// 
/// </summary>
/// <typeparam name="TEntity"></typeparam>
public interface IRepository<TEntity>:
    IDisposable
        where TEntity: class
{
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="entity"></param>
    /// <param name="cancellationToken"></param>
    /// <returns></returns>
    Task CreateAsync(
        TEntity entity,
        CancellationToken cancellationToken = default);
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="entityKey"></param>
    /// <param name="cancellationToken"></param>
    /// <returns></returns>
    Task<TEntity> SelectEntityAsync(
        object entityKey,
        CancellationToken cancellationToken = default);
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="cancellationToken"></param>
    /// <returns></returns>
    Task<IEnumerable<TEntity>> SelectEntitiesAsync(
        CancellationToken cancellationToken = default);
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="entityToUpdate"></param>
    /// <param name="cancellationToken"></param>
    /// <returns></returns>
    Task UpdateEntityAsync(
        TEntity entityToUpdate,
        CancellationToken cancellationToken = default);
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="entityToDelete"></param>
    /// <param name="cancellationToken"></param>
    /// <returns></returns>
    Task DeleteEntityAsync(
        TEntity entityToDelete,
        CancellationToken cancellationToken = default);

}