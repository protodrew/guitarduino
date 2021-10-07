int sol1 = 2;
int sol2 = 4;
int sol3 = 6;
int sol4 = 8;
int mot = 10;

struct Note{
     int solenoid; // 1-4 (will be multiplied by 2 when outputting to pin)
     int string; // 1-6

};

struct Pentatonic{
    char key;
    int keyType; // major = 1, minor =  0
    Note notes[5];
};
  
void setup() {
  pinMode(sol1, OUTPUT);
  pinMode(sol2, OUTPUT);
  pinMode(sol3, OUTPUT);
  pinMode(sol4, OUTPUT);
  Serial.begin(9600);
  question();
}

void loop(){

  while (Serial.available() == 0) {
    // Wait for User to Input Data
  }
  String temp = Serial.readString();
  char *input;
  temp.toCharArray(input,50);
  char inpKey = strtok(input,",");
  char inp2 = strtok(input,","); // temporary, for validation and conversion
  char pent = strtok(NULL,",");
  int inpKeyType = validate(inp2);
  int isPenta = 1; // will eventually be mutable if pentatonic playing goes smoothly and we have more time

  struct Pentatonic toPlay;
  toPlay.key = inpKey;
  toPlay.keyType = inpKeyType; 
  //Notes will be filled in seperate function
  
  


}

int validate(char temp){
  switch(temp){ // TODO, lowercase conversion for cleaner code
    case 'y':
      return 1;
    case 'Y':
      return 1;
    case 'n':
      return 0;
     case 'N':
      return 0;
    default:
      Serial.println("INVALID KEY TYPE, defaulting to major and pentatonic");
      return 1;
  }
}

void play(Pentatonic scale){
  /* TODO organize solanoid input
   *  via a switch...case
   */
}

void fillNotes(struct pentatonic *scale){
  /*
   * TODO, write a looped switch...case to fill struct's Note array
   */
}

void question(){
  Serial.println("what scale are we playing? (seperate with commas)\n+-----------+--------+-------------+\n|    Key    | Major? | Pentatonic? |\n+-----------+--------+-------------+\n| c,d,e...  | Y/n    | Y/n         |\n+-----------+--------+-------------+");
}
