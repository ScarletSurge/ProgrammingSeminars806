using System.Text;

namespace DB.Client.Domain;

/// <summary>
/// 
/// </summary>
public static class StringExtensions
{
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="value"></param>
    /// <returns></returns>
    /// <exception cref="ArgumentNullException"></exception>
    public static string ToHexString(
        this byte[] value)
    {
        return new StringBuilder((value ?? throw new ArgumentNullException(nameof(value))).Length * 2)
            .AppendJoin(string.Empty, value.Select(@byte => $"{@byte:x2}"))
            .ToString();
    }
    
    public static byte[] FromHexString(
        this string value)
    {
        var charsCount = value.Length;
        var result = new byte[charsCount / 2];
            
        for (var i = 0; i < charsCount; i += 2)
        {
            result[i / 2] = Convert.ToByte(value.Substring(i, 2), 16);
        }

        return result;
    }
    
}