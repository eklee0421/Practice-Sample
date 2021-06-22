using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using WpfPreset.Model;

namespace WpfPreset.ViewModel
{
    internal class ProductListViewModel : ViewModelBase
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

        private RelayCommand checkAllCommand;
        public ICommand CheckAllCommand
        {
            get
            {
                return checkAllCommand ??
                    (checkAllCommand = new RelayCommand(param => this.SelectUnselectAll(Convert.ToBoolean(param.ToString()))));
            }
        }

        private void SelectUnselectAll(bool isSelected)
        {
            for (int i = 0; i < products.Count; i++)
            {
                products[i].IsSelected = isSelected;
            }
        }

        public void deleteList(ObservableCollection<Product> collection, Product p)
        {
            if (collection.Contains(p))
            {
                collection.Remove(p);
            }
            
        }
    }
}
