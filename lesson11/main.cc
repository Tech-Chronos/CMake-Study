#include <iostream>
#include "proto/person.pb.h"
int main()
{
    example::Person p;
    p.set_name("dsj");
    p.set_id(123);
    p.set_email("dongsijie8@gmail.com");

    std::cout << p.name() << " " << p.id() << " " << p.email() << std::endl;
    return 0;
}