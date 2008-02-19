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

class JValueArrayAdapter
{
private:
	jvalue *dummy;

public:
	JValueArrayAdapter( IList<PJValue>^ args );
	~JValueArrayAdapter();
	operator const jvalue *();
};

	}	// namespace Raw
} // namespace MikJNI
