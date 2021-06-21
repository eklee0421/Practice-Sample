using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using WpfPreset.Model;

namespace WpfPreset.ViewModel
{
    class InputNumCodeViewModel : ViewModelBase
    {
        private string inputString = String.Empty;
        public string InputString
        {
            set
            {
                inputString = value;
                OnPropertyChanged("InputString");
            }
            get
            {
                return inputString;
            }
        }

        private ICommand saveCommand;
        public ICommand SaveCommand
        {
            get
            {
                return saveCommand ?? (this.saveCommand = new DelegateCommand(SaveProduct));
            }
        }

        private void SaveProduct()
        {
            int x;
            if (!Int32.TryParse(InputString, out x))
            {
                MessageBox.Show("숫자만 입력 가능합니다");

            }
            else if (Convert.ToInt32("0") < Convert.ToInt32(InputString) && Convert.ToInt32(InputString) > Convert.ToInt32("20"))
            {
                MessageBox.Show("20 이하의 숫자를 입력해주세요");
            }
            else
            {
                OnPropertyChanged("SaveProduct");
            }
        }
    }
}
