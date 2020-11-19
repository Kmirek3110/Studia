#include <iostream>
#include <type_traits>
#include <string>

using namespace std;


template<typename From, typename To>
void  move_to_extra(From val, To& rec, true_type){
    if(is_convertible<typename remove_pointer<From>::type,To>::value){
        rec = (To&&)move(*val);
        cout<<"Convertion and move with pointer succesfuly"<<endl;
        return ;      
    };
    cout<<"Failed to convert"<<endl;
}

template<typename From, typename To>
void move_to_extra(From& val, To& rec, false_type){
    if(is_convertible<From,To>::value){
        cout<<"Move and convertion without pointer sucessfuly"<<endl;
        rec = (To&&)(move(val));
        return ;
    }
    cout<<"Failed to convert"<<endl;
}



template<typename From, typename To>
void move_to(From val, To& rec){
    move_to_extra(val, rec, is_pointer<From>());
}


int main(){
    string s0 = "abc123";
    string s1 = "qwe890";

    string s2;
    string* s3 = new string ("123abc");

    move_to(s1, s2);

    cout<<"Test1"<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;

    cout<<"Test2"<<endl;
    move_to(s3,s2);
    cout<<s3<<endl;
    cout<<s2<<endl;
    
    struct A{};
    struct B { A a; operator A() {return a;}};
    A a;
    B b;

    move_to(b,a);

    return 0;
}