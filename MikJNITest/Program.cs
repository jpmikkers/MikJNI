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

            // create the Java VM with default parameters
            if( RawJavaVM.CreateJavaVM( out vm, out env, new RawJavaVMInitArgs() ) == RawJNIResultCodes.OK )
            {
                Console.WriteLine("Java VM created");

                // create a raw java string, and probe some of its properties
                Rawjstring js = env.NewString("Test");
                Console.WriteLine("Contents of javastring: '{0}', length {1}, type {2}", env.GetStringChars(js), env.GetStringLength(js), env.GetObjectRefType( new Rawjobject(js) ) );
                // unref the java string
                env.DeleteLocalRef(new Rawjobject(js));

                vm.DestroyJavaVM();
                Console.WriteLine("VM destroyed");
            }
        }
    }
}
