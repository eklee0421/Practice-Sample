using System;
using System.Collections.Generic;
using System.Text;
using wpfProductApp.Model;

namespace wpfProductApp.Interface
{
    public interface IProductList
    {
        //List<Product> GetProducts();

        void ResultChange(Total total);
    }
}
