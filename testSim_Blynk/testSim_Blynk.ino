#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6yTb8cqIU"
#define BLYNK_TEMPLATE_NAME "TEST"
#define BLYNK_AUTH_TOKEN "756K9gfhO9tG9TNI7C3-MmCE0oHoEnrW"

#define TINY_GSM_MODEM_SIM7600

#include <TinyGsmClient.h>
#include <BlynkSimpleTinyGSM.h>

char apn[]  = "";
char user[] = "";
char pass[] = "";

// Hardware Serial on Mega, Leonardo, Micro
#define SerialAT Serial2

TinyGsm modem(SerialAT);

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); 
  digitalWrite(2, pinValue);
}

void setup()
{
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  SerialAT.begin(115200);
  delay(3000);


  Serial.println("Initializing modem...");
  modem.restart();

  Blynk.begin(BLYNK_AUTH_TOKEN, modem, apn, user, pass);
}

void loop()
{
  Blynk.run();
}