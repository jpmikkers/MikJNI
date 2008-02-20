#pragma once

using namespace System;
using namespace System::Text;

namespace MikJNI {
	namespace Raw {

		/// <summary>
		/// Class that simplifies creating a temporary unmanaged UTF8 string from a managed string.
		/// </summary>
		class StringToModifiedUTF8Adapter
		{
		private:
			char *buf;

		public:
			StringToModifiedUTF8Adapter(System::String ^s);
			~StringToModifiedUTF8Adapter();
			operator const char *();
		};

	}	// namespace Raw
} // namespace MikJNI
