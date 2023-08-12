void startSever() {
  webServer.on("/", [] {
    String s = MainPage;
    webServer.send(200, "text/html", s);
  });
  webServer.on("/flow.html", []() {
    String s = flowPage;
    webServer.send(200, "text/html", s);
  });
  webServer.on("/add.html", []() {
    String s = addPage;
    webServer.send(200, "text/html", s);
  });
}