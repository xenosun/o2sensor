/*   o2sensor Test
 *   (c)2019-2021, Dr.-Ing. Martin Richter, XENOSUN Diving
 * 
 */


#define _debug  // debug build

class o2sensor {
  private:
    int pin;
  
  public:
    o2sensor(int sensorPin) {
      pin = sensorPin;
    }

    // calibrate the o2 sensor and write the result into the eeprom
    void calibrate() {
      
    }

    // read ppo2
    float readPPO2() {
    
    }

#ifdef _debug
    void toText() {
      Serial.println("o2sensor debug build");
      Serial.print("Pin: "); Serial.println(pin);
    }
#endif
};

o2sensor s(3);

void setup() {
  // initialize serial port
  Serial.begin(115200);
  
  // banner
#ifdef _debug
  Serial.println("*** O2 Sensor Test, (c)2018-2020, Dr.-Ing. Martin Richter");
#endif

#ifdef _debug
  s.toText();
#endif
}

void loop() {
  // put your main code here, to run repeatedly:
  s.readPPO2();
}

// eof o2sensor.ino
