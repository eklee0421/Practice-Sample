using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using wpfProductApp.Model;
using wpfProductApp.ViewModel.ViewModels;

namespace wpfProductApp.ViewModel
{
    class TotalPriceViewModel:ViewModelBase
    {
        private Total newTotal;
        public Total NewTotal
        {
            get
            {
                return newTotal;
            }
            set
            {
                newTotal = value;
                //MessageBox.Show(newTotal.sSumPrice);
                this.OnPropertyChanged("SettingTotal");
            }
        }

        
    }

    
}
