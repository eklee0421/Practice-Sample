using WpfKeypad.ViewModel.ViewModels;
using System.Windows.Controls;
using WpfKeypad.ViewModel;
using System.Windows;
using WpfKeypad.Interface;

namespace WpfKeypad.View
{
    /// <summary>
    /// numText.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class NumText : UserControl, numPadInterface
    {
        private numTextViewModel _vm;
        public numTextInterface interactor { set; private get; }
        public NumText()
        {
            InitializeComponent();
            this.DataContext = new numTextViewModel();
            _vm = this.DataContext as numTextViewModel;

            //_vm.PropertyChanged += _vm_PropertyChanged;
        }

        private void _vm_PropertyChanged(object sender, System.ComponentModel.PropertyChangedEventArgs e)
        {

            switch (e.PropertyName)
            {
                case "numchange":
                    //code
                    break;
            }
        }

        /// <summary>
        /// 신규 유저가 추가되면 뷰모델 프로퍼티에 값을 입력하면 뷰모델에서 처리함.
        /// </summary>
        /// <param name="num"></param>
        void numPadInterface.Numchanged(string num) { _vm.numstring = num; }


    }
}
