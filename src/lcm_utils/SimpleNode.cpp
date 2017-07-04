//
// Created by andreanistico on 03/07/17.
//

#include "include/lcm_utils/SimpleNode.h"
namespace lcmutils {

    void SimpleNode::pollSubscriptions() {
        for (auto i = subscriptions_.begin(); i != subscriptions_.end(); ++i) {
            (*i).get()->pollMe();
        }
    }
    SimpleNode::SimpleNode(const std::string &name_) : AbstractNode(name_) {}

}