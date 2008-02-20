#pragma unmanaged
#include <string>
#include <memory>
#include <vector>
#include "jni.h"

#pragma managed
#include "JNIEnv.h"
#include "JavaVM.h"
#include "StringToModifiedUTF8Adapter.h"
#include "StringToUnicodeAdapter.h"
#include "JValueArrayAdapter.h"

using namespace System;
using namespace System::Text;
using namespace System::Runtime::InteropServices;

namespace MikJNI
{
	namespace Raw
	{

		RawJNINativeInterface::RawJNINativeInterface(IntPtr p)
		{
			this->env = p;
		}

		/*
			static void test( const jvalue *p )
			{
				printf("sizeof(jvalue)=%d sizeof(Rawjvalue)=%d",sizeof(jvalue),sizeof(Rawjvalue));
				printf("sizeof(jchar)=%d sizeof(char)=%d",sizeof(jchar),sizeof(System::Char));
				printf("sizeof(jobject)=%d sizeof(IntPtr)=%d",sizeof(jobject),sizeof(IntPtr));
				printf("sizeof(jboolean)=%d sizeof(bool)=%d",sizeof(jboolean),sizeof(bool));
				printf("sizeof(jobject)=%d sizeof(Rawjobject)=%d",sizeof(jboolean),sizeof(Rawjobject));
				Console::ReadLine();
			}
		*/
		jint  RawJNINativeInterface::GetVersion()
		{
			return GetNativeEnv()->GetVersion();
		}

		Rawjclass  RawJNINativeInterface::DefineClass(String ^name, Rawjobject loader, array<jbyte> ^buf )
		{
			pin_ptr<jbyte> pinnedBuf = &buf[0];
			return GetNativeEnv()->DefineClass( StringToModifiedUTF8Adapter(name), loader, pinnedBuf, buf->Length );
		}

		Rawjclass  RawJNINativeInterface::FindClass(String ^name)
		{
			return GetNativeEnv()->FindClass( StringToModifiedUTF8Adapter(name) );
		}

		RawjmethodID  RawJNINativeInterface::FromReflectedMethod(Rawjobject method)
		{
			return GetNativeEnv()->FromReflectedMethod( method );
		}

		RawjfieldID  RawJNINativeInterface::FromReflectedField(Rawjobject field)
		{
			return GetNativeEnv()->FromReflectedField( field );
		}

		Rawjobject  RawJNINativeInterface::ToReflectedMethod(Rawjclass cls, RawjmethodID methodID, bool isStatic)
		{
			return GetNativeEnv()->ToReflectedMethod( cls, methodID, isStatic );
		}

		Rawjclass  RawJNINativeInterface::GetSuperclass(Rawjclass sub)
		{
			return GetNativeEnv()->GetSuperclass( sub );
		}

		bool  RawJNINativeInterface::IsAssignableFrom(Rawjclass sub, Rawjclass sup)
		{
			return GetNativeEnv()->IsAssignableFrom( sub, sup ) ? true : false;
		}

		Rawjobject  RawJNINativeInterface::ToReflectedField(Rawjclass cls, RawjfieldID fieldID, bool isStatic)
		{
			return GetNativeEnv()->ToReflectedField( cls, fieldID, isStatic );
		}

		jint  RawJNINativeInterface::Throw(Rawjthrowable obj)
		{
			return GetNativeEnv()->Throw( obj );
		}

		jint  RawJNINativeInterface::ThrowNew(Rawjclass clazz, String ^ msg)
		{
			return GetNativeEnv()->ThrowNew( clazz, StringToModifiedUTF8Adapter(msg) );
		}

		Rawjthrowable  RawJNINativeInterface::ExceptionOccurred()
		{
			return GetNativeEnv()->ExceptionOccurred();
		}

		void  RawJNINativeInterface::ExceptionDescribe()
		{
			GetNativeEnv()->ExceptionDescribe();
		}

		void RawJNINativeInterface::ExceptionClear()
		{
			GetNativeEnv()->ExceptionClear();
		}

		void  RawJNINativeInterface::FatalError(String ^ msg)
		{
			GetNativeEnv()->FatalError( StringToModifiedUTF8Adapter( msg ) );
		}

		jint  RawJNINativeInterface::PushLocalFrame(jint capacity)
		{
			return GetNativeEnv()->PushLocalFrame( capacity );
		}

		Rawjobject  RawJNINativeInterface::PopLocalFrame(Rawjobject result)
		{
			return GetNativeEnv()->PopLocalFrame( result );
		}

		Rawjobject  RawJNINativeInterface::NewGlobalRef(Rawjobject lobj)
		{
			return GetNativeEnv()->NewGlobalRef( lobj );
		}

		void  RawJNINativeInterface::DeleteGlobalRef(Rawjobject gref)
		{
			GetNativeEnv()->DeleteGlobalRef( gref );
		}

		void RawJNINativeInterface::DeleteLocalRef(Rawjobject obj)
		{
			GetNativeEnv()->DeleteLocalRef( obj );
		}

		bool  RawJNINativeInterface::IsSameObject(Rawjobject obj1, Rawjobject obj2)
		{
			return GetNativeEnv()->IsSameObject( obj1, obj2 ) ? true : false;
		}

		Rawjobject  RawJNINativeInterface::NewLocalRef(Rawjobject ref)
		{
			return GetNativeEnv()->NewLocalRef( ref );
		}

		jint  RawJNINativeInterface::EnsureLocalCapacity(jint capacity)
		{
			return GetNativeEnv()->EnsureLocalCapacity( capacity );
		}

		Rawjobject  RawJNINativeInterface::AllocObject(Rawjclass clazz)
		{
			return GetNativeEnv()->AllocObject( clazz );
		}

		Rawjobject  RawJNINativeInterface::NewObjectA(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->NewObjectA( clazz, methodID, JValueArrayAdapter(args) );
		}

		Rawjclass  RawJNINativeInterface::GetObjectClass(Rawjobject obj)
		{
			return GetNativeEnv()->GetObjectClass( obj );
		}

		bool  RawJNINativeInterface::IsInstanceOf(Rawjobject obj, Rawjclass clazz)
		{
			return GetNativeEnv()->IsInstanceOf( obj, clazz ) ? true : false;
		}

		RawjmethodID  RawJNINativeInterface::GetMethodID(Rawjclass clazz, String ^ name, String ^ sig)
		{
			return GetNativeEnv()->GetMethodID( clazz, StringToModifiedUTF8Adapter(name), StringToModifiedUTF8Adapter(sig) );
		}

		Rawjobject  RawJNINativeInterface::CallObjectMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallObjectMethodA( obj, methodID, JValueArrayAdapter(args) );
		}

		bool  RawJNINativeInterface::CallBooleanMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallBooleanMethodA( obj, methodID, JValueArrayAdapter(args) ) ? true : false;
		}

		jbyte  RawJNINativeInterface::CallByteMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallByteMethodA( obj, methodID, JValueArrayAdapter(args) );
		}

		jchar  RawJNINativeInterface::CallCharMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallCharMethodA( obj, methodID, JValueArrayAdapter(args) );
		}

		jshort  RawJNINativeInterface::CallShortMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallShortMethodA( obj, methodID, JValueArrayAdapter(args) );
		}

		jint  RawJNINativeInterface::CallIntMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallIntMethodA( obj, methodID, JValueArrayAdapter(args) );
		}

		jlong  RawJNINativeInterface::CallLongMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallLongMethodA( obj, methodID, JValueArrayAdapter(args) );
		}

		jfloat  RawJNINativeInterface::CallFloatMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallFloatMethodA( obj, methodID, JValueArrayAdapter(args) );
		}

		jdouble  RawJNINativeInterface::CallDoubleMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallDoubleMethodA( obj, methodID, JValueArrayAdapter(args) );
		}

		void  RawJNINativeInterface::CallVoidMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			GetNativeEnv()->CallVoidMethodA( obj, methodID, JValueArrayAdapter(args) );
		}

		Rawjobject RawJNINativeInterface::CallNonvirtualObjectMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallNonvirtualObjectMethodA( obj, clazz, methodID, JValueArrayAdapter(args) );
		}

		bool  RawJNINativeInterface::CallNonvirtualBooleanMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallNonvirtualBooleanMethodA( obj, clazz, methodID, JValueArrayAdapter(args) ) ? true : false;
		}

		jbyte  RawJNINativeInterface::CallNonvirtualByteMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallNonvirtualByteMethodA( obj, clazz, methodID, JValueArrayAdapter(args) );
		}

		jchar  RawJNINativeInterface::CallNonvirtualCharMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallNonvirtualCharMethodA( obj, clazz, methodID, JValueArrayAdapter(args) );
		}

		jshort  RawJNINativeInterface::CallNonvirtualShortMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallNonvirtualShortMethodA( obj, clazz, methodID, JValueArrayAdapter(args) );
		}

		jint  RawJNINativeInterface::CallNonvirtualIntMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallNonvirtualIntMethodA( obj, clazz, methodID, JValueArrayAdapter(args) );
		}

		jlong  RawJNINativeInterface::CallNonvirtualLongMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallNonvirtualLongMethodA( obj, clazz, methodID, JValueArrayAdapter(args) );
		}

		jfloat  RawJNINativeInterface::CallNonvirtualFloatMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallNonvirtualFloatMethodA( obj, clazz, methodID, JValueArrayAdapter(args) );
		}

		jdouble  RawJNINativeInterface::CallNonvirtualDoubleMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallNonvirtualDoubleMethodA( obj, clazz, methodID, JValueArrayAdapter(args) );
		}

		void  RawJNINativeInterface::CallNonvirtualVoidMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			GetNativeEnv()->CallNonvirtualVoidMethodA( obj, clazz, methodID, JValueArrayAdapter(args) );
		}

		RawjfieldID RawJNINativeInterface::GetFieldID(Rawjclass clazz, String ^ name, String ^ sig)
		{
			return GetNativeEnv()->GetFieldID( clazz, StringToModifiedUTF8Adapter(name), StringToModifiedUTF8Adapter(sig) );
		}

		Rawjobject  RawJNINativeInterface::GetObjectField(Rawjobject obj, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetObjectField( obj, fieldID );
		}

		bool RawJNINativeInterface::GetBooleanField(Rawjobject obj, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetBooleanField( obj, fieldID ) ? true : false;
		}

		jbyte  RawJNINativeInterface::GetByteField(Rawjobject obj, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetByteField( obj, fieldID );
		}

		jchar  RawJNINativeInterface::GetCharField(Rawjobject obj, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetCharField( obj, fieldID );
		}

		jshort  RawJNINativeInterface::GetShortField(Rawjobject obj, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetShortField( obj, fieldID );
		}

		jint  RawJNINativeInterface::GetIntField(Rawjobject obj, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetIntField( obj, fieldID );
		}

		jlong  RawJNINativeInterface::GetLongField(Rawjobject obj, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetLongField( obj, fieldID );
		}

		jfloat  RawJNINativeInterface::GetFloatField(Rawjobject obj, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetFloatField( obj, fieldID );
		}

		jdouble  RawJNINativeInterface::GetDoubleField(Rawjobject obj, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetDoubleField( obj, fieldID );
		}

		void  RawJNINativeInterface::SetObjectField(Rawjobject obj, RawjfieldID fieldID, Rawjobject val)
		{
			GetNativeEnv()->SetObjectField( obj, fieldID, val );
		}

		void RawJNINativeInterface::SetBooleanField(Rawjobject obj, RawjfieldID fieldID, bool val)
		{
			GetNativeEnv()->SetBooleanField( obj, fieldID, val );
		}

		void  RawJNINativeInterface::SetByteField(Rawjobject obj, RawjfieldID fieldID, jbyte val)
		{
			GetNativeEnv()->SetByteField( obj, fieldID, val );
		}

		void RawJNINativeInterface::SetCharField(Rawjobject obj, RawjfieldID fieldID, jchar val)
		{
			GetNativeEnv()->SetCharField( obj, fieldID, val );
		}

		void  RawJNINativeInterface::SetShortField(Rawjobject obj, RawjfieldID fieldID, jshort val)
		{
			GetNativeEnv()->SetShortField( obj, fieldID, val );
		}

		void  RawJNINativeInterface::SetIntField(Rawjobject obj, RawjfieldID fieldID, jint val)
		{
			GetNativeEnv()->SetIntField( obj, fieldID, val );
		}

		void  RawJNINativeInterface::SetLongField(Rawjobject obj, RawjfieldID fieldID, jlong val)
		{
			GetNativeEnv()->SetLongField( obj, fieldID, val );
		}

		void  RawJNINativeInterface::SetFloatField(Rawjobject obj, RawjfieldID fieldID, jfloat val)
		{
			GetNativeEnv()->SetFloatField( obj, fieldID, val );
		}

		void  RawJNINativeInterface::SetDoubleField(Rawjobject obj, RawjfieldID fieldID, jdouble val)
		{
			GetNativeEnv()->SetDoubleField( obj, fieldID, val );
		}

		RawjmethodID  RawJNINativeInterface::GetStaticMethodID(Rawjclass clazz, String ^ name, String ^ sig)
		{
			return GetNativeEnv()->GetStaticMethodID( clazz, StringToModifiedUTF8Adapter(name), StringToModifiedUTF8Adapter(sig) );
		}

		Rawjobject  RawJNINativeInterface::CallStaticObjectMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallStaticObjectMethodA( clazz, methodID, JValueArrayAdapter(args) );
		}

		bool  RawJNINativeInterface::CallStaticBooleanMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallStaticBooleanMethodA( clazz, methodID, JValueArrayAdapter(args) ) ? true : false;
		}

		jbyte  RawJNINativeInterface::CallStaticByteMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallStaticByteMethodA( clazz, methodID, JValueArrayAdapter(args) );
		}

		jchar  RawJNINativeInterface::CallStaticCharMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallStaticCharMethodA( clazz, methodID, JValueArrayAdapter(args) );
		}

		jshort  RawJNINativeInterface::CallStaticShortMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallStaticShortMethodA( clazz, methodID, JValueArrayAdapter(args) );
		}

		jint  RawJNINativeInterface::CallStaticIntMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallStaticIntMethodA( clazz, methodID, JValueArrayAdapter(args) );
		}

		jlong  RawJNINativeInterface::CallStaticLongMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallStaticLongMethodA( clazz, methodID, JValueArrayAdapter(args) );
		}

		jfloat  RawJNINativeInterface::CallStaticFloatMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallStaticFloatMethodA( clazz, methodID, JValueArrayAdapter(args) );
		}

		jdouble  RawJNINativeInterface::CallStaticDoubleMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			return GetNativeEnv()->CallStaticDoubleMethodA( clazz, methodID, JValueArrayAdapter(args) );
		}

		void  RawJNINativeInterface::CallStaticVoidMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args)
		{
			GetNativeEnv()->CallStaticVoidMethodA( clazz, methodID, JValueArrayAdapter(args) );
		}

		RawjfieldID RawJNINativeInterface::GetStaticFieldID(Rawjclass clazz, String ^ name, String ^ sig)
		{
			return  GetNativeEnv()->GetStaticFieldID( clazz, StringToModifiedUTF8Adapter(name), StringToModifiedUTF8Adapter(sig) );
		}

		Rawjobject  RawJNINativeInterface::GetStaticObjectField(Rawjclass clazz, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetStaticObjectField( clazz, fieldID );
		}

		bool  RawJNINativeInterface::GetStaticBooleanField(Rawjclass clazz, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetStaticBooleanField( clazz, fieldID ) ? true : false;
		}

		jbyte  RawJNINativeInterface::GetStaticByteField(Rawjclass clazz, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetStaticByteField( clazz, fieldID );
		}

		jchar  RawJNINativeInterface::GetStaticCharField(Rawjclass clazz, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetStaticCharField( clazz, fieldID );
		}

		jshort  RawJNINativeInterface::GetStaticShortField(Rawjclass clazz, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetStaticShortField( clazz, fieldID );
		}

		jint  RawJNINativeInterface::GetStaticIntField(Rawjclass clazz, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetStaticIntField( clazz, fieldID );
		}

		jlong  RawJNINativeInterface::GetStaticLongField(Rawjclass clazz, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetStaticLongField( clazz, fieldID );
		}

		jfloat  RawJNINativeInterface::GetStaticFloatField(Rawjclass clazz, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetStaticFloatField( clazz, fieldID );
		}

		jdouble  RawJNINativeInterface::GetStaticDoubleField(Rawjclass clazz, RawjfieldID fieldID)
		{
			return GetNativeEnv()->GetStaticDoubleField( clazz, fieldID );
		}

		void  RawJNINativeInterface::SetStaticObjectField(Rawjclass clazz, RawjfieldID fieldID, Rawjobject val)
		{
			GetNativeEnv()->SetStaticObjectField( clazz, fieldID, val );
		}

		void RawJNINativeInterface::SetStaticBooleanField(Rawjclass clazz, RawjfieldID fieldID, bool val)
		{
			GetNativeEnv()->SetStaticBooleanField( clazz, fieldID, val );
		}

		void  RawJNINativeInterface::SetStaticByteField(Rawjclass clazz, RawjfieldID fieldID, jbyte val)
		{
			GetNativeEnv()->SetStaticByteField( clazz, fieldID, val );
		}

		void RawJNINativeInterface::SetStaticCharField(Rawjclass clazz, RawjfieldID fieldID, jchar val)
		{
			GetNativeEnv()->SetStaticCharField( clazz, fieldID, val );
		}

		void  RawJNINativeInterface::SetStaticShortField(Rawjclass clazz, RawjfieldID fieldID, jshort val)
		{
			GetNativeEnv()->SetStaticShortField( clazz, fieldID, val );
		}

		void RawJNINativeInterface::SetStaticIntField(Rawjclass clazz, RawjfieldID fieldID, jint val)
		{
			GetNativeEnv()->SetStaticIntField( clazz, fieldID, val );
		}

		void  RawJNINativeInterface::SetStaticLongField(Rawjclass clazz, RawjfieldID fieldID, jlong val)
		{
			GetNativeEnv()->SetStaticLongField( clazz, fieldID, val );
		}

		void  RawJNINativeInterface::SetStaticFloatField(Rawjclass clazz, RawjfieldID fieldID, jfloat val)
		{
			GetNativeEnv()->SetStaticFloatField( clazz, fieldID, val );
		}

		void  RawJNINativeInterface::SetStaticDoubleField(Rawjclass clazz, RawjfieldID fieldID, jdouble val)
		{
			GetNativeEnv()->SetStaticDoubleField( clazz, fieldID, val );
		}

		Rawjstring  RawJNINativeInterface::NewString(String ^ utf)
		{
			return GetNativeEnv()->NewString( StringToUnicodeAdapter( utf ), utf->Length );
		}

		jsize  RawJNINativeInterface::GetStringLength(Rawjstring str)
		{
			return GetNativeEnv()->GetStringLength( str );
		}

		String ^ RawJNINativeInterface::GetStringChars(Rawjstring str)
		{
			const jchar *src = GetNativeEnv()->GetStringChars(str,NULL);
			StringBuilder ^builder = gcnew StringBuilder();
			jsize length = GetStringLength( str );
			for(jsize t=0;t<length;t++)
			{
				builder->Append((wchar_t)src[t]);
			}
			GetNativeEnv()->ReleaseStringChars( str, src );
			return builder->ToString();
		}

		//void ReleaseStringChars(Rawjstring str, const jchar *chars);

		// There's no point in offering the following as a managed method, just use the unicode based NewString()
		//Rawjstring  RawJNINativeInterface::NewStringUTF(String ^ utf)
		//{
		//	return GetNativeEnv()->NewStringUTF( StringToModifiedUTF8Adapter( utf ) );
		//}

		jsize  RawJNINativeInterface::GetStringUTFLength(Rawjstring str)
		{
			return GetNativeEnv()->GetStringUTFLength( str );
		}

		array<Byte> ^ RawJNINativeInterface::GetStringUTFChars(Rawjstring str)
		{
			array<Byte> ^result = gcnew array<Byte>( GetStringUTFLength( str ) );
			const char * src=GetNativeEnv()->GetStringUTFChars( str, NULL );
			pin_ptr<Byte> dst = &result[0];
			memcpy( dst, src, result->Length );
			GetNativeEnv()->ReleaseStringUTFChars( str, src );
			return result;		
		}

		//void ReleaseStringUTFChars(Rawjstring str, const char* chars);

		jsize  RawJNINativeInterface::GetArrayLength(Rawjarray arr)
		{
			return GetNativeEnv()->GetArrayLength(arr);
		}

		RawjobjectArray  RawJNINativeInterface::NewObjectArray(jsize len, Rawjclass clazz, Rawjobject init)
		{
			return GetNativeEnv()->NewObjectArray(len, clazz, init);
		}

		Rawjobject  RawJNINativeInterface::GetObjectArrayElement(RawjobjectArray arr, jsize index)
		{
			return GetNativeEnv()->GetObjectArrayElement(arr, index);
		}

		void  RawJNINativeInterface::SetObjectArrayElement(RawjobjectArray arr, jsize index, Rawjobject val)
		{
			GetNativeEnv()->SetObjectArrayElement(arr,index,val);
		}

		jbooleanArray  RawJNINativeInterface::NewBooleanArray(jsize len)
		{
			return GetNativeEnv()->NewBooleanArray(len);
		}

		jbyteArray  RawJNINativeInterface::NewByteArray(jsize len)
		{
			return GetNativeEnv()->NewByteArray(len);
		}

		jcharArray  RawJNINativeInterface::NewCharArray(jsize len)
		{
			return GetNativeEnv()->NewCharArray(len);
		}

		jshortArray  RawJNINativeInterface::NewShortArray(jsize len)
		{
			return GetNativeEnv()->NewShortArray(len);
		}

		jintArray  RawJNINativeInterface::NewIntArray(jsize len)
		{
			return GetNativeEnv()->NewIntArray(len);
		}

		jlongArray  RawJNINativeInterface::NewLongArray(jsize len)
		{
			return GetNativeEnv()->NewLongArray(len);
		}

		jfloatArray  RawJNINativeInterface::NewFloatArray(jsize len)
		{
			return GetNativeEnv()->NewFloatArray(len);
		}

		jdoubleArray   RawJNINativeInterface::NewDoubleArray(jsize len)
		{
			return GetNativeEnv()->NewDoubleArray(len);
		}

		//jboolean * GetBooleanArrayElements(PJNIEnv env, jbooleanArray array,[Runtime::InteropServices::Out] bool %isCopy)
		//jbyte * GetByteArrayElements(PJNIEnv env, jbyteArray array,[Runtime::InteropServices::Out] bool %isCopy)
		//jchar * GetCharArrayElements(PJNIEnv env, jcharArray array,[Runtime::InteropServices::Out] bool %isCopy)
		//jshort * GetShortArrayElements(PJNIEnv env, jshortArray array,[Runtime::InteropServices::Out] bool %isCopy)
		//jint * GetIntArrayElements(PJNIEnv env, jintArray array,[Runtime::InteropServices::Out] bool %isCopy)
		//jlong * GetLongArrayElements(PJNIEnv env, jlongArray array,[Runtime::InteropServices::Out] bool %isCopy)
		//jfloat * GetFloatArrayElements(PJNIEnv env, jfloatArray array,[Runtime::InteropServices::Out] bool %isCopy)
		//jdouble * GetDoubleArrayElements(PJNIEnv env, jdoubleArray array,[Runtime::InteropServices::Out] bool %isCopy)
		//void ReleaseBooleanArrayElements(PJNIEnv env, jbooleanArray array, jboolean *elems, jint mode)
		//void ReleaseByteArrayElements(PJNIEnv env, jbyteArray array, jbyte *elems, jint mode)
		//void ReleaseCharArrayElements(PJNIEnv env, jcharArray array, jchar *elems, jint mode)
		//void ReleaseShortArrayElements(PJNIEnv env, jshortArray array, jshort *elems, jint mode)
		//void ReleaseIntArrayElements(PJNIEnv env, jintArray array, jint *elems, jint mode)
		//void ReleaseLongArrayElements(PJNIEnv env, jlongArray array, jlong *elems, jint mode)
		//void ReleaseFloatArrayElements(PJNIEnv env, jfloatArray array, jfloat *elems, jint mode)
		//void ReleaseDoubleArrayElements(PJNIEnv env, jdoubleArray array, jdouble *elems, jint mode)

		void  RawJNINativeInterface::GetBooleanArrayRegion(RawjbooleanArray arr, jsize start, jsize l, array<bool> ^dst, int dstIndex)
		{
			pin_ptr<bool> dstPtr = &dst[dstIndex];
			GetNativeEnv()->GetBooleanArrayRegion( arr, start, l, (jboolean *)dstPtr );
		}

		void  RawJNINativeInterface::GetByteArrayRegion(RawjbyteArray arr, jsize start, jsize len, array<jbyte> ^dst, int dstIndex)
		{
			pin_ptr<jbyte> dstPtr = &dst[dstIndex];
			GetNativeEnv()->GetByteArrayRegion( arr, start, len, dstPtr );
		}

		void  RawJNINativeInterface::GetCharArrayRegion(RawjcharArray arr, jsize start, jsize len, array<jchar> ^dst, int dstIndex)
		{
			pin_ptr<jchar> dstPtr = &dst[dstIndex];
			GetNativeEnv()->GetCharArrayRegion( arr, start, len, dstPtr );
		}

		void  RawJNINativeInterface::GetShortArrayRegion(RawjshortArray arr, jsize start, jsize len, array<jshort> ^dst, int dstIndex)
		{
			pin_ptr<jshort> dstPtr = &dst[dstIndex];
			GetNativeEnv()->GetShortArrayRegion( arr, start, len, dstPtr );
		}

		void  RawJNINativeInterface::GetIntArrayRegion(RawjintArray arr, jsize start, jsize len, array<jint> ^dst, int dstIndex)
		{
			pin_ptr<jint> dstPtr = &dst[dstIndex];
			GetNativeEnv()->GetIntArrayRegion( arr, start, len, dstPtr );
		}

		void  RawJNINativeInterface::GetLongArrayRegion(RawjlongArray arr, jsize start, jsize len, array<jlong> ^dst, int dstIndex)
		{
			pin_ptr<jlong> dstPtr = &dst[dstIndex];
			GetNativeEnv()->GetLongArrayRegion( arr, start, len, dstPtr );
		}

		void  RawJNINativeInterface::GetFloatArrayRegion(RawjfloatArray arr, jsize start, jsize len, array<jfloat> ^dst, int dstIndex)
		{
			pin_ptr<jfloat> dstPtr = &dst[dstIndex];
			GetNativeEnv()->GetFloatArrayRegion( arr, start, len, dstPtr );
		}

		void  RawJNINativeInterface::GetDoubleArrayRegion(RawjdoubleArray arr, jsize start, jsize len, array<jdouble> ^dst, int dstIndex)
		{
			pin_ptr<jdouble> dstPtr = &dst[dstIndex];
			GetNativeEnv()->GetDoubleArrayRegion( arr, start, len, dstPtr );
		}

		void  RawJNINativeInterface::SetBooleanArrayRegion(RawjbooleanArray arr, jsize start, jsize l, array<bool> ^src, int srcIndex)
		{
			pin_ptr<bool> srcPtr = &src[srcIndex];
			GetNativeEnv()->SetBooleanArrayRegion( arr, start, l, (const jboolean *)srcPtr );
		}

		void  RawJNINativeInterface::SetByteArrayRegion(RawjbyteArray arr, jsize start, jsize len, array<jbyte> ^src, int srcIndex)
		{
			pin_ptr<jbyte> srcPtr = &src[srcIndex];
			GetNativeEnv()->SetByteArrayRegion( arr, start, len, srcPtr );
		}

		void  RawJNINativeInterface::SetCharArrayRegion(RawjcharArray arr, jsize start, jsize len, array<jchar> ^src, int srcIndex)
		{
			pin_ptr<jchar> srcPtr = &src[srcIndex];
			GetNativeEnv()->SetCharArrayRegion( arr, start, len, srcPtr );
		}

		void  RawJNINativeInterface::SetShortArrayRegion(RawjshortArray arr, jsize start, jsize len, array<jshort> ^src, int srcIndex)
		{
			pin_ptr<jshort> srcPtr = &src[srcIndex];
			GetNativeEnv()->SetShortArrayRegion( arr, start, len, srcPtr );
		}

		void  RawJNINativeInterface::SetIntArrayRegion(RawjintArray arr, jsize start, jsize len, array<jint> ^src, int srcIndex)
		{
			pin_ptr<jint> srcPtr = &src[srcIndex];
			GetNativeEnv()->SetIntArrayRegion( arr, start, len, srcPtr );
		}

		void  RawJNINativeInterface::SetLongArrayRegion(RawjlongArray arr, jsize start, jsize len, array<jlong> ^src, int srcIndex)
		{
			pin_ptr<jlong> srcPtr = &src[srcIndex];
			GetNativeEnv()->SetLongArrayRegion( arr, start, len, srcPtr );
		}

		void  RawJNINativeInterface::SetFloatArrayRegion(RawjfloatArray arr, jsize start, jsize len, array<jfloat> ^src, int srcIndex)
		{
			pin_ptr<jfloat> srcPtr = &src[srcIndex];
			GetNativeEnv()->SetFloatArrayRegion( arr, start, len, srcPtr );
		}

		void  RawJNINativeInterface::SetDoubleArrayRegion(RawjdoubleArray arr, jsize start, jsize len, array<jdouble> ^src, int srcIndex)
		{
			pin_ptr<jdouble> srcPtr = &src[srcIndex];
			GetNativeEnv()->SetDoubleArrayRegion( arr, start, len, srcPtr );
		}

		//jint RegisterNatives(Rawjclass clazz, const JNINativeMethod *methods, jint nMethods);
		//jint UnregisterNatives(Rawjclass clazz);

		jint  RawJNINativeInterface::MonitorEnter(Rawjobject obj)
		{
			return GetNativeEnv()->MonitorEnter( obj );
		}

		jint  RawJNINativeInterface::MonitorExit(Rawjobject obj)
		{
			return GetNativeEnv()->MonitorExit( obj );
		}

		jint  RawJNINativeInterface::GetJavaVM([Runtime::InteropServices::Out] RawJavaVM %jvm)
		{
			JavaVM *pvm;
			jint result = GetNativeEnv()->GetJavaVM( &pvm );
			jvm = RawJavaVM(IntPtr(pvm));
			return result;
		}

		//void GetStringRegion(jstring str, jsize start, jsize len, jchar *buf);
		//void GetStringUTFRegion(jstring str, jsize start, jsize len, char *buf);
		//void * GetPrimitiveArrayCritical(jarray array,[Runtime::InteropServices::Out] bool %isCopy);
		//void ReleasePrimitiveArrayCritical(jarray array, void *carray, jint mode);
		//const jchar * GetStringCritical(jstring string,[Runtime::InteropServices::Out] bool %isCopy);
		//void ReleaseStringCritical(jstring string, const jchar *cstring);

		Rawjweak  RawJNINativeInterface::NewWeakGlobalRef(Rawjobject obj)
		{
			return GetNativeEnv()->NewWeakGlobalRef( obj );
		}

		void  RawJNINativeInterface::DeleteWeakGlobalRef(Rawjweak ref)
		{
			GetNativeEnv()->DeleteWeakGlobalRef( ref );
		}

		bool  RawJNINativeInterface::ExceptionCheck()
		{
			return GetNativeEnv()->ExceptionCheck() ? true : false;
		}

		Rawjobject  RawJNINativeInterface::NewDirectByteBuffer(IntPtr address, jlong capacity)
		{
			return GetNativeEnv()->NewDirectByteBuffer( address.ToPointer(), capacity );
		}

		IntPtr  RawJNINativeInterface::GetDirectBufferAddress(Rawjobject buf)
		{
			return IntPtr(GetNativeEnv()->GetDirectBufferAddress( buf ));
		}

		jlong  RawJNINativeInterface::GetDirectBufferCapacity(Rawjobject buf)
		{
			return GetNativeEnv()->GetDirectBufferCapacity( buf );
		}

		PjobjectRefType  RawJNINativeInterface::GetObjectRefType(Rawjobject obj)
		{
			return (PjobjectRefType)GetNativeEnv()->GetObjectRefType( obj );
		}


	} // namespace Raw
} // namespace MikJNI
