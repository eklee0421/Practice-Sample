using System;
using System.Runtime.InteropServices;

namespace UsingKeyboard
{
    /// <summary>
    /// WIN32 헬퍼
    /// </summary>
    public class WIN32Helper
    {
        //////////////////////////////////////////////////////////////////////////////////////////////////// Import
        ////////////////////////////////////////////////////////////////////////////////////////// Static
        //////////////////////////////////////////////////////////////////////////////// Public

        #region 윈도우 후킹 설정하기 (확장) - SetWindowsHookEx(hookID, hookProc, moduleHandle, threadID)

        /// <summary>
        /// 윈도우 후킹 설정하기 (확장)
        /// </summary>
        /// <param name="hookID">후킹 ID</param>
        /// <param name="hookProc">후킹 프로시저</param>
        /// <param name="moduleHandle">모듈 핸들</param>
        /// <param name="threadID">스레드 ID</param>
        /// <returns>후킹 핸들</returns>
        [DllImport("user32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        public static extern IntPtr SetWindowsHookEx(int hookID, HookProc hookProc, IntPtr moduleHandle, uint threadID);

        #endregion
        #region 윈도우 후킹 해제하기 (확장) - UnhookWindowsHookEx(hookHandle)

        /// <summary>
        /// 윈도우 후킹 해제하기 (확장)
        /// </summary>
        /// <param name="hookHandle">후킹 핸들</param>
        /// <returns>처리 결과</returns>
        [DllImport("user32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        [return: MarshalAs(UnmanagedType.Bool)]
        public static extern bool UnhookWindowsHookEx(IntPtr hookHandle);

        #endregion
        #region 다음 후킹 호출하기 (확장) - CallNextHookEx(hookHandle, code, wordParameter, longParameter)

        /// <summary>
        /// 다음 후킹 호출하기 (확장)
        /// </summary>
        /// <param name="hookHandle">후킹 핸들</param>
        /// <param name="code">코드</param>
        /// <param name="wordParameter">WORD 매개 변수</param>
        /// <param name="longParameter">LONG 매개 변수</param>
        /// <returns>처리 결과</returns>
        [DllImport("user32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        public static extern IntPtr CallNextHookEx(IntPtr hookHandle, int code, IntPtr wordParameter, IntPtr longParameter);

        #endregion
        #region 모듈 핸들 구하기 - GetModuleHandle(moduleName)

        /// <summary>
        /// 모듈 핸들 구하기
        /// </summary>
        /// <param name="moduleName">모듈명</param>
        /// <returns>모듈 핸들</returns>
        [DllImport("kernel32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        public static extern IntPtr GetModuleHandle(string moduleName);

        #endregion
        #region 현재 스레드 ID 구하기 - GetCurrentThreadId()

        /// <summary>
        /// 현재 스레드 ID 구하기
        /// </summary>
        /// <returns>현재 스레드 ID</returns>
        [DllImport("kernel32.dll")]
        public static extern uint GetCurrentThreadId();

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Delegate
        ////////////////////////////////////////////////////////////////////////////////////////// Public

        #region 후킹 프로시저 대리자 - HookProc(code, wordParameter, longParameter)

        /// <summary>
        /// 후킹 프로시저 대리자
        /// </summary>
        /// <param name="code">코드</param>
        /// <param name="wordParameter">WORD 매개 변수</param>
        /// <param name="longParameter">LONG 매개 변수</param>
        /// <returns>처리 결과</returns>
        public delegate IntPtr HookProc(int code, IntPtr wordParameter, IntPtr longParameter);

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Field
        ////////////////////////////////////////////////////////////////////////////////////////// Public

        #region Field

        /// <summary>
        /// HC_ACTION
        /// </summary>
        public const int HC_ACTION = 0;

        #endregion
    }
}