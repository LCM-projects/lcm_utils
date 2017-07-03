#ifndef LCM_UTILS_LIBRARY_H
#define LCM_UTILS_LIBRARY_H

#include <iostream>
#include <vector>
#include <memory>
#include "AbstractSubscription.h"

namespace lcmutils {
    typedef std::shared_ptr<AbstractSubscription> subsription_ptr;
    //Abstract node class
    class AbstractNode {

    private:

        std::string name_;
        std::vector<subsription_ptr> subscriptions_;

    public:

        virtual void pollSubscriptions() = 0;
        virtual void pollSubscription(int p)  = 0;
        virtual int  addSubscription(std::string name, int timeout = 0) = 0;
        virtual void removeSubscription() = 0;


    };//AbstractNode

} //lcmutils

#endif