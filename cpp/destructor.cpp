#include <iostream>
#include <string>

class Example4 {
        std::string* ptr;
    public:
        Example4 (): ptr(new std::string) {};
        Example4 (const std::string& str) {ptr=new std::string; *ptr=str;};
        ~Example4 () {delete ptr;};

        const std::string& content() const {return *ptr;}
};

int main () {
    Example4 foo;
    Example4 bar ("Example");
    std::cout << "bar's content: " << bar.content() << std::endl;
    return 0;
}