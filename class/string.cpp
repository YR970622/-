#include <iostream>
using namespace std;

class String{
public:
    String():_p(nullptr), _len(0){
        _p = new char[1];
        _p[0] = '\0';
    }

    String(const char *str): _p(nullptr) , _len(0){
        if(str==nullptr){
            _p = new char[1];
            _p[0] = '\0';
        }else{
            _p = new char[strlen(str)+1];
            memmove((void*)_p, str, strlen(str)+1);
        }
    }

    ~String(){
        if(_p != nullptr){
            delete [] _p;
        }
        _p = nullptr;
        _len = 0;
    }

    String(const String &rhs){
        _len = strlen(rhs._p);
        _p = new char[_len + 1];
        strcpy(_p,rhs._p);
    }
    
    String &operator=(const String &rhs){
        if(this != &rhs){
            if(_p){
                delete [] _p;
            }
            _len = rhs._len;
            _p =new char[_len+1];
            strcpy(_p,rhs._p);
        }
        return *this;
    }

    const char *c_str() const{
        return _p;
    }

    size_t length() const{
        return _len;
    }

private:
    char *_p;
    size_t _len;
};