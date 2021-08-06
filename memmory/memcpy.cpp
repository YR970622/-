#include <iostream>


// 如果源和目标重叠，这个函数不能确保重叠区域的原始源字节在被覆盖之前被复制
// memmove在内存重叠时，可确保内存正确拷贝，未重叠时，memmove和memcpy作用相同
//以下memcpy的实现其实是memmove的实现
void *memcpy(void *des, const void *src , size_t n){
    if(des == nullptr || src == nullptr || n==0 || des == src){
        return;
    }

    char *pdes = (char *)des;                           //空指针只有在类型转换后才能使用
    char *psrc = (char *)src;

    if(pdes > psrc && pdes < psrc + 10){                //覆盖情况，从高地址开始复制
        pdes = pdes + n - 1;
        psrc = psrc + n - 1;
        while(n--){
            *pdes-- = *psrc--;
        }   
    }else{                                              //正常情况，从低地址开始复制
        while(n--){                                     
            *pdes++ = *psrc++;
        }
    }

    return des;
}

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


// 对des开始的n个字节空间进行初始化，赋值为c
void memset(void *des, int c, size_t n){

}