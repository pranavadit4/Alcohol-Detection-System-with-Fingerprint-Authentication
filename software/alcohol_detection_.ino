#include <Adafruit_Fingerprint.h>
#include <TinyGPSPlus.h>
#include<LiquidCrystal.h>

#define KEY_PIN 21
#define sensor_pin 25
#define RELAY_PIN 22
#define BUZZ_PIN 26

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&Serial2);
TinyGPSPlus gps;
LiquidCrystal lcd ( 23, 19, 18, 5, 4, 15);  //rs,en,d4,d5,d6,d7


int sensor_value;
int keyy1, a = 0,b=0,c=0;
int Relay = 26;
int p, t, d_c, bpm, ID, ID2, sms_f;


bool on_f = false, alertFlag , keyyflag = 0;

void setup()
{

  //--------------------------------------------------bike key(keyy1)----------------------------------------------
  pinMode(KEY_PIN, INPUT_PULLUP);
  //---------------------------------------------------mq3(alcohol sensor )-------------------------------
  //Serial.println("MQ3 warming up!");

  delay(500);
  Serial.begin(9600);


  //-------------------------------------------------dc motor (relay)-------------------------------------
  pinMode(RELAY_PIN, OUTPUT);
  pinMode( BUZZ_PIN , OUTPUT);
  digitalWrite(BUZZ_PIN, LOW);

  //-----------------------------------------------------------lcd print-------------------------------------------
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ALCOHOL");
  lcd.setCursor(5, 1);
  lcd.print(" DETECTION");


  //-----------------------------------------------finger print---------------------------------------------


  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");
  finger.begin(57600);
  delay(5);
  if (finger.verifyPassword()) {
    lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("FPS FOUND");
      delay(1000);
      
    //Serial.println("Found fingerprint sensor!");
  } else {
    lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("FPS NOT FOUND");
      delay(1000);
    //Serial.println("Did not find fingerprint sensor :(");
    while (1) {
      delay(1);
    }
  }

  //Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  //Serial.print(F("Status: 0x"));
  //Serial.println(finger.status_reg, HEX);
  //Serial.print(F("Sys ID: 0x")); 
  //Serial.println(finger.system_id, HEX);
  //Serial.print(F("Capacity: "));
  //Serial.println(finger.capacity);
  finger.capacity;
 //Serial.print(F("Security level: "));
 //Serial.println(finger.security_level);
 finger.security_level;
 // Serial.print(F("Device address: ")); 
  //Serial.println(finger.device_addr, HEX);
  //Serial.print(F("Packet len: "));
  //Serial.println(finger.packet_len);
  finger.packet_len;
 // Serial.print(F("Baud rate: "));
  //Serial.println(finger.baud_rate);
  finger.baud_rate;

  finger.getTemplateCount();

  if (finger.templateCount == 0) {
    //Serial.print("Sensor doesn't contain any fingerprint data. Please run the 'enroll' example.");
  }
  else {
   // Serial.println("Waiting for valid finger...");
   // Serial.print("Sensor contains ");
    //Serial.print(finger.templateCount);
    finger.templateCount;
   // Serial.println(" templates");
  }


}
void loop()
{

  //--------------------------------------------keyy(1)-------------------------------------------
  keyy1 = digitalRead(KEY_PIN);
 // Serial.println(keyy1);

  //-------------------------------------------------ALCOHOL SENSOR--------------------------------------
  sensor_value = analogRead(sensor_pin);
  //Serial.print("Analog output: ");
  //Serial.println(sensor_value);


  if (!digitalRead(KEY_PIN))
  {
    if (keyyflag == 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("PLACE THE FINGER");
      delay(1000);
      // keyyflag=1;
    }
    ID = getFingerprintID();
    ID2 = getFingerprintIDez();
  // Serial.print("ID=");
    //Serial.println(ID);

   // Serial.print("ID2=");
  // Serial.println(ID2);
    if (ID2 == 1) {
      a = 1;
    }
    if (ID2 == 2) {
      b = 1;
    }
    if ( on_f == true ) 
    {
     // Serial.println("ID1 MATCHED");
      if((a == 1)||(a==2)||(a==3)||(a==4))      //|| (ID == 2) || (ID == 3))
      {
      //Serial.println("ID2 MATCHED");
      if (sensor_value > 1500)
      {
        // alertFlag = true;
        // on_f == true ;
        digitalWrite(RELAY_PIN, LOW);
        //Serial.println("Relay off...");
        digitalWrite(BUZZ_PIN, HIGH);
        //Serial.println("Buzzer on......");
        // on_f = false;
      }
      else
      {

        //  on_f = false;
        digitalWrite(RELAY_PIN, HIGH);
        digitalWrite(BUZZ_PIN, LOW);

        // on_f = false;
      }
      keyyflag = 1;
  
      }

     /* else if(b == 1)
    {
      
      Serial.println("FINGERPRINT DOES NOT MATCHED");
      // on_f == false;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" FINGERPRINT DOES");
      lcd.setCursor(3, 1);
      lcd.print(" NOT  MATCH ");
      delay(1000);
         digitalWrite(RELAY_PIN, LOW);
        digitalWrite(BUZZ_PIN, LOW);
      send_SMS("FINGER PRINT DOES NOT MATCH", "7092100846");
    b =0;
   // c=0;
    }*/
}


  }
  else if  (digitalRead(KEY_PIN) == 1)
  {
    on_f = false;
    keyyflag = 0;
    a = 0;
    b=0;
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(BUZZ_PIN, LOW);
  }

 //-----------------------------------gps--------------------------------------------------------
    if (Serial.available() > 0)
    if (gps.encode(Serial.read()))
      //displayInfo();
    if (millis() > 5000 && gps.charsProcessed() < 10)
    {
    //Serial.println(F("No GPS detected: check wiring."));
    while (true);
    }

 
  //-------------------------------------------Display----------------------------------------------------------
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ALCOHOL = ");
  lcd.print(sensor_value);
  if (sensor_value > 1000 && alertFlag == false)
  {
    lcd.setCursor(0, 0);
    lcd.print("ALCOHOL DETECTED");
    // digitalWrite(BUZZ_PIN, HIGH);
    //digitalWrite(RELAY_PIN, LOW);
    send_SMS("7092100846","Alcohol Detected");
    send_SMS("8925747143","Alcohol Detected");
    
    alertFlag = true;

  }
  if (sensor_value < 1500) {

    digitalWrite(BUZZ_PIN, LOW);
    alertFlag = false;

  }

}
//---------------------------------------------------------------SMS----------------------------------------------

void send_SMS(String number, String nam)
{

  Serial.println("AT+CMGF=1");
  delay(1000);
  Serial.println("AT+CMGS=\"+91" + number + "\"");
  delay(1000);
  Serial.println(nam);
  //Serial.println("sms sent");
  delay(1000);
  //Serial.write((char)26);
  Serial.print("http://maps.google.com/maps?q=+");
  Serial.print(gps.location.lat(), 6);
  Serial.print("+");
  Serial.println(gps.location.lng(), 6);
  Serial.write((char)26);
  delay(1000);
}
//------------------------------------------------------GPS---------------------------------------------------
/*void displayInfo()
{
  Serial.print(F("Location: "));
  if (gps.location.isValid()) {
    Serial.print("Lat: ");
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print("Lng: ");
    Serial.print(gps.location.lng(), 6);
    Serial.println();
  }
  else
  {
    Serial.println(F("INVALID"));
  }
  delay(500);
}
*/


int getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
     // Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
     // Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      //Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
     // Serial.println("Imaging error");
      return p;
    default:
      //Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      //Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      //Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      //Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      //Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      //Serial.println("Could not find fingerprint features");
      return p;
    default:
      //Serial.println("Unknown error");
      return p;
  }

  // OK converted!
  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    //Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    //Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
   // Serial.println("Did not find a match");
    lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("FPS NOT MATCH");
      delay(1000);
      send_SMS("7092100846","FINGER PRINT DOES NOT MATCH");
      send_SMS("8925747143","FINGER PRINT DOES NOT MATCH");
   // on_f = false;
    return p;

  } else {
    //Serial.println("Unknown error");
    return p;
  }

  // found a match!
  //Serial.print("Found ID #");
  //Serial.print(finger.fingerID);
  finger.fingerID;
  //Serial.print(" with confidence of ");
  //Serial.println(finger.confidence);
  finger.confidence;
  on_f = true;
  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK) {
    //on_f = false;
    return -1;}

  // found a match!
 // Serial.print("Found ID #");
 //Serial.print(finger.fingerID);
 finger.fingerID;
  //Serial.print(" with confidence of ");
  //Serial.println(finger.confidence);
  finger.confidence;
  return finger.fingerID;
}
