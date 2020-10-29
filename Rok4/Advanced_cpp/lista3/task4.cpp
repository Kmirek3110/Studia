#include <iostream>
#include <type_traits>
#include <string>

using namespace std;


template<typename From, typename To>
void  foo_impl(From val, To& rec, true_type){
    if(is_convertible<typename remove_pointer<From>::type,To>::value){
        // cout<<*val<<" val "<< endl;
        // cout<<rec<<" rec "<<endl;
        rec = (To&&)move(*val);
        // cout<<*val<<" val "<< endl;
        // cout<<rec<<" rec "<<endl;
        cout<<"UDało sie ze wskaznikiem"<<endl;
        val = nullptr;
        return ;
        
    };
    cout<<"NIe da sie tego skonwertowac"<<endl;
}

template<typename From, typename To>
void foo_impl(From& val, To& rec, false_type){
    if(is_convertible<From,To>::value){
        // cout<<val<<" val "<< endl;
        // cout<<rec<<" rec "<<endl;
        // cout<<&val<<endl;
        cout<<"Udalo sie bez wskaznika"<<endl;
        rec = (To&&)(move(val));
        // cout<<val<<" val "<< endl;

        return ;
    }
    cout<<"NIe da sie tego skonwertowac"<<endl;
}



template<typename From, typename To>
void foo(From val, To& rec){
    foo_impl(val, rec, is_pointer<From>());
}


int main(){
    string s0 = "abc123";
    string s1 = "qwe890";

    string s2;
    string* s3 = new string ("123abc");

    foo(s1, s2);

    cout<<"Test1"<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;

    cout<<"Test2"<<endl;
    foo(s3,s2);
    cout<<s3<<endl;
    cout<<s2<<endl;
    
    struct A{};
    struct B { A a; operator A() {return a;}};
    A a;
    B b;

    foo(b,a);

    return 0;
}