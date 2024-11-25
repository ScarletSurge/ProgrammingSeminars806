using Microsoft.AspNetCore.Builder;

namespace DB.Client.Backend.Host.Core;

/// <summary>
/// 
/// </summary>
public interface IApplicationConfigurator
{
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="applicationBuilder"></param>
    void Configure(
        IApplicationBuilder applicationBuilder);
    
}