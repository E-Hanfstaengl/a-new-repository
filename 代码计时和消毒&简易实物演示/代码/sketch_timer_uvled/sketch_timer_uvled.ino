#include<LiquidCrystal.h> 
#define buzzer 4
#define BUTTON 5
#define LED 9//消毒完毕提示灯
LiquidCrystal lcd(2,3,12,11,10,13);
int a=0;//时间设定
int b=0;
int c=0;
int val=0;//储存紫外灯按钮状态
int old_val=0;
int state=0;//0紫外灯关闭1打开
void setup() {
  lcd.begin(16,2);
  lcd.print("Youhaveusedfor:");
  pinMode(buzzer,OUTPUT);
  for(int UVLED=6;UVLED<=8;UVLED++){
   pinMode(UVLED,OUTPUT); 
   }
   pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT);
}
void loop(){
lcd.setCursor(0,1);//以下为计时 显示以及蜂鸣器提醒
  if(millis()<=216000000){
  if(millis()<=60000){a=0;b=0;c=millis()/1000;}
  if((millis()>60000)&&(millis()<=3600000)){
    a=0;
    b=int (millis()/60000);
    c=(millis()-(60000*b))/1000;
  }
  if((millis()>3600000)){
    a=int (millis()/3600000);
    b=int ((millis()-a*3600000)/60000);
    c=(millis()-(3600000*a)-(60000*b))/1000;
  }
  lcd.print(a);
  lcd.setCursor(2,1);
  lcd.print(":");
  lcd.setCursor(3,1);
  lcd.print(b);
  lcd.setCursor(5,1);
  lcd.print(":");
  lcd.setCursor(6,1);
    lcd.print(c);}
  else{lcd.print("TIME IS UP");
      digitalWrite(buzzer,HIGH);}//以下为按键控制紫外灯亮起
      val=digitalRead(BUTTON);//读取按钮输入并存储，检查变化情况
  if((val==HIGH)&&(old_val==LOW)){
    state=1-state;
    delay(1000);
    }
    old_val=val;//暂存
    if(state==1){
      for(int UVLED=6;UVLED<=8;UVLED++){
       digitalWrite(UVLED,HIGH);}
       digitalWrite(LED,LOW);
        delay(900000);//消毒时间15分钟
        for(int UVLED=6;UVLED<=8;UVLED++){
       digitalWrite(UVLED,LOW);}
       digitalWrite(LED,HIGH);
       delay(300000);
       }
      else{
        for(int UVLED=6;UVLED<=8;UVLED++){
       digitalWrite(UVLED,LOW);}
       delay(600);
        }}
