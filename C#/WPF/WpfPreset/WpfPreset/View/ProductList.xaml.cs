using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using WpfPreset.Interface;
using WpfPreset.Model;
using WpfPreset.ViewModel;

namespace WpfPreset.View
{
    /// <summary>
    /// ProductList.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class ProductList : UserControl, IInputNumCode
    {
        public IProductList interactor { set; private get; }
        private ProductListViewModel _vm;

        public ProductList()
        {
            InitializeComponent();
            this.DataContext = new ProductListViewModel();
            _vm = this.DataContext as ProductListViewModel;

            
        }

        /// <summary>
        /// 신규 상품이 추가되면 뷰모델 프로퍼티에 값을 입력하면 뷰모델에서 처리함.
        /// </summary>
        /// <param name="product"></param>
        void IInputNumCode.SearchCode(string Inputstring)
        {
            FindProductModel findProductModel = new FindProductModel(Inputstring);
            _vm.NewProduct = findProductModel.GetProduct();
            
            //pname.DisplayMemberBinding = new Binding(_vm.NewProduct.Name);
            //txt.Text += _vm.NewProduct.Name;
        }
    }
}
