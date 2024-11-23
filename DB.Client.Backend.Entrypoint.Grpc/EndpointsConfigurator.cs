using DB.Client.Backend.Host.Core;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Routing;

namespace DB.Client.Backend.Entrypoint.Grpc;

/// <summary>
/// 
/// </summary>
public sealed class EndpointsConfigurator:
    IEndpointsConfigurator
{
    
    #region DB.Client.Backend.Host.Core.IEndpointsConfigurator implementation

    /// <inheritdoc cref="IEndpointsConfigurator.Configure(IEndpointRouteBuilder)"/>
    public void Configure(
        IEndpointRouteBuilder routeBuilder)
    {
        routeBuilder.MapGrpcService<Services.GrpcServiceSample>();
    }

    #endregion
    
}