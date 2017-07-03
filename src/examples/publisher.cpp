//
// Created by andreanistico on 03/07/17.
//

#include <iostream>
#include "lcm/lcm-cpp.hpp"
#include "poll.h"
#include "lcm_utils/Subscription.hpp"
#include "msg/test/test.hpp"

int main(int argc, char** argv){


    lcm::LCM h;


    test::test t;
    double u = 10.4;
    t.field = u;
    t.field2 = 1;
    t.field3[0] = 0;
    t.field3[1] = 1;
    t.field3[2] = 2;
    t.field3[3] = 3;
    t.t = 6;
    h.publish("test",&t);

    return 0;

}