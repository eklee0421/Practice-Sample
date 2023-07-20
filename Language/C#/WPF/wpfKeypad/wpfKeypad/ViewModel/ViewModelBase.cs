using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace WpfKeypad.ViewModel.ViewModels
{
    public abstract class ViewModelBase : INotifyPropertyChanged
    {
        #region Property Changed Event Handler

        protected void OnPropertyChanged(string propertyName)
        {
            PropertyChangedEventHandler handler = PropertyChanged;
            if (handler != null)
            {
                handler(this, new PropertyChangedEventArgs(propertyName));
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
        #endregion Property Changed Event Handler

        private string inputString = String.Empty;
        public string InputString
        {
            set
            {
                if (inputString != value)
                {
                    inputString = value;
                    OnPropertyChanged("InputString");
                    if (value != "")
                    {
                        DisplayText = value;
                    }
                }
            }
            get
            {
                //MessageBox.Show(inputString);
                return inputString;
            }
        }

        /// <summary>
        /// 출력창과 바인딩된 속성
        /// </summary>
        private string displayText = "";
        public string DisplayText
        {
            set
            {
                if (displayText != value)
                {
                    displayText = value;
                    OnPropertyChanged(DisplayText);
                }
            }
            get { return displayText; }
        }
    }
}
