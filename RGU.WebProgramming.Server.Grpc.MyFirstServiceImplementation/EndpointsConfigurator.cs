using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Routing;

using RGU.WebProgramming.Server.Core;
using RGU.WebProgramming.Server.Grpc.MyFirstServiceImplementation.Services;

namespace RGU.WebProgramming.Server.Grpc.MyFirstServiceImplementation;

/// <summary>
/// 
/// </summary>
public sealed class EndpointsConfigurator:
    IEndpointsConfigurator
{
    
    #region Terminal.Host.Grpc.IEndpointsConfigurator implementation

    /// <inheritdoc cref="IEndpointsConfigurator.Configure(IEndpointRouteBuilder)"/>
    public void Configure(
        IEndpointRouteBuilder routeBuilder)
    {
        routeBuilder.MapGrpcService<Services.MyFirstServiceImplementation>();
    }

    #endregion
    
}