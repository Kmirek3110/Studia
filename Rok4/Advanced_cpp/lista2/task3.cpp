#include <iostream>
#include <memory>



int main(){

    std::weak_ptr<int> weak;
   
    {
        auto shared = std::make_shared<int>(42);
        weak = shared;
        std::cout<<"Weak pointer has been initialized with shared_pntr"<<std::endl;
        std::cout<<*weak.lock()<<std::endl;
    }

    std::cout << "shared_ptr<> has been destructed due to scope exit.\n";
    std::cout<<*weak.lock();

    return EXIT_SUCCESS;
}