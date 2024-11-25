namespace DB.Client.WPF.MVVM.NestedMultiBinding;

/// <summary>
/// 
/// </summary>
public class NestedMultiBindingNode
{
    
    #region Constructors
    /// <summary>
    /// 
    /// </summary>
    /// <param name="index"></param>
    public NestedMultiBindingNode(
        int index)
    {
        Index = index;
    }
    
    #endregion
    
    #region Properties

    /// <summary>
    /// 
    /// </summary>
    public int Index
    {
        get;
    }
    
    #endregion
    
    #region System.Object overrides
    
    /// <inheritdoc cref="object.ToString" />
    public override string ToString()
    {
        return Index.ToString();
    }
    
    #endregion

}