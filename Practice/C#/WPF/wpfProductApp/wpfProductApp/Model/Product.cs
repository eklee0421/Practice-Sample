using System;
using System.Collections.Generic;
using System.Text;
using wpfProductApp.ViewModel.ViewModels;

namespace wpfProductApp.Model
{
    public class Product : ViewModelBase
    {
        public string Name { get; set; }  

        public int Price { get; set; }

        public int Discount { get; set; }
    }
}
