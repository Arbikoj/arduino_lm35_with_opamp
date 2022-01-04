#include <WiFi.h>
const char * ssid = "WIFI_SSID"; 
const char * password = "WIFI_PASSWORD";
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  int adc_opamp = analogRead(25);
  int adc_lm35 = analogRead(14);
  
  float volt_lm35 = (adc_lm35 * 3.3) / 4095;
  float volt_opamp = ((adc_opamp * 3.3) / 4095);

  float Av = volt_opamp/volt_lm35;
  
  float suhu_lm35 = volt_lm35 * 100;
  float suhu_opamp = (volt_opamp * 100) / Av;

  Serial.print("adc_opamp : ");
  Serial.print(adc_opamp);
  Serial.print(" , ");
  Serial.print("volt_opamp : ");
  Serial.print(volt_opamp);
  Serial.print(" , ");
  Serial.print("adc_lm35 : ");
  Serial.print(adc_lm35);
  Serial.print(" , ");
  Serial.print("volt_lm35 : ");
  Serial.print(volt_lm35);
  Serial.print(" , ");
  Serial.print("suhu lm: ");
  Serial.print(suhu_lm35);
  Serial.print(" , ");
  Serial.print("Av: ");
  Serial.print(Av);
  Serial.print(" , ");
  Serial.print("suhu opamp: ");
  Serial.println(suhu_opamp);
  

  delay(1000);
}
