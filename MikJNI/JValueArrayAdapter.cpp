#pragma unmanaged
#include <string>
#include <memory>
#include <vector>
#include "jni.h"

#pragma managed
#include "MikJNI.h"
#include "JValueArrayAdapter.h"

using namespace System;

namespace MikJNI
{
	namespace Raw
	{

JValueArrayAdapter::JValueArrayAdapter( IList<PJValue>^ args )
{
	dummy = new jvalue[args->Count];
	for(int t=0;t<args->Count;t++)
	{
		dummy[t] = args->default[t];
	}
}

JValueArrayAdapter::~JValueArrayAdapter()
{
	delete[] dummy;
}

JValueArrayAdapter::operator const jvalue *()
{
	return dummy;
}

	} // namespace Raw
} // namespace MikJNI
