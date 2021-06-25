using System.Runtime.InteropServices;

namespace UsingKeyboard
{
    /// <summary>
    /// 포인트
    /// </summary>
    [StructLayout(LayoutKind.Sequential)]
    public struct POINT
    {
        //////////////////////////////////////////////////////////////////////////////////////////////////// Field
        ////////////////////////////////////////////////////////////////////////////////////////// Public

        #region Field

        /// <summary>
        /// X
        /// </summary>
        public int X;

        /// <summary>
        /// Y
        /// </summary>
        public int Y;

        #endregion
    }
}