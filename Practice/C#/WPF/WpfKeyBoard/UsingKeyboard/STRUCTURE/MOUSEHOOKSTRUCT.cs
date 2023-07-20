using System;
using System.Runtime.InteropServices;

namespace UsingKeyboard
{
    [StructLayout(LayoutKind.Sequential)]
    public struct MOUSEHOOKSTRUCT
    {
        //////////////////////////////////////////////////////////////////////////////////////////////////// Field
        ////////////////////////////////////////////////////////////////////////////////////////// Public

        #region Field

        /// <summary>
        /// 위치
        /// </summary>
        public POINT Location;

        /// <summary>
        /// 윈도우 핸들
        /// </summary>
        public IntPtr WindowHandle;

        /// <summary>
        /// 히트 테스트 코드
        /// </summary>
        public uint HitTestCode;

        /// <summary>
        /// 부가 정보 핸들
        /// </summary>
        public IntPtr ExtraInformationHandle;

        #endregion
    }
}