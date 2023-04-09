#include <iostream>
#include <string>

class Example5 {
        std::string* ptr;
    public:
        Example5 (const std::string& str) {ptr=new std::string; *ptr=str;}
        ~Example5 () {delete ptr;}
        const std::string& content() const {return *ptr;}
        // copy constructor
        Example5 (const Example5& x) {ptr=new std::string; *ptr=x.content();}
};

int main () {
    Example5 foo ("Example");
    Example5 bar = foo;
    std::cout << "bar's content: " << bar.content() << std::endl;
    return 0;
}