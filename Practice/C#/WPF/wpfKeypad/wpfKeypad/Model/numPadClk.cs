using System;
using System.Windows;
using System.Windows.Input;
using WpfKeypad.ViewModel;

namespace numPadClk
{    
    class Append : ICommand
    {
        private numPadViewModel numpadviewmodel;
        public event EventHandler CanExecuteChanged;

        public Append(numPadViewModel numpadviewmodel)
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
        private numPadViewModel numpadviewmodel;
        public Back(numPadViewModel numpadviewmodel)
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
            return numpadviewmodel.DisplayText.Length > 0;
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
                numpadviewmodel.InputString = numpadviewmodel.DisplayText = string.Empty;
            }

        }
    }

    class Clear : ICommand
    {
        private numPadViewModel numpadviewmodel;

        public Clear(numPadViewModel numpadviewmodel)
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
            return numpadviewmodel.DisplayText.Length > 0;
        }

        public void Execute(object parameter)
        {
            numpadviewmodel.InputString = numpadviewmodel.DisplayText = string.Empty;
        }
    }    
}