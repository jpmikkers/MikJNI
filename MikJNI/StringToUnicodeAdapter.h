#pragma once

using namespace System;
using namespace System::Text;

namespace MikJNI {
	namespace Raw {

class StringToUnicodeAdapter
{
private:
	unsigned short *buf;

public:
	StringToUnicodeAdapter(System::String ^s);
	~StringToUnicodeAdapter();
	operator const unsigned short *();
};

	}	// namespace Raw
} // namespace MikJNI
