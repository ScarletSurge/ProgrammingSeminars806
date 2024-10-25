using System.Collections.ObjectModel;
using System.Globalization;
using System.Windows.Data;
using System.Windows.Markup;

namespace RGU.DistributedSystems.WPF.MVVM.NestedMultiBinding;

/// <summary>
/// 
/// </summary>
[ContentProperty(nameof(Bindings))]
public sealed class NestedMultiBinding:
    MarkupExtension
{
    
    #region Constructors
    
    /// <summary>
    /// 
    /// </summary>
    public NestedMultiBinding()
    {
        Bindings = new Collection<BindingBase>();
    }
    
    #endregion
    
    #region Properties

    /// <summary>
    /// 
    /// </summary>
    public Collection<BindingBase> Bindings
    {
        get;
    }

    /// <summary>
    /// 
    /// </summary>
    public IMultiValueConverter Converter
    {
        get;
        
        set;
    }

    /// <summary>
    /// 
    /// </summary>
    public object ConverterParameter
    {
        get;
        
        set;
    }

    /// <summary>
    /// 
    /// </summary>
    public CultureInfo ConverterCulture
    {
        get;
        
        set;
    }
    
    #endregion
    
    #region Methods
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="nestedBinding"></param>
    /// <param name="multiBinding"></param>
    /// <returns></returns>
    private static NestedMultiBindingsTree GetNestedBindingsTree(
        NestedMultiBinding nestedBinding,
        MultiBinding multiBinding)
    {
        var tree = new NestedMultiBindingsTree
        {
            Converter = nestedBinding.Converter,
            ConverterParameter = nestedBinding.ConverterParameter,
            ConverterCulture = nestedBinding.ConverterCulture
        };
        
        foreach (var bindingBase in nestedBinding.Bindings)
        {
            var binding = bindingBase as Binding;
            if (binding?.Source is NestedMultiBinding childNestedBinding && binding.Converter == null)
            {
                tree.Nodes.Add(GetNestedBindingsTree(childNestedBinding, multiBinding));
                continue;
            }

            tree.Nodes.Add(new NestedMultiBindingNode(multiBinding.Bindings.Count));
            multiBinding.Bindings.Add(bindingBase);
        }

        return tree;
    }
    
    #endregion
    
    #region System.Windows.Markup.MarkupExtension overrides
    
    /// <inheritdoc cref="MarkupExtension.ProvideValue" />
    public override object ProvideValue(
        IServiceProvider serviceProvider)
    {
        if (!Bindings.Any())
            throw new ArgumentNullException(nameof(Bindings));
        if (Converter == null)
            throw new ArgumentNullException(nameof(Converter));

        var target = (IProvideValueTarget)serviceProvider.GetService(typeof(IProvideValueTarget));
        if (target.TargetObject is Collection<BindingBase>)
        {
            var binding = new Binding
            {
                Source = this
            };
            return binding;
        }

        var multiBinding = new MultiBinding
        {
            Mode = BindingMode.OneWay,
            StringFormat = "N2"
        };
        var tree = GetNestedBindingsTree(this, multiBinding);
        var converter = new NestedMultiBindingConverter(tree);
        multiBinding.Converter = converter;

        return multiBinding.ProvideValue(serviceProvider);
    }
    
    #endregion
    
}