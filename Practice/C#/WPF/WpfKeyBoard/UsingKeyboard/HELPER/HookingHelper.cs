using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Windows;

namespace UsingKeyboard
{
    /// <summary>
    /// 후킹 헬퍼
    /// </summary>
    public class HookingHelper
    {
        //////////////////////////////////////////////////////////////////////////////////////////////////// Delegate
        ////////////////////////////////////////////////////////////////////////////////////////// Public

        #region 키 클릭시 핸들러 - KeyClickHandler(keyCode)

        /// <summary>
        /// 키 클릭시 핸들러
        /// </summary>
        /// <param name="keyCode">키 코드</param>
        public delegate void KeyClickHandler(uint keyCode);

        #endregion
        #region 마우스 클릭시 핸들러 - MouseClickHandler(point, message)

        /// <summary>
        /// 마우스 클릭시 핸들러
        /// </summary>
        /// <param name="point">포인트</param>
        /// <param name="message">메시지</param>
        public delegate void MouseClickHandler(POINT point, MouseMessage message);

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Event
        ////////////////////////////////////////////////////////////////////////////////////////// Public

        #region 키 클릭시 이벤트 - KeyClick

        /// <summary>
        /// 키 클릭시 이벤트
        /// </summary>
        public static event KeyClickHandler KeyClick;

        #endregion
        #region 마우스 클릭시 이벤트 - MouseClick

        /// <summary>
        /// 마우스 클릭시 이벤트
        /// </summary>
        public static event MouseClickHandler MouseClick;

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Field
        ////////////////////////////////////////////////////////////////////////////////////////// Static
        //////////////////////////////////////////////////////////////////////////////// Private

        #region Field

        /// <summary>
        /// 핸들
        /// </summary>
        private static IntPtr _handle = IntPtr.Zero;

        /// <summary>
        /// 모듈 핸들
        /// </summary>
        private static IntPtr _moduleHandle = IntPtr.Zero;

        /// <summary>
        /// 키보드 후킹 핸들
        /// </summary>
        private static IntPtr _keyboardHookHandle = IntPtr.Zero;

        /// <summary>
        /// 마우스 후킹 핸들
        /// </summary>
        private static IntPtr _mouseHookHandle = IntPtr.Zero;

        /// <summary>
        /// 키보드 프로시저
        /// </summary>
        private static WIN32Helper.HookProc _keyboardProc = new WIN32Helper.HookProc(KeyboardProc);

        /// <summary>
        /// 마우스 프로시저
        /// </summary>
        private static WIN32Helper.HookProc _mouseProc = new WIN32Helper.HookProc(MouseProc);

        /// <summary>
        /// 마우스 후킹 구조체
        /// </summary>
        private static MOUSEHOOKSTRUCT _mouseHookStructure;

        /// <summary>
        /// 이전 윈도우 핸들
        /// </summary>
        private static IntPtr _previousWindowHandle = IntPtr.Zero;

        /// <summary>
        /// 이전 포커스 핸들
        /// </summary>
        private static IntPtr _previusFocusHandle = IntPtr.Zero;

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Property
        ////////////////////////////////////////////////////////////////////////////////////////// Static
        //////////////////////////////////////////////////////////////////////////////// Public

        #region 실행 여부 - IsRun

        /// <summary>
        /// 실행 여부
        /// </summary>
        public static bool IsRun { get; private set; }

        #endregion
        #region 전역 사용 여부 - UseGlobal

        /// <summary>
        /// 전역 사용 여부
        /// </summary>
        public static bool UseGlobal { get; set; }

        #endregion
        #region 후킹 영역 - HookArea

        /// <summary>
        /// 후킹 영역
        /// </summary>
        public static Rect HookArea { get; set; }

        #endregion
        #region 후킹 엘리먼트 - HookElement

        /// <summary>
        /// 후킹 엘리먼트
        /// </summary>
        public static UIElement HookElement { get; set; }

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Method
        ////////////////////////////////////////////////////////////////////////////////////////// Static
        //////////////////////////////////////////////////////////////////////////////// Public

        #region 시작하기 - Start()

        /// <summary>
        /// 시작하기
        /// </summary>
        public static void Start()
        {
            if(!IsRun)
            {
                uint threadID = WIN32Helper.GetCurrentThreadId();

                using(Process process = Process.GetCurrentProcess())
                {
                    using(ProcessModule processModule = process.MainModule)
                    {
                        _handle = process.MainWindowHandle;

                        _moduleHandle = WIN32Helper.GetModuleHandle(processModule.ModuleName);

                        _keyboardHookHandle = WIN32Helper.SetWindowsHookEx
                        (
                            (int)HookType.WH_KEYBOARD_LL,
                            _keyboardProc,
                            _moduleHandle,
                            0
                        );

                        _mouseHookHandle = WIN32Helper.SetWindowsHookEx
                        (
                            (int)HookType.WH_MOUSE_LL,
                            _mouseProc,
                            _moduleHandle,
                            0
                        );

                        IsRun = true;
                    }
                }
            }
        }

        #endregion
        #region 중단하기 - Stop()

        /// <summary>
        /// 중단하기
        /// </summary>
        public static void Stop()
        {
            if(IsRun)
            {
                WIN32Helper.UnhookWindowsHookEx(_keyboardHookHandle);
                WIN32Helper.UnhookWindowsHookEx(_mouseHookHandle   );

                IsRun = false;
            }
        }

        #endregion

        //////////////////////////////////////////////////////////////////////////////// Private

        #region 후킹 영역 여부 구하기 - IsHookingArea()

        /// <summary>
        /// 후킹 영역 여부 구하기
        /// </summary>
        /// <returns>후킹 영역 여부</returns>
        private static bool IsHookingArea()
        {
            if(HookElement != null && !HookArea.IsEmpty)
            {
                Point point = HookElement.PointFromScreen
                (
                    new Point
                    (
                        _mouseHookStructure.Location.X,
                        _mouseHookStructure.Location.Y)
                );

                bool contains = HookArea.Contains(point);

                return contains;
            }

            return true;
        }

        #endregion

        #region 키보드 프로시저 처리하기 - KeyboardProc(code, wordParameter, longParameter)

        /// <summary>
        /// 키보드 프로시저 처리하기
        /// </summary>
        /// <param name="code">코드</param>
        /// <param name="wordParameter">WORD 매개 변수</param>
        /// <param name="longParameter">LONG 매개 변수</param>
        /// <returns>처리 결과</returns>
        private static IntPtr KeyboardProc(int code, IntPtr wordParameter, IntPtr longParameter)
        {
            if(code == WIN32Helper.HC_ACTION)
            {
                uint wordParameterValue = (uint)wordParameter;
                long longParamererValue = (long)longParameter;

                if(wordParameterValue == 256)
                {
                    KEYBOARDHOOKSTRUCT keyboardHookStructure = (KEYBOARDHOOKSTRUCT)Marshal.PtrToStructure
                    (
                        longParameter,
                        typeof(KEYBOARDHOOKSTRUCT)
                    );

                    KeyClick?.Invoke(keyboardHookStructure.VirtualKeyCode);
                }

                if((wordParameterValue == 229 && longParamererValue == -2147483647) || (wordParameterValue == 229 && longParamererValue == -2147483648))
                {
                    if(IsHookingArea())
                    {
                        return (IntPtr)1;
                    }
                }
            }

            return WIN32Helper.CallNextHookEx(_keyboardHookHandle, code, wordParameter, longParameter);
        }

        #endregion
        #region 마우스 프로시저 처리하기 - MouseProc(code, wordParameter, longParameter)

        /// <summary>
        /// 마우스 프로시저 처리하기
        /// </summary>
        /// <param name="code">코드</param>
        /// <param name="wordParameter">WORD 매개 변수</param>
        /// <param name="longParameter">LONG 매개 변수</param>
        /// <returns>처리 결과</returns>
        private static IntPtr MouseProc(int code, IntPtr wordParameter, IntPtr longParameter)
        {
            if(code >= 0)
            {
                _mouseHookStructure = (MOUSEHOOKSTRUCT)Marshal.PtrToStructure
                (
                    longParameter,
                    typeof(MOUSEHOOKSTRUCT)
                );

                MouseMessage mouseMessage = (MouseMessage)wordParameter;

                if(UseGlobal)
                {
                    if(mouseMessage == MouseMessage.WM_LBUTTONDOWN || mouseMessage == MouseMessage.WM_LBUTTONUP)
                    {
                        MouseClick?.Invoke(_mouseHookStructure.Location, mouseMessage);

                        if(mouseMessage == MouseMessage.WM_LBUTTONDOWN && IsHookingArea())
                        {
                            return (IntPtr)1;
                        }
                    }
                }
            }

            return WIN32Helper.CallNextHookEx(_mouseHookHandle, code, wordParameter, longParameter);
        }

        #endregion
    }
}