using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WpfPreset.ViewModel;

namespace WpfPreset.Model
{
    public class Product : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;
        public Product()
        {

        }

        public Product(string NumCode, string Name, int Price)
        {
            this.NumCode = NumCode;
            this.Name = Name;
            this.Price = Price;
            
        }

        private bool isSelected;
        public bool IsSelected
        {
            get { return isSelected; }
            set
            {
                isSelected = value;
                PropertyChanged?.Invoke(this,
                    new PropertyChangedEventArgs(nameof(IsSelected)));
            }
        }

        public string NumCode { get; set; }

        public string Name { get; set; }

        public int Price { get; set; }

    }

    
}
