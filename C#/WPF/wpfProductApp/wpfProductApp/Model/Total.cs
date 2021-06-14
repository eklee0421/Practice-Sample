﻿using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Input;
using wpfProductApp.ViewModel;
using wpfProductApp.ViewModel.ViewModels;

namespace wpfProductApp.Model
{
    public class Total : ViewModelBase
    {
        public int SumPrice { get; set; }

        public int SumDiscount { get; set; }
        
        public int TotalPrice { get; set; }
    }

    class ResultPrice
    {
        private ProductListViewModel productlistviewmodel;
        public ResultPrice(ProductListViewModel productviewmodel)
        {
            this.productlistviewmodel = productviewmodel;
            
        }
    }
}
