#include <iostream>
#include <string>

class Example {
    std::string element;
    public:
        Example (const std::string& data) {element=data;};
        Example () {};
        const std::string& getstring () {return element;}

};

int main () {
    Example foo;
    Example bar ("Example");
    std::cout << "bar's content: " << bar.getstring() << std::endl;
    return 0;
}
