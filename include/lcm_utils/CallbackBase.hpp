//
// Created by andreanistico on 29/06/17.
//

#ifndef LCM_UTILS_CALLBACKBASE_H
#define LCM_UTILS_CALLBACKBASE_H
#include <iostream>
#include "msg/test/test.hpp"
#include "lcm/lcm-cpp.hpp"
namespace lcmutils {
    template<class T>
    class CallbackBase {
    private:
        T data_;

    public:
        CallbackBase(){}

        void callBackFun(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const test::test *msg) {
            data_ = *msg;
        }

        T getData() {
            return data_;
        }
    };
}
#endif //LCM_UTILS_CALLBACKBASE_H
