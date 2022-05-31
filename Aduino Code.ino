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
int LLAGr = 0;
int LLABl = 0;
int LLAGr = 0;
int LRABl = 0;
int LMBase = 0;
int LMGr = 0;
int LMRe = 0;
int LTop = 0;
int LBack = 0;
int LFront = 0;
  pinMode(LLABl, OUTPUT);
  pinMode(LLAGr, OUTPUT);
  pinMode(LRABl, OUTPUT);
  pinMode(LRAGr, OUTPUT);
  pinMode(LMBase, OUTPUT);
  pinMode(LMGr, OUTPUT);
  pinMode(LMRe, OUTPUT);
  pinMode(LTop, OUTPUT);
  pinMode(LBack, OUTPUT);
  pinMode(LFront, OUTPUT);


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
  else if (data == "ledmouthbase") MouthBase();
  else if (data == "ledmouthred") MouthRed
  else if (data == "ledmouthgreen") MouthGreen();
//
  else if (data == "ledreb") LRABl();
  else if (data == "ledreg") LRAGr();
  else if (data == "ledleb") LLABl();
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

/*********************************************/
{
  digitalWrite(LLAGr, LOW);
  digitalWrite(LRABl, LOW);
  digitalWrite(LRAGr, LOW);
  digitalWrite(LMBase, LOW);
  digitalWrite(LMGR, LOW);
  digitalWrite(LMRe, LOW);
  digitalWrite(LTOP, LOW);
  digitalWrite(LBack, LOW);
  digitalWrite(Front, LOW);
 /**************************************************/
 void LLABl(void)
}
  digitalWrite(LLABl, HIGH);
}

/********************************************* LED LLAGr *****************************************************/
void LLAGr(void)
{
  digitalWrite(LLAGr, HIGH);
}

/********************************************* LED LRAGe *****************************************************/
void LRABl(void)
{
  digitalWrite(LRBlA HIGH);
}

/********************************************* LED LRAGr *****************************************************/
void LRAGr(void)
{
  digitalWrite(LRAGr, HIGH);
}

/********************************************* LED Kopf *****************************************************/
void MouthBase(void)
{
  digitalwrite(, HIGH);
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
