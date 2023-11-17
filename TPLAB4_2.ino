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

struct ambiente{
  float cocina;
  float living;
  float dormitorio1;
  float dormitorio2;
  char SW_1;
  char SW_2;
  char SW_3;
  char SW_4;
  
};
    
ambiente casa;
    
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
  casa.SW_1='0';
  casa.SW_2='0';
  casa.SW_3='0';
  casa.SW_4='0';
  
  
}

void loop() {    
  char *salidas;
  int k;
  salidas=lamparas;
  
  contador++;
  
  if (digitalRead(SW1)){
    if (enable1==0){ 
     
        casa.SW_1='1';
        enable1=1;
    }
    else{
    
        casa.SW_1='0';  
        enable1=0;
    }
  }

   if (digitalRead(SW2)){
    if (enable2==0){ 
    
        casa.SW_2='1';
        enable2=1;
    }
    else{
    
        casa.SW_2='0';
        enable2=0;
    }
  }
  if (digitalRead(SW3)){
    if (enable3==0){ 
    
        casa.SW_3='1';
        enable3=1;
    }
    else{
    
        casa.SW_3='0';
        enable3=0;
    }
  }

   if (digitalRead(SW4)){
    if (enable4==0){ 
    
        casa.SW_4='1';
        enable4=1;
    }
    else{
    
        casa.SW_4='0';
        enable4=0;
    }
  }  

  //Serial.println(lamparas);
  
  
    if (casa.SW_1=='1') 
      digitalWrite (6, HIGH);
    else 
      digitalWrite (6, LOW);

    if (casa.SW_2=='1') 
      digitalWrite (7, HIGH);
    else 
      digitalWrite (7, LOW);
  
    if (casa.SW_3=='1') 
      digitalWrite (8, HIGH);
    else 
      digitalWrite (8, LOW);
  
    if (casa.SW_4=='1') 
      digitalWrite (9, HIGH);
    else 
      digitalWrite (9, LOW);
  
  
  //lectura de temperaturas
   myTime = millis();
   diftime=myTime-contador;
   //Serial.println(diftime);
   if (diftime>=1000){
     
      casa.cocina=analogRead(0)/10.0;
      casa.living=analogRead(1)/10.0;
      casa.dormitorio1=analogRead(2)/10.0;
      casa.dormitorio2=analogRead(3)/10.0;
      
      Serial.print(" temp. cocina=");
      Serial.print(casa.cocina);
      Serial.print(" temp. living=");
      Serial.print(casa.living);
      Serial.print(" temp. dormitorio1=");
      Serial.print(casa.dormitorio1);
      Serial.print(" temp. dormitorio2=");
      Serial.print(casa.dormitorio2);
      Serial.println(" ");     
      contador=myTime;
    }

}
     
