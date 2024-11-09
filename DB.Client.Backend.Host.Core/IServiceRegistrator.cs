using DryIoc;
using Microsoft.Extensions.Configuration;

namespace DB.Client.Backend.Host.Core;

/// <summary>
/// 
/// </summary>
public interface IServiceRegistrator
{
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="registrator"></param>
    /// <param name="configuration"></param>
    public void Register(
        IRegistrator registrator,
        IConfiguration configuration);

}