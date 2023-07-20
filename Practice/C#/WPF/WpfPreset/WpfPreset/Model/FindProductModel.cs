using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using WpfPreset.Data;

namespace WpfPreset.Model
{
    public class FindProductModel
    {

        private ProductPreset productPreset = new ProductPreset();
        private Product product = new Product();
        public FindProductModel(string Inputstring)
        {
            product = productPreset.GetProduct(Inputstring);
            
        }

        public Product GetProduct()
        {
            return product;
        }
    }
}
