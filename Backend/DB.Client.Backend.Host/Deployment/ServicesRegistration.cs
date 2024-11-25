using DryIoc;
using Microsoft.Extensions.Logging;

using DB.Client.Backend.Host.Core;

namespace DB.Client.Backend.Host.Deployment;

/// <summary>
/// 
/// </summary>
internal sealed class ServicesRegistration
{
    
    #region Constructors

    /// <summary>
    /// 
    /// </summary>
    /// <param name="registrator"></param>
    public ServicesRegistration(
        IRegistrator registrator)
    {
        var loggerFactoryMethod = typeof(LoggerFactoryExtensions).GetMethod(
            "CreateLogger",
            1,
            new[] { typeof(ILoggerFactory) }
        );

        registrator.Register(
            typeof(ILogger<>),
            made: Made.Of(
                req => loggerFactoryMethod?.MakeGenericMethod(req.ServiceType.GenericTypeArguments)
            )
        );

        var loggerProviderMethod = typeof(ILoggerFactory).GetMethod("CreateLogger");

        registrator.Register(
            typeof(ILogger),
            made: Made.Of(
                req => loggerProviderMethod,
                ServiceInfo.Of<ILoggerFactory>(),
                Parameters.Of.Type(request => "Default")
            )
        );
        
        registrator.Register<App>(Reuse.Singleton);
        
        registrator.RegisterMany(
            AppDomain.CurrentDomain
                .GetAssemblies()
                .Distinct(),
            type =>
                type.ImplementsServiceType<IServiceRegistrator>()
                    ? type.GetInterfaces()
                    : null,
            type => ReflectionFactory.Of(type, Reuse.Singleton, Made.Of(), Setup.Default)
        );
    }

    #endregion
    
}