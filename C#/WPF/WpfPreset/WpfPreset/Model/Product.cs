using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WpfPreset.Model
{
    public class Product
    {
        public Product()
        {

        }

        public Product(string NumCode, string Name, int Price)
        {
            this.NumCode = NumCode;
            this.Name = Name;
            this.Price = Price;
        }

        public string NumCode { get; set; }

        public string Name { get; set; }

        public int Price { get; set; }

    }

    
}
