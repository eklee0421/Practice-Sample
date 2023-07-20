using System;
using System.Runtime.InteropServices;

namespace UsingKeyboard
{
    /// <summary>
    /// 키보드 후킹 구조체
    /// </summary>
    [StructLayout(LayoutKind.Sequential)]
    public class KEYBOARDHOOKSTRUCT
    {
        //////////////////////////////////////////////////////////////////////////////////////////////////// Field
        ////////////////////////////////////////////////////////////////////////////////////////// Public

        #region Field

        /// <summary>
        /// 가상 키 코드
        /// </summary>
        public uint VirtualKeyCode;

        /// <summary>
        /// 스캔 코드
        /// </summary>
        public uint ScanCode;

        /// <summary>
        /// 키보드 후킹 구조체 플래그
        /// </summary>
        public KeyboardHookStructureFlag Flag;

        /// <summary>
        /// 시간
        /// </summary>
        public uint Time;

        /// <summary>
        /// 부가 정보 핸들
        /// </summary>
        public UIntPtr ExtraInformationHandle;

        #endregion
    }
}