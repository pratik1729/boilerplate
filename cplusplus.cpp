#include<iostream>
#include<cmath>
#include <memory>
#include <thread>
#include <chrono>
#define log(s,x) std::cout<<#s<<" "<<(x)<<std::endl

namespace array_decay{
    void p_size(int *arr){
        log(pass as pointer: size is, sizeof(arr)); //decays
    }

    void arr_size(int arr[4]){
        log(pass as array: size is, sizeof(arr)); //decays
    }

    void arr_ref_size(int (&arr)[4]){
        log(pass as ref array: size is, sizeof(arr)); //does not decay
    }

    void arr_dec(){
        int arr[4]={0,1,2,3};
        log(direct size is, sizeof(arr));
        p_size(arr);
        arr_ref_size(arr);
        arr_size(arr);
    }
}

namespace pointer{
    void null(){
        log(NULL is, NULL);
    }
    void null_ptr(){
        int *x1 = nullptr;
        int *x2 = nullptr;
        log(Two nullptrs are equal:,x1==x2);
    }

    class A{
        int x;
        public:
        A(int x){
            this->x = x;
        }
        void showData()
        {   
            log(x is,this->x);
        }
    };
    std::unique_ptr<A> fun_uniq(){
        std::unique_ptr<A> p(new A(2));
        log(p is:,p.get()); //get() address of resource
        std::unique_ptr<A> p2 = std::move(p); //transfer ownership to p2,
        log(p after move() is:,p.get()); //p will be 0 now
        return (p2); //the return value must be explictly captured otherwise p will be freed
    }
    void fun_shared(std::shared_ptr<A> p){ //pass by value increases ref count
        p->showData();
        log(pass by value: count is,p.use_count()); //#references to the resource
        p.reset(); //give up ownership
    }
    void sharedptr(){
        std::shared_ptr<A> p1(new A(1));
        p1->showData();
        std::shared_ptr<A> p2(p1);
        p2->showData();
        log(count is,p2.use_count());
        fun_shared(p2);
        log(count after reset is,p2.use_count());
    }
    void uniqueptr(){
        log(p2 is,fun_uniq().get());
    }

}

namespace math{
    void complex(){
        float a = sqrt(-2);
        std::cout<<a; //output is nan
    }
}

namespace _const{
    void constFun(){

        const int a = 9;
        //a=0; run time error
        int b = 0;
        int d = 8;
        const int c = b; //can be assigned only once
        log(c is , c);
        //const int d; must be innitialized otherwise compile time error (CTE)

        const int* bptr1 = &b;
        b++;
        log(b is,b);
        //*bptr = 3; CTE, bptr location is read only location
        bptr1 = &d; //bptr can be reassigned

        int* bptr2 = &b;
        *bptr2 = 3; //bptr2 location is writable. A location is readable or writable depends on the type of pointer to that location
        log(b is,b);

        int* const dptr1 = &d;
        d++;
        log(d is, d); //works
        (*dptr1)++; //works
        log(d is, d);
        //dptr1 = &b; dptr1 is read only variable, dptr1 cannot be reassigned

        int e = 7;
        const int* const eptr = &e;
        //eptr = &b; CTE, eptr is read only variable, eptr cannot be reassigned
        //(*eptr)++; eptr location is read only.

        //int* cptr = &a; //CTE, int* cannot point to const int*, a is const int type
        const int* cptr = &a;
        //(*cptr)++; CTE as location is read only
        //int* const cptr1 = &a; CTE, int* cannot point to const int*, a is const int type

    }
}

namespace cast{

    class Base{

        private:
        int a;

        public:
        int b;

        Base(int i, int j) : a(i),b(j){
            log(constructor called,a);
        }
        

    };

    class Derived : public Base {

        public:
        int c;
        Derived(){
            
        }

    };

    void stat_cast(){
        Base b(3,4);
        Derived d;
        d.b = 100;
        log(d is,d.b);       
        return;     

        float f = 7.9;
        int a = static_cast<int>(f); //compile time cast
        log(f is, f);
        log(a is, a);     
    }    

}
int main(){
    //array_decay::arr_dec();
    //pointer::sharedptr();
    //math::complex();
    cast::stat_cast();
  
//     for (int i = 1; i <= 5; ++i)
//    {
//       std::cout << i << " " << std::flush; //flush is required because cout is line buffered
//       std::this_thread::sleep_for(std::chrono::seconds(1));
//    }
}

//name of an array is a constant pointer to the first element of the array. so it cannot be changedl like arr++
//two nullptrs are always equal. nullptr is convertible to bool
//float variable can store nan. Two nan are not equal