// JNIDotNet.cpp : main project file.
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

namespace MikJNI
{
	namespace Raw
	{

JValueAdapter::JValueAdapter( JValueArgs args )
{
	dummy = new jvalue[args->Count];
	for(int t=0;t<args->Count;t++)
	{
		dummy[t] = args->default[t];
	}
}

JValueAdapter::~JValueAdapter()
{
	delete[] dummy;
}

JValueAdapter::operator const jvalue *()
{
	return dummy;
}

	} // namespace Raw
} // namespace MikJNI
