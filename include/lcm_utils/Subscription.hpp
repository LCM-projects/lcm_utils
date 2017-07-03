//
// Created by andreanistico on 29/06/17.
//

#ifndef LCM_UTILS_SUBSCRIPTION_HPP
#define LCM_UTILS_SUBSCRIPTION_HPP

#include <include/msg/test/test.hpp>
#include "lcm_utils/AbstractSubscription.h"
#include "lcm_utils/CallbackBase.hpp"
namespace lcmutils {

    template<class T>
    class Subscription : public AbstractSubscription {

    public:

        Subscription(const std::string &topic_, const int timeout = 0) : AbstractSubscription(topic_, timeout) {}

        CallbackBase<T> call_;

        void init(int queue=1) {

            //Open LCM channel
            lcm::Subscription *s = handler_.subscribe(topic_,&CallbackBase<T>::callBackFun,&call_);
            s->setQueueCapacity(queue);

            //Init File descriptor

            fds[0].fd = handler_.getFileno();
            fds[0].events = POLLIN;
        }

        bool isUpdated() {
            bool t = updated_;
            updated_ = false;
            return t;
        }

        lcm::LCM* getHandler(){
            return &handler_;
        }
    };
}
#endif //LCM_UTILS_SUBSCRIPTION_HPP
