namespace DB.Client.Launcher.Protoc.Engine.Settings;

/// <summary>
/// 
/// </summary>
public sealed class GrpcClientSettings
{

    #region Properties

    /// <summary>
    /// 
    /// </summary>
    public string TargetAddress
    {
        get;
        
        set;
    }
    
    /// <summary>
    /// 
    /// </summary>
    public string TargetName
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

    #endregion

}