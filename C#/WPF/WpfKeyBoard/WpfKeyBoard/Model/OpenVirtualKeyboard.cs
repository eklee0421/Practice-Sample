using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using WpfKeyBoard.ViewModel;

namespace WpfKeyBoard.Model
{
    class OpenVirtualKeyboard
    {

        private string numstring = string.Empty;
        public OpenVirtualKeyboard(string nowString)
        {
            numstring = nowString;
            UsingKeyboard.MainWindow keyboardWindow = new UsingKeyboard.MainWindow();
            keyboardWindow.DataSendEvent += new UsingKeyboard.DataGetEventHandlder(this.DataGet);
            keyboardWindow.ShowDialog();
        }

        public string ReturnData()
        {
            return numstring;
        }

        private void DataGet(string inputstring)
        {
            if (!inputstring.Equals(string.Empty))
            {
                numstring = inputstring;
            }
        }
    }
}
