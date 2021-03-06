#pragma once

#pragma unmanaged
#include <string>
#include <memory>
#include <vector>
#include "jni.h"

#pragma managed
#include "MikJNI.h"

using namespace System;
using namespace System::Text;
using namespace System::Runtime::InteropServices;
using namespace System::Collections::Generic;

namespace MikJNI {
	namespace Raw {

		value class RawJNINativeInterface;

		/// <summary>
		/// Holds a command line argument to pass to the Java virtual machine.
		/// </summary>
		public ref class RawJavaVMOption 
		{
		public:
			String ^optionString;
			IntPtr extraInfo;
		};

		/// <summary>
		/// Holds the arguments to use for construction of the Java virtual machine.
		/// </summary>
		public ref class RawJavaVMInitArgs
		{
		public:
			RawJNIVersion version;
			List<RawJavaVMOption ^> ^options;
			bool ignoreUnrecognized;

			RawJavaVMInitArgs::RawJavaVMInitArgs()
			{
				this->version = RawJNIVersion::VERSION_1_6;
				this->options = gcnew List<RawJavaVMOption ^>(0);
				this->ignoreUnrecognized = true;
			}
		};

		/// <summary>
		/// Holds the arguments to use for attaching the java virtual machine to a thread.
		/// </summary>
		public ref class RawJavaVMAttachArgs 
		{
		public:
			RawJNIVersion version;		/* must be at least JNI_VERSION_1_2 */
			String ^name;				/* the name of the thread as a modified UTF-8 string, or NULL */
			Rawjobject group;			/* global ref of a ThreadGroup object, or NULL */
		};

		/// <summary>
		/// Managed wrapper for the pointer to the Java virtual machine.
		/// </summary>
		public value class RawJavaVM{

		private:
			IntPtr jvm;

			inline JavaVM *GetJVM()
			{
				return (JavaVM *)jvm.ToPointer();
			}

		public:
			RawJavaVM(IntPtr p);
			bool IsNull();
			static jint CreateJavaVM( 
				[Runtime::InteropServices::Out] RawJavaVM %jvm,
				[Runtime::InteropServices::Out] RawJNINativeInterface %env, RawJavaVMInitArgs ^args );
			jint DestroyJavaVM();
			jint AttachCurrentThread( [Runtime::InteropServices::Out] RawJNINativeInterface %env, RawJavaVMAttachArgs ^args );
			jint DetachCurrentThread();
			jint GetEnv([Runtime::InteropServices::Out] RawJNINativeInterface %env, RawJNIVersion version);
			jint AttachCurrentThreadAsDaemon([Runtime::InteropServices::Out] RawJNINativeInterface %env);
		};

	}	// namespace Raw
} // namespace MikJNI
