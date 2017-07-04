//
// Created by andreanistico on 27/06/17.
//

#ifndef LCM_UTILS_SUBSCRIPTION_H
#define LCM_UTILS_SUBSCRIPTION_H

#include <iostream>
#include <memory>
#include "lcm/lcm-cpp.hpp"
#include "poll.h"
#include "lcm_utils/CallbackBase.hpp"


namespace lcmutils {
    class SubscriptionBase {

    public:

        SubscriptionBase(const std::string &topic_, const int timeout) : topic_(topic_),
                                                                         updated_(false),
                                                                         timeout_(timeout) {}
        /*
        Returns the number of file descriptors with events, zero if timed out,
        or -1 for errors.
        */
        virtual int pollMe(){
            int ret = poll(fds, 1, timeout_);
            updated_ = false;

            if (fds[0].revents & POLLIN) {
                handler_.handle();
                updated_ = true;
            }
            return ret;
        }
        virtual bool updated(){
            return updated_;
        }
        template <class T>
        const T& getData() const;

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



    //Subscription Derived
    template<class T>
    class Subscription : public SubscriptionBase {

    public:

        Subscription(const std::string &topic_, const int timeout = 0, const int queue = 1) : SubscriptionBase(topic_, timeout) {
            init(queue);
        }

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

        const T& getData() const {
            return call_.getData();
        }

    };

    template <class T>
    const T& SubscriptionBase::getData() const {
        return dynamic_cast<const Subscription<T>&>(*this).getData();
    }



}
#endif //LCM_UTILS_SUBSCRIPTION_H
