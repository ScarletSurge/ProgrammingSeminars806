using RGU.WebProgramming.Server.Core;
using RGU.WebProgramming.Server.REST.API.Controller;

namespace RGU.WebProgramming.Server.REST.API;

public class ApplicationConfigurator:
    IApplicationConfigurator,
    Core.IStartup
{
    
    #region RGU.WebProgramming.Server.Core.IApplicationConfigurator implementation
    
    /// <inheritdoc cref="IApplicationConfigurator.Configure" /> 
    public void Configure(
        IApplicationBuilder applicationBuilder)
    {
        applicationBuilder.UseRouting();
        applicationBuilder.UseEndpoints(endpointRouteBuilder =>
        {
            endpointRouteBuilder.MapControllers();
        });
    }
    
    #endregion
    
    #region RGU.WebProgramming.Server.Core.IStartup implementation
    
    /// <inheritdoc cref="Core.IStartup.ConfigureServices" />
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