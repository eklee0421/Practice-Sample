using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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
    }
}
