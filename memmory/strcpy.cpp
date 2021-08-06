#include <iostream>
using namespace std;

char *strcpy(char *des,const char *src){
    if(des == nullptr || src == nullptr || des == src){
        return nullptr;
    }

    if(src < des && des <= src+ strlen(src)){               //内存重叠时,拷贝过程中会导致'\0'字符丢失
        // memmove(des, src, strlen(src)+1);                //memcpy自带内存重叠检测功能
        int len=strlen(src);
        const char *psrc=src+len;
        char *pdes = des+len;
        for(int i=0;i<=len;++i){
            *pdes-- = *psrc--;
        }
    }else{
        char *pdes=des;
        while(*src!='\0'){
            *pdes++ = *src++;
        }
        *pdes = '\0';
    }
    return des;
}