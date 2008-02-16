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

namespace MikJNI {
	namespace Raw {

StringToUnicodeAdapter::StringToUnicodeAdapter(System::String ^s)
{
	if(s!=nullptr)
	{
		array<Char> ^t=StringConverter::ConvertStringToUnicodeArray(s);
		pin_ptr<Char> pin = &t[0];
		buf = new jchar[t->Length];
		memcpy(buf,pin,t->Length * sizeof(jchar));
	}
	else
	{
		buf = NULL;
	}
}

StringToUnicodeAdapter::~StringToUnicodeAdapter()
{
	delete[] buf;
}

StringToUnicodeAdapter::operator const jchar *()
{
	return buf;
}

	}	// namespace Raw
} // namespace MikJNI
