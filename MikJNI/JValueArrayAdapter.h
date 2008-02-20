#pragma once

#pragma unmanaged
#include <string>
#include <memory>
#include <vector>
#include "jni.h"

#pragma managed
#include "MikJNI.h"

using namespace System;
using namespace System::Collections::Generic;

namespace MikJNI {
	namespace Raw {

		/// <summary>
		/// Class that simplifies creating a temporary unmanaged jvalue array from a list of (managed) Rawjvalues.
		/// </summary>
		class JValueArrayAdapter
		{
		private:
			jvalue *dummy;

		public:
			JValueArrayAdapter( IList<Rawjvalue>^ args );
			~JValueArrayAdapter();
			operator const jvalue *();
		};

	}	// namespace Raw
} // namespace MikJNI
