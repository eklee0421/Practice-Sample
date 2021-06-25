namespace UsingKeyboard
{
    /// <summary>
    /// 키보드 후킹 구조체 플래그
    /// </summary>
    public enum KeyboardHookStructureFlag
    {
        /// <summary>
        /// LLKHF_EXTENDED
        /// </summary>
        LLKHF_EXTENDED = 0x01,

        /// <summary>
        /// LLKHF_INJECTED
        /// </summary>
        LLKHF_INJECTED = 0x10,

        /// <summary>
        /// LLKHF_ALTDOWN
        /// </summary>
        LLKHF_ALTDOWN = 0x20,

        /// <summary>
        /// LLKHF_UP
        /// </summary>
        LLKHF_UP = 0x80
    }
}