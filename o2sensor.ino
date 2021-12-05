/*   o2sensor Test
 *   (c)2019-2022, Dr.-Ing. Martin Richter, XENOSUN Diving
 * 
 */

class o2sensor {
  private:
    int pin;
    float cal1x, cal1y, cal2x, cal2y;
  
  public:
    o2sensor(int sensorPin) {
      pin = sensorPin;
    }

    // calibrate the o2 sensor and write the result into the eeprom
    void calibrate() {
      cal1x = 2;
      cal1y = 0.21;
      cal2x = 10;
      cal2y = 0.98;
      
    }

    float convert(float sensorValue)
    {
      float ppO2 = 2;
      return ppO2;
    }

    // read ppo2
    float readPPO2() {
      // Lesen des Eingangs am analogen Pin A0
      int sensorValue = analogRead(pin);
      float ppO2 = sensorValue;
      return ppO2;
    }

    void toText() {
      Serial.println("o2sensor");
      Serial.print("Pin: "); Serial.println(pin);
      Serial.print("CAL 1-x: "); Serial.println(cal1x, 3);
      Serial.print("CAL 1-y: "); Serial.println(cal1y, 3);
      Serial.print("CAL 2-x: "); Serial.println(cal2x, 3);
      Serial.print("CAL 2-y: "); Serial.println(cal2y, 3);
      Serial.println(readPPO2());
    }

};

o2sensor sensor(A0);

void setup() {
  // initialize serial port
  Serial.begin(9600);
  sensor.calibrate();
}

void loop() {

  // Ausgabe des Wertes über die serielle Schnittstelle 
  sensor.toText();
}

// eof o2sensor.ino
