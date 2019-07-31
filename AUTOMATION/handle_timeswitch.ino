 void handle_timeswitch() {
  String content ="<html><head>";
  content +="<script>var connection = new WebSocket('ws://'+location.hostname+':81/', ['arduino']);connection.onopen = function () {  connection.send('Connect ' + new Date()); }; connection.onerror = function (error) {    console.log('WebSocket Error ', error);};connection.onmessage = function (e) {  console.log('Server: ', e.data);};";
  content +="function sendRGB() {  var r = parseInt(document.getElementById('r').value).toString(16);";
  content +="if(r.length < 2) { r = '0' + r; }   "; 
  content +="var rgb = '#'+r;    console.log('RGB: ' + rgb); connection.send(rgb); }</script>";
  content +="</head><body>";
   if(statusroom1==HIGH ){
  content +=" Control light intensity of room1:<br/><br/>R: <input id=\"r\" type=\"range\" min=\"0\" max=\"255\" step=\"1\" oninput=\"sendRGB();\" /><br/>";
  }
  else if(statusroom2==HIGH){
    content +=" Control light intensity of room2:<br/><br/>R: <input id=\"r\" type=\"range\" min=\"0\" max=\"255\" step=\"1\" oninput=\"sendRGB();\" /><br/>"; 
  }
  else if(statusroom3==HIGH){
     content +=" Control light intensity of room3:<br/><br/>R: <input id=\"r\" type=\"range\" min=\"0\" max=\"255\" step=\"1\" oninput=\"sendRGB();\" /><br/>";
  }

  content +="</body></html>";
      server.send(200, "text/html", content);
  }
 
