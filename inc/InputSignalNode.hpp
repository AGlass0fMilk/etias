/*
 * InputSignalNode.h
 *
 *  Created on: Mar 12, 2020
 *      Author: gdbeckstein
 */

#ifndef ETIAS_INC_INPUTSIGNALNODE_HPP_
#define ETIAS_INC_INPUTSIGNALNODE_HPP_

#include "SignalNode.hpp"

#include "Callback.h"

namespace etias
{

    template<typename T, int SampleRate = SAMPLE_RATE_UNDEFINED>
    class InputSignalNode : public SignalNode
    {
    public:

        InputSignalNode(mbed::Callback<void(T)> cb) : input_cb(cb) { }

        void process(T arg) {
            input_cb(arg);
        }

    protected:

        mbed::Callback<void(T)> input_cb;
    };

}


#endif /* ETIAS_INC_INPUTSIGNALNODE_HPP_ */
