#pragma once

#pragma unmanaged
#include <string>
#include <memory>
#include <vector>
#include "jni.h"

#pragma managed

using namespace System;
using namespace System::Text;
using namespace System::Runtime::InteropServices;
using namespace System::Collections::Generic;

namespace MikJNI {
	namespace Raw {

		public ref class RawJNIResultCodes 
		{
		public:
			static const int OK           = JNI_OK;                 // success
			static const int ERR          = JNI_ERR;             // unknown error
			static const int EDETACHED    = JNI_EDETACHED;             // thread detached from the VM
			static const int EVERSION     = JNI_EVERSION;             // JNI version error
			static const int ENOMEM       = JNI_ENOMEM;             // not enough memory
			static const int EEXIST       = JNI_EEXIST;             // VM already created
			static const int EINVAL       = JNI_EINVAL;             // invalid arguments
			static const int COMMIT		  = JNI_COMMIT;
			static const int ABORT        = JNI_ABORT;
		};

		public enum class RawJNIVersion
		{
			VERSION_1_1 = JNI_VERSION_1_1,
			VERSION_1_2 = JNI_VERSION_1_2,
			VERSION_1_4 = JNI_VERSION_1_4,
			VERSION_1_6 = JNI_VERSION_1_6
		};

	#define PWrap(wrapname,origname)	\
		public value class wrapname			\
		{									\
			private:						\
			IntPtr p;						\
			\
		public:							\
			wrapname(IntPtr p)				\
			{								\
				this->p = p;				\
			}								\
				\
			static operator IntPtr(wrapname w)	 	        \
			{								\
				return w.p;					\
			}								\
			\
			static operator wrapname(IntPtr p)	        \
			{								\
				return wrapname(p);			\
			}								\
			\
			internal:						\
			static operator wrapname(origname p)	        \
			{								\
				wrapname result;			\
				result.p = IntPtr(p);		\
				return result;				\
			}								\
			\
			static operator origname(wrapname w)	 	        \
			{								\
				return (origname)w.p.ToPointer();		\
			}								\
		};									


		public enum class PjobjectRefType
		{
			JNIInvalidRefType    = 0,
			JNILocalRefType      = 1,
			JNIGlobalRefType     = 2, 
			JNIWeakGlobalRefType = 3
		};

		PWrap(Rawjclass        , jclass         )
		PWrap(Rawjobject       , jobject        )
		PWrap(RawjmethodID     , jmethodID      )
		PWrap(RawjfieldID      , jfieldID       )
		PWrap(Rawjthrowable    , jthrowable     )
		PWrap(Rawjweak         , jweak          )
		PWrap(Rawjstring       , jstring        )
		PWrap(Rawjarray	       , jarray	        )
		PWrap(RawjobjectArray  , jobjectArray   )
		PWrap(RawjbooleanArray , jbooleanArray  )
		PWrap(RawjbyteArray    , jbyteArray	    )	
		PWrap(RawjcharArray    , jcharArray	    )	
		PWrap(RawjshortArray   , jshortArray    )	
		PWrap(RawjintArray     , jintArray      )
		PWrap(RawjlongArray    , jlongArray	    )	
		PWrap(RawjfloatArray   , jfloatArray    )	
		PWrap(RawjdoubleArray  , jdoubleArray   )

		[StructLayout(LayoutKind::Explicit)]
		public value struct Rawjvalue 
		{
			[FieldOffset(0)]
			bool     z;
			[FieldOffset(0)]
			jbyte    b;
			[FieldOffset(0)]
			System::Char c;
			[FieldOffset(0)]
			jshort   s;
			[FieldOffset(0)]
			jint     i;
			[FieldOffset(0)]
			jlong    j;
			[FieldOffset(0)]
			jfloat   f;
			[FieldOffset(0)]
			jdouble  d;
			[FieldOffset(0)]
			Rawjobject l;

		internal:
			operator jvalue()
			{
				jvalue result;
				pin_ptr<Rawjvalue> t = this;
				result = *((jvalue *)t);
				return result;
			};
		};

	}	// namespace Raw
} // namespace MikJNI
