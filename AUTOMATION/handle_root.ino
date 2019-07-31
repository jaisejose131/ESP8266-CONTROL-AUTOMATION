void handleRoot() {
  Serial.println("Enter handleRoot");
  String header;
  if (!is_authenticated()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }
  
  String content = "<body><div style='text-align: center'>";
  content +="<style>html body { width: 100wh; height: 90vh; color: #fff;background: linear-gradient(-45deg, #d7cd0c, #600c0c, #1a1719, #20e1c6);  background-size: 400% 400%; -webkit-animation: Gradient 15s ease infinite;  -moz-animation: Gradient 15s ease infinite; animation: Gradient 15s ease infinite;}@-webkit-keyframes Gradient {0% {  background-position: 0% 50% }50% {  background-position: 100% 50% } 100% {  background-position: 0% 50% }}@-moz-keyframes Gradient {0% {background-position: 0% 50% }50% {background-position: 100% 50%}100% {  background-position: 0% 50% }}@keyframes Gradient {0% {background-position: 0% 50%  }50% {  background-position: 100% 50%}100% {background-position: 0% 50% }}h1,h6 { font-family: 'Open Sans';font-weight: 300;  text-align: center; position: bsolute;  top: 45%; right: 0;left: 0;}\n";
  content +=".btn{  border:0;  background: none;  display: block;  margin: 20px auto;  text-align: center;  border: 2px solid #f3ca1a;  padding: 14px 40px;  outline: none;  color: white;  border-radius: 24px;  transition: 0.25s;  cursor: pointer;}";
  content +=".btn:hover{  background: #f3ca1a;}";
  content +=".dcnt{  border:0;  background: none;  display: block;  margin: 20px auto;  text-align: center;  border: 2px solid red;  padding: 2px 20px;  outline: none;  color: white;  border-radius: 24px;  transition: 0.25s;  cursor: pointer;}";
  content +=".dcnt:hover{  background: red;}";
  content +="*{margin: 0px;    padding: 0px;} body{  font-family: 'Exo', sans-serif;}";
content +=".context {    width: 100%;    position: absolute;    top:5vh;}";
content +=".context h1{ text-align: center;    color: #fff;    font-size: 50px;}";
content +=".area{  background: transparent;  background: -webkit-linear-gradient(to left, #8f94fb, #4e54c8); width: 100%;   height:100vh; }";
content +=".circles{    position: absolute;    top: 0;    left: 0;    width: 100%;    height: 100%;   }";
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
  content +="</style>\n";
  content += "<br><hr />";
    content +="<head><meta charset=\"utf-8\"><link rel=\"stylesheet\" href=\"style.css\"></head><body>";
    content +="<H1 style='color:white;'>HOME AUTOMATION</H1>";
  content += "<marquee><h3 style='color:white;'> EEE-we connect,we electrify, we lightify </h3></marquee>";
  content += "<hr Size=20 noshade/>";
   content +="<div class=\"area\" ><ul class=\"circles\"><li></li><li></li><li></li><li></li><li></li><li></li><li></li><li></li><li></li><li></li>";
  content += "<br><br><br><br><br><br><button class=\"btn\" onclick=\"window.location.href='/room1'\">ROOM 1</button>";
  content +="<br><button class=\"btn\" onclick=\"window.location.href='/room2'\">ROOM 2</button>";
  content +="<br> <button class=\"btn\" onclick=\"window.location.href='/room3'\">ROOM 3</button>";
  content +="<br><button class=\"btn\" onclick=\"window.location.href='/outdoor'\">OUT DOOR</button>";
  content +="<br><button class=\"btn\" onclick=\"window.location.href='/timeswitch'\">TIME CONTROLL</button>";
  content +="<br><button class=\"btn\" onclick=\"window.location.href='/reset'\">RESET</button>";
  content += "<button class=\"dcnt\" onclick=\"window.location.href='/login'\">Disconnect</button>";
  content +="</ul></div></body></html>";
  server.send(200, "text/html", content);
}
