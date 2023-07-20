using System;
using System.Collections.Generic;
using System.Text;
using wpfProductApp.Model;
using System.Windows.Input;
using wpfProductApp.ViewModel.ViewModels;
using System.Windows;

namespace wpfProductApp.ViewModel
{
    
    public class SetProductViewModel : ViewModelBase
    {
        List<Product> ProductLists = new List<Product>();

        private Product newproduct;
        public Product NewProduct
        {
            get
            {
                return newproduct ?? (this.newproduct = new Product());
            }
            set
            {
                newproduct = value;
                this.OnPropertyChanged("SettingProduct");
            }
        }

        private ICommand saveCommand;
        public ICommand SaveCommand
        {
            get
            {
                return saveCommand ?? (this.saveCommand = new DelegateCommand(SaveProduct));
            }
        }

        private void SaveProduct()
        {

            if (NewProduct.Name == null)
            {
                MessageBox.Show("상품명을 등록하세요");
            }
            else if(NewProduct.Price.ToString() == null)
            {
                MessageBox.Show("가격을 등록하세요");
            }
            else if (NewProduct.Discount.ToString() == null)
            {
                MessageBox.Show("할인 금액을 등록하세요");
            }
            else if (NewProduct.Discount > NewProduct.Price)
            {
                MessageBox.Show("할인 금액이 상품 가격보다 클 수 없습니다.");
            }
            else
            {
                Product product = new Product();
                product.Name = NewProduct.Name;
                product.Price = NewProduct.Price;
                product.Discount = NewProduct.Discount;

                ProductLists.Add(product);
                OnPropertyChanged("SaveProduct");
            }
        }
    }
}
