namespace RGU.WebProgramming.Server.REST.Models;

/// <summary>
/// 
/// </summary>
public class ModelExample
{
    
    #region Properties
    
    /// <summary>
    /// 
    /// </summary>
    public int IntValue
    {
        get;

        set;
    }
    
    /// <summary>
    /// 
    /// </summary>
    public string StringValue
    {
        get;

        set;
    }
    
    #endregion
    
    #region System.Object overrides
    
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    public override string ToString()
    {
        return $"\"IntValue\": {IntValue}, \"StringValue\": \"{StringValue}\"";
    }

    #endregion
    
}