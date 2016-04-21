#include <iostream>

struct cookie{
    std::string flavor;
    std::string *toppings = nullptr;
    std::string *fillings = nullptr;
};

// This looks similar to
class Cookie{
private:
    std::string _flavor;
    std::string *_toppings = nullptr;
    std::string *_fillings = nullptr;

    bool validate_flavor(){
        return this->getFlavor() == "chocolate chip";
    }
public:
    std::string getFlavor(){
        return _flavor;
    }
    void setFlavor(std::string flava){
        _flavor = flava;
    }
    bool isValid(){
        return this->validate_flavor();
    }
};

// Passed in as a pointer
// Look at the invocation below to see the implications of pass by reference vs pass by value
Cookie print_cookie(Cookie *cookie){
    cookie->getFlavor();
    return *cookie;
}

// Passed by reference
// Look at the invocation below to see the implications of pass by reference vs pass by value
Cookie print_cookie_by_reference(Cookie cookie){
    cookie.getFlavor();
    return cookie;
}

void test_it_out(){
    // A Struct Instance
    cookie snickerdoodle;
    snickerdoodle.flavor = "snickers";

    // A Class instance (Notice the C in Cookie they are different)
    Cookie choco_chippy;

    // We access all private fields through an accessor method
    choco_chippy.setFlavor("NOODLE");
    std::string the_flava = choco_chippy.getFlavor();

    std::cout << the_flava << std::endl;

    // Part of the public api (it will call things from the private api)
    bool is_it_choco = choco_chippy.isValid();
    std::cout << is_it_choco << std::endl;

    Cookie cookie2 = print_cookie(&choco_chippy);

    Cookie cookie3 = print_cookie_by_reference(choco_chippy);
}

int main(){
    test_it_out();
}
