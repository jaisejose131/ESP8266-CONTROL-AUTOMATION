
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFiMulti.h>
#include <WebSocketsServer.h>
#include <DNSServer.h>
#include <ESP8266mDNS.h>
#include <EEPROM.h>
#include <ESP.h>
#include <Hash.h>

#ifndef APSSID
#define APSSID "HOME_WIFI"
#define APPSK  "12345678"
#endif
#define LED_RED     15
#define LED_GREEN   12
#define LED_BLUE    13

const char *softAP_ssid = APSSID;
const char *softAP_password = APPSK;

/* hostname for mDNS. Should work at least on windows. Try http://esp8266.local */
const char *myHostname = "esp8266";
String Argument_Name, Clients_Response1, Clients_Response2;


/* Don't set this wifi credentials. They are configurated at runtime and stored on EEPROM */
char ssid[32] = "";
char password[32] = "";

// DNS server
const byte DNS_PORT = 53;
DNSServer dnsServer;

// Web server
ESP8266WiFiMulti WiFiMulti;
ESP8266WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(81);


/* Soft AP network parameters */
IPAddress apIP(192, 168, 100, 007);
IPAddress netMsk(255, 255, 255, 0);


/** Should I connect to WLAN asap? */
boolean connect;

/** Last time I tried to connect to WLAN */
unsigned long lastConnectTry = 0;

/** Current WLAN status */
unsigned int status = WL_IDLE_STATUS;



uint8_t pin0 = D0;
uint8_t pin1 = D1;
uint8_t pin2 = D2;
uint8_t pin3 = D3;
uint8_t pin4 = D4;
uint8_t pin5 = D5;
uint8_t pin6 = D6;
uint8_t pin7 = D7;
uint8_t pin8 = D8;


bool status0=LOW;
bool status1=LOW;
bool status2=LOW;
bool status3=LOW;
bool status4=LOW;
bool status5=LOW;
bool status6=LOW;
bool status7=LOW;
bool status8=LOW;



bool statusroom1 = LOW;
bool statusroom2 = LOW;
bool statusroom3 = LOW;
bool statusoutdoor =LOW;
bool statusreset =LOW;



bool is_authenticated() {
  Serial.println("Enter is_authenticated");
  if (server.hasHeader("Cookie")) {
    Serial.print("Found cookie: ");
    String cookie = server.header("Cookie");
    Serial.println(cookie);
    if (cookie.indexOf("ESPSESSIONID=1") != -1) {
      Serial.println("Authentication Successful");
      return true;
    }
  }
  Serial.println("Authentication Failed");
  return false;
}
void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

    switch(type) {
        case WStype_DISCONNECTED:
            Serial.printf("[%u] Disconnected!\n", num);
            break;
        case WStype_CONNECTED: {
            IPAddress ip = webSocket.remoteIP(num);
            Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);

            // send message to client
            webSocket.sendTXT(num, "Connected");
        }
            break;
        case WStype_TEXT:
            Serial.printf("[%u] get Text: %s\n", num, payload);

            if(payload[0] == '#' && status2==HIGH && statusroom1==HIGH) {   
              uint32_t rgb = (uint32_t) strtol((const char *) &payload[1], NULL, 16);
                analogWrite(pin2,    ((rgb ) & 0xFF));
            }
            else if(payload[0] == '#' && status3==HIGH && statusroom2==HIGH) {   
              uint32_t rgb = (uint32_t) strtol((const char *) &payload[1], NULL, 16);
                analogWrite(pin3,    ((rgb ) & 0xFF));
            }
            else if(payload[0] == '#' && status4==HIGH && statusroom3==HIGH){
                 uint32_t rgb = (uint32_t) strtol((const char *) &payload[1], NULL, 16);
                analogWrite(pin4,    ((rgb ) & 0xFF));
 
            }
            break;
    }

}


void setup(void) {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAPConfig(apIP, apIP, netMsk);
  WiFi.softAP(softAP_ssid, softAP_password);
  delay(500); // Without delay I've seen the IP address blank
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());

  dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
  dnsServer.start(DNS_PORT, "*", apIP);

   pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);

  
  server.on("/root", handleRoot);
  server.on("/login", handleLogin);
  server.on("/room1", handle_room1);
  server.on("/room2", handle_room2);
  server.on("/room3", handle_room3);
  server.on("/timeswitch", handle_timeswitch);
  server.on("/reset",handle_reset);
  server.on("/outdoor", handle_outdoor);  
  server.on("/fan1on", handle_fan1on);
  server.on("/fan2on", handle_fan2on); 
  server.on("/fan1off", handle_fan1off);
  server.on("/fan2off", handle_fan2off);
  server.on("/light1on", handle_light1on);
  server.on("/light2on", handle_light2on); 
  server.on("/light3on", handle_light3on);  
  server.on("/light1off", handle_light1off);
  server.on("/light2off", handle_light2off); 
  server.on("/light3off", handle_light3off);
  server.on("/light1on", handle_light1on);
  server.on("/light2on", handle_light2on); 
  server.on("/light3on", handle_light3on);
  server.on("/pumpon", handle_pumpon);
  server.on("/pumpoff", handle_pumpoff);
  server.on("/gateon" , handle_gateon);
  server.on("/gateoff" , handle_gateoff);
  server.on("/parkinglighton" , handle_parkinglighton);
  server.on("/parkinglightoff" , handle_parkinglightoff);
  server.on("/surroundinglighton",handle_surroundinglighton);
  server.on("/surroundinglightoff",handle_surroundinglightoff);
  server.on("/resetnow",handle_resetnow); 
  server.on("/inline", []() {
    server.send(200, "text/plain", "this works without need of authentication");
  });

  server.onNotFound(handle_NotFound);
  const char * headerkeys[] = {"User-Agent", "Cookie"} ;
  size_t headerkeyssize = sizeof(headerkeys) / sizeof(char*);
  //ask server to track these headers
  server.collectHeaders(headerkeys, headerkeyssize);

 webSocket.begin();
    webSocket.onEvent(webSocketEvent);

    if(MDNS.begin("esp8266")) {
        Serial.println("MDNS responder started");
    }
  
  server.begin();
  MDNS.addService("http", "tcp", 80);
    MDNS.addService("ws", "tcp", 81);

   

     connect = strlen(ssid) > 0; // Request WLAN connect if there is a SSID
 
}

void connectWifi() {
  Serial.println("Connecting as wifi client...");
  WiFi.disconnect();
  WiFi.begin(ssid, password);
  int connRes = WiFi.waitForConnectResult();
  Serial.print("connRes: ");
  Serial.println(connRes);
}


void loop() {
  if (connect) {
    Serial.println("Connect requested");
    connect = false;
    connectWifi();
    lastConnectTry = millis();
  }
  {
    unsigned int s = WiFi.status();
    if (s == 0 && millis() > (lastConnectTry + 60000)) {
      /* If WLAN disconnected and idle try to connect */
      /* Don't set retry time too low as retry interfere the softAP operation */
      connect = true;
    }
    if (status != s) { // WLAN status change
      Serial.print("Status: ");
      Serial.println(s);
      status = s;
      if (s == WL_CONNECTED) {
        /* Just connected to WLAN */
        Serial.println("");
        Serial.print("Connected to ");
        Serial.println(ssid);
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());

        // Setup MDNS responder
        if (!MDNS.begin(myHostname)) {
          Serial.println("Error setting up MDNS responder!");
        } else {
          Serial.println("mDNS responder started");
          // Add service to MDNS-SD
          MDNS.addService("http", "tcp", 80);
        }
      } else if (s == WL_NO_SSID_AVAIL) {
        WiFi.disconnect();
      }
    }
    if (s == WL_CONNECTED) {
      MDNS.update();
    }
  }
  // Do work:
  //DNS
  dnsServer.processNextRequest();

  server.handleClient();


    if(status0==HIGH)    //FOR FAN1
    digitalWrite(pin0 ,HIGH);
  else 
     digitalWrite(pin0 ,LOW);
  if(status1==HIGH)   //FOR FAN2
    digitalWrite(pin1 ,HIGH);
  else 
     digitalWrite(pin1 ,LOW);


  if(status5==HIGH)   //FOR pumb
    digitalWrite(pin5 ,HIGH);
  else 
    digitalWrite(pin5 ,LOW);
  if(status6==HIGH)  //FOR gate
    digitalWrite(pin6 ,HIGH);
  else 
    digitalWrite(pin6 ,LOW);
  if(status7==HIGH)   //FOR parkinglight
    digitalWrite(pin7 ,HIGH);
  else
    digitalWrite(pin7 ,LOW);
  if(status8==HIGH)   //FOR surrounding
    digitalWrite(pin8 ,HIGH);
  else
    digitalWrite(pin8 ,LOW);
    

    webSocket.loop(); 
  
  
  
}
