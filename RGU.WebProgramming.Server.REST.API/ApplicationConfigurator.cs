using Microsoft.AspNetCore.Builder;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using RGU.WebProgramming.Server.Core;
using RGU.WebProgramming.Server.REST.API.Controller;

namespace RGU.WebProgramming.Server.REST.API;

public class ApplicationConfigurator:
    IApplicationConfigurator,
    IStartup
{
    
    #region RGU.WebProgramming.Server.Core.IApplicationConfigurator implementation
    
    /// <inheritdoc cref="IApplicationConfigurator.Configure" /> 
    public void Configure(
        IApplicationBuilder applicationBuilder)
    {
        // JToken
        applicationBuilder.UseRouting();
    }
    
    #endregion
    
    #region RGU.WebProgramming.Server.Core.IStartup implementation
    
    /// <inheritdoc cref="IStartup.ConfigureServices" />
    public void ConfigureServices(
        HostBuilderContext ctx,
        IServiceCollection services)
    {
        services
            .AddControllers()
            .AddApplicationPart(typeof(ControllerExample).Assembly)
            .AddNewtonsoftJson();
    }
    
    #endregion
    
}