#pragma unmanaged
#include <string>
#include <memory>

#pragma managed
#include "StringToUnicodeAdapter.h"
#include "StringConverter.h"

using namespace System;
using namespace System::Text;
using namespace System::Runtime::InteropServices;

namespace MikJNI {
	namespace Raw {

StringToUnicodeAdapter::StringToUnicodeAdapter(System::String ^s)
{
	if(s!=nullptr)
	{
		// this depends on sizeof(Char) == sizeof(unsigned short) == sizeof(jchar)
		array<Char> ^t=StringConverter::ConvertStringToUnicodeArray(s);
		pin_ptr<Char> pin = &t[0];
		buf = new unsigned short[t->Length];
		memcpy(buf,pin,t->Length * sizeof(unsigned short));
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

StringToUnicodeAdapter::operator const unsigned short *()
{
	return buf;
}

	}	// namespace Raw
} // namespace MikJNI
