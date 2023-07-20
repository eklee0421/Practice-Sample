using System;
using System.Collections.Generic;
using System.Text;
using wpfProductApp.ViewModel.ViewModels;
using System.Windows.Input;
using System.Collections.ObjectModel;
using wpfProductApp.Model;
using System.Linq;
using System.Windows;

namespace wpfProductApp.ViewModel
{
    internal class ProductListViewModel:ViewModelBase
    {
        private ObservableCollection<Product> products = new ObservableCollection<Product>();
        public ObservableCollection<Product> Products
        {
            get
            {
                return products;
            }
        }

        private Product newProduct;
        public Product NewProduct
        {
            get
            {
                return products.LastOrDefault();
            }
            set
            {
                newProduct = value;
                products.Add(value);
                
                OnPropertyChanged("ProductAdded");
            }
        }

        private Total newTotal;
        public Total NewTotal
        {
            get
            {
                if (newTotal == null)
                {
                    return newTotal ?? (this.newTotal = new Total());
                }
                else
                {
                    return newTotal;
                }
                
            }
            set
            {
                newTotal = value;
                this.OnPropertyChanged("SettingTotal");
            }
        }

        //private ICommand loadDataCommand;
        //public ICommand LoadDataCommand
        //{
        //    get
        //    {
        //        return loadDataCommand ?? (this.loadDataCommand = new DelegateCommand(LoadData));
        //    }
        //}

        //private void LoadData()
        //{
        //    this.OnPropertyChanged("LoadData");
        //}


    }
}
