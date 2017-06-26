#include <jni.h>
#include <stdlib.h>



/**
 * 把一个jstring转换成一个c语言的char* 类型.
 */
char* _JString2CStr(JNIEnv* env, jstring jstr) {
	 char* rtn = NULL;
	 jclass clsstring = (*env)->FindClass(env, "java/lang/String");
	 jstring strencode = (*env)->NewStringUTF(env,"GB2312");
	 jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
	 jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid, strencode); // String .getByte("GB2312");
	 jsize alen = (*env)->GetArrayLength(env, barr);
	 jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
	 if(alen > 0) {
		rtn = (char*)malloc(alen+1); //"\0"
		memcpy(rtn, ba, alen);
		rtn[alen]=0;
	 }
	 (*env)->ReleaseByteArrayElements(env, barr, ba,0);
	 return rtn;
}
/*
 * Class:     com_itheima_wordprocess_MainActivity
 * Method:    encodeInC
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_xiaopengwang_textmanagendkdemo_MainActivity_encodeInC
  (JNIEnv * env, jobject obj, jstring jstr){
	//把jstring类型字符串转化成 c能够处理的char* 类型
	char* cstr = _JString2CStr(env,jstr);
	int length = strlen(cstr);
	int i;
	for(i = 0; i<length; i++){
		*(cstr+i) += 2;
	}
	return (*env)->NewStringUTF(env,cstr);
}

/*
 * Class:     com_itheima_wordprocess_MainActivity
 * Method:    decodeInC
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_xiaopengwang_textmanagendkdemo_MainActivity_decodeInC
  (JNIEnv * env, jobject obj, jstring jstr){
	char* cstr = _JString2CStr(env,jstr);
		int length = strlen(cstr);
		int i;
		for(i = 0; i<length; i++){
			*(cstr+i) -= 2;
		}
		return (*env)->NewStringUTF(env,cstr);
}
