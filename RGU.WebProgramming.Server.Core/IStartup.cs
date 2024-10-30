using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;

namespace RGU.WebProgramming.Server.Core;

/// <summary>
/// 
/// </summary>
public interface IStartup
{
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="ctx"></param>
    /// <param name="services"></param>
    void ConfigureServices(
        HostBuilderContext ctx,
        IServiceCollection services);
    
}