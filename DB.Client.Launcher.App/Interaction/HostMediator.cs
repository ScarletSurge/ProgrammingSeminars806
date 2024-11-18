using System.Runtime.CompilerServices;
using System.Windows;
using DB.Client.Domain.Converters;
using DB.Client.Grpc;
using DB.Client.Launcher.Protoc.Engine.Grpc;
using Google.Protobuf.WellKnownTypes;
using Microsoft.Extensions.Logging;
using Microsoft.Extensions.Options;
using Product = DB.Client.Domain.Product;

namespace DB.Client.Launcher.App.Interaction;

/// <summary>
/// 
/// </summary>
public sealed class HostMediator
{
    
    #region Fields
    
    /// <summary>
    /// 
    /// </summary>
    private readonly GrpcChannelFactory _grpcChannelFactory;
    
    /// <summary>
    /// 
    /// </summary>
    private readonly IOptions<HostMediatorSettings> _options;
    
    /// <summary>
    /// 
    /// </summary>
    private readonly ILogger<HostMediator>? _logger;

    #endregion
    
    #region Constructor
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="grpcChannelFactory"></param>
    /// <param name="options"></param>
    /// <param name="logger"></param>
    /// <exception cref="ArgumentNullException"></exception>
    public HostMediator(
        GrpcChannelFactory grpcChannelFactory,
        IOptions<HostMediatorSettings> options,
        ILogger<HostMediator>? logger)
    {
        _grpcChannelFactory = grpcChannelFactory ?? throw new ArgumentNullException(nameof(grpcChannelFactory));
        _options = options ?? throw new ArgumentNullException(nameof(options));
        _logger = logger;
    }
    
    #endregion
    
    #region Methods
    
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    private ProductService.ProductServiceClient CreateClient()
    {
        return new ProductService.ProductServiceClient(_grpcChannelFactory.Create());
    }
    
    #endregion

    #region API Methods
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="cancellationToken"></param>
    /// <returns></returns>
    public async Task<Product[]> GetProductsFromDbAsync(
        
        CancellationToken cancellationToken = default)
    {
        try
        {
            var response = await CreateClient().GetProductsAsync(new Empty(), cancellationToken: cancellationToken);

            return response.Products_.Select(ConverterExtensions.ConvertBack).ToArray();
        }
        catch (Exception ex)
        {
            // TODO: logs here...
            return Array.Empty<Product>();
        }

        return null;
    }
    
    #endregion
    
}