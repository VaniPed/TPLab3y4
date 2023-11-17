#define SW4 2
#define SW3 3
#define SW2 4
#define SW1 5

#define LAMP1 9
#define LAMP2 8
#define LAMP3 7
#define LAMP4 6

int enable1=0;
int enable2=0;
int enable3=0;
int enable4=0;
char lamparas[5]="0000";
float temperaturas[4];
float *tempe;
unsigned long contador=0;
unsigned long myTime;
unsigned long diftime;

void setup() {              
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  tempe=temperaturas;
}

void loop() {    
  char *salidas;
  int k;
  salidas=lamparas;
  
  contador++;
  
  if (digitalRead(SW1)){
    if (enable1==0){ 
     
        lamparas[0]='1';
        enable1=1;
    }
    else{
    
        lamparas[0]='0';  
        enable1=0;
    }
  }

   if (digitalRead(SW2)){
    if (enable2==0){ 
    
        lamparas[1]='1';
        enable2=1;
    }
    else{
    
        lamparas[1]='0';
        enable2=0;
    }
  }
  if (digitalRead(SW3)){
    if (enable3==0){ 
    
        lamparas[2]='1';
        enable3=1;
    }
    else{
    
        lamparas[2]='0';
        enable3=0;
    }
  }

   if (digitalRead(SW4)){
    if (enable4==0){ 
    
        lamparas[3]='1';
        enable4=1;
    }
    else{
    
        lamparas[3]='0';
        enable4=0;
    }
  }  

  //Serial.println(lamparas);
  
  for (k=0; k<4; k++){
    if (*(lamparas+k)=='1') 
      digitalWrite (6+k, HIGH);
    else 
      digitalWrite (6+k, LOW);
   }
  //lectura de temperaturas
   myTime = millis();
   diftime=myTime-contador;
   Serial.println(diftime);
   if (diftime>=1000){
     for(k=0;k<4;k++){
      temperaturas[k]=analogRead(0+k)/10.0;
     }
     tempe=temperaturas;
     for(k=0;k<4;k++){
        Serial.print(" temperatura ");
      Serial.print(k);
      Serial.print("= ");
      Serial.print(*tempe);
        tempe++;
     }
     Serial.println(" ");
     contador=myTime;
    }
  
}
    
