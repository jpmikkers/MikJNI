#pragma unmanaged
#include <string>
#include <memory>
#include <vector>
#include "jni.h"

#pragma managed
#include "JavaVM.h"
#include "JNIEnv.h"
#include "StringToModifiedUTF8Adapter.h"

using namespace System;
using namespace System::Text;
using namespace System::Runtime::InteropServices;

// the following two structs are provided to prevent linker warnings. jni.h makes a forward declaration for them,
// but doesn't actually define them.
struct _jfieldID
{
};

struct _jmethodID
{
};

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
	[Runtime::InteropServices::Out] RawJNINativeInterface %env,
	RawJavaVMInitArgs ^args )
{
	JavaVM *pjvm = NULL;
	JNIEnv *penv = NULL;

	// use default parametes if args is null
	if( args == nullptr ) args = gcnew RawJavaVMInitArgs();

	JavaVMInitArgs vm_args;
	vm_args.version = (jint)args->version;
	vm_args.nOptions = args->options->Count;
	vm_args.options = new JavaVMOption[args->options->Count];
	vm_args.ignoreUnrecognized = false;

	for(int t=0;t<args->options->Count;t++)
	{
		RawJavaVMOption ^item = args->options->default[t];
		vm_args.options[t].optionString = (char*)Marshal::StringToHGlobalAnsi(item->optionString).ToPointer();
		vm_args.options[t].extraInfo = item->extraInfo.ToPointer();
	}

	// load and initialize a Java VM, return a JNI interface pointer in env
	jint result = JNI_CreateJavaVM(&pjvm, (void **)&penv, &vm_args);
	jvm = RawJavaVM( IntPtr(pjvm) );
	env = RawJNINativeInterface( IntPtr(penv) );

	// free the option strings and array that we allocated above
	for(int t=0;t<args->options->Count;t++)
	{
		Marshal::FreeHGlobal(IntPtr(vm_args.options[t].optionString));
	}
	delete[] vm_args.options;

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
		a.version = (jint)args->version;
		result = GetJVM()->AttachCurrentThread( &envptr, (void *)&a );
	}

	env = RawJNINativeInterface( IntPtr( envptr ) );
	return result;
}

jint RawJavaVM::DetachCurrentThread() 
{
	return GetJVM()->DetachCurrentThread();
}

jint RawJavaVM::GetEnv([Runtime::InteropServices::Out] RawJNINativeInterface %env, RawJNIVersion version) 
{
	void *envptr = NULL;
	int result = GetJVM()->GetEnv( &envptr, (jint)version );
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
