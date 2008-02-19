#pragma managed
#include "StringConverter.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;

namespace MikJNI
{
	namespace Raw
	{

#define         MASKBITS                0x3F
#define         MASKBYTE                0x80
#define         MASK2BYTES              0xC0
#define         MASK3BYTES              0xE0
#define         MASK4BYTES              0xF0
#define         MASK5BYTES              0xF8
#define         MASK6BYTES              0xFC

array<System::Byte> ^StringConverter::ConvertStringToModifiedUTF8Array(System::String ^s)
{
	List<System::Byte> ^v = gcnew List<System::Byte>();

	for each(System::Char c in s)
	{
		if(c==0)
		{
			v->Add( (Byte)(MASK2BYTES | (c >> 6)));
			v->Add( (Byte)(MASKBYTE | (c & MASKBITS)));
		}
		else if(c < 0x80)
		{
			v->Add( (Byte) c );
		}
		else if(c < 0x800)
		{
			v->Add( (Byte)(MASK2BYTES | (c >> 6)));
			v->Add( (Byte)(MASKBYTE | (c & MASKBITS)));
		}
		else if(c < 0x10000)
		{
			v->Add( (Byte)(MASK3BYTES | (c >> 12)));
			v->Add( (Byte)(MASKBYTE | ((c >> 6) & MASKBITS)));
			v->Add( (Byte)(MASKBYTE | (c & MASKBITS)));
		}
	}
	v->Add(0);
	return v->ToArray();
}

array<Char> ^StringConverter::ConvertStringToUnicodeArray(System::String ^s)
{
	List<Char> ^v = gcnew List<Char>();
	for each(Char c in s)
	{
		v->Add(c);
	}
	return v->ToArray();
}

	} // namespace Raw
} // namespace MikJNI
