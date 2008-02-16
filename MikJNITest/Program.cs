using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using MikJNI;
using MikJNI.Raw;

namespace MikJNITest
{
    class Program
    {
        static void Main(string[] args)
        {            
            RawJavaVM vm;
            RawJNINativeInterface env;

            if( RawJavaVM.CreateJavaVM( out vm, out env ) == RawJNIResultCodes.OK )
            {
                RawJavaVMAttachArgs vmargs = new RawJavaVMAttachArgs();
                vmargs.group = IntPtr.Zero;
                vmargs.name = null;
                vmargs.version = RawJNIVersion.VERSION_1_6;

                Console.WriteLine("It's ok");
                Console.WriteLine("Result of attachcurrentthread {0}", vm.AttachCurrentThread(out env, vmargs));

                Rawjstring js = env.NewString("Test");
                Console.WriteLine("Contents of javastring: '{0}', length {1}, type {2}", env.GetStringChars(js), env.GetStringLength(js), env.GetObjectRefType( new Rawjobject(js) ) );

                Rawjclass clinet = env.FindClass("java/net/InetAddress");
                Console.WriteLine("class {0}", (IntPtr)clinet);
                RawjmethodID methodid = env.GetStaticMethodID(clinet, "getByName", "(Ljava/lang/String;)Ljava/net/InetAddress;");
                Console.WriteLine("method {0}", (IntPtr)methodid);

                PJValue v = new PJValue();
                v.l = new Rawjobject( env.NewString("localhost") );

                //paraams.Add( 
                Rawjobject result = env.CallStaticObjectMethod(clinet, methodid, new PJValue[]{ v });
                Console.WriteLine("result {0}", (IntPtr)result);

                vm.DestroyJavaVM();
                Console.WriteLine("destroyed");
                Console.ReadLine();
            }
        }
    }
}
