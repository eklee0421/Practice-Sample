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
using wpfProductApp.Model;
using wpfProductApp.ViewModel;
using wpfProductApp.ViewModel.ViewModels;

namespace wpfProductApp.View
{
    /// <summary>
    /// ProductList.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class ProductList : UserControl, ISetProduct
    {
        public IProductList interactor { set; private get; }
        private ProductListViewModel _vm;
        public ProductList()
        {
            InitializeComponent();
            this.DataContext = new ProductListViewModel();
            _vm = this.DataContext as ProductListViewModel;

            _vm.PropertyChanged += _vm_PropertyChanged;
        }

        private void _vm_PropertyChanged(object sender, System.ComponentModel.PropertyChangedEventArgs e)
        {
            switch (e.PropertyName)
            {
                case "ProductAdded":
                    
                    //MessageBox.Show($"{_vm.NewProduct.Name}(이)가 추가되었음!!", "사용자추가");
                    break;
            }
        }

        /// <summary>
        /// 신규 상품이 추가되면 뷰모델 프로퍼티에 값을 입력하면 뷰모델에서 처리함.
        /// </summary>
        /// <param name="product"></param>
        void ISetProduct.ProductAdded(Product product)
        {
            _vm.NewProduct = product;
            
        }
    }
}
