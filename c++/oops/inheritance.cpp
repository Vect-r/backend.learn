#include <iostream>
using namespace std;

class A{
    public:
    void a(){
        cout<<"I am from class A"<<endl;
    }
};

class B: public A{
    public:
    void b(){

        cout<<"I am from class B"<<endl;
    }
};

int main() {
    B obj;
    obj.a();
    obj.b();
    return 0;
}

------------------------------------------------------------------------------
#include <iostream>
using namespace std;

class A{
    protected:
    void a(){
        cout<<"I am from class A"<<endl;
    }
};

class B: public A{
    public:
    void b(){
        a();
        cout<<"I am from class B"<<endl;
    }
};

int main() {
    B obj;
    // obj.a();
    obj.b();
    return 0;
}

------------------------------------------------------------------------------
#include <iostream>
using namespace std;

class A{
   public:
    void a(){
        cout<<"I am from class A"<<endl;
    }
};

class B: public A{
    public:
    void b(){
        cout<<"I am from class B"<<endl;
    }
};
class C: public B{
    public:
    void c(){
        cout<<"I am from class C"<<endl;
    }
};

int main() {
    C obj;
    obj.a();
    obj.b();
    obj.c();
    return 0;
}
------------------------------------------------------------------------------

#include <iostream>
using namespace std;

class A{
   public:
    void a(){
        cout<<"I am from class A"<<endl;
    }
};

class B{
    public:
    void b(){
        cout<<"I am from class B"<<endl;
    }
};
class C: public A, public B{
    public:
    void c(){
        cout<<"I am from class C"<<endl;
    }
};

int main() {
    C obj;
    obj.a();
    obj.b();
    obj.c();
    return 0;
}
------------------------------------------------------------------------------