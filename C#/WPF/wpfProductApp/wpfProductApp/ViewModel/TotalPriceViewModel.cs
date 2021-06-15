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

        public TotalPriceViewModel()
        {

        }

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
                MessageBox.Show(NewTotal.SumPrice.ToString());
                this.OnPropertyChanged("SettingTotal");
            }
        }

        
    }

    
}
