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
#ifndef CyclicOutput_h
#define CyclicOutput_h

#if ARDUINO >= 100
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <WConstants.h>
#endif

class CyclicOutput {

  public:
    CyclicOutput(int pin, unsigned int minOn=1000, unsigned int maxOn=5000, unsigned int minOff=1000, unsigned int maxOff=5000);

    void begin(void);
    void tick(unsigned long time);

  private:
    int _pin;
    unsigned int _minOn;
    unsigned int _maxOn;
    unsigned int _minOff;
    unsigned int _maxOff;
    unsigned long _lastStateChange;
    boolean _state;

    void setState(unsigned long time, boolean state);
};

#endif
