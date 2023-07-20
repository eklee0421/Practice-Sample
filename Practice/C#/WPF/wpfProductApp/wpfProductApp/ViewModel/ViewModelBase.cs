﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace wpfProductApp.ViewModel.ViewModels
{
    public abstract class ViewModelBase : INotifyPropertyChanged
    {
        #region Property Changed Event Handler

        protected void OnPropertyChanged(string propertyName)
        {
            this.PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        public event PropertyChangedEventHandler PropertyChanged;
        #endregion Property Changed Event Handler
    }
}
