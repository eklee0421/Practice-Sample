using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using wpfProductApp.Interface;
using wpfProductApp.ViewModel;

namespace wpfProductApp.View
{
    /// <summary>
    /// SetProduct.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class SetProduct : UserControl
    {
        public ISetProduct interactor { set; private get; }
        private SetProductViewModel _vm;

        public SetProduct()
        {
            InitializeComponent();
            this.DataContext = new SetProductViewModel();

            _vm = this.DataContext as SetProductViewModel;
            _vm.PropertyChanged += _vm_PropertyChanged;
        }

        private void _vm_PropertyChanged(object sender, System.ComponentModel.PropertyChangedEventArgs e)
        {
            if(e.PropertyName == "SaveProduct")
            {
                interactor.ProductAdded(_vm.NewProduct);
            }
        }
    }
}
