void handle_OnConnect() { 
 status0 = LOW;
 status1 = LOW;
 status2 = LOW;
 status3 = LOW;
 status4 = LOW;
 status5 = LOW;
 status6 = LOW;
 status7 = LOW;
 status8 = LOW;

  server.send(200, "text/html", content(false));
}

void handle_room1() {
   if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }

  statusroom1=HIGH;
  statusroom2=LOW;
  statusroom3=LOW;
  statusoutdoor =LOW;
  statusreset =LOW;

  server.send(200, "text/html", content(true));
}
void handle_room2() {
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
  statusroom2=HIGH;
  statusroom1=LOW;
  statusroom3=LOW;
  statusoutdoor =LOW;
  statusreset =LOW;
  server.send(200, "text/html", content(true));
}
void handle_room3() {
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
  statusroom3=HIGH; 
  statusroom1=LOW;
  statusroom2=LOW;
  statusoutdoor =LOW;
  statusreset =LOW;

  server.send(200, "text/html", content(true));
}
void handle_outdoor() {
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  } 
  statusoutdoor =HIGH;
  statusroom3=LOW; 
  statusroom1=LOW;
  statusroom2=LOW;
 statusreset =LOW;
  server.send(200, "text/html", content(true)); 
}
void handle_reset(){
   if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
   }
   statusreset=HIGH;
   statusoutdoor =LOW;
   statusroom3=LOW; 
   statusroom1=LOW;
   statusroom2=LOW;
     server.send(200, "text/html", content(true));

}
void handle_resetnow(){
   if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
   }
   status0 = LOW;
   status1 = LOW;
   status2 = LOW;
   status3 = LOW;
   status4 = LOW;
   status5 = LOW;
   status6 = LOW;
   status7 = LOW;
   status8 = LOW;
     server.send(200, "text/html", content(true));
}
void handle_fan1on() {
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
  status0=HIGH;
  server.send(200, "text/html", content(true));
}
void handle_fan1off() {
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
  status0=LOW;
  server.send(200, "text/html", content(false));
}
void handle_fan2on() {
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
  status1=HIGH;
  server.send(200, "text/html", content(true));
}
void handle_fan2off() {
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
 status1=LOW;
  server.send(200, "text/html", content(false));
}
void handle_light1on() {
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
 status2=HIGH;
  server.send(200, "text/html", content(false));
}
void handle_light1off() {
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
 status2=LOW;
  server.send(200, "text/html", content(false));
}
void handle_light2on() {
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
 status3=HIGH;
  server.send(200, "text/html", content(false));
}
void handle_light2off() {
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
 status3=LOW;
  server.send(200, "text/html", content(false));
}
void handle_light3on() {
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
 status4=HIGH;
  server.send(200, "text/html", content(false));
}
void handle_light3off() {
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
 status4=LOW;
  server.send(200, "text/html", content(false));
}
void handle_pumpon() {
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
 status5=HIGH;
  server.send(200, "text/html", content(false));
}
void handle_pumpoff() {
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
 status5=LOW;
  server.send(200, "text/html", content(false));
}
void  handle_gateon() {
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
 status6=HIGH;
  server.send(200, "text/html", content(false));
}
void  handle_gateoff() {
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
 status6=LOW;
  server.send(200, "text/html", content(false));
}
void handle_parkinglighton(){
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
  status7=HIGH;
  server.send(200, "text/html", content(false));
}
void handle_parkinglightoff(){
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
  status7=LOW;
  server.send(200, "text/html", content(false));
}
void handle_surroundinglighton(){
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
  status8=HIGH;
  server.send(200, "text/html", content(false));
}
void handle_surroundinglightoff(){
    if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
  status8=LOW;
  server.send(200, "text/html", content(false));
}

void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}
