void handleLogin() {
  String msg;
  if (server.hasHeader("Cookie")) {
    Serial.print("Found cookie: ");
    String cookie = server.header("Cookie");
    Serial.println(cookie);
  }
  if (server.hasArg("DISCONNECT")) {
    Serial.println("Disconnection");
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.sendHeader("Set-Cookie", "ESPSESSIONID=0");
    server.send(301);
    return;
  }
  if (server.hasArg("HOME")) {
    server.sendHeader("Location", "/");
    server.sendHeader("Cache-Control", "no-cache");
    server.sendHeader("Set-Cookie", "ESPSESSIONID=0");
    server.send(301);
    return;
  }
  if (server.hasArg("USERNAME") && server.hasArg("PASSWORD")) {
    if (server.arg("USERNAME") == "admin" &&  server.arg("PASSWORD") == "admin") {
      server.sendHeader("Location", "/root");
      server.sendHeader("Cache-Control", "no-cache");
    Serial.println("return home");
      server.sendHeader("Set-Cookie", "ESPSESSIONID=1");
      server.send(301);
      Serial.println("Log in Successful");
      return;
    }
       String content ="<html><style>.box input[type = \"password\"]{  border:0;  background: none;  display: block;  margin: 20px auto;  text-align: center;  border: 5px solid #09f;  padding: 11px 60px;  width: 300px;  outline: none;  color: white; border-color:red; border-radius: 24px;  transition: 0.25s;}</style></html>";

    Serial.println("Log in Failed");
  }
  String content = "<html>";
   content +=" <html lang=\"en\" dir=\"ltr\">";
   content +="<body bgcolor='black'>";
  content +="<head><center><meta charset=\"utf-8\"><title>َAnimated Login Form</title><link rel=\"stylesheet\" href=\"style.css\"></head><body>";
   content +="<div class=\"area\" ><ul class=\"circles\"><li></li><li></li><li></li><li></li><li></li><li></li><li></li><li></li><li></li><li></li></ul></div >\n";
 content +="<form class=\"box\" action=\"/login\" method=\"post\"><h1>Login</h1>";
 content +="<input type=\"text\" name=\"USERNAME\" placeholder=\"Username\">";
 content +="<input type=\"password\" name=\"PASSWORD\" placeholder=\"Password\">";
 content +=" <input type=\"submit\" name=\"SUBMIT\" value=\"Login\"><\form></body></center>";

content +="<style>\n";
content +="*{margin: 0px;    padding: 0px;} body{  font-family: 'Exo', sans-serif;}";
content +=".context {    width: 100%;    position: absolute;    top:5vh;}";
content +=".context h1{ text-align: center;    color: #fff;    font-size: 50px;}";
content +=".area{  background: transparent;  background: -webkit-linear-gradient(to left, #8f94fb, #4e54c8); width: 100%;   height:100vh; }";
content +=".circles{    position: absolute;    top: 0;    left: 0;    width: 100%;    height: 100%;    }";
content +=".circles li{    position: absolute;    display: block;    list-style: none;    width: 20px;    height: 20px;    background: rgba(255, 255, 255, 0.2);    animation: animate 25s linear infinite;    bottom: -150px; }";
content +=".circles li:nth-child(1){  left: 25%;    width: 80px;    height: 80px;  animation-delay: 0s;}";
content +=".circles li:nth-child(2){ left: 10%;    width: 20px;    height: 20px;    animation-delay: 2s;    animation-duration: 12s;}";
content +=".circles li:nth-child(3){  left: 70%;    width: 20px;    height: 20px;    animation-delay: 4s;}";
content +=".circles li:nth-child(4){  left: 40%;    width: 60px;    height: 60px;    animation-delay: 0s;    animation-duration: 18s;}";
content +=".circles li:nth-child(5){  left: 65%;   width: 20px;    height: 20px;  animation-delay: 0s;}";
content +=".circles li:nth-child(6){ left: 75%;  width: 110px;  height: 110px; animation-delay: 3s;}";
content +=".circles li:nth-child(7){ left: 35%; width: 150px; height: 150px;animation-delay: 7s;}";
content +=".circles li:nth-child(8){ left: 50%; width: 25px;  height: 25px;  animation-delay: 15s; animation-duration: 45s;}";
content +=".circles li:nth-child(9){ left: 20%;   width: 15px; height: 15px;  animation-delay: 2s;  animation-duration: 35s;}";
content +=".circles li:nth-child(10){ left: 85%;    width: 150px;    height: 150px;    animation-delay: 0s;    animation-duration: 11s;}";
content +="@keyframes animate { 0%{ transform: translateY(0) rotate(0deg); opacity: 1; border-radius: 0; } 100%{ transform: translateY(-1000px) rotate(720deg);  opacity: 0; border-radius: 50%;}}\n";
 content +=" body{  margin: 0;  padding: 0;  font-family: sans-serif; }";
 content +=".box{  width: 100%;  padding: 19%;  position: absolute;  top: 50%;  left: 50%;  transform: translate(-50%,-50%);   text-align: center;}";
 content +=".box h1{  color: white;  text-transform: uppercase;  font-weight: 200;}";
 content +=".box input[type = \"text\"],.box input[type = \"password\"]{  border:0;  background: none;  display: block;  margin: 20px auto;  text-align: center;  border: 5px solid #09f;  padding: 11px 60px;  width: 300px;  outline: none;  color: white;  border-radius: 24px;  transition: 0.25s;}";
 content +=".box input[type = \"text\"]:focus,.box input[type = \"password\"]:focus{  width: 400px;  border-color: #2ecc71;}";
 content +=".box input[type = \"submit\"]{  border:0;  background: none;  display: block;  margin: 20px auto;  text-align: center;  border: 2px solid #2ecc71;  padding: 14px 40px;  outline: none;  color: white;  border-radius: 24px;  transition: 0.25s;  cursor: pointer;}";
 content +=".box input[type = \"submit\"]:hover{  background: #2ecc71;}";
 content +="</style>";

   content += "You also can go <a href='/inline'>here</a></center></html>";
  server.send(200, "text/html", content);
}
