// --------------------------------------------------------------------------------
// This example file was written by Dan Malec and is released to the public domain.
// You can copy, modify, and distribute this file, even for commercial purposes,
// without asking permission.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// --------------------------------------------------------------------------------
#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
  #include <WConstants.h>
#endif

#include "CyclicOutput.h"

const int ledPin = 13;
CyclicOutput ledOutput(ledPin, 250, 3000, 250, 3000);

boolean state_change_trigger(int pin, boolean state) {
  return false;
}

void setup() {
  ledOutput.registerStateChangeTrigger(&state_change_trigger);

  ledOutput.begin();
}

void loop() {
  ledOutput.tick(millis());

  delay(250);
}
