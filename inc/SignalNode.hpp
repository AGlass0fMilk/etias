/*
 * SignalNode.h
 *
 *  Created on: Mar 12, 2020
 *      Author: gdbeckstein
 */

#ifndef ETIAS_INC_SIGNALNODE_HPP_
#define ETIAS_INC_SIGNALNODE_HPP_

/**
 * Some signal chains do not care about sample rate
 *
 * For simplicity, users can specify -1 when
 * sample rate is unimportant to their data
 */
#define SAMPLE_RATE_UNDEFINED -1

namespace etias
{

    class SignalNode
    {

    };

}

#endif /* ETIAS_INC_SIGNALNODE_HPP_ */
