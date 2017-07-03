//
// Created by andreanistico on 27/06/17.
//

#include "include/lcm_utils/AbstractSubscription.h"
namespace lcmutils {
    AbstractSubscription::AbstractSubscription(const std::string &topic_, const int timeout) : topic_(topic_),
                                                                                               updated_(false),
                                                                                               timeout_(timeout) {}

    int AbstractSubscription::pollMe() {

        int ret = poll(fds, 1, timeout_);
        updated_ = false;

        if (fds[0].revents & POLLIN) {
            handler_.handle();
            updated_ = true;
        }
        return ret;

    }

}