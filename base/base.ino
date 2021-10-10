int solenoid[4] = {7,6,5,4}; // solenoid pins
int actuator[2] = {2,3};
int scale1[6][4] = {{1,1,0,1},{1,0,1,1},{1,0,1,1},{1,0,1,0},{1,1,0,1},{1,1,0,1}};
int strlength = 423;
void setup() {
  pinMode(solenoid[0], OUTPUT);
  pinMode(solenoid[1], OUTPUT);
  pinMode(solenoid[2], OUTPUT);
  pinMode(solenoid[3], OUTPUT);
  pinMode(actuator[0], OUTPUT);
  pinMode(actuator[1], OUTPUT);
  actu_control(-1);
    delay(3000);
}

void loop(){
    
    for(int x = 0; x < 6; x++){
      actu_control(1);
      delay(strlength);
      actu_control(0);
      for(int s = 0; s < 4; s++){
        
        if(scale1[x][s] == 1){
        digitalWrite(solenoid[s],HIGH);
         
        delay(200);
        digitalWrite(solenoid[s],LOW);
        
        delay(150);
        }
        
        
       
      }
      
      
    }
    actu_control(-1);
    delay(3000);
    actu_control(0);
}

void actu_control(int dir){
  if(dir==0) {
    digitalWrite(actuator[0], LOW);
    digitalWrite(actuator[1], LOW);
  }
  if(dir<0) {
    digitalWrite(actuator[0], HIGH);
    digitalWrite(actuator[1], LOW);
  }
  if(dir>0) {
    digitalWrite(actuator[0], LOW);
    digitalWrite(actuator[1], HIGH);
  }
}
