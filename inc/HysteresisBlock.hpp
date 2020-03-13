/*
 * HysteresisBlock.hpp
 *
 *  Created on: Mar 12, 2020
 *      Author: gdbeckstein
 */

#ifndef ETIAS_INC_HYSTERESISBLOCK_HPP_
#define ETIAS_INC_HYSTERESISBLOCK_HPP_

#include "SignalBlock.hpp"

namespace etias
{
    template<typename T>
    class HysteresisBlock
    {

    public:

    /**
     * Construct a hysteresis block
     *
     * This simple hysteresis block applies a sharp
     * hysteresis loop like that of a Schmitt trigger.
     *
     * @param[in] lower Lower threshold of the hysteresis loop
     * @param[in] upper Upper threshold of the hysteresis loop
     */
    HysteresisBlock(T lower, T upper) :
        lower_threshold(lower), upper_threshold(upper),
        input_node(mbed::callback(this, &HysteresisBlock::process_input)),
        last_value() {}

    /**
     * Connect an InputSignalNode to the upper-crossing hysteresis threshold output
     *
     * @param[in] input InputSignalNode to connect to
     */
    OutputSignalNode<T, SAMPLE_RATE_UNDEFINED>& cross_upper(void) {
        return upper_output;
    }

    /**
     * Connect an InputSignalNode to the lower-crossing hysteresis threshold output
     *
     * @param[in] input InputSignalNode to connect to
     */
    OutputSignalNode<T, SAMPLE_RATE_UNDEFINED>& cross_lower(void) {
        return lower_output;
    }

    T get_lower_threshold() const {
        return lower_threshold;
    }

    void set_lower_threshold(T lower) {
        lower_threshold = lower;
    }

    T get_upper_threshold() const {
        return upper_threshold;
    }

    void set_upper_threshold(T upper) {
        upper_threshold = upper;
    }

    InputSignalNode<T, SAMPLE_RATE_UNDEFINED>& input(void) {
        return input_node;
    }

    protected:

    void process_input(T input) {
        if(last_value >= lower_threshold && input < lower_threshold) {
            // Notify lower threshold subscribers
            lower_output.notify(input);
        } else
        if(last_value <= upper_threshold && input > upper_threshold) {
            upper_output.notify(input);
        }

        last_value = input;
    }

    protected:

        T lower_threshold;
        T upper_threshold;

        InputSignalNode<T, SAMPLE_RATE_UNDEFINED> input_node;

        // TODO - how would you templatize an OutputSignal that has no arguments?
        OutputSignalNode<T, SAMPLE_RATE_UNDEFINED> lower_output;
        OutputSignalNode<T, SAMPLE_RATE_UNDEFINED> upper_output;

        T last_value;
    };

}

#endif /* ETIAS_INC_HYSTERESISBLOCK_HPP_ */
