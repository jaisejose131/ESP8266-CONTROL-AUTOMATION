
String content(uint8_t led){
  String content = "<!DOCTYPE html>\n";
  content += "<body><center><div style='text-align: center'>";
  content += "<body><body bgcolor='black'>";
  content += "<H1 style='color:white;'>ROOM CONTROL</H1>"; 
  content += "<br><hr />";
  content += "<marquee><h3 style='color:white;'> ~~~ save energy  ** switch off all after use ** save electricity ~~~ </h3></marquee>";  
  content +="<head>";
  content +="<meta charset=\"utf-8\"><link rel=\"stylesheet\" href=\"style.css\">";
   content +="<script>var connection = new WebSocket('ws://'+location.hostname+':81/', ['arduino']);connection.onopen = function () {  connection.send('Connect ' + new Date()); }; connection.onerror = function (error) {    console.log('WebSocket Error ', error);};connection.onmessage = function (e) {  console.log('Server: ', e.data);};";
  content +="function sendRGB() {  var r = parseInt(document.getElementById('r').value).toString(16);";
  content +="if(r.length < 2) { r = '0' + r; }   "; 
  content +="var rgb = '#'+r;    console.log('RGB: ' + rgb); connection.send(rgb); }";
  content +="</script>";
  content +="</head><body>";
   content +="<div class=\"area\" ><ul class=\"circles\"><li></li><li></li><li></li><li></li><li></li><li></li><li></li><li></li><li></li><li></li>";
  
  if(statusroom1==HIGH && statusroom2==LOW && statusroom3==LOW && statusoutdoor==LOW && statusreset==LOW){
    content +="<br><br><br><br><br><br><br><button class=\"btn\" onclick=\"window.location.href='/light1on'\">LIGHT ON</button>";
    if(status2==HIGH){
       content +="<input id=\"r\" type=\"range\" min=\"0\" max=\"255\" step=\"1\" oninput=\"sendRGB();\" />";
    }
    content +="<button class=\"btn\" onclick=\"window.location.href='/light1off'\">LIGHT OFF</button>";
    content +="<br><button class=\"btn\" onclick=\"window.location.href='/fan1on'\">FAN ON</button>";
    content +="<button class=\"btn\" onclick=\"window.location.href='/fan1off'\">FAN OFF</button>";
    content += "<button class=\"dcnt\" onclick=\"window.location.href='/login'\">Disconnect</button>";
    content += "<button class=\"home\" onclick=\"window.location.href='/root'\">Home</button>";
  }
  
  else if(statusroom2==HIGH && statusroom1==LOW && statusroom3==LOW &&  statusoutdoor==LOW && statusreset==LOW ){
     content +="<br><br><br><br><br><br><br><button class=\"btn\" onclick=\"window.location.href='/light2on'\">LIGHT ON</button>";
     if(status3==HIGH){
       content +=" <input id=\"r\" type=\"range\" min=\"0\" max=\"255\" step=\"1\" oninput=\"sendRGB();\" />";
     }
    content +="<button class=\"btn\" onclick=\"window.location.href='/light2off'\">LIGHT OFF</button>";
    content +="<br><button class=\"btn\" onclick=\"window.location.href='/fan2on'\">FAN ON</button>";
    content +="<button class=\"btn\" onclick=\"window.location.href='/fan2off'\">FAN OFF</button>";
    content += "<button class=\"dcnt\" onclick=\"window.location.href='/login'\">Disconnect</button>";
    content += "<button class=\"home\" onclick=\"window.location.href='/root'\">Home</button>";
  }
  else if(statusroom3==HIGH && statusroom2==LOW && statusroom1==LOW &&  statusoutdoor==LOW && statusreset==LOW ){
    content +="<br><br><br><br><br><br><br><button class=\"btn\" onclick=\"window.location.href='/light3on'\">LIGHT ON</button>";
    if(status4==HIGH){
       content +="<input id=\"r\" type=\"range\" min=\"0\" max=\"255\" step=\"1\" oninput=\"sendRGB();\" />";
    }
    content +="<button class=\"btn\" onclick=\"window.location.href='/light3off'\">LIGHT OFF</button>";
       content += "<button class=\"dcnt\" onclick=\"window.location.href='/login'\">Disconnect</button>";
    content += "<button class=\"home\" onclick=\"window.location.href='/root'\">Home</button>";
  }
  else if( statusoutdoor==HIGH && statusroom3==LOW && statusroom2==LOW && statusroom1==LOW && statusreset==LOW){
     content +="<br><br><br><br><br><br><br><button class=\"btn\" onclick=\"window.location.href='/pumpon'\">PUMP ON</button>";
    content +="<button class=\"btn\" onclick=\"window.location.href='/pumpoff'\">PUMP OFF</button>";
    content +="<br><button class=\"btn\" onclick=\"window.location.href='/gateon'\">GATE OPEN</button>";
    content +="<button class=\"btn\" onclick=\"window.location.href='/gateoff'\">GATE CLOSE</button>";
      content +="<br><button class=\"btn\" onclick=\"window.location.href='/parkinglighton'\">PARKING LIGHT ON</button>";
   content +="<button class=\"btn\" onclick=\"window.location.href='/parkinglightoff'\">PARKING LIGHT  OFF</button>";
   content +="<br><button class=\"btn\" onclick=\"window.location.href='/surroundinglighton'\">SURROUNDING LIGHT ON</button>";
   content +="<button class=\"btn\" onclick=\"window.location.href='/surroundinglightoff'\">SURROUNDING LIGHT  OFF</button>";
   content += "<button class=\"dcnt\" onclick=\"window.location.href='/login'\">Disconnect</button>";
    content += "<button class=\"home\" onclick=\"window.location.href='/root'\">Home</button>"; 
  }
   else if(statusreset==HIGH && statusoutdoor==LOW && statusroom3==LOW && statusroom2==LOW && statusroom1==LOW ){
     content +="<br><br><br><br><br><br><br><button class=\"btn\" onclick=\"window.location.href='/resetnow'\">RESET NOW </button>";
     content += "<button class=\"dcnt\" onclick=\"window.location.href='/login'\">Disconnect</button>";
    content += "<button class=\"home\" onclick=\"window.location.href='/root'\">Home</button>"; 
   }

  content +="</ul></div ></body>\n";
  content +="</center>\n";
   content +="<style>";
   content +="*{margin: 0px;    padding: 0px;} body{  font-family: 'Exo', sans-serif;}";
content +=".context {    width: 100%;    position: absolute;    top:5vh;}";
content +=".context h1{ text-align: center;    color: #fff;    font-size: 50px;}";
content +=".area{  background:transparent;  background: -webkit-linear-gradient(to left, #8f94fb, #4e54c8); width: 100%;   height:100vh; }";
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
  content +=".btn{  border:0;  background: none;  display: block;  margin: 20px auto;  text-align: center;  border: 2px solid #912ecc;  padding: 14px 40px;  outline: none;  color: white;  border-radius: 24px;  transition: 0.25s;  cursor: pointer;}";
  content +=".btnon{  border:0;  background: green;  display: block;  margin: 20px auto;  text-align: center;  border: 2px solid #912ecc;  padding: 14px 40px;  outline: none;  color: white;  border-radius: 24px;  transition: 0.25s;  cursor: pointer;}";
   content +=".btnoff{  border:0;  background: green;  display: block;  margin: 20px auto;  text-align: center;  border: 2px solid green;  padding: 14px 40px;  outline: none;  color: white;  border-radius: 24px;  transition: 0.25s;  cursor: pointer;}";
  content +=".btn:hover{  background: #912ecc;}";
  content +=".home{ border:0;  background: none;  display: block;  margin: 20px auto;  text-align: center;  border: 2px solid blue;  padding: 2px 20px;  outline: none;  color: white;  border-radius: 24px;  transition: 0.25s;  cursor: pointer;}";
  content +=".home:hover{  background: blue;}";
  content +=".dcnt{  border:0;  background: none;  display: block;  margin: 20px auto;  text-align: center;  border: 2px solid red;  padding: 2px 20px;  outline: none;  color: white;  border-radius: 24px;  transition: 0.25s;  cursor: pointer;}";
  content +=".dcnt:hover{  background: red;}";
  content +="</style>\n";
  content +="</html>\n";
  return content;
 }
