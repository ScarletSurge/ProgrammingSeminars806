using System.Windows;
using System.Windows.Controls;

namespace DB.Client.UI.Attached;

/// <summary>
/// 
/// </summary>
public class OwnButtonTemplateAttachedProperties:
    Button
{
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="obj"></param>
    /// <returns></returns>
    public static object GetOneMoreContent(
        DependencyObject obj)
    {
        return obj.GetValue(OneMoreContentProperty);
    }
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="obj"></param>
    /// <param name="value"></param>
    public static void SetOneMoreContent(
        DependencyObject obj,
        object value)
    {
        obj.SetValue(OneMoreContentProperty, value);
    }
    
    /// <summary>
    /// 
    /// </summary>
    public static readonly DependencyProperty OneMoreContentProperty = DependencyProperty.RegisterAttached("OneMoreContent", typeof(object), typeof(OwnButtonTemplateAttachedProperties));
    
}