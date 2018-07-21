/*******************************************************************************
 * This file is part of the millis library.                                    *
 *                                                                             *
 * millis is free software: you can redistribute it and/or                     *
 * modify it under the terms of the GNU General Public License as              *
 * published by the Free Software Foundation, either version 3 of              *
 * the License, or any later version.                                          *
 *                                                                             *
 * millis is distributed in the hope that it will be useful,                   *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 * GNU Lesser General Public License for more details.                         *
 *                                                                             *
 * millis is distributed in the hope that it will be useful,                   *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 * GNU Lesser General Public License for more details.                         *
 *                                                                             *
 * You should have received a copy of the GNU Lesser General Public            *
 * License along with millis. If not, see                                      *
 * <http://www.gnu.org/licenses/>.                                             *
 ******************************************************************************/

/*
 *  Copyright:  DFRobot
 *  name:       millis
 *  version:    1.0
 *  Author:     lisper (lisper.li@dfrobot.com)
 *  Date:       2014-10-30
 *  Description:    millis library for mbed
 */

#include "mbed.h"

static volatile uint32_t millisValue = 0;
static Ticker ticker;


extern "C"
{

inline void millisTicker ()
{
    millisValue ++;
}

inline uint32_t millis ()
{
    return millisValue;
}

inline void setMillis (uint32_t theValue) {
    millisValue = theValue;
}

inline void startMillis () {
    ticker.attach (millisTicker, 0.001);
}

inline void stopMillis () {
    ticker.detach ();
}

}


// helper class that starts the millis ticker
class MillisHelper
{
  public:
   MillisHelper() { startMillis(); }
};

static MillisHelper h;
