using Grpc.Core;
using Microsoft.Extensions.Options;

using DB.Client.Launcher.Protoc.Engine.Settings;
using DB.Client.Core.Interfaces;

namespace DB.Client.Launcher.Protoc.Engine;

/// <summary>
/// 
/// </summary>
public sealed class GrpcChannelFactory:
    IAbstractFactory<Channel>
{
    
    #region Fields

    /// <summary>
    /// 
    /// </summary>
    private readonly IOptions<GrpcClientSettings> _options;

    #endregion
    
    #region Constructors
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="options"></param>
    /// <exception cref="ArgumentNullException"></exception>
    public GrpcChannelFactory(
        IOptions<GrpcClientSettings> options)
    {
        _options = options ?? throw new ArgumentNullException(nameof(options));
    }
    
    #endregion
    
    #region DB.Client.Core.Interfaces.IAbstractFactory<out Channel> implementation
    
    /// <inheritdoc cref="IAbstractFactory{T}.Create" />
    public Channel Create()
    {
        return new Channel(_options.Value.TargetAddress, ChannelCredentials.Insecure);
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
    ~GrpcChannelFactory()
    {
        
    }
    
    #endregion
    
}