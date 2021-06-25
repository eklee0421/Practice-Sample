using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using WpfKeyBoard.View;
using WpfKeyBoard.Windows;

namespace WpfKeyBoard.ViewModel
{
    class KeyboardViewModel : ViewModelBase
    {
        public KeyboardViewModel()
        {
            //clk char
            this.Append = new StringAppend(this);

            //clk backspace
            this.Back = new StringBack(this);

            //clk C
            this.Clear = new StringClear(this);

            //this.CloseWindow = new CloseWindow(this);

            this.Shift = new PushedShift(this);
        }

        public ICommand Append { protected set; get; }
        public ICommand Back { protected set; get; }
        public ICommand Clear { protected set; get; }
        //public ICommand CloseWindow { protected set; get; }
        public ICommand Shift { protected set; get; }

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

        private bool checkedShift = false;
        public bool CheckedShift
        {
            get { return checkedShift; }
            set { checkedShift = value; OnPropertyChanged("TriggerShift"); }
        }
        private bool checkedKorean = false;
        public bool CheckedKorean
        {
            get { return checkedKorean; }
            set { checkedKorean = value; }
        }

    }

    class StringAppend : ICommand
    {
        private KeyboardViewModel keyboardviewmodel;
        public event EventHandler CanExecuteChanged;

        public StringAppend(KeyboardViewModel keyboardviewModel)
        {
            this.keyboardviewmodel = keyboardviewModel;
        }

        public bool CanExecute(object parameter)
        {
            return true;
        }

        public void Execute(object parameter)
        {
            parameter = changedChar(parameter);
            keyboardviewmodel.InputString += parameter;
        }

        private object changedChar(object parameter)
        {
            if(keyboardviewmodel.CheckedShift == true && keyboardviewmodel.CheckedKorean == false)
            {
                switch (parameter)
                {
                    case "`": parameter = "~"; break;
                    case "1": parameter = "!"; break;
                    case "2": parameter = "@"; break;
                    case "3": parameter = "#"; break;
                    case "4": parameter = "$"; break;
                    case "5": parameter = "%"; break;
                    case "6": parameter = "^"; break;
                    case "7": parameter = "&"; break;
                    case "8": parameter = "*"; break;
                    case "9": parameter = "("; break;
                    case "0": parameter = ")"; break;
                    case "-": parameter = "_"; break;
                    case "=": parameter = "+"; break;
                    case "q": parameter = "Q"; break;
                    case "w": parameter = "W"; break;
                    case "e": parameter = "E"; break;
                    case "r": parameter = "R"; break;
                    case "t": parameter = "T"; break;
                    case "y": parameter = "Y"; break;
                    case "u": parameter = "U"; break;
                    case "i": parameter = "I"; break;
                    case "o": parameter = "O"; break;
                    case "p": parameter = "P"; break;
                    case "[": parameter = "{"; break;
                    case "]": parameter = "}"; break;
                    case "\\": parameter = ""; break;
                    case "a": parameter = "A"; break;
                    case "s": parameter = "S"; break;
                    case "d": parameter = "D"; break;
                    case "f": parameter = "F"; break;
                    case "g": parameter = "G"; break;
                    case "h": parameter = "H"; break;
                    case "j": parameter = "J"; break;
                    case "k": parameter = "K"; break;
                    case "l": parameter = "L"; break;
                    case ";": parameter = ":"; break;
                    case "'": parameter = "\""; break;
                    case "z": parameter = "Z"; break;
                    case "x": parameter = "X"; break;
                    case "c": parameter = "C"; break;
                    case "v": parameter = "V"; break;
                    case "b": parameter = "B"; break;
                    case "n": parameter = "N"; break;
                    case "m": parameter = "M"; break;
                    case ",": parameter = "<"; break;
                    case ".": parameter = ">"; break;
                    case "/": parameter = "?"; break;

                }
            }
            return parameter;
        }
    }
    class StringBack : ICommand
    {
        private KeyboardViewModel keyboardviewmodel;
        public StringBack(KeyboardViewModel keyboardviewmodel)
        {
            this.keyboardviewmodel = keyboardviewmodel;
        }

        public event EventHandler CanExecuteChanged
        {
            add { CommandManager.RequerySuggested += value; }
            remove { CommandManager.RequerySuggested -= value; }
        }

        public bool CanExecute(object parameter)
        {
            return keyboardviewmodel.InputString.Length > 0;
        }

        public void Execute(object parameter)
        {
            int length = keyboardviewmodel.InputString.Length - 1;
            if (0 < length)
            {
                keyboardviewmodel.InputString = keyboardviewmodel.InputString.Substring(0, length);
            }
            else
            {
                keyboardviewmodel.InputString = string.Empty;
            }

        }
    }
    class StringClear : ICommand
    {
        private KeyboardViewModel keyboardviewmodel;

        public StringClear(KeyboardViewModel keyboardviewmodel)
        {
            this.keyboardviewmodel = keyboardviewmodel;
        }
        public event EventHandler CanExecuteChanged
        {
            add { CommandManager.RequerySuggested += value; }
            remove { CommandManager.RequerySuggested -= value; }
        }

        public bool CanExecute(object parameter)
        {
            return keyboardviewmodel.InputString.Length > 0;
        }

        public void Execute(object parameter)
        {
            keyboardviewmodel.InputString = keyboardviewmodel.InputString = string.Empty;
        }
    }

    internal class PushedShift : ICommand
    {
        private KeyboardViewModel keyboardviewmodel;
        public event EventHandler CanExecuteChanged;

        public PushedShift(KeyboardViewModel keyboardviewModel)
        {
            this.keyboardviewmodel = keyboardviewModel;
        }

        public bool CanExecute(object parameter)
        {
            return true;
        }

        public void Execute(object parameter)
        {
            keyboardviewmodel.CheckedShift = !keyboardviewmodel.CheckedShift;
        }
    }

    

}
