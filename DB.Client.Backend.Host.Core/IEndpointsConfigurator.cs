using Microsoft.AspNetCore.Routing;

namespace DB.Client.Backend.Host.Core;

/// <summary>
/// 
/// </summary>
public interface IEndpointsConfigurator
{
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="routeBuilder"></param>
    void Configure(
        IEndpointRouteBuilder routeBuilder);
    
}