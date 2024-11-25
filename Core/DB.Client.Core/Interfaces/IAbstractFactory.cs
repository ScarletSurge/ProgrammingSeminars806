namespace DB.Client.Core.Interfaces;

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
public interface IAbstractFactory<out T>:
    IDisposable
{
    
    /// <summary>
    /// 
    /// </summary>
    /// <returns></returns>
    T Create();

}