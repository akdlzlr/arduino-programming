
int seg[]={6,7,8,9,10,11,12};
int sel[]={2,3,4,5};

byte digits[10][7] =
{
 {1,1,1,1,1,1,0},
 {0,1,1,0,0,0,0},
 {1,1,0,1,1,0,1},
 {1,1,1,1,0,0,1},
 {0,1,1,0,0,1,1},
 {1,0,1,1,0,1,1},
 {1,0,1,1,1,1,1},
 {1,1,1,0,0,0,0},
 {1,1,1,1,1,1,1},
 {1,1,1,0,0,1,1} 
};

int cnt=0;
int num=0;
int num2=0;

boolean start=false;

void setup() {
  // put your setup code here, to run once:
  for(int i=2;i<=12;i++){
    pinMode(i,OUTPUT);
  }
  
  digitalWrite(sel[0],HIGH);
  digitalWrite(sel[1],HIGH);
  digitalWrite(sel[2],HIGH);
  digitalWrite(sel[3],HIGH);

  pinMode(A5,INPUT);
  pinMode(A4,INPUT);
  pinMode(A3,INPUT);
  pinMode(A2,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a=digitalRead(A5);
  int b=digitalRead(A4);
  int c=digitalRead(A3);
  int d=digitalRead(A2);
  
  if(a==HIGH){
    num2--;
    if(num2<0){
      num2=0;
    }
    delay(400);
  }
  if(b==HIGH){
    num2++;
    if(num2>60){
      num2=0;
    }
    delay(400);
  }
   if(c==HIGH){
    start=true;
    delay(400);
  }
   if(d==HIGH){
    num=0;
    start=false;
    delay(400);
  }
  int val1=num%10;
  int val2=(num/10)%10;
  
  selSeg(2);
  displayDigit(val2);
  delay(1);

  selSeg(3);
  displayDigit(val1);
  delay(1);

  selSeg(0);
  displayDigit((num2/10)%10);
  delay(1);

  selSeg(1);
  displayDigit(num2%10);
  delay(1);
    
  if(start==true){
    cnt++;
    if(cnt==250){
        num++;
        cnt=0;
    }
  }

  if(num==num2&&num2!=0){
    num=0;
    tone(A0,3521,100);
    delay(200);
    noTone(A0);
    start=false;
  }

  
}

void displayDigit(int num){
  int pin =6;
  for(int i =0 ;i <=12;i++){
    digitalWrite(pin+i,digits[num][i]);
  }
}

void selSeg(int num){
  digitalWrite(sel[0],HIGH);
  digitalWrite(sel[1],HIGH);
  digitalWrite(sel[2],HIGH);
  digitalWrite(sel[3],HIGH);
  
  digitalWrite(sel[num],LOW);
}
