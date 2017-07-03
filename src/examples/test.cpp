//
// Created by andreanistico on 27/06/17.
//

#include <iostream>
#include "lcm/lcm-cpp.hpp"
#include "poll.h"
#include "lcm_utils/Subscription.hpp"
#include "msg/test/test.hpp"

int main(int argc, char** argv){

    lcmutils::Subscription<test::test> s("test");
    s.init();

    while (0==s.getHandler()->handle()){



    }

    /*
    while (0==s.handler_.handle()) {
        s.pollMe();

        test::test t;




        std::cout << t.field << std::endl;
    }
     */
}