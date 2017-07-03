//
// Created by andreanistico on 27/06/17.
//

#ifndef LCM_UTILS_SUBSCRIPTION_H
#define LCM_UTILS_SUBSCRIPTION_H

#include <iostream>
#include <memory>
#include "lcm/lcm-cpp.hpp"
#include "poll.h"

namespace lcmutils {
    class AbstractSubscription {

    public:

        AbstractSubscription(const std::string &topic_, const int timeout = 0);
        /*
        Returns the number of file descriptors with events, zero if timed out,
        or -1 for errors.
        */
        virtual int pollMe();

    protected:
        lcm::LCM handler_;
        std::string topic_;
        struct pollfd fds[1];
        /*
        If TIMEOUT is nonzero and not -1, allow TIMEOUT milliseconds for
        an event to occur; if TIMEOUT is -1, block until an event occurs
        */
        int timeout_;
        bool updated_;

    };
}
#endif //LCM_UTILS_SUBSCRIPTION_H
