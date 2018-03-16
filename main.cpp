#include "main.h"

 //extern "C"{

    JNIEXPORT jint JNICALL Agent_OnLoad(JavaVM *jvm, char *options,void *reserved)
    {
        printf("my jvm call staring..");
        jvmtiEnv *jvmti;
        jint result = jvm->GetEnv((void **) &jvmti, JVMTI_VERSION_1_1);
        if (result != JNI_OK)
        {
            printf("ERROR: Unable to access JVMTI!\n");
        }
        jvmtiError err = (jvmtiError) 0;
        jclass *classes;
        jint count;

        err = jvmti->GetLoadedClasses(&count, &classes);
        if (err)
        {
            printf("ERROR: JVMTI GetLoadedClasses failed!\n");
        }
        for (int i = 0; i < count; i++)
        {
            char *sig;
            jvmti->GetClassSignature(classes[i], &sig, NULL);
            printf("cls sig=%s\n", sig);
        }
        printf("my jvm call end..");
        return err;
    }
//}
JNIEXPORT void JNICALL Agent_OnUnload(JavaVM *vm)
{
    printf("my jvm Agent_OnUnload");
}
