using System.ComponentModel;
using System.Windows;
using System.Windows.Input;

namespace UsingKeyboard
{

    public delegate void DataGetEventHandlder(string item);

    /// <summary>
    /// 메인 윈도우
    /// </summary>
    public partial class MainWindow : Window
    {
        //////////////////////////////////////////////////////////////////////////////////////////////////// Constructor
        ////////////////////////////////////////////////////////////////////////////////////////// Public

        #region 생성자 - MainWindow()
        public DataGetEventHandlder DataSendEvent;
        /// <summary>
        /// 생성자
        /// </summary>
        public MainWindow()
        {
            InitializeComponent();

            this.inputTextBox.Focus();           
        }

        public void OnKeyDownHandler(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Return)
            { 
                Window.GetWindow(this).Close();
            }
        }

        private void Window_Closing(object sender, CancelEventArgs e)
        {
            VirtualKeyboard virtualKeyboard = new VirtualKeyboard();
            virtualKeyboard.ReturnString(); 
            DataSendEvent(virtualKeyboard.InputString);
        }

        #endregion
    }
}