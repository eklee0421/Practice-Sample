using WpfKeypad.ViewModel.ViewModels;
using System.Windows.Controls;
using WpfKeypad.ViewModel;
using System.Windows;
using WpfKeypad.Interface;

namespace WpfKeypad.View
{
    /// <summary>
    /// numPad.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class numPad : UserControl
    {

        private numPadViewModel _vm;
        public numPadInterface interactor { set; private get; }
        public numPad()
        {
            InitializeComponent();
            this.DataContext = new numPadViewModel();

            _vm = this.DataContext as numPadViewModel;

            _vm.PropertyChanged += _vm_PropertyChanged;

        }

        private void _vm_PropertyChanged(object sender, System.ComponentModel.PropertyChangedEventArgs e)
        {
            if (e.PropertyName == "InputString")
            {
                // 연결된 인터페이스에 알려줌
                interactor.Numchanged(_vm.InputString);
            }
        }
        
    }
}
