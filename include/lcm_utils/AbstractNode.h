#ifndef LCM_UTILS_LIBRARY_H
#define LCM_UTILS_LIBRARY_H

#include <iostream>
#include <vector>
#include <memory>
//#include "Subscription.h"
#include "Subscription.hpp"

namespace lcmutils {
    typedef std::shared_ptr<SubscriptionBase> subsription_ptr;
    //Abstract node class
    class AbstractNode {

    protected:

        std::string name_;
        std::vector<subsription_ptr> subscriptions_;

    public:
        AbstractNode(const std::string &name_);

        virtual void pollSubscriptions() = 0;

    };//AbstractNode

} //lcmutils

#endif