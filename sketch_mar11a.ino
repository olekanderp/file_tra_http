#include "DHT.h"
#define DHTPIN 5 // номер пина, к которому подсоединен датчик
DHT dht(DHTPIN, DHT11);

int incomingByte = 0;   // переменная для хранения полученного байта
long randNumber;  // ваги 
long randNumber_step; // шаг 
long divide = 0; 
long weight = 0; 
int j ;
int x;
int y = 0;
int y1 = 0;
int randNumber_step_2;
int sub;
int led_green = 8;
int led_red = 9;

int raw_1 = 0;//temp
float temp_1 = 0;//temp
int raw_2 = 0;//temp
float temp_2 = 0;//temp



void setup(){
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT); 
  Serial.begin(9600); // устанавливаем последовательное соединение
   
   dht.begin();
   pinMode( A0, INPUT );//temp
   pinMode( A1, INPUT );//temp
}

void loop() {


  
  





  
  while(1){    
    if (Serial.available() > 0) {  //если есть доступные данные
      // считываем байт
      incomingByte = Serial.read();
      // зелений
      if(weight == 0 and y == 0){
      digitalWrite(led_green, HIGH);
      digitalWrite(led_red, LOW);
      y = y + 1;
      incomingByte = 0;
      }                                                     
      // червоний
      if(weight > 0 and y == 1){
      digitalWrite(led_red, HIGH);
      digitalWrite(led_green, LOW);
      y = 0;
      incomingByte = 0;
      }        
      if(j == 0){
      randNumber = 10 *  (random(500, 8000));
      randNumber_step = 0.2 * randNumber;
      j = j + 1;  
      //ДІЛЕННЯ НА 10 ЩО ЗАВЖДИ БУВ 0 В КІНЦІ ЧИСЛА
      x = randNumber_step % 10;  
      sub = 10 - x;
      randNumber_step_2 = sub + randNumber_step;
      }
      // ЗБІЛЬШЕННЯ НА ПЕВНИЙ КРОК
      if(incomingByte == 67 and j < 6 and j > 0 ){
      weight = weight + randNumber_step_2;
      //Serial.println(weight, DEC);
      
      raw_1 = analogRead(A0);
      temp_1 = ( raw_1/1023.0 )*5.0*1000/10;
      Serial.print("LM351=");
      Serial.println(temp_1);

      raw_2 = analogRead(A1);
      temp_2 = ( raw_2/1023.0 )*5.0*1000/10;
      Serial.print("LM352=");
      Serial.println(temp_2);

      // Считываем температуру
      float t = dht.readTemperature();
      Serial.print("DHT11=");
      Serial.println(t);   
         
      incomingByte = 0; 
      j = j + 1;       
      }
      // ВИВОДИМ ТЕ ЩО ОТРИМАЛИ В РЕЗУЛЬТАТІ ДОДАВАННЯ
      if(incomingByte == 67 and j == 6){
      //Serial.println(weight, DEC);
      
      raw_1 = analogRead(A0);
      temp_1 = ( raw_1/1023.0 )*5.0*1000/10;
      Serial.print("LM351=");
      Serial.println(temp_1);

      raw_2 = analogRead(A1);
      temp_2 = ( raw_2/1023.0 )*5.0*1000/10;
      Serial.print("LM352=");
      Serial.println(temp_2);

      // Считываем температуру
      float t = dht.readTemperature();
      Serial.print("DHT11=");
      Serial.println(t);  
      
      delay(1000);
      incomingByte = 0; 
      j = j + 1;  
      }
      // ВОДІЙ ВИЙШОВ З МАШИНИ
      if(incomingByte == 67 and j == 7){
      weight = weight - 150 ;
      //Serial.println(weight, DEC);

      raw_1 = analogRead(A0);
      temp_1 = ( raw_1/1023.0 )*5.0*1000/10;
      Serial.print("LM351=");
      Serial.println(temp_1);

      raw_2 = analogRead(A1);
      temp_2 = ( raw_2/1023.0 )*5.0*1000/10;
      Serial.print("LM352=");
      Serial.println(temp_2);

      // Считываем температуру
      float t = dht.readTemperature();
      Serial.print("DHT11=");
      Serial.println(t);  
      
      delay(1000);         
      incomingByte = 0; 
      j = j + 1;  
      }
      // ВИВОДИМ ТЕ ЩО ОТРИМАЛИ В РЕЗУЛЬТАТІ ТОГО ЩО ВИЙЩОВ ВОДІЙ
      if(incomingByte == 67 and j == 8){
      //Serial.println(weight, DEC); 

      raw_1 = analogRead(A0);
      temp_1 = ( raw_1/1023.0 )*5.0*1000/10;
      Serial.print("LM351=");
      Serial.println(temp_1);

      raw_2 = analogRead(A1);
      temp_2 = ( raw_2/1023.0 )*5.0*1000/10;
      Serial.print("LM352=");
      Serial.println(temp_2);

      // Считываем температуру
      float t = dht.readTemperature();
      Serial.print("DHT11=");
      Serial.println(t);  
              
      incomingByte = 0; 
      j = j + 1;  
      }
      if(incomingByte == 67 and j == 9){
      Serial.println(weight, DEC);
        for(int r = 0; r <= 10; r++){
        weight = weight;
        //Serial.println(weight, DEC);

        raw_1 = analogRead(A0);
        temp_1 = ( raw_1/1023.0 )*5.0*1000/10;
        Serial.print("LM351=");
        Serial.println(temp_1);

        raw_2 = analogRead(A1);
        temp_2 = ( raw_2/1023.0 )*5.0*1000/10;
        Serial.print("LM351=");
        Serial.println(temp_2);

        // Считываем температуру
      float t = dht.readTemperature();
      Serial.print("DHT11=");
      Serial.println(t);  
        
        
        delay(1000);           
        }
      incomingByte = 0;   
      j = j + 1;  
      }     
      // ВОДІЙ  ЗАЙШОВ В МАШИНУ
      if(incomingByte == 67 and j == 10){
      weight = weight + 150 ;
      
      raw_1 = analogRead(A0);
      temp_1 = ( raw_1/1023.0 )*5.0*1000/10;
      Serial.print("LM351=");
      Serial.println(temp_1);

      raw_2 = analogRead(A1);
      temp_2 = ( raw_2/1023.0 )*5.0*1000/10;
      Serial.print("LM352=");
      Serial.println(temp_2);

      // Считываем температуру
      float t = dht.readTemperature();
      Serial.print("DHT11=");
      Serial.println(t);  

      
      delay(1000);              
      incomingByte = 0; 
      j = j + 1;  
      }                                                
      // ВИВОДИМ ВАГУ МАШИНИ І ВОДІЯ КОЛИ ВІН ЗАЙшОВ
      if(incomingByte == 67 and j == 11){
      //Serial.println(weight, DEC);

      raw_1 = analogRead(A0);
      temp_1 = ( raw_1/1023.0 )*5.0*1000/10;
      Serial.print("LM351=");
      Serial.println(temp_1);

      raw_2 = analogRead(A1);
      temp_2 = ( raw_2/1023.0 )*5.0*1000/10;
      Serial.print("LM352=");
      Serial.println(temp_2);

      // Считываем температуру
      float t = dht.readTemperature();
      Serial.print("DHT11=");
      Serial.println(t);  
      
      delay(1000);                 
      incomingByte = 0; 
      j = j + 1;  
      }
      if(incomingByte == 67 and j == 12){
      //Serial.println(weight, DEC);

      raw_1 = analogRead(A0);
      temp_1 = ( raw_1/1023.0 )*5.0*1000/10;
      Serial.print("LM351=");
      Serial.println(temp_1);

      raw_2 = analogRead(A1);
      temp_2 = ( raw_2/1023.0 )*5.0*1000/10;
      Serial.print("LM352=");
      Serial.println(temp_2);

      // Считываем температуру
      float t = dht.readTemperature();
      Serial.print("DHT11=");
      Serial.println(t);  
      
      delay(1000);                 
      incomingByte = 0; 
      j = j + 1;  
      }
      // ВОДІЙ ЗЇЖАЄ З ВАГІВ
      if(incomingByte == 67 and j >= 13 and j <= 17){
      weight = weight - randNumber_step_2;
      //Serial.println(weight, DEC);

      raw_1 = analogRead(A0);
      temp_1 = ( raw_1/1023.0 )*5.0*1000/10;
      Serial.print("LM351=");
      Serial.println(temp_1);

      raw_2 = analogRead(A1);
      temp_2 = ( raw_2/1023.0 )*5.0*1000/10;
      Serial.print("LM352=");
      Serial.println(temp_2);

      // Считываем температуру
      float t = dht.readTemperature();
      Serial.print("DHT11=");
      Serial.println(t);  

      
      delay(1000);
      incomingByte = 0; 
      j = j + 1;       
      }                                                                    
      // виводим 0
      if(incomingByte == 67 and j == 18){
      weight = 0;
      //Serial.println(weight, DEC);

      raw_1 = analogRead(A0);
      temp_1 = ( raw_1/1023.0 )*5.0*1000/10;
      Serial.print("LM351=");
      Serial.println(temp_1);

      raw_2 = analogRead(A1);
      temp_2 = ( raw_2/1023.0 )*5.0*1000/10;
      Serial.print("LM352=");
      Serial.println(temp_2);

      // Считываем температуру
      float t = dht.readTemperature();
      Serial.print("DHT11=");
      Serial.println(t);  


      
      delay(1000);
      incomingByte = 0; 
      j = j + 1;
      }
      if(incomingByte == 67 and j == 19){
      //Serial.println(weight, DEC);

      raw_1 = analogRead(A0);
      temp_1 = ( raw_1/1023.0 )*5.0*1000/10;
      Serial.print("LM351=");
      Serial.println(temp_1);

      raw_2 = analogRead(A1);
      temp_2 = ( raw_2/1023.0 )*5.0*1000/10;
      Serial.print("LM352=");
      Serial.println(temp_2);

      // Считываем температуру
      float t = dht.readTemperature();
      Serial.print("DHT11=");
      Serial.println(t);  


      
      delay(1000);
      incomingByte = 0; 
      j = j + 1;
      }
      if(incomingByte == 67 and j == 20){
      Serial.println(weight, DEC);
       for(int ri = 0; ri <= 10; ri++){
        weight = weight;
       // Serial.println(weight, DEC);

        raw_1 = analogRead(A0);
        temp_1 = ( raw_1/1023.0 )*5.0*1000/10;
        Serial.print("LM351=");
        Serial.println(temp_1);

        raw_2 = analogRead(A1);
        temp_2 = ( raw_2/1023.0 )*5.0*1000/10;
        Serial.print("LM352=");
        Serial.println(temp_2);

        // Считываем температуру
      float t = dht.readTemperature();
      Serial.print("DHT11");
      Serial.println(t);  


        
        delay(1000);           
        }
      incomingByte = 0; 
      j = 0;  
      }
    }                                                                     
  }
}

  

