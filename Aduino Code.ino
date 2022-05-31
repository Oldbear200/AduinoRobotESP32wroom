#include <WiFi.h>
WiFiClient client;4
WiFiServer server(80);
 
const char* ssid = "name";
const char* password = "pw";

String  data = "";
 
int leftMotorForward = 2;
int rightMotorForward = 15;
int leftMotorBackward = 0;
int rightMotorBackward = 13;
int LLAGe = 0;
int LLAGr = 0;
int LRAGe = 0;
int LRAGr = 0;
int HeadLED = 0;
void setup()
{
  Serial.begin(115200);
  pinMode(leftMotorForward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
  pinMode(LLAGe, OUTPUT);
  pinMode(LLAGr, OUTPUT);
  pinMode(LRAGe, OUTPUT);
  pinMode(LRAGr, OUTPUT);
  pinMode(LEDMund, OUTPUT);
  pinMode(HeadLED, OUTPUT);
  pinMode(BackLED, OUTPUT);
  pinMode(FrontLED, OUTPUT);


  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(3000);
  }
 
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
 
  server.begin();
}
 
void loop()
{
  client = server.available();
  if (!client) return;
  data = checkClient ();
 
  /************************ Eingang zu Funktion *************************/
 
  if (data == "forward") MotorForward();
  else if (data == "backward") MotorBackward();
  else if (data == "left") TurnLeft();
  else if (data == "right") TurnRight();
  else if (data == "stop") MotorStop();
  else if (data == "ledmund") Mund();
//
  else if (data == "ledrey") LRAGe();
  else if (data == "ledreg") LRAGr();
  else if (data == "ledley") LLAGe();
  else if (data == "ledleg") LLAGr();
//
  else if (data == "ledback") BackLED();
  else if (data == "ledfront") FrontLED();
  else if (data == "ledhead") HeadLED();
}
 
/********************************************* Vorwärts *****************************************************/
void MotorForward(void)
{
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorBackward, LOW);
}
 
/********************************************* Rückwerts *****************************************************/
void MotorBackward(void)
{
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorBackward, HIGH);
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(rightMotorForward, LOW);
}
 
/********************************************* Links *****************************************************/
void TurnLeft(void)
{
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
}
 
/********************************************* Rechts *****************************************************/
void TurnRight(void)
{
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, HIGH);
  digitalWrite(leftMotorBackward, LOW);
}
 
/********************************************* STOP *****************************************************/
void MotorStop(void)
{
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, LOW);
}

/********************************************* LED OFF*****************************************************/
void LEDoff(void)
{
  digitalWrite(GesichtLED1, LOW);
  digitalWrite(GesichtLED2, LOW);
  digitalWrite(KopfLED, LOW);
  digitalWrite(BackLED, LOW);
  digitalWrite(FrontLED, LOW);
}

/********************************************* LED LLAGe *****************************************************/
void LLAGe(void)
{
  digitalWrite(LLAGe, HIGH);
}

/********************************************* LED LLAGr *****************************************************/
void LLAGGr(void)
{
  digitalWrite(LLAGr, HIGH);
}

/********************************************* LED LRAGe *****************************************************/
void LRAGe(void)
{
  digitalWrite(LRAGe, HIGH);
}

/********************************************* LED LRAGr *****************************************************/
void LRAGr(void)
{
  digitalWrite(LRAGr, HIGH);
}

/********************************************* LED Kopf *****************************************************/
void LED(void)
{
  digitalWrite(KopfLED, HIGH);
}

/********************************************* LED Back *****************************************************/
void BackLED(void)
{
  digitalWrite(BackLED, HIGH);
}

/********************************** App Daten Annahme ******************************************/
String checkClient (void)
{
  while (!client.available()) delay(1);
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length() - 9, 9);
  return request;
}
