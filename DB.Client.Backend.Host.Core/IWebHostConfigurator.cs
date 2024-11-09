using Microsoft.AspNetCore.Hosting;

namespace DB.Client.Backend.Host.Core;

/// <summary>
/// 
/// </summary>
public interface IWebHostConfigurator
{
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="webHostBuilder"></param>
    void Configure(
        IWebHostBuilder webHostBuilder);
    
}