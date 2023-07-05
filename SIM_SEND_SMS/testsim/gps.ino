void GPS(){
   while (Serial.available()) 
  {
    if (gps.encode(Serial.read())) 
    {
        Lat = gps.location.lat();
        Lng = gps.location.lng(); 
       }
    }
}
