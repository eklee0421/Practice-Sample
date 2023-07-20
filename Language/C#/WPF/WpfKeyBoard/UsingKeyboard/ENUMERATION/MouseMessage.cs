namespace UsingKeyboard
{
    /// <summary>
    /// 마우스 메시지
    /// </summary>
    public enum MouseMessage
    {
        /// <summary>
        /// WM_LBUTTONDOWN
        /// </summary>
        WM_LBUTTONDOWN = 0x0201,

        /// <summary>
        /// WM_LBUTTONUP
        /// </summary>
        WM_LBUTTONUP = 0x0202,

        /// <summary>
        /// WM_MOUSEMOVE
        /// </summary>
        WM_MOUSEMOVE = 0x0200,

        /// <summary>
        /// WM_MOUSEWHEEL
        /// </summary>
        WM_MOUSEWHEEL = 0x020A,

        /// <summary>
        /// WM_RBUTTONDOWN
        /// </summary>
        WM_RBUTTONDOWN = 0x0204,

        /// <summary>
        /// WM_RBUTTONUP
        /// </summary>
        WM_RBUTTONUP = 0x0205,

        /// <summary>
        /// WM_NCLBUTTONDOWN
        /// </summary>
        WM_NCLBUTTONDOWN = 0x00A
    }
}