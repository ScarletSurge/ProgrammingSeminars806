using System.Net;

namespace RGU.WebProgramming.Server.REST.API.Settings;

/// <summary>
/// 
/// </summary>
public sealed class ServerSettings
{
    
    #region Fields
    
    /// <summary>
    /// 
    /// </summary>
    private string _listenAddress;
    
    #endregion
    
    #region Properties
    
    /// <summary>
    /// 
    /// </summary>
    public string ListenAddress
    {
        get =>
            _listenAddress.Equals("localhost")
                ? IPAddress.Loopback.ToString()
                : _listenAddress;

        set =>
            _listenAddress = value;
}
    
    /// <summary>
    /// 
    /// </summary>
    public ushort ListenPort
    {
        get;

        set;
    }
    
    /// <summary>
    /// 
    /// </summary>
    public string CertPath
    {
        get;

        set;
    }
    
    /// <summary>
    /// 
    /// </summary>
    public string CertPassword
    {
        get;

        set;
    }
    
    #endregion
    
}