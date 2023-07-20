using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Input;
using numPadClk;
using WpfKeypad.ViewModel.ViewModels;

using System.Collections.ObjectModel;
using wpfKeyPad.ViewModel;

namespace WpfKeypad.ViewModel
{
    class numTextViewModel : ViewModelBase
    {
        public numTextViewModel()
        { 
        }

        public string numstring
        {
            get
            {
                return numstring;
            }
            set
            {
                this.InputString = value;
                OnPropertyChanged("NumChanged");
            }
        }

    }
    
}
