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
using WpfPreset.ViewModel;

namespace WpfPreset.View
{
    /// <summary>
    /// InputNumCode.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class InputNumCode : UserControl
    {
        private InputNumCodeViewModel _vm;
        public IInputNumCode interactor { set; get; }
        public InputNumCode()
        {
            InitializeComponent();
            this.DataContext = new InputNumCodeViewModel();
            _vm = this.DataContext as InputNumCodeViewModel;

            _vm.PropertyChanged += _vm_PropertyChanged;

        }

        private void _vm_PropertyChanged(object sender, System.ComponentModel.PropertyChangedEventArgs e)
        {
            switch (e.PropertyName)
            {
                case "SaveProduct":
                    interactor.SearchCode(_vm.InputString);
                    break;
            }
        }
    }
}
