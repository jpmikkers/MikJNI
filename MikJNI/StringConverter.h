#pragma once

using namespace System;
using namespace System::Text;

namespace MikJNI {
	namespace Raw {

		/// <summary>
		/// Helper class containing methods that convert strings to various native formats.
		/// </summary>
		public ref class StringConverter
		{
		public:
			static array<System::Byte> ^ConvertStringToModifiedUTF8Array(System::String ^s);
			static array<Char> ^ConvertStringToUnicodeArray(System::String ^s);
		};

	}	// namespace Raw
} // namespace MikJNI
