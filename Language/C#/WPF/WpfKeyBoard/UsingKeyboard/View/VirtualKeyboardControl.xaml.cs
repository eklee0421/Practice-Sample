using System.Windows;
using System.Windows.Input;

namespace UsingKeyboard
{
    /// <summary>
    /// 가상 키보드 컨트롤
    /// </summary>
    public partial class VirtualKeyboardControl : VirtualKeyboard
    {
        //////////////////////////////////////////////////////////////////////////////////////////////////// Constructor
        ////////////////////////////////////////////////////////////////////////////////////////// Public

        #region 생성자 - VirtualKeyboardControl()

        /// <summary>
        /// 생성자
        /// </summary>
        public VirtualKeyboardControl()
        {
            InitializeComponent();

            IsEnableHook = false;
        }

        #endregion
    }
}