#pragma once

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
using namespace System::Collections::Generic;

namespace MikJNI {
	namespace Raw {

		value class RawJavaVM;

		/// <summary>
		/// Managed wrapper for the Java native interface.
		/// </summary>
		public value class RawJNINativeInterface{

		private:
			IntPtr env;

			inline JNIEnv *GetNativeEnv()
			{
				return (JNIEnv *)env.ToPointer();
			}

		public:
			RawJNINativeInterface(IntPtr p);

			/************************************************************************************/

			jint GetVersion();
			Rawjclass DefineClass(String ^name, Rawjobject loader, array<jbyte> ^buf );
			Rawjclass FindClass(String ^name);
			RawjmethodID FromReflectedMethod(Rawjobject method);
			RawjfieldID FromReflectedField(Rawjobject field);
			Rawjobject ToReflectedMethod(Rawjclass cls, RawjmethodID methodID, bool isStatic);
			Rawjclass GetSuperclass(Rawjclass sub);
			bool IsAssignableFrom(Rawjclass sub, Rawjclass sup);
			Rawjobject ToReflectedField(Rawjclass cls, RawjfieldID fieldID, bool isStatic);
			jint Throw(Rawjthrowable obj);
			jint ThrowNew(Rawjclass clazz, String ^ msg);
			Rawjthrowable ExceptionOccurred();
			void ExceptionDescribe();
			void ExceptionClear();
			void FatalError(String ^ msg);
			jint PushLocalFrame(jint capacity);
			Rawjobject PopLocalFrame(Rawjobject result);
			Rawjobject NewGlobalRef(Rawjobject lobj);
			void DeleteGlobalRef(Rawjobject gref);
			void DeleteLocalRef(Rawjobject obj);
			bool IsSameObject(Rawjobject obj1, Rawjobject obj2);
			Rawjobject NewLocalRef(Rawjobject ref);
			jint EnsureLocalCapacity(jint capacity);
			Rawjobject AllocObject(Rawjclass clazz);
			Rawjobject NewObjectA(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			Rawjclass GetObjectClass(Rawjobject obj);
			bool IsInstanceOf(Rawjobject obj, Rawjclass clazz);
			RawjmethodID GetMethodID(Rawjclass clazz, String ^ name, String ^ sig);
			Rawjobject CallObjectMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args);
			bool CallBooleanMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jbyte CallByteMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jchar CallCharMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jshort CallShortMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jint CallIntMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jlong CallLongMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jfloat CallFloatMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jdouble CallDoubleMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args);
			void CallVoidMethod(Rawjobject obj, RawjmethodID methodID, IList<Rawjvalue>^ args);
			Rawjobject CallNonvirtualObjectMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			bool CallNonvirtualBooleanMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jbyte CallNonvirtualByteMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jchar CallNonvirtualCharMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jshort CallNonvirtualShortMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jint CallNonvirtualIntMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jlong CallNonvirtualLongMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jfloat CallNonvirtualFloatMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jdouble CallNonvirtualDoubleMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			void CallNonvirtualVoidMethod(Rawjobject obj, Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			RawjfieldID GetFieldID(Rawjclass clazz, String ^ name, String ^ sig);
			Rawjobject GetObjectField(Rawjobject obj, RawjfieldID fieldID);
			bool GetBooleanField(Rawjobject obj, RawjfieldID fieldID);
			jbyte GetByteField(Rawjobject obj, RawjfieldID fieldID);
			jchar GetCharField(Rawjobject obj, RawjfieldID fieldID);
			jshort GetShortField(Rawjobject obj, RawjfieldID fieldID);
			jint GetIntField(Rawjobject obj, RawjfieldID fieldID);
			jlong GetLongField(Rawjobject obj, RawjfieldID fieldID);
			jfloat GetFloatField(Rawjobject obj, RawjfieldID fieldID);
			jdouble GetDoubleField(Rawjobject obj, RawjfieldID fieldID);
			void SetObjectField(Rawjobject obj, RawjfieldID fieldID, Rawjobject val);
			void SetBooleanField(Rawjobject obj, RawjfieldID fieldID, bool val);
			void SetByteField(Rawjobject obj, RawjfieldID fieldID, jbyte val);
			void SetCharField(Rawjobject obj, RawjfieldID fieldID, jchar val);
			void SetShortField(Rawjobject obj, RawjfieldID fieldID, jshort val);
			void SetIntField(Rawjobject obj, RawjfieldID fieldID, jint val);
			void SetLongField(Rawjobject obj, RawjfieldID fieldID, jlong val);
			void SetFloatField(Rawjobject obj, RawjfieldID fieldID, jfloat val);
			void SetDoubleField(Rawjobject obj, RawjfieldID fieldID, jdouble val);
			RawjmethodID GetStaticMethodID(Rawjclass clazz, String ^ name, String ^ sig);
			Rawjobject CallStaticObjectMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			bool CallStaticBooleanMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jbyte CallStaticByteMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jchar CallStaticCharMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jshort CallStaticShortMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jint CallStaticIntMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jlong CallStaticLongMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jfloat CallStaticFloatMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			jdouble CallStaticDoubleMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			void CallStaticVoidMethod(Rawjclass clazz, RawjmethodID methodID, IList<Rawjvalue>^ args);
			RawjfieldID GetStaticFieldID(Rawjclass clazz, String ^ name, String ^ sig);
			Rawjobject GetStaticObjectField(Rawjclass clazz, RawjfieldID fieldID);
			bool GetStaticBooleanField(Rawjclass clazz, RawjfieldID fieldID);
			jbyte GetStaticByteField(Rawjclass clazz, RawjfieldID fieldID);
			jchar GetStaticCharField(Rawjclass clazz, RawjfieldID fieldID);
			jshort GetStaticShortField(Rawjclass clazz, RawjfieldID fieldID);
			jint GetStaticIntField(Rawjclass clazz, RawjfieldID fieldID);
			jlong GetStaticLongField(Rawjclass clazz, RawjfieldID fieldID);
			jfloat GetStaticFloatField(Rawjclass clazz, RawjfieldID fieldID);
			jdouble GetStaticDoubleField(Rawjclass clazz, RawjfieldID fieldID);
			void SetStaticObjectField(Rawjclass clazz, RawjfieldID fieldID, Rawjobject val);
			void SetStaticBooleanField(Rawjclass clazz, RawjfieldID fieldID, bool val);
			void SetStaticByteField(Rawjclass clazz, RawjfieldID fieldID, jbyte val);
			void SetStaticCharField(Rawjclass clazz, RawjfieldID fieldID, jchar val);
			void SetStaticShortField(Rawjclass clazz, RawjfieldID fieldID, jshort val);
			void SetStaticIntField(Rawjclass clazz, RawjfieldID fieldID, jint val);
			void SetStaticLongField(Rawjclass clazz, RawjfieldID fieldID, jlong val);
			void SetStaticFloatField(Rawjclass clazz, RawjfieldID fieldID, jfloat val);
			void SetStaticDoubleField(Rawjclass clazz, RawjfieldID fieldID, jdouble val);
			Rawjstring NewString(String ^ utf);
			jsize GetStringLength(Rawjstring str);
			String ^GetStringChars(Rawjstring str);
			//void ReleaseStringChars(Rawjstring str, const jchar *chars);
			//Rawjstring NewStringUTF(String ^ utf);
			jsize GetStringUTFLength(Rawjstring str);
			array<Byte> ^GetStringUTFChars(Rawjstring str);
			//void ReleaseStringUTFChars(Rawjstring str, const char* chars);
			jsize GetArrayLength(Rawjarray arr);
			RawjobjectArray NewObjectArray(jsize len, Rawjclass clazz, Rawjobject init);
			Rawjobject GetObjectArrayElement(RawjobjectArray arr, jsize index);
			void SetObjectArrayElement(RawjobjectArray arr, jsize index, Rawjobject val);
			jbooleanArray NewBooleanArray(jsize len);
			jbyteArray NewByteArray(jsize len);
			jcharArray NewCharArray(jsize len);
			jshortArray NewShortArray(jsize len);
			jintArray NewIntArray(jsize len);
			jlongArray NewLongArray(jsize len);
			jfloatArray NewFloatArray(jsize len);
			jdoubleArray NewDoubleArray(jsize len);
			//jboolean * GetBooleanArrayElements(PJNIEnv env, jbooleanArray array,[Runtime::InteropServices::Out] bool %isCopy);
			//jbyte * GetByteArrayElements(PJNIEnv env, jbyteArray array,[Runtime::InteropServices::Out] bool %isCopy);
			//jchar * GetCharArrayElements(PJNIEnv env, jcharArray array,[Runtime::InteropServices::Out] bool %isCopy);
			//jshort * GetShortArrayElements(PJNIEnv env, jshortArray array,[Runtime::InteropServices::Out] bool %isCopy);
			//jint * GetIntArrayElements(PJNIEnv env, jintArray array,[Runtime::InteropServices::Out] bool %isCopy);
			//jlong * GetLongArrayElements(PJNIEnv env, jlongArray array,[Runtime::InteropServices::Out] bool %isCopy);
			//jfloat * GetFloatArrayElements(PJNIEnv env, jfloatArray array,[Runtime::InteropServices::Out] bool %isCopy);
			//jdouble * GetDoubleArrayElements(PJNIEnv env, jdoubleArray array,[Runtime::InteropServices::Out] bool %isCopy);
			//void ReleaseBooleanArrayElements(PJNIEnv env, jbooleanArray array, jboolean *elems, jint mode);
			//void ReleaseByteArrayElements(PJNIEnv env, jbyteArray array, jbyte *elems, jint mode);
			//void ReleaseCharArrayElements(PJNIEnv env, jcharArray array, jchar *elems, jint mode);
			//void ReleaseShortArrayElements(PJNIEnv env, jshortArray array, jshort *elems, jint mode);
			//void ReleaseIntArrayElements(PJNIEnv env, jintArray array, jint *elems, jint mode);
			//void ReleaseLongArrayElements(PJNIEnv env, jlongArray array, jlong *elems, jint mode);
			//void ReleaseFloatArrayElements(PJNIEnv env, jfloatArray array, jfloat *elems, jint mode);
			//void ReleaseDoubleArrayElements(PJNIEnv env, jdoubleArray array, jdouble *elems, jint mode);
			void GetBooleanArrayRegion(RawjbooleanArray arr, jsize start, jsize l, array<bool> ^dst, int dstIndex);
			void GetByteArrayRegion(RawjbyteArray arr, jsize start, jsize len, array<jbyte> ^dst, int dstIndex);
			void GetCharArrayRegion(RawjcharArray arr, jsize start, jsize len, array<jchar> ^dst, int dstIndex);
			void GetShortArrayRegion(RawjshortArray arr, jsize start, jsize len, array<jshort> ^dst, int dstIndex);
			void GetIntArrayRegion(RawjintArray arr, jsize start, jsize len, array<jint> ^dst, int dstIndex);
			void GetLongArrayRegion(RawjlongArray arr, jsize start, jsize len, array<jlong> ^dst, int dstIndex);
			void GetFloatArrayRegion(RawjfloatArray arr, jsize start, jsize len, array<jfloat> ^dst, int dstIndex);
			void GetDoubleArrayRegion(RawjdoubleArray arr, jsize start, jsize len, array<jdouble> ^dst, int dstIndex);
			void SetBooleanArrayRegion(RawjbooleanArray arr, jsize start, jsize l, array<bool> ^src, int srcIndex);
			void SetByteArrayRegion(RawjbyteArray arr, jsize start, jsize len, array<jbyte> ^src, int srcIndex);
			void SetCharArrayRegion(RawjcharArray arr, jsize start, jsize len, array<jchar> ^src, int srcIndex);
			void SetShortArrayRegion(RawjshortArray arr, jsize start, jsize len, array<jshort> ^src, int srcIndex);
			void SetIntArrayRegion(RawjintArray arr, jsize start, jsize len, array<jint> ^src, int srcIndex);
			void SetLongArrayRegion(RawjlongArray arr, jsize start, jsize len, array<jlong> ^src, int srcIndex);
			void SetFloatArrayRegion(RawjfloatArray arr, jsize start, jsize len, array<jfloat> ^src, int srcIndex);
			void SetDoubleArrayRegion(RawjdoubleArray arr, jsize start, jsize len, array<jdouble> ^src, int srcIndex);
			//jint RegisterNatives(Rawjclass clazz, const JNINativeMethod *methods, jint nMethods);
			//jint UnregisterNatives(Rawjclass clazz);	
			jint MonitorEnter(Rawjobject obj);
			jint MonitorExit(Rawjobject obj);
			jint GetJavaVM([Runtime::InteropServices::Out] RawJavaVM %jvm);
			//void GetStringRegion(jstring str, jsize start, jsize len, jchar *buf);
			//void GetStringUTFRegion(jstring str, jsize start, jsize len, char *buf);
			//void * GetPrimitiveArrayCritical(jarray array,[Runtime::InteropServices::Out] bool %isCopy);
			//void ReleasePrimitiveArrayCritical(jarray array, void *carray, jint mode);
			//const jchar * GetStringCritical(jstring string,[Runtime::InteropServices::Out] bool %isCopy);
			//void ReleaseStringCritical(jstring string, const jchar *cstring);
			Rawjweak NewWeakGlobalRef(Rawjobject obj);
			void DeleteWeakGlobalRef(Rawjweak ref);
			bool ExceptionCheck();
			Rawjobject NewDirectByteBuffer(IntPtr address, jlong capacity);
			IntPtr GetDirectBufferAddress(Rawjobject buf);
			jlong GetDirectBufferCapacity(Rawjobject buf);
			PjobjectRefType GetObjectRefType(Rawjobject obj);

		};

	}	// namespace Raw
} // namespace MikJNI
