//
// Created by andreanistico on 27/06/17.
//

#include <iostream>
#include "lcm/lcm-cpp.hpp"
#include "lcm_utils/Subscription.hpp"
#include "msg/test/test.hpp"
#include "lcm_utils/SimpleNode.h"
#include "TimeHelpers.hpp"


int main(int argc, char** argv){

    lcmutils::SimpleNode node("test_node");
    lcmutils::SubscriptionBase* sub = node.addSubscription<test::test>("test");
    lcmutils::SubscriptionBase* sub2 = node.addSubscription<test::test>("test2");

    node.pollSubscriptions();

    Spinner sp(2);
    while (sp.ok()){

        node.pollSubscriptions();

        if (sub->updated()){
            // be aware, sub must be updated in order to getData, no control is done
            test::test rec  = sub->getData<test::test>();
            std::cout << rec.field3[2] << std::endl;
        }



    }

}