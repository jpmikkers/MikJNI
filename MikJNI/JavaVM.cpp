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

RawJavaVM::RawJavaVM(IntPtr p)
{
	this->jvm = p;
}

bool RawJavaVM::IsNull()
{
	return(jvm == IntPtr::Zero);
}

jint RawJavaVM::CreateJavaVM( 
	[Runtime::InteropServices::Out] RawJavaVM %jvm,
	[Runtime::InteropServices::Out] RawJNINativeInterface %env/*, void **penv, void *args */)
{
	JavaVM *pjvm = NULL;
	JNIEnv *penv = NULL;       /* pointer to native method interface */

	JavaVMInitArgs vm_args; /* JDK/JRE 6 VM initialization arguments */
	JavaVMOption* options = new JavaVMOption[1];
	options[0].optionString = "-Djava.class.path=/usr/lib/java";
	options[0].extraInfo = NULL;

	vm_args.version = JNI_VERSION_1_6;
	vm_args.nOptions = 1;
	vm_args.options = options;
	vm_args.ignoreUnrecognized = false;
	/* load and initialize a Java VM, return a JNI interface
	 * pointer in env */
	jint result = JNI_CreateJavaVM(&pjvm, (void **)&penv, &vm_args);

	jvm = RawJavaVM( IntPtr(pjvm) );
	env = RawJNINativeInterface( IntPtr(penv) );
	delete[] options;

	return result;
}

jint RawJavaVM::DestroyJavaVM()
{
	return GetJVM()->DestroyJavaVM();
}

jint RawJavaVM::AttachCurrentThread( [Runtime::InteropServices::Out] RawJNINativeInterface %env, RawJavaVMAttachArgs ^args )
{
	jint result;
	void *envptr = NULL;

	if(args == nullptr)
	{
		result = GetJVM()->AttachCurrentThread( &envptr, NULL );
	}
	else
	{
		JavaVMAttachArgs a;
		StringToModifiedUTF8Adapter name(args->name);
		a.group = args->group;
		a.name = (char *)(name.operator const char *());
		a.version = args->version;
		result = GetJVM()->AttachCurrentThread( &envptr, (void *)&a );
	}

	env = RawJNINativeInterface( IntPtr( envptr ) );
	return result;
}

jint RawJavaVM::DetachCurrentThread() 
{
	return GetJVM()->DetachCurrentThread();
}

jint RawJavaVM::GetEnv([Runtime::InteropServices::Out] RawJNINativeInterface %env, jint version) 
{
	void *envptr = NULL;
	int result = GetJVM()->GetEnv( &envptr, version );
	env = RawJNINativeInterface( IntPtr( envptr ) );
	return result;
}

jint RawJavaVM::AttachCurrentThreadAsDaemon([Runtime::InteropServices::Out] RawJNINativeInterface %env)
{
	void *envptr = NULL;
	jint result = GetJVM()->AttachCurrentThreadAsDaemon( &envptr, NULL );
	env = RawJNINativeInterface( IntPtr( envptr ) );
	return result;
}

	} // namespace Raw
} // namespace MikJNI
