#include <Servo.h>

int movable[6];
movable[0] = 3;
movable[1] = 5;
movable[2] = 6;
movable[3] = 9;
movable[4] = 10;
movable[5] = 11;

const int rightHandLength;
const int leftHandLength;

int noteTimesRight[rightHandLength];
int notesRight[rightHandLength];
int noteTimesLeft[leftHandLength];
int notesLeft[leftHandLength];

int nextTimeRight = 0; // time of next note for right hand
int nextTimeLeft = 0; // time of next note for right hand
int nextIndexRight = 0; // time of next index of right hand note
int nextIndexLeft = 0; // time of next index of left hand note

void setup(){
}

void keypressLeft(){
  note = notes[nextIndexLeft];
  note.write(70);
  nextTimeLeft = noteTimes[nextIndexLeft+1];
  nextIndexLeft++;
}

void keypressRight(){
  note = notes[nextIndexRight];
  note.write(70);
  nextTimeRight = noteTimes[nextIndexRight+1];
  nextIndexRight++;
}

void loop(){
  currentTime = Wire.read(); // gives time
  if(currentTime > nextTimeRight && curentTime > nextTimeLeft){
    keypressLeft();
    keypressRight();
  }else if(currentTime > nextTimeRight){
    keypressRight();
  }else if(currentTime > nextTimeLeft){
    keypressLeft();
  }
}
