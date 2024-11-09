namespace DB.Client.Domain.Converters;

/// <summary>
/// 
/// </summary>
public static class ConverterExtensions
{

    #region Product

    /// <summary>
    /// 
    /// </summary>
    /// <param name="domainProduct"></param>
    /// <returns></returns>
    public static DB.Client.Grpc.Product Convert(
        this DB.Client.Domain.Product domainProduct)
    {
        ArgumentNullException.ThrowIfNull(domainProduct, nameof(domainProduct));

        return new DB.Client.Grpc.Product
        {
            Barcode = domainProduct.Barcode,
            Name = domainProduct.Name,
            PackageSize = domainProduct.PackageSize,
            Weight = domainProduct.Weight
        };
    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="protobufProduct"></param>
    /// <returns></returns>
    public static DB.Client.Domain.Product ConvertBack(this DB.Client.Grpc.Product protobufProduct)
    {
        ArgumentNullException.ThrowIfNull(protobufProduct, nameof(protobufProduct));

        return new DB.Client.Domain.Product
        {
            Barcode = protobufProduct.Barcode,
            Name = protobufProduct.Name,
            PackageSize = protobufProduct.PackageSize,
            Weight = protobufProduct.Weight
        };
    }

    #endregion

}