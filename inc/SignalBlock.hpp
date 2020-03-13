/*
 * SignalBlock.hpp
 *
 *  Created on: Mar 12, 2020
 *      Author: gdbeckstein
 */

#ifndef ETIAS_INC_SIGNALBLOCK_HPP_
#define ETIAS_INC_SIGNALBLOCK_HPP_


#include "InputSignalNode.hpp"
#include "OutputSignalNode.hpp"

#include "mbed_assert.h"

namespace etias
{

    template<typename InT, typename OutT, int InSampleRate = SAMPLE_RATE_UNDEFINED,
            int OutSampleRate = SAMPLE_RATE_UNDEFINED, unsigned int NumInputs = 0,
            unsigned int NumOutputs = 0>
    class SignalBlock
    {

    private:
        using InNode = InputSignalNode<InT, InSampleRate>;
        using OutNode = OutputSignalNode<OutT, OutSampleRate>;

    public:

        /** Only enable for debug builds -- used when timing */
        void on_start();
        void on_end();

    const InNode& input(unsigned int index) const {
        MBED_ASSERT(index < NumInputs);
        return inputs[index];
    }

    const OutNode& output(unsigned int index) const {
        MBED_ASSERT(index < NumOutputs);
        return outputs[index];
    }

    protected:

        InNode inputs[NumInputs];
        OutNode outputs[NumOutputs];

    };


}

#endif /* ETIAS_INC_SIGNALBLOCK_HPP_ */
