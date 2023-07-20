using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using WpfPreset.Model;

namespace WpfPreset.Data
{
    public class ProductPreset
    {

        private Dictionary<string, Product> products = new Dictionary<string, Product>();

        public ProductPreset()
        {
            products["1"] = new Product("1", "토레타", 1800);
            products["2"] = new Product("2", "마우스", 23500);
            products["3"] = new Product("3", "키보드", 150000);
            products["4"] = new Product("4", "모니터", 100000);
            products["5"] = new Product("5", "수첩", 1020);
            products["6"] = new Product("6", "샐러드", 7000);
            products["7"] = new Product("7", "달력", 1550);
            products["8"] = new Product("8", "샤프", 3600);
            products["9"] = new Product("9", "볼펜", 1700);
            products["10"] = new Product("10", "핸드폰", 990000);
            products["11"] = new Product("11", "치약", 990);
            products["12"] = new Product("12", "칫솔", 980);
            products["13"] = new Product("13", "과자", 1010);
            products["14"] = new Product("14", "우산", 14300);
            products["15"] = new Product("15", "형광펜", 770);
            products["16"] = new Product("16", "가방", 36000);
            products["17"] = new Product("17", "신발", 88000);
            products["18"] = new Product("18", "이어폰", 3000);
            products["19"] = new Product("19", "지갑", 134870);
            products["20"] = new Product("20", "연필꽂이", 88000);
        }

        public Product GetProduct(string inputcode)
        {
            Product product = products[inputcode];
            return product;
        }
        
    }
}
