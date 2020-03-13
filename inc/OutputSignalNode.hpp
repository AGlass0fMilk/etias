/*
 * OutputSignalNode.h
 *
 *  Created on: Mar 12, 2020
 *      Author: gdbeckstein
 */

#ifndef ETIAS_OUTPUTSIGNALNODE_HPP_
#define ETIAS_OUTPUTSIGNALNODE_HPP_

#include "SignalNode.hpp"
#include "InputSignalNode.hpp"

#include "extensions/CallChain.h"

namespace etias
{
    template<typename T, int SampleRate = SAMPLE_RATE_UNDEFINED>
    class OutputSignalNode : public SignalNode
    {

    public:

        /**
         * Connect the given signal node to the output of
         * this signal node
         *
         * @param[in] input Input node to connect to
         */
        void connect(InputSignalNode<T, SampleRate> input_node) {
            output_chain.attach(mbed::callback(&input_node, &InputSignalNode<T, SampleRate>::process));
        }

        /**
         * Disconnect the given signal node from the output of
         * this signal node
         *
         * @param[in] input Input node to disconnect from
         */
        void disconnect(InputSignalNode<T, SampleRate> input_node) {
            output_chain.detach(mbed::callback(&input_node, &InputSignalNode<T, SampleRate>::process));
        }

        void notify(T arg) {
            output_chain.call(arg);
        }

    protected:

        ep::CallChain<T> output_chain;

    };
}

#endif
