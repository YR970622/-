#include <iostream>
using namespace std;

template <class T>
class Shared_ptr{
    Shared_ptr(T *p);
    ~Shared_ptr();
    Shared_ptr(const Shared_ptr<T> &rhs);
    Shared_ptr<T> &operator=(const Shared_ptr<T> &rhs);

private:
    T *ptr;
    int *use_count;
};

template <class T>
Shared_ptr<T>:: Shared_ptr(T *p){
    if(p){
        ptr = p;
        use_count = new int(1);
    }
}

template <class T>
Shared_ptr<T>:: ~Shared_ptr(){
    if(use_count && --(*use_count)==0){
        delete ptr;
        delete use_count;
        pte = nullptr;
        use_count = nullptr;
    }
}

template <class T>
Shared_ptr<T>:: Shared_ptr(const Shared_ptr<T> &rhs){
    ptr = rhs.ptr;
    use_count = rhs.use_count;
    ++(*use_count);
}

template <class T>
Shared_ptr<T>& Shared_ptr<T>::operator=(const Shared_ptr<T> &rhs){
    ++(*rhs.use_count);

    if(--(*use_count)==0){
        delete ptr;
        delete use_count;
    }

    ptr = rhs.ptr;
    use_count = rhs.use_count;
}

int main(){
    int *p=new int(1);
    Shared_ptr<int> p1(p);

}
