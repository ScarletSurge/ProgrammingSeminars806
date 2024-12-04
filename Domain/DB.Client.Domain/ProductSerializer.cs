namespace DB.Client.Domain;

/// <summary>
/// 
/// </summary>
public static class ProductSerializer
{
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="product"></param>
    /// <returns></returns>
    /// <exception cref="NotImplementedException"></exception>
    public static MemoryStream Serialize(
        this Product product)
    {
        // TODO: implement me

        throw new NotImplementedException();
    }
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="stream"></param>
    /// <returns></returns>
    public static Product Deserialize(
        this MemoryStream stream)
    {
        // TODO: implement me

        throw new NotImplementedException();
    }
    
}