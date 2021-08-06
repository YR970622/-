#include <iostream>
using namespace std;

class Singleton{
    Singleton();
    ~Singleton();
    Singleton(const Singleton &);
    Singleton &operator(const Singleton &);

public:

    static Singleton &getInstance(){
        static Singleton obj;
        return obj;
    }
};