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
using WpfKeyBoard.Interface;
using WpfKeyBoard.ViewModel;

namespace WpfKeyBoard.View
{
    /// <summary>
    /// NumPad.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class NumPad : UserControl
    {
        private NumPadViewModel _vm;
        public INumPad interactor { set; private get; }

        public NumPad()
        {
            InitializeComponent();

            this.DataContext = new NumPadViewModel();

            _vm = this.DataContext as NumPadViewModel;

            _vm.PropertyChanged += _vm_PropertyChanged;
        }
        private void _vm_PropertyChanged(object sender, System.ComponentModel.PropertyChangedEventArgs e)
        {
            if (e.PropertyName == "InputString")
            {
                // 연결된 인터페이스에 알려줌
                //interactor.Numchanged(_vm.InputString);
            }
        }
    }
}
