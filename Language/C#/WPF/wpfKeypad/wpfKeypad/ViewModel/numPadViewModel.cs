using numPadClk;
using System.Windows;
using System.Windows.Input;
using wpfKeyPad.ViewModel;
using WpfKeypad.ViewModel.ViewModels;


namespace WpfKeypad.ViewModel
{
    public class numPadViewModel : ViewModelBase
    {
        public numPadViewModel()
        {
            //clk num
            this.Append = new Append(this);

            //clk backspace
            this.Back = new Back(this);

            //clk C
            this.Clear = new Clear(this);
        }

        public ICommand Append { protected set; get; }
        public ICommand Back { protected set; get; }
        public ICommand Clear { protected set; get; }


    }
}