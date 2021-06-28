using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using WpfKeyBoard.Model;
using WpfKeyBoard.View;

namespace WpfKeyBoard.ViewModel
{
    class NumPadViewModel : ViewModelBase
    {
        public NumPadViewModel()
        {
            //clk num
            this.Append = new Append(this);

            //clk backspace
            this.Back = new Back(this);

            //clk C
            this.Clear = new Clear(this);

            this.OpenKeyboard = new OpenKeyboard(this);
        }

        public ICommand Append { protected set; get; }
        public ICommand Back { protected set; get; }
        public ICommand Clear { protected set; get; }

        public ICommand OpenKeyboard { protected set; get; }

        private string inputString = String.Empty;
        public string InputString
        {
            set
            {
                if (inputString != value)
                {
                    inputString = value;
                    OnPropertyChanged("InputString");
                }
            }
            get
            {
                return inputString;
            }
        }

    }

    class Append : ICommand
    {
        private NumPadViewModel numpadviewmodel;
        public event EventHandler CanExecuteChanged;

        public Append(NumPadViewModel numpadviewmodel)
        {
            this.numpadviewmodel = numpadviewmodel;
        }

        public bool CanExecute(object parameter)
        {
            return true;
        }

        public void Execute(object parameter)
        {
            numpadviewmodel.InputString += parameter;
        }
    }

    class Back : ICommand
    {
        private NumPadViewModel numpadviewmodel;
        public Back(NumPadViewModel numpadviewmodel)
        {
            this.numpadviewmodel = numpadviewmodel;
        }

        public event EventHandler CanExecuteChanged
        {
            add { CommandManager.RequerySuggested += value; }
            remove { CommandManager.RequerySuggested -= value; }
        }

        public bool CanExecute(object parameter)
        {
            return numpadviewmodel.InputString.Length > 0;
        }

        public void Execute(object parameter)
        {
            int length = numpadviewmodel.InputString.Length - 1;
            if (0 < length)
            {
                numpadviewmodel.InputString = numpadviewmodel.InputString.Substring(0, length);
            }
            else
            {
                numpadviewmodel.InputString = string.Empty;
            }

        }
    }
    class Clear : ICommand
    {
        private NumPadViewModel numpadviewmodel;

        public Clear(NumPadViewModel numpadviewmodel)
        {
            this.numpadviewmodel = numpadviewmodel;
        }
        public event EventHandler CanExecuteChanged
        {
            add { CommandManager.RequerySuggested += value; }
            remove { CommandManager.RequerySuggested -= value; }
        }

        public bool CanExecute(object parameter)
        {
            return numpadviewmodel.InputString.Length > 0;
        }

        public void Execute(object parameter)
        {
            numpadviewmodel.InputString = numpadviewmodel.InputString = string.Empty;
        }
    }

    class OpenKeyboard : ICommand
    {
        private NumPadViewModel numpadviewmodel;
        public event EventHandler CanExecuteChanged;

        public OpenKeyboard(NumPadViewModel numpadviewmodel)
        {
            this.numpadviewmodel = numpadviewmodel;
        }

        public bool CanExecute(object parameter)
        {
            return true;
        }

        public void Execute(object parameter)
        {

            OpenVirtualKeyboard openVirtualKeyboard = new OpenVirtualKeyboard(numpadviewmodel.InputString);
            numpadviewmodel.InputString = openVirtualKeyboard.ReturnData();

        }
       
    }
}
   
    

