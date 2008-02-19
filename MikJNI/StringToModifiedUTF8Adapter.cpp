#pragma unmanaged
#include <string>
#include <memory>

#pragma managed
#include "StringToModifiedUTF8Adapter.h"
#include "StringConverter.h"

using namespace System;
using namespace System::Text;
using namespace System::Runtime::InteropServices;

namespace MikJNI
{
	namespace Raw
	{

StringToModifiedUTF8Adapter::StringToModifiedUTF8Adapter(System::String ^s)
{
	if(s!=nullptr)
	{
		array<Byte> ^t=StringConverter::ConvertStringToModifiedUTF8Array(s);
		pin_ptr<Byte> pin = &t[0];
		buf = new char[t->Length];
		memcpy(buf,pin,t->Length);
	}
	else
	{
		buf = NULL;
	}
}

StringToModifiedUTF8Adapter::~StringToModifiedUTF8Adapter()
{
	delete[] buf;
}

StringToModifiedUTF8Adapter::operator const char *()
{
	return buf;
}

	}	// namespace Raw
} // namespace MikJNI
