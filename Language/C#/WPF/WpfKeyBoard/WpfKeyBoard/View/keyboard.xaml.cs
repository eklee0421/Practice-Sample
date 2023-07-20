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
using WpfKeyBoard.ViewModel;

namespace WpfKeyBoard.View
{
    /// <summary>
    /// keyboard.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class keyboard : UserControl
    {

        private KeyboardViewModel _vm;
        public keyboard()
        {
            InitializeComponent();
            this.DataContext = new KeyboardViewModel();
            _vm = this.DataContext as KeyboardViewModel;
            _vm.PropertyChanged += _vm_PropertyChanged;
            _vm.PropertyChanged += _vm_PropertyChanged;
        }

        private void _vm_PropertyChanged(object sender, System.ComponentModel.PropertyChangedEventArgs e)
        {
            
            if(e.PropertyName == "TriggerShift")
            {
                if(_vm.CheckedShift == false)
                {
                    shift.Background = new SolidColorBrush(Color.FromArgb(0xFF, 221, 221, 221));
                    numsign1.Content = "`"; num1.Content = "1"; num2.Content = "2"; num3.Content = "3"; num4.Content = "4"; 
                }
                else
                {
                    shift.Background = new SolidColorBrush(Color.FromArgb(0xFF, 0x99, 0xDD, 0x99));
                    numsign1.Content = "~"; num1.Content = "!"; num2.Content = "@"; num3.Content = "#"; num4.Content = "$";
                    
                }


            }
            
        }

    }
}
