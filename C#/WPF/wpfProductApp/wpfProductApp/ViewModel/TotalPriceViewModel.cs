using System;
using System.Collections.Generic;
using System.Text;
using wpfProductApp.Model;
using wpfProductApp.ViewModel.ViewModels;

namespace wpfProductApp.ViewModel
{
    class TotalPriceViewModel:ViewModelBase
    {

        public TotalPriceViewModel()
        {

        }
        public Total total
        {
            get
            {
                return total;
            }
            set
            {
                this.total = value;
                OnPropertyChanged("SetTotal");
            }
        }
    }

    
}
