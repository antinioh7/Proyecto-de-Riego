#include <SFE_BMP180.h>
#include <Wire.h>
int input;
SFE_BMP180 bmp180;

void setup()
{
  pinMode(8,OUTPUT); // Bomba
  pinMode(9,OUTPUT); // Valvula1
  pinMode(10,OUTPUT); // Valvula2
  Serial.begin(9600);

  if (bmp180.begin())
    Serial.println("BMP180 iniciado correctamenten");
  else
  {
    Serial.println("Error al iniciar el BMP180");
    while(1); // bucle infinito
  }
}

void loop()
{
  char status;
  double T,P;
 
  input=Serial.read();
  if (input=='Q'){
    digitalWrite(8, HIGH); //Si el valor de input es 1, se enciende el led
    }
    else if(input=='W'){
      digitalWrite(8, LOW); //Si el valor de input es 1, se enciende el led
    }
    if (input=='A'){
    digitalWrite(9, HIGH); //Si el valor de input es 1, se enciende el led
    }
    else if(input=='S'){
      digitalWrite(9, LOW); //Si el valor de input es 1, se enciende el led
    }
    if (input=='Z'){
    digitalWrite(10, HIGH); //Si el valor de input es 1, se enciende el led
    }
    else if(input=='X'){
      digitalWrite(10, LOW); //Si el valor de input es 1, se enciende el led
    }
  status = bmp180.startTemperature();//Inicio de lectura de temperatura
  if (status != 0)
  {   
    delay(status); //Pausa para que finalice la lectura
    status = bmp180.getTemperature(T); //Obtener la temperatura
    if (status != 0)
    {
      status = bmp180.startPressure(3); //Inicio lectura de presión
      if (status != 0)
      {        
        delay(status);//Pausa para que finalice la lectura        
        status = bmp180.getPressure(P,T); //Obtenemos la presión
        if (status != 0)
        {
          Serial.print("Presion: ");
          Serial.print(P);
          Serial.print(" mb ");
          Serial.print("Temp: ");
          Serial.print(T);
          Serial.println(" °C");
          ;          
        }      
      }      
    }   
  } 
  delay(100);
}
