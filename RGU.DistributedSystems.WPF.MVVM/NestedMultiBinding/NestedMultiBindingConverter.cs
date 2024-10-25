using System.Globalization;
using System.Windows.Data;

namespace RGU.DistributedSystems.WPF.MVVM.NestedMultiBinding;

/// <summary>
/// 
/// </summary>
public sealed class NestedMultiBindingConverter:
    IMultiValueConverter
{
    
    #region Constructors
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="tree"></param>
    public NestedMultiBindingConverter(
        NestedMultiBindingsTree tree)
    {
        Tree = tree;
    }
    
    #endregion
    
    #region Properties
    
    /// <summary>
    /// 
    /// </summary>
    private NestedMultiBindingsTree Tree
    {
        get;
    }
    
    #endregion
    
    #region Methods
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="tree"></param>
    /// <param name="values"></param>
    /// <param name="targetType"></param>
    /// <param name="culture"></param>
    /// <returns></returns>
    private object GetTreeValue(
        NestedMultiBindingsTree tree,
        object[] values,
        Type targetType, CultureInfo culture)
    {
        var objects = tree.Nodes.Select(x =>
            x is NestedMultiBindingsTree nestedMultiBindingsTree
                ? GetTreeValue(nestedMultiBindingsTree, values, targetType, culture)
                : values[x.Index]).ToArray();
        return tree.Converter.Convert(objects, targetType, tree.ConverterParameter,
            tree.ConverterCulture ?? culture);
    }
    
    #endregion
    
    #region System.Windows.Data.IMultiValueConverter implementation
    
    /// <inheritdoc cref="IMultiValueConverter.Convert" />
    public object Convert(
        object[] values,
        Type targetType,
        object parameter,
        CultureInfo culture)
    {
        var value = GetTreeValue(Tree, values, targetType, culture);
        return value;
    }
    
    /// <inheritdoc cref="IMultiValueConverter.ConvertBack" />
    public object[] ConvertBack(
        object value,
        Type[] targetTypes,
        object parameter,
        CultureInfo culture)
    {
        throw new NotImplementedException();
    }
    
    #endregion

}