//Joy stick Stuff
#define JoyX A1
#define JoyY A0
int XJ;
int YJ;
int YC;
int XC;

const byte Row[] = {A5,3,6,A2,13,7,12,9};
const byte Col[] = {2,11,10,A4,8,A3,4,5};

void setup() {
  
  Serial.begin(9600);
  
  for(int x=0; x<8; x+=1){
    pinMode(Row[x], OUTPUT);
    digitalWrite(Row[x], HIGH);
  }
  for(int y=0; y<8; y+=1){
    pinMode(Col[y], OUTPUT);
    digitalWrite(Col[y], LOW);
  }
  XJ = 0;
  YJ = 0;
  YC = 0;
  XC = 0;
}

void loop() {
  
  int ReadX = analogRead(JoyX);
  int ReadY = analogRead(JoyY);
 
  XJ = ReadX/137.1428571;
  YJ = ReadY/137.1428571;
  
  Serial.print(XJ);
  Serial.print(" ");
  Serial.println(YJ);
  
  digitalWrite(Row[XJ],LOW);
  digitalWrite(Col[YJ],HIGH);

  
  if (XJ != XC){
    //digitalWrite(Row[XC],HIGH);
    //digitalWrite(Col[YC],LOW);
  }
  if (YJ != YC){
    //digitalWrite(Col[YC],LOW);
    //digitalWrite(Row[XC],HIGH);
  }
  
  XC = XJ;
  YC = YJ;
}
