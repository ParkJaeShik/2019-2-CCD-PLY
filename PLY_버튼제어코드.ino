#include <SoftwareSerial.h> // 시리얼통신 라이브러리 호출

int blueTx = 2;    // Tx (보내는 핀 설정)
int blueRx = 3;    // Rx (받는 핀 설정)
SoftwareSerial mySerial(blueTx, blueRx); // 시리얼 통신을 위한 객체선언

#define MAX 5
char whichSensor[MAX];

int Sensor1 = 7;    // 센서핀을 7번에 연결
int Sensor2 = 8;    // 센서핀을 8번에 연결
int Sensor3 = 9;    // 센서핀을 9번에 연결
int Button1 = 11;   // 버튼을 11번에 연결
int Button2 = 12;   // 버튼을 12번에 연결
int Button3 = 13;   // 버튼을 13번에 연결
int Buzzer = 4;     // 버저핀을 4번에 연결

int val1, val2, val3;  // 적외선 센서값 읽을 변수 
int btn1, btn2, btn3;  // 버튼 입력값을 읽을 변수  

void setup () {
  Serial.begin(9600);        // 시리얼 모니터, PC와 연결
  mySerial.begin(9600);      // 블루투스 시리얼, 블루투스와 연결
  
  pinMode(Buzzer, OUTPUT);   // 버저를 출력으로 설정
  pinMode(Sensor1, INPUT);   // 센서값을 입력으로 설정
  pinMode(Sensor2, INPUT);   
  pinMode(Sensor3, INPUT);
  pinMode(Button1, INPUT);   // 버튼을 입력으로
  pinMode(Button2, INPUT);
  pinMode(Button3, INPUT);
}
 
void loop () {
  if (mySerial.available()) {                          // 블루투스로 데이터 받으면
    
    int i;
    for(i=0; i<MAX; i++) {
      whichSensor[i] = mySerial.read();                     // whichSensor[i]에 저장
      Serial.println("저장완료");
    }  

    for(i=0; i<MAX; i++) {
      Serial.write(whichSensor[i]);                         // 시리얼 모니터에 whichSensor[i]에 저장된 값 출력
      Serial.println("");
    
     val1 = digitalRead(Sensor1);                      // 센서값 읽어옴
     val2 = digitalRead(Sensor2);
     val3 = digitalRead(Sensor3); 

     btn1 = digitalRead(Button1);
     btn2 = digitalRead(Button2);
     btn3 = digitalRead(Button3);
    
     while(whichSensor[i] != '0') {                       // 블루투스에 0 입력시 또는 값이 없을 시 while문 중단, 버튼 제어 중단
      
         val1 = digitalRead(Sensor1);                  // 센서값 읽어옴
         val2 = digitalRead(Sensor2);
         val3 = digitalRead(Sensor3);

         btn1 = digitalRead(Button1);
         btn2 = digitalRead(Button2);
         btn3 = digitalRead(Button3);
              
         if(whichSensor[i] == '1') {                      // 1을 입력하면 Sensor1에게 다가갈 때 거리 감지만 가능, 나머지는 버저 작동까지 가능  
             if (val1 == 0) {                             // 0은 장애물이 감지 되었을 때 나오는 출력값
                  Serial.println("check1");
                  Serial.println("확인완료");
                  noTone(Buzzer);
                  delay(100);
                  if (btn1 == LOW) {                      // LOW는 버튼이 눌려졌을 때 나오는 출력값
                      delay(1000);                        // 버튼이 여러번 눌리는 현상을 방지하기 위해 1초동안 delay 설정
                      break;                              // 해당 순서의 버튼이 눌렸으므로 다음 원소(다음 버튼의 순서)로 이동
                  }
             }
          
             else if (val2 == 0 || val3 == 0) {
                   Serial.println("check 2 or 3");
                   tone(Buzzer,220);                    // 버저가 울린다
                   delay(100);     
             }
          
             else {
                   Serial.println("nocheck");
                   noTone(Buzzer);
                   delay(100);
             }
          }
          
         else if (whichSensor[i] == '2') {                 // 2를 입력하면 Sensor2에게 다가갈 때 거리 감지만 가능, 나머지는 버저 작동까지 가능 
             if (val2 == 0) {
                   Serial.println("check2");
                   Serial.println("확인완료");
                   noTone(Buzzer);
                   delay(100);
                   if (btn2 == LOW) { 
                      delay(1000);
                      break;
                  }
             }
          
             else if (val1 == 0 || val3 == 0) {
                   Serial.println("check1 or 3");
                   tone(Buzzer,220);                    // 버저가 울린다
                   delay(100);     
             }
          
             else {
                   Serial.println("nocheck");
                   noTone(Buzzer);
                   delay(100);
             }     
               
         }
          
         else if (whichSensor[i] == '3') {                   // 3  
             if (val3 == 0) {
                     Serial.println("check3");
                     Serial.println("확인완료");
                     noTone(Buzzer);
                     delay(100);
                     if (btn3 == LOW) {
                      delay(1000); 
                      break;
                  }
             }
          
             else if (val1 == 0 || val2 == 0) {
                     Serial.println("check1 or 2");
                     tone(Buzzer,220);                    // 버저가 울린다
                     delay(100);     
             }
          
             else {
                     Serial.println("nocheck");
                     noTone(Buzzer);
                     delay(100);
             }
         }
          
         else {
                noTone(Buzzer);
                delay(100);
         } 
     }  
     }
  }
}
