using Microsoft.Extensions.Options;
using StackExchange.Redis;

using DB.Client.Backend.DBInteraction.Redis.Settings;
using DB.Client.Domain;

namespace DB.Client.Backend.DBInteraction.Redis;

// RedisConnectionFactory
// IServer
// Redis arch
// Redis keys
// StackExchange.Redis Exceptions

/// <summary>
/// 
/// </summary>
public sealed class RedisInteractionExample
{
    
    #region Fields
    
    /// <summary>
    /// 
    /// </summary>
    private readonly IOptions<RedisInteractionExampleSettings> _options;
    
    #endregion
    
    #region Constructors
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="options"></param>
    public RedisInteractionExample(
        IOptions<RedisInteractionExampleSettings> options)
    {
        _options = options ?? throw new ArgumentNullException(nameof(options));
    }
    
    #endregion
    
    #region Methods

    /// <summary>
    /// 
    /// </summary>
    /// <param name="toStore"></param>
    /// <param name="cancellationToken"></param>
    public async Task FooAsync(
        string key,
        Product toStore,
        CancellationToken cancellationToken = default)
    {
        await using var redisConnection =
            await ConnectionMultiplexer.ConnectAsync($"{_options.Value.Address}:{_options.Value.Port}");

        var db = redisConnection.GetDatabase(0);
        await using var stream = toStore.Serialize();
        var objectBinaryState = stream.GetBuffer().ToHexString();
        await db.StringGetSetAsync(new RedisKey(key), new RedisValue(objectBinaryState));
    }

}