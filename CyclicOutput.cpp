// --------------------------------------------------------------------------------
// Copyright (C) 2012 Dan Malec
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is furnished to do
// so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// --------------------------------------------------------------------------------
#include "CyclicOutput.h"

//! Class constructor.
/*!
  The class constructor saves the configuraion parameters.
  
  \param minOn the minimum number of milliseconds to turn the pin on
  \param maxOn the maximum number of milliseconds to turn the pin on
  \param minOff the minimum number of milliseconds to turn the pin off
  \param maxOff the maximum number of milliseconds to turn the pin off
 */
CyclicOutput::CyclicOutput(int pin, unsigned int minOn, unsigned int maxOn, unsigned int minOff, unsigned int maxOff) {
  _pin = pin;
  _minOn = minOn;
  _maxOn = maxOn;
  _minOff = minOff;
  _maxOff = maxOff;
  _stateChangeCallback = NULL;
}

void CyclicOutput::registerStateChangeCallback(void (*stateChangeCallback)(int, boolean)) {
  _stateChangeCallback = stateChangeCallback;
}

//! Initialize the object.
/*!
  Client code should call begin prior to any calls to tick.
*/
void CyclicOutput::begin(void) {
  pinMode(_pin, OUTPUT);
}

//! Update pin state based on the passed in time.
/*!
  Recalculate the pin state based on the passed in absolute time in milliseconds.

  \param time the absolute time in milliseconds
*/
void CyclicOutput::tick(unsigned long time) {
  unsigned int elapsedTime = time - _lastStateChange;

  if (_state) {
    if (elapsedTime >= _maxOn) {
      setState(time, false);
    }
  } else {
    if (elapsedTime >= _maxOff) {
      setState(time, true);
    }
  }
}

//! Internal method to update pin state.
/*!
  Update the physical pin state and all related variables.

  \param time the absolute time in milliseconds
  \param state the state to set the pin to
*/
void CyclicOutput::setState(unsigned long time, boolean state) {
  _state = state;

  if (_state) {
    digitalWrite(_pin, HIGH);
  } else {
    digitalWrite(_pin, LOW);
  }

  if (_stateChangeCallback != NULL) {
    (*_stateChangeCallback)(_pin, _state);
  }

  _lastStateChange = time;
}
