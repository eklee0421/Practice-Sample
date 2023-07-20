using WindowsInput;

namespace UsingKeyboard
{
    /// <summary>
    /// 시뮬레이터
    /// </summary>
    internal class Simulator
    {
        //////////////////////////////////////////////////////////////////////////////////////////////////// Property
        ////////////////////////////////////////////////////////////////////////////////////////// Static
        //////////////////////////////////////////////////////////////////////////////// Internal

        #region 입력 시뮬레이터 - Input

        /// <summary>
        /// 입력 시뮬레이터
        /// </summary>
        internal static InputSimulator Input { get; private set; }

        #endregion
        #region 키보드 시뮬레이터 - Keyboard

        /// <summary>
        /// 키보드 시뮬레이터
        /// </summary>
        internal static KeyboardSimulator Keyboard { get; private set; }

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Constructor
        ////////////////////////////////////////////////////////////////////////////////////////// Static

        #region 생성자 - Simulator()

        /// <summary>
        /// 생성자
        /// </summary>
        static Simulator()
        {
            Input    = new InputSimulator();
            Keyboard = new KeyboardSimulator(Input);
        }

        #endregion
    }
}