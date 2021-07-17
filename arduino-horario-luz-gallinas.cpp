int segundo,minuto,hora,dia,mes,diaDeLaSemana;

DateTime HoraFecha;

void setup () {
  Serial.begin(9600);
  rtc.begin(); //Inicializamos el RTC
  pinMode(12, OUTPUT);
}

void loop () {
    HoraFecha = rtc.now(); //obtenemos la hora y fecha actual
    
    segundo=HoraFecha.second();
    minuto=HoraFecha.minute();
    hora=HoraFecha.hour();
    diaDeLaSemana=HoraFecha.dayOfTheWeek(); //0:Dominogo, 1:Lunes, 2:Martes ...
    
    float horas=hora+minuto/60.0;

    //condicion: >Domingo y  <sabado    y   >6.30pm  y <11.30pm
    if(diaDeLaSemana>=0&&diaDeLaSemana<7 && horas>6.75&&horas<8.0 || horas>18.5&&horas<19.75)
    {
      digitalWrite(12, HIGH);
      Serial.print("Salida digital 13 = ON");
    }
    else
    {
      digitalWrite(12, LOW);
      Serial.print("Salida digital 13 = OFF");
    }

    //Enviamos por el puerto serie la hora y fecha.
    Serial.print("   hora = ");
    Serial.print(hora);
    Serial.print(":");
    Serial.print(minuto);
    Serial.print(":");
    Serial.print(segundo);
    Serial.print("  dia de La semana = ");
    Serial.print(HoraFecha.dayOfTheWeek());
    Serial.println();
    delay(1000);
}