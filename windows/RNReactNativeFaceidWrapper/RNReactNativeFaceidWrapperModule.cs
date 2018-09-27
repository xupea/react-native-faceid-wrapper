using ReactNative.Bridge;
using System;
using System.Collections.Generic;
using Windows.ApplicationModel.Core;
using Windows.UI.Core;

namespace React.Native.Faceid.Wrapper.RNReactNativeFaceidWrapper
{
    /// <summary>
    /// A module that allows JS to share data.
    /// </summary>
    class RNReactNativeFaceidWrapperModule : NativeModuleBase
    {
        /// <summary>
        /// Instantiates the <see cref="RNReactNativeFaceidWrapperModule"/>.
        /// </summary>
        internal RNReactNativeFaceidWrapperModule()
        {

        }

        /// <summary>
        /// The name of the native module.
        /// </summary>
        public override string Name
        {
            get
            {
                return "RNReactNativeFaceidWrapper";
            }
        }
    }
}
