using System;
using System.ComponentModel;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using WindowsInput.Native;

namespace UsingKeyboard
{
    /// <summary>
    /// 가상 키보드
    /// </summary>
    public class VirtualKeyboard : UserControl
    {
        //////////////////////////////////////////////////////////////////////////////////////////////////// ROUTED EVENT
        ////////////////////////////////////////////////////////////////////////////////////////// Static
        //////////////////////////////////////////////////////////////////////////////// Public

        #region 가상 키 DOWN 이벤트 - VirtualKeyDownEvent

        /// <summary>
        /// 가상 키 DOWN 이벤트
        /// </summary>
        public static readonly RoutedEvent VirtualKeyDownEvent = EventManager.RegisterRoutedEvent
        (
            "VirtualKeyDown",
            RoutingStrategy.Bubble,
            typeof(RoutedEventHandler),
            typeof(VirtualKeyboard)
        );

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Dependency Property
        ////////////////////////////////////////////////////////////////////////////////////////// Static
        //////////////////////////////////////////////////////////////////////////////// Public

        #region 표시 여부 속성 - IsShowProperty

        /// <summary>
        /// 표시 여부 속성
        /// </summary>
        public static readonly DependencyProperty IsShowProperty = DependencyProperty.Register
        (
            "IsShow",
            typeof(bool),
            typeof(VirtualKeyboard),
            new PropertyMetadata(true, IsShowPropertyChangedCallback)
        );

        #endregion
        #region 전역 사용 여부 속성 - UseGlobalProperty

        /// <summary>
        /// 전역 사용 여부 속성
        /// </summary>
        public static readonly DependencyProperty UseGlobalProperty = DependencyProperty.Register
        (
            "UseGlobal",
            typeof(bool),
            typeof(VirtualKeyboard),
            new PropertyMetadata(true, UseGlobalPropertyChangedCallback)
        );

        #endregion
        #region 후킹 이용 가능 여부 속성 - IsEnableHookProperty

        /// <summary>
        /// 후킹 이용 가능 여부 속성
        /// </summary>
        public static readonly DependencyProperty IsEnableHookProperty = DependencyProperty.Register
        (
            "IsEnableHook",
            typeof(bool),
            typeof(VirtualKeyboard),
            new PropertyMetadata(false, IsEnableHookPropertyChangedCallback)
        );

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Field
        ////////////////////////////////////////////////////////////////////////////////////////// Private

        #region Field

        /// <summary>
        /// 키 눌림 여부
        /// </summary>
        private bool keyPressed;

        /// <summary>
        /// 이전 키 버튼
        /// </summary>
        private KeyButton previusKeyButton;

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Event
        ////////////////////////////////////////////////////////////////////////////////////////// Public

        #region 가상 키 DOWN 이벤트 - VirtualKeyDown

        /// <summary>
        /// 가상 키 DOWN 이벤트
        /// </summary>
        public event RoutedEventHandler VirtualKeyDown
        {
            add
            {
                AddHandler(VirtualKeyDownEvent, value);
            }
            remove
            {
                RemoveHandler(VirtualKeyDownEvent, value);
            }
        }

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Property
        ////////////////////////////////////////////////////////////////////////////////////////// Public

        #region 표시 여부 - IsShow

        /// <summary>
        /// 표시 여부
        /// </summary>
        public bool IsShow
        {
            get
            {
                return (bool)GetValue(IsShowProperty);
            }
            set
            {
                SetValue(IsShowProperty, value);
            }
        }

        #endregion
        #region 전역 사용 여부 - UseGlobal

        /// <summary>
        /// 전역 사용 여부
        /// </summary>
        public bool UseGlobal
        {
            get
            {
                return (bool)GetValue(UseGlobalProperty);
            }
            set
            {
                SetValue(UseGlobalProperty, value);
            }
        }

        #endregion
        #region 후킹 이용 가능 여부 - IsEnableHook

        /// <summary>
        /// 후킹 이용 가능 여부
        /// </summary>
        public bool IsEnableHook
        {
            get
            {
                return (bool)GetValue(IsEnableHookProperty);
            }
            set
            {
                SetValue(IsEnableHookProperty, value);
            }
        }

        #endregion

        #region SHIFT 눌림 여부 - IsPressedShift

        /// <summary>
        /// SHIFT 눌림 여부
        /// </summary>
        public bool IsPressedShift { get; private set; }

        #endregion
        #region 한글 눌림 여부 - IsPressedHangul

        /// <summary>
        /// 한글 눌림 여부
        /// </summary>
        public bool IsPressedHangul { get; private set; }

        #endregion
        #region CAPS LOCK 눌림 여부 - IsPressedCapsLock

        /// <summary>
        /// CAPS LOCK 눌림 여부
        /// </summary>
        public bool IsPressedCapsLock { get; private set; }

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Method
        ////////////////////////////////////////////////////////////////////////////////////////// Static
        //////////////////////////////////////////////////////////////////////////////// Private

        #region 표시 여부 속성 변경시 콜백 처리하기 - IsShowPropertyChangedCallback(d, e)

        /// <summary>
        /// 표시 여부 속성 변경시 콜백 처리하기
        /// </summary>
        /// <param name="d">의존 객체</param>
        /// <param name="e">이벤트 인자</param>
        private static void IsShowPropertyChangedCallback(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            VirtualKeyboard keyboard = d as VirtualKeyboard;

            bool isShow = (bool)e.NewValue;

            keyboard.ChangeShow(isShow);
        }

        #endregion
        #region 전역 사용 여부 속성 변경시 콜백 처리하기 - UseGlobalPropertyChangedCallback(d, e)

        /// <summary>
        /// 전역 사용 여부 속성 변경시 콜백 처리하기
        /// </summary>
        /// <param name="d">의존 객체</param>
        /// <param name="e">이벤트 인자</param>
        private static void UseGlobalPropertyChangedCallback(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            HookingHelper.UseGlobal = (bool)e.NewValue;
        }

        #endregion
        #region 후킹 이용 가능 여부 속성 변경시 콜백 처리하기 - IsEnableHookPropertyChangedCallback(d, e)

        /// <summary>
        /// 후킹 이용 가능 여부 속성 변경시 콜백 처리하기
        /// </summary>
        /// <param name="d">의존 객체</param>
        /// <param name="e">이벤트 인자</param>
        private static void IsEnableHookPropertyChangedCallback(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            VirtualKeyboard virtualKeyboard = d as VirtualKeyboard;

            if((bool)e.NewValue)
            {
                virtualKeyboard.UpdateHookData();

                HookingHelper.UseGlobal = virtualKeyboard.UseGlobal;

                HookingHelper.MouseClick += virtualKeyboard.Hook_MouseClick;
                HookingHelper.KeyClick   += virtualKeyboard.Hook_KeyClick;

                HookingHelper.Start();
            }
            else
            {
                HookingHelper.MouseClick -= virtualKeyboard.Hook_MouseClick;
                HookingHelper.KeyClick   -= virtualKeyboard.Hook_KeyClick;

                HookingHelper.Stop();
            }
        }

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Constructor
        ////////////////////////////////////////////////////////////////////////////////////////// Public

        #region 생성자 - VirtualKeyboard()

        /// <summary>
        /// 생성자
        /// </summary>
        public VirtualKeyboard()
        {
            Loaded           += UserControl_Loaded;
            Unloaded         += UserControl_Unloaded;
            IsVisibleChanged += UserControl_IsVisibleChanged;
        }

        #endregion

        //////////////////////////////////////////////////////////////////////////////////////////////////// Method
        ////////////////////////////////////////////////////////////////////////////////////////// Protected

        #region 키 업데이트하기 - UpdateKeys(panel)

        /// <summary>
        /// 키 업데이트하기
        /// </summary>
        /// <param name="panel">패널</param>
        protected void UpdateKeys(Panel panel)
        {
            foreach(UIElement child in panel.Children)
            {
                if(child is Panel)
                {
                    Panel content = child as Panel;

                    UpdateKeys(content);
                }
                else if(child is KeyButton)
                {
                    KeyButton keyButton = child as KeyButton;

                    keyButton.UpdateKey(IsPressedShift, IsPressedCapsLock, IsPressedHangul);
                }
            }
        }

        #endregion
        #region 키 업데이트하기 - UpdateKeys()

        /// <summary>
        /// 키 업데이트하기
        /// </summary>
        protected void UpdateKeys()
        {
            Panel content = Content as Panel;

            UpdateKeys(content);
        }

        #endregion

        ////////////////////////////////////////////////////////////////////////////////////////// Private
        //////////////////////////////////////////////////////////////////////////////// Event

        #region 사용자 컨트롤 로드시 처리하기 - UserControl_Loaded(sender, e)

        /// <summary>
        /// 사용자 컨트롤 로드시 처리하기
        /// </summary>
        /// <param name="sender">이벤트 발생자</param>
        /// <param name="e">이벤트 인자</param>
        private void UserControl_Loaded(object sender, RoutedEventArgs e)
        {
            if(DesignerProperties.GetIsInDesignMode(this))
            {
                return;
            }

            RenderTransform = new TranslateTransform();

            AddHandler(KeyButton.ClickEvent, (RoutedEventHandler)KeyButton_Click);

            if(IsEnableHook)
            {
                UpdateHookData();

                HookingHelper.KeyClick += Hook_KeyClick;

                HookingHelper.UseGlobal = UseGlobal;

                HookingHelper.Start();
            }

            Application.Current.MainWindow.Closed += (sender2, e2) => HookingHelper.Stop();
        }

        #endregion
        #region 사용자 컨트롤 언로드시 처리하기 - UserControl_Unloaded(sender, e)

        /// <summary>
        /// 사용자 컨트롤 언로드시 처리하기
        /// </summary>
        /// <param name="sender">이벤트 발생자</param>
        /// <param name="e">이벤트 인자</param>
        private void UserControl_Unloaded(object sender, RoutedEventArgs e)
        {
            HookingHelper.MouseClick -= Hook_MouseClick;
            HookingHelper.KeyClick   -= Hook_KeyClick;
        }

        #endregion
        #region 사용자 컨트롤 표시 여부 변경시 처리하기 - UserControl_IsVisibleChanged(sender, e)

        /// <summary>
        /// 사용자 컨트롤 표시 여부 변경시 처리하기
        /// </summary>
        /// <param name="sender">이벤트 발생자</param>
        /// <param name="e">이벤트 인자</param>
        private void UserControl_IsVisibleChanged(object sender, DependencyPropertyChangedEventArgs e)
        {
            IsPressedHangul = true;

            if((bool)e.NewValue)
            {
                if(IsEnableHook)
                {
                    IsPressedHangul   = !Simulator.Input.InputDeviceState.IsTogglingKeyInEffect(VirtualKeyCode.HANGUL );
                    IsPressedCapsLock =  Simulator.Input.InputDeviceState.IsTogglingKeyInEffect(VirtualKeyCode.CAPITAL);

                    UpdateHookData();
                }

                UpdateKeys();
            }
        }

        #endregion

        #region 후킹 마우스 클릭시 처리하기 - Hook_MouseClick(point, message)

        /// <summary>
        /// 후킹 마우스 클릭시 처리하기
        /// </summary>
        /// <param name="point">포인트</param>
        /// <param name="message">메시지</param>
        private void Hook_MouseClick(POINT point, MouseMessage message)
        {
            Point screenPoint = PointFromScreen(new Point(point.X, point.Y));

            KeyButton keyButton = VisualElementHelper.TryFindFromPoint<KeyButton>(this, screenPoint);

            if(keyButton == null)
            {
                return;
            }

            VirtualKeyCode keyCode = keyButton.KeyCode;

            if(message == MouseMessage.WM_LBUTTONDOWN)
            {
                this.previusKeyButton = keyButton;

                keyButton.IsPressed = true;

                if(keyButton.ClickMode == ClickMode.Press)
                {
                    keyButton.RaiseEvent(new RoutedEventArgs(KeyButton.ClickEvent));
                }
            }
            else if(message == MouseMessage.WM_LBUTTONUP)
            {
                if(keyCode != VirtualKeyCode.CAPITAL && keyCode != VirtualKeyCode.SHIFT)
                {
                    if(this.previusKeyButton != null)
                    {
                        this.previusKeyButton.IsPressed = false;

                        this.previusKeyButton = null;
                    }

                    keyButton.IsPressed = false;
                }

                if(keyButton.ClickMode == ClickMode.Release)
                {
                    keyButton.RaiseEvent(new RoutedEventArgs(KeyButton.ClickEvent));
                }
            }
        }

        #endregion
        #region 후킹 키 클릭시 처리하기 - Hook_KeyClick(keyCode)

        /// <summary>
        /// 후킹 키 클릭시 처리하기
        /// </summary>
        /// <param name="keyCode">키 코드</param>
        private void Hook_KeyClick(uint keyCode)
        {
            if(this.keyPressed)
            {
                return;
            }

            switch((VirtualKeyCode)keyCode)
            {
                case VirtualKeyCode.HANGUL :

                    IsPressedHangul = !Simulator.Input.InputDeviceState.IsTogglingKeyInEffect(VirtualKeyCode.HANGUL);

                    break;

                case VirtualKeyCode.CAPITAL :

                    IsPressedCapsLock = !Simulator.Input.InputDeviceState.IsTogglingKeyInEffect(VirtualKeyCode.CAPITAL);

                    break;

                case VirtualKeyCode.LSHIFT :
                case VirtualKeyCode.RSHIFT :

                    IsPressedShift = !Simulator.Input.InputDeviceState.IsTogglingKeyInEffect(VirtualKeyCode.SHIFT);

                    break;
            }

            if(IsShow || Visibility == Visibility.Visible)
            {
                UpdateKeys();
            }
        }

        #endregion

        #region 키 버튼 클릭시 처리하기 - KeyButton_Click(sender, e)

        /// <summary>
        /// 키 버튼 클릭시 처리하기
        /// </summary>
        /// <param name="sender">이벤트 발생자</param>
        /// <param name="e">이벤트 인자</param>
        private void KeyButton_Click(object sender, RoutedEventArgs e)
        {
            KeyButton keyButton = e.OriginalSource as KeyButton;

            if(keyButton == null || (IsEnableHook && keyButton.IsStylusCaptured))
            {
                return;
            }

            this.keyPressed = true;

            if(keyButton.KeyCode == VirtualKeyCode.CAPITAL)
            {
                IsPressedCapsLock = !IsPressedCapsLock;

                //Simulator.Keyboard.KeyPress(keyButton.KeyCode);
            }
            else if(keyButton.KeyCode == VirtualKeyCode.SHIFT)
            {
                IsPressedShift = !IsPressedShift;

                if(IsPressedShift)
                {
                    Simulator.Keyboard.KeyDown(keyButton.KeyCode);
                    keyButton.Background = new SolidColorBrush(Color.FromArgb(0xFF, 91, 165, 37));
                }
                else
                {
                    Simulator.Keyboard.KeyUp(keyButton.KeyCode);
                    keyButton.Background = Brushes.RoyalBlue;
                }
            }
            else if(keyButton.KeyCode == VirtualKeyCode.HANGUL)
            {
                IsPressedHangul = !IsPressedHangul;

                Simulator.Keyboard.KeyPress(keyButton.KeyCode);
            }
            else if(keyButton.KeyCode == VirtualKeyCode.CLEAR)
            {
                if (Keyboard.FocusedElement is TextBox)
                {
                    TextBox textBox = Keyboard.FocusedElement as TextBox;
                    textBox.Text = string.Empty;
                }
            }
            else if(keyButton.Name == "exit")
            {
                TextBox textBox = Keyboard.FocusedElement as TextBox;
                textBox.Text = string.Empty;
                Window.GetWindow(this).Close();
            }
            else if (keyButton.KeyCode == VirtualKeyCode.RETURN)
            {
                if (Keyboard.FocusedElement is TextBox)
                {
                    //ReturnString();

                    Window.GetWindow(this).Close();
                    //TextBox textBox = Keyboard.FocusedElement as TextBox;

                    //InputString = textBox.Text;
                    //if (!InputString.Equals(string.Empty))
                    //{
                    //    BindingExpression expression = textBox.GetBindingExpression(TextBox.TextProperty);
                    //    expression?.UpdateSource();

                    //    Window.GetWindow(this).Close();
                    //}

                }
            }
            else
            {

                Simulator.Keyboard.KeyPress(keyButton.KeyCode);

                //if (IsPressedShift)
                //{
                //    IsPressedShift = false;
                //    Simulator.Keyboard.KeyPress(keyButton.KeyCode);
                //    Simulator.Keyboard.KeyUp(VirtualKeyCode.SHIFT);
                //}
                //else
                //{
                //    Simulator.Keyboard.KeyPress(keyButton.KeyCode);
                //}
            }
            
            UpdateKeys();

            RaiseEvent(new RoutedEventArgs(VirtualKeyDownEvent, keyButton.KeyCode));

            this.keyPressed = false;
        }

        #endregion

        //////////////////////////////////////////////////////////////////////////////// Function

        #region 후킹 데이터 업데이트하기 - UpdateHookData()

        /// <summary>
        /// 후킹 데이터 업데이트하기
        /// </summary>
        private void UpdateHookData()
        {
            FrameworkElement content = Content as FrameworkElement;

            if(content == null)
            {
                return;
            }

            Rect area = VisualTreeHelper.GetDescendantBounds(content);

            if(!area.IsEmpty)
            {
                HookingHelper.HookArea    = area;
                HookingHelper.HookElement = this;
            }
        }

        #endregion
        #region 표시 여부 변경하기 - ChangeShow(isShow)

        /// <summary>
        /// 표시 여부 변경하기
        /// </summary>
        /// <param name="isShow">표시 여부</param>
        private void ChangeShow(bool isShow)
        {
            Vector offset = VisualTreeHelper.GetOffset(this);

            Storyboard storyboard = new Storyboard();

            double to = isShow ? 0 : ActualHeight + offset.Y;

            DoubleAnimation doubleAnimation = new DoubleAnimation(to, new Duration(TimeSpan.FromSeconds(0.35)));

            doubleAnimation.EasingFunction = new QuinticEase { EasingMode = EasingMode.EaseInOut };

            storyboard.Children.Add(doubleAnimation);

            Storyboard.SetTargetProperty
            (
                storyboard,
                new PropertyPath
                (
                    "(0).(1)",
                    new DependencyProperty[] { UIElement.RenderTransformProperty, TranslateTransform.YProperty }
                )
            );

            BeginStoryboard(storyboard, HandoffBehavior.SnapshotAndReplace);
        }

        #endregion

        #region 문자열 저장 객체
        private string inputString = String.Empty;
        public string InputString
        {
            set
            {
                if (inputString != value)
                {
                    inputString = value;
                    //OnPropertyChanged("InputString");
                }
            }
            get
            {
                return inputString;
            }
        }
        #endregion

        #region 텍스트값 던지기

        public void ReturnString()
        {
            TextBox textBox = Keyboard.FocusedElement as TextBox;

            if (!textBox.Text.Equals(string.Empty))
            {
                InputString = textBox.Text;

                BindingExpression expression = textBox.GetBindingExpression(TextBox.TextProperty);
                expression?.UpdateSource();
            }
        }

        
        #endregion
    }
    
}