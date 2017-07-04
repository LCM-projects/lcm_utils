//
// Created by andreanistico on 03/07/17.
//

#ifndef LCM_UTILS_SIMPLENODE_H
#define LCM_UTILS_SIMPLENODE_H

#include "lcm_utils/AbstractNode.h"
namespace lcmutils{

class SimpleNode : public AbstractNode {

public:

    SimpleNode(const std::string &name_);
    void pollSubscriptions() override;
    template <class T>

    SubscriptionBase* addSubscription(std::string name, int timeout = 0, int queue = 1) {
        auto p = std::shared_ptr <SubscriptionBase> (new Subscription<T>(name,timeout,queue));
        subscriptions_.push_back(p);
        return p.get();
    }

};

}

#endif //LCM_UTILS_SIMPLENODE_H
