 using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using WindowsInput.Native;

namespace UsingKeyboard
{
    /// <summary>
    /// 키 버튼
    /// </summary>
    public class KeyButton : Button
    {
        //////////////////////////////////////////////////////////////////////////////////////////////////// Dependency Property
        ////////////////////////////////////////////////////////////////////////////////////////// Static
        //////////////////////////////////////////////////////////////////////////////// Public

        #region 키 코드 속성 - KeyCodeProperty

        /// <summary>
        /// 키 코드 속성
        /// </summary>
        public static readonly DependencyProperty KeyCodeProperty = DependencyProperty.Register
        (
            "KeyCode",
            typeof(VirtualKeyCode),
            typeof(KeyButton)
        );

        #endregion
        #region PRESS 여부 속성 - IsPressedProperty

        /// <summary>
        /// PRESS 여부 속성
        /// </summary>
        public static readonly new DependencyProperty IsPressedProperty = DependencyProperty.Register
        (
            "IsPressed",
            typeof(bool),
            typeof(KeyButton)
        );

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Field
        ////////////////////////////////////////////////////////////////////////////////////////// Static
        //////////////////////////////////////////////////////////////////////////////// Private

        #region Field

        /// <summary>
        /// 키 데이터 딕셔너리
        /// </summary>
        private static Dictionary<VirtualKeyCode, KeyData> _keyDataDictionary;

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Property
        ////////////////////////////////////////////////////////////////////////////////////////// Public

        #region PRESS 여부 - IsPressed

        /// <summary>
        /// PRESS 여부
        /// </summary>
        public new bool IsPressed
        {
            get
            {
                return (bool)GetValue(IsPressedProperty);
            }
            set
            {
                SetValue(IsPressedProperty, value);
            }
        }

        #endregion
        #region 키 코드 - KeyCode

        /// <summary>
        /// 키 코드
        /// </summary>
        public VirtualKeyCode KeyCode
        {
            get
            {
                return (VirtualKeyCode)GetValue(KeyCodeProperty);
            }
            set
            {
                SetValue(KeyCodeProperty, value);
            }
        }

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Constructor
        ////////////////////////////////////////////////////////////////////////////////////////// Static

        #region 생성자 - KeyButton()

        /// <summary>
        /// 생성자
        /// </summary>
        static KeyButton()
        {
            SetKeyDataDictionary();
        }

        #endregion

        ////////////////////////////////////////////////////////////////////////////////////////// Instance
        //////////////////////////////////////////////////////////////////////////////// Public

        #region 생성자 - KeyButton()

        /// <summary>
        /// 생성자
        /// </summary>
        public KeyButton()
        {
            Focusable = false;
            IsTabStop = false;
            ClickMode = ClickMode.Press;
        }

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Method
        ////////////////////////////////////////////////////////////////////////////////////////// Static
        //////////////////////////////////////////////////////////////////////////////// Private

        #region 키 데이터 딕셔너리 설정하기 - SetKeyDataDictionary()

        /// <summary>
        /// 키 데이터 딕셔너리 설정하기
        /// </summary>
        private static void SetKeyDataDictionary()
        {
            _keyDataDictionary = new Dictionary<VirtualKeyCode, KeyData>();

            _keyDataDictionary.Add(VirtualKeyCode.VK_1, new KeyData { DefaultKey = "1", ShiftKey = "!" });
            _keyDataDictionary.Add(VirtualKeyCode.VK_2, new KeyData { DefaultKey = "2", ShiftKey = "@" });
            _keyDataDictionary.Add(VirtualKeyCode.VK_3, new KeyData { DefaultKey = "3", ShiftKey = "#" });
            _keyDataDictionary.Add(VirtualKeyCode.VK_4, new KeyData { DefaultKey = "4", ShiftKey = "$" });
            _keyDataDictionary.Add(VirtualKeyCode.VK_5, new KeyData { DefaultKey = "5", ShiftKey = "%" });
            _keyDataDictionary.Add(VirtualKeyCode.VK_6, new KeyData { DefaultKey = "6", ShiftKey = "^" });
            _keyDataDictionary.Add(VirtualKeyCode.VK_7, new KeyData { DefaultKey = "7", ShiftKey = "&" });
            _keyDataDictionary.Add(VirtualKeyCode.VK_8, new KeyData { DefaultKey = "8", ShiftKey = "*" });
            _keyDataDictionary.Add(VirtualKeyCode.VK_9, new KeyData { DefaultKey = "9", ShiftKey = "(" });
            _keyDataDictionary.Add(VirtualKeyCode.VK_0, new KeyData { DefaultKey = "0", ShiftKey = ")" });

            _keyDataDictionary.Add(VirtualKeyCode.VK_A, new KeyData { DefaultKey = "a", HangulKey = "ㅁ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_B, new KeyData { DefaultKey = "b", HangulKey = "ㅠ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_C, new KeyData { DefaultKey = "c", HangulKey = "ㅊ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_D, new KeyData { DefaultKey = "d", HangulKey = "ㅇ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_E, new KeyData { DefaultKey = "e", HangulKey = "ㄷ", HangulShiftKey = "ㄸ" });
            _keyDataDictionary.Add(VirtualKeyCode.VK_F, new KeyData { DefaultKey = "f", HangulKey = "ㄹ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_G, new KeyData { DefaultKey = "g", HangulKey = "ㅎ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_H, new KeyData { DefaultKey = "h", HangulKey = "ㅗ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_I, new KeyData { DefaultKey = "i", HangulKey = "ㅑ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_J, new KeyData { DefaultKey = "j", HangulKey = "ㅓ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_K, new KeyData { DefaultKey = "k", HangulKey = "ㅏ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_L, new KeyData { DefaultKey = "l", HangulKey = "ㅣ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_M, new KeyData { DefaultKey = "m", HangulKey = "ㅡ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_N, new KeyData { DefaultKey = "n", HangulKey = "ㅜ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_O, new KeyData { DefaultKey = "o", HangulKey = "ㅐ", HangulShiftKey = "ㅒ" });
            _keyDataDictionary.Add(VirtualKeyCode.VK_P, new KeyData { DefaultKey = "p", HangulKey = "ㅔ", HangulShiftKey = "ㅖ" });
            _keyDataDictionary.Add(VirtualKeyCode.VK_Q, new KeyData { DefaultKey = "q", HangulKey = "ㅂ", HangulShiftKey = "ㅃ" });
            _keyDataDictionary.Add(VirtualKeyCode.VK_R, new KeyData { DefaultKey = "r", HangulKey = "ㄱ", HangulShiftKey = "ㄲ" });
            _keyDataDictionary.Add(VirtualKeyCode.VK_S, new KeyData { DefaultKey = "s", HangulKey = "ㄴ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_T, new KeyData { DefaultKey = "t", HangulKey = "ㅅ", HangulShiftKey = "ㅆ" });
            _keyDataDictionary.Add(VirtualKeyCode.VK_U, new KeyData { DefaultKey = "u", HangulKey = "ㅕ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_V, new KeyData { DefaultKey = "v", HangulKey = "ㅍ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_W, new KeyData { DefaultKey = "w", HangulKey = "ㅈ", HangulShiftKey = "ㅉ" });
            _keyDataDictionary.Add(VirtualKeyCode.VK_X, new KeyData { DefaultKey = "x", HangulKey = "ㅌ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_Y, new KeyData { DefaultKey = "y", HangulKey = "ㅛ"                     });
            _keyDataDictionary.Add(VirtualKeyCode.VK_Z, new KeyData { DefaultKey = "z", HangulKey = "ㅋ"                     });

            _keyDataDictionary.Add(VirtualKeyCode.OEM_3     , new KeyData { DefaultKey = "`"        , ShiftKey = "~"  });
            _keyDataDictionary.Add(VirtualKeyCode.OEM_MINUS , new KeyData { DefaultKey = "-"        , ShiftKey = "_"  });
            _keyDataDictionary.Add(VirtualKeyCode.OEM_PLUS  , new KeyData { DefaultKey = "="        , ShiftKey = "+"  });
            _keyDataDictionary.Add(VirtualKeyCode.BACK      , new KeyData { DefaultKey = "←"                         });
            _keyDataDictionary.Add(VirtualKeyCode.TAB       , new KeyData { DefaultKey = "Tab"                        });
            _keyDataDictionary.Add(VirtualKeyCode.OEM_4     , new KeyData { DefaultKey = "["        , ShiftKey = "{"  });
            _keyDataDictionary.Add(VirtualKeyCode.OEM_6     , new KeyData { DefaultKey = "]"        , ShiftKey = "}"  });
            _keyDataDictionary.Add(VirtualKeyCode.OEM_5     , new KeyData { DefaultKey = "￦"       , ShiftKey = "|"  });
            _keyDataDictionary.Add(VirtualKeyCode.CAPITAL   , new KeyData { DefaultKey = "Caps Lock"                  });
            _keyDataDictionary.Add(VirtualKeyCode.OEM_1     , new KeyData { DefaultKey = ";"        , ShiftKey = ":"  });
            _keyDataDictionary.Add(VirtualKeyCode.OEM_7     , new KeyData { DefaultKey = "'"        , ShiftKey = "″" });
            _keyDataDictionary.Add(VirtualKeyCode.RETURN    , new KeyData { DefaultKey = "Enter"                      });
            _keyDataDictionary.Add(VirtualKeyCode.SHIFT     , new KeyData { DefaultKey = "Shift"                      });
            _keyDataDictionary.Add(VirtualKeyCode.OEM_COMMA , new KeyData { DefaultKey = ","        , ShiftKey = "<"  });
            _keyDataDictionary.Add(VirtualKeyCode.OEM_PERIOD, new KeyData { DefaultKey = "."        , ShiftKey = ">"  });
            _keyDataDictionary.Add(VirtualKeyCode.OEM_2     , new KeyData { DefaultKey = "/"        , ShiftKey = "?"  });
            _keyDataDictionary.Add(VirtualKeyCode.HANGUL    , new KeyData { DefaultKey = "한/영"                      });
            _keyDataDictionary.Add(VirtualKeyCode.SPACE     , new KeyData { DefaultKey = ""                           });
            _keyDataDictionary.Add(VirtualKeyCode.CLEAR     , new KeyData { DefaultKey = "Clear"                      });

            _keyDataDictionary.Add(VirtualKeyCode.NUMPAD0, new KeyData { DefaultKey = "0" });
            _keyDataDictionary.Add(VirtualKeyCode.NUMPAD1, new KeyData { DefaultKey = "1" });
            _keyDataDictionary.Add(VirtualKeyCode.NUMPAD2, new KeyData { DefaultKey = "2" });
            _keyDataDictionary.Add(VirtualKeyCode.NUMPAD3, new KeyData { DefaultKey = "3" });
            _keyDataDictionary.Add(VirtualKeyCode.NUMPAD4, new KeyData { DefaultKey = "4" });
            _keyDataDictionary.Add(VirtualKeyCode.NUMPAD5, new KeyData { DefaultKey = "5" });
            _keyDataDictionary.Add(VirtualKeyCode.NUMPAD6, new KeyData { DefaultKey = "6" });
            _keyDataDictionary.Add(VirtualKeyCode.NUMPAD7, new KeyData { DefaultKey = "7" });
            _keyDataDictionary.Add(VirtualKeyCode.NUMPAD8, new KeyData { DefaultKey = "8" });
            _keyDataDictionary.Add(VirtualKeyCode.NUMPAD9, new KeyData { DefaultKey = "9" });

        }

        #endregion

        ////////////////////////////////////////////////////////////////////////////////////////// Instance
        //////////////////////////////////////////////////////////////////////////////// Public

        #region 키 업데이트하기 - UpdateKey(shift, capsLock, hangul)

        /// <summary>
        /// 키 업데이트하기
        /// </summary>
        /// <param name="shift">SHIFT 키 눌림 여부</param>
        /// <param name="capsLock">CAPS LOCK 키 눌림 여부</param>
        /// <param name="hangul">한글 키 눌림 여부</param>
        public void UpdateKey(bool shift, bool capsLock, bool hangul)
        {
            if(!_keyDataDictionary.ContainsKey(KeyCode))
            {
                return;
            }

            KeyData keyData = _keyDataDictionary[KeyCode];

            string key = keyData.DefaultKey;

            if(KeyCode >= VirtualKeyCode.VK_A && KeyCode <= VirtualKeyCode.VK_Z)
            {
                if(hangul)
                {
                    key = keyData.HangulKey;

                    if
                    (
                        shift &&
                        (
                            KeyCode == VirtualKeyCode.VK_Q ||
                            KeyCode == VirtualKeyCode.VK_W ||
                            KeyCode == VirtualKeyCode.VK_E ||
                            KeyCode == VirtualKeyCode.VK_R ||
                            KeyCode == VirtualKeyCode.VK_T ||
                            KeyCode == VirtualKeyCode.VK_O ||
                            KeyCode == VirtualKeyCode.VK_P
                        )
                    )
                    {
                        key = keyData.HangulShiftKey;
                    }
                }
                else if(shift && !capsLock)
                {
                    key = key.ToUpper();
                }
                else if(capsLock && (KeyCode >= VirtualKeyCode.VK_A && KeyCode <= VirtualKeyCode.VK_Z))
                {
                    key = key.ToUpper();

                    if(shift && capsLock)
                    {
                        key = key.ToLower();
                    }
                }
            }
            else
            {
                if(!hangul)  
                {
                    key = keyData.DefaultKey;

                    if(shift && !capsLock)
                    {
                        key = string.IsNullOrWhiteSpace(keyData.ShiftKey) ? key : keyData.ShiftKey;
                    }
                    else if(shift && capsLock)
                    {
                        key = string.IsNullOrWhiteSpace(keyData.ShiftKey) ? key : keyData.ShiftKey;
                    }
                }
                else if(hangul)
                {
                    if(shift && !capsLock)
                    {
                        key = string.IsNullOrWhiteSpace(keyData.ShiftKey) ? key : keyData.ShiftKey;
                    }
                    else if(shift && capsLock)
                    {
                        key = string.IsNullOrWhiteSpace(keyData.ShiftKey) ? key : keyData.ShiftKey;
                    }
                }

            }

            Content = key;
        }

        #endregion
    }
}