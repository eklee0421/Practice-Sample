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

        public Product NewProduct
        {
            get
            {
                return products.LastOrDefault();
            }
            set
            {
                products.Add(value);
                OnPropertyChanged("ProductAdded");
            }
        }

        public Total total
        {
            get
            {
                return total;
            }
            set
            {
                this.total.SumPrice += this.NewProduct.Price;
                string str = this.total.SumPrice.ToString();
                MessageBox.Show(str);
            }
        }

        private ICommand loadDataCommand;
        public ICommand LoadDataCommand
        {
            get
            {
                return loadDataCommand ?? (this.loadDataCommand = new DelegateCommand(LoadData));
            }
        }

        private void LoadData()
        {
            this.OnPropertyChanged("LoadData");
        }


    }
}
