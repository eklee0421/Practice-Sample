using System.Collections.Generic;
using System.Windows;
using System.Windows.Media;

namespace UsingKeyboard
{
    /// <summary>
    /// 비주얼 엘리먼트 헬퍼
    /// </summary>
    public static class VisualElementHelper
    {
        //////////////////////////////////////////////////////////////////////////////////////////////////// Method
        ////////////////////////////////////////////////////////////////////////////////////////// Static
        //////////////////////////////////////////////////////////////////////////////// Public

        #region 부모 구하기 - GetParent(child)

        /// <summary>
        /// 부모 구하기
        /// </summary>
        /// <param name="child">자식</param>
        /// <returns>부모</returns>
        public static DependencyObject GetParent(this DependencyObject child)
        {
            if(child == null)
            {
                return null;
            }

            ContentElement childContentElement = child as ContentElement;

            if(childContentElement != null)
            {
                DependencyObject parent = ContentOperations.GetParent(childContentElement);

                if(parent != null)
                {
                    return parent;
                }

                FrameworkContentElement childFrameworkContentElement = childContentElement as FrameworkContentElement;

                return childFrameworkContentElement != null ? childFrameworkContentElement.Parent : null;
            }

            FrameworkElement childFrameworkElement = child as FrameworkElement;

            if(childFrameworkElement != null)
            {
                DependencyObject parent = childFrameworkElement.Parent;

                if(parent != null)
                {
                    return parent;
                }
            }

            return VisualTreeHelper.GetParent(child);
        }

        #endregion
        #region 부모 찾기 시도하기 - TryFindParent<TParent>(child)

        /// <summary>
        /// 부모 찾기 시도하기
        /// </summary>
        /// <typeparam name="TParent">부모 타입</typeparam>
        /// <param name="child">자식</param>
        /// <returns>부모</returns>
        public static TParent TryFindParent<TParent>(this DependencyObject child) where TParent : DependencyObject
        {
            DependencyObject parentObject = GetParent(child);

            if(parentObject == null)
            {
                return null;
            }

            TParent parent = parentObject as TParent;

            if(parent != null)
            {
                return parent;
            }
            else
            {
                return TryFindParent<TParent>(parentObject);
            }
        }

        #endregion
        #region 자식 열거 가능형 구하기 - GetChildEnumerable(parent)

        /// <summary>
        /// 자식 열거 가능형 구하기
        /// </summary>
        /// <param name="parent">부모</param>
        /// <returns>자식 열거 가능형</returns>
        public static IEnumerable<DependencyObject> GetChildEnumerable(this DependencyObject parent)
        {
            if(parent == null)
            {
                yield break;
            }

            if(parent is ContentElement || parent is FrameworkElement)
            {
                foreach(object childObject in LogicalTreeHelper.GetChildren(parent))
                {
                    DependencyObject child = childObject as DependencyObject;

                    if(child != null)
                    {
                        yield return (DependencyObject)childObject;
                    }
                }
            }
            else
            {
                int count = VisualTreeHelper.GetChildrenCount(parent);

                for(int i = 0; i < count; i++)
                {
                    yield return VisualTreeHelper.GetChild(parent, i);
                }
            }
        }

        #endregion
        #region 자식 찾기 - FindChildren<TChild>(parent)

        /// <summary>
        /// 자식 찾기
        /// </summary>
        /// <typeparam name="TChild">자식 타입</typeparam>
        /// <param name="parent">부모</param>
        /// <returns>자식 열거 가능형</returns>
        public static IEnumerable<TChild> FindChildren<TChild>(this DependencyObject parent) where TChild : DependencyObject
        {
            if(parent != null)
            {
                IEnumerable<DependencyObject> childEnumerable = GetChildEnumerable(parent);

                foreach(DependencyObject child in childEnumerable)
                {
                    if(child != null && child is TChild)
                    {
                        yield return (TChild)child;
                    }

                    foreach(TChild descendant in FindChildren<TChild>(child))
                    {
                        yield return descendant;
                    }
                }
            }
        }

        #endregion
        #region 포인트에서 찾기 시도하기 - TryFindFromPoint<T>(referenceElement, point)

        /// <summary>
        /// 포인트에서 찾기 시도하기
        /// </summary>
        /// <typeparam name="TElement">엘리먼트 타입</typeparam>
        /// <param name="referenceElement">참조 엘리먼트</param>
        /// <param name="point">포인트</param>
        /// <returns>엘리먼트</returns>
        public static TElement TryFindFromPoint<TElement>(UIElement referenceElement, Point point) where TElement : DependencyObject
        {
            DependencyObject element = referenceElement.InputHitTest(point) as DependencyObject;

            if(element == null)
            {
                return null;
            }
            else if(element is TElement)
            {
                return (TElement)element;
            }
            else
            {
                return TryFindParent<TElement>(element);
            }
        }

        #endregion
    }
}