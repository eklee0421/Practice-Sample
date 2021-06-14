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
using wpfProductApp.ViewModel.ViewModels;

namespace wpfProductApp.View
{
    /// <summary>
    /// totalPrice.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class totalPrice : UserControl
    {
        private TotalPriceViewModel _vm;
        public ITotalPrice Interactor { set; private get; }
        public totalPrice()
        {
            InitializeComponent();
            this.DataContext = new TotalPriceViewModel();
            _vm = this.DataContext as TotalPriceViewModel;

        }


        /// <summary>
        /// </summary>
        /// <param name="num"></param>
        //void total.Numchanged(string num) { _vm.numstring = num; }

    }
}
