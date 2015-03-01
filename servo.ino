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

noteTimesRight = {1, 1, 1, 2, 3, 1, 1, 1, 2, 2, 1, 1, 1, 1, 2, 2, 1, 4, 4, 1, 1, 1, 2, 3, 1, 1, 1, 2, 2, 1, 1, 1, 1, 2, 2, 1, 4, 3, 1, 2, 2, 2, 1, 1, 1, 1, 1, 3, 1, 1, 1, 4, 1, 1, 8, 1, 1, 1, 1, 3, 1, 3, 4, 1, 1, 1, 4, 1, 1, 11, 1, 2, 2, 3, 2, 2, 2, 2, 1, 2, 2, 1, 10, 1, 1, 1, 2, 3, 1, 1, 2, 2, 18, 1, 2, 2, 3, 1, 2, 2, 3, 1, 1, 1, 2, 1, 1, 2, 2, 2, 3, 1, 2, 2, 3, 1, 2, 1, 15, 1, 2, 2, 10, 1, 1, 6, 1, 1, 7, 2, 2, 2, 1, 2, 6, 1, 1, 6, 1, 1, 6, 1, 1, 2, 2, 2, 1, 1, 1, 1, 7, 3, 3, 6, 2, 2, 3, 3, 8, 1, 1, 3, 3, 9, 1, 2, 1, 1, 1, 1, 1, 1, 1, 7};
notesRight = {7, 8, 0, 7, 8, 7, 8, 0, 8, 7, -2, 5, 7, -2, 5, 7, -2, 3, 1, 7, 8, 0, 7, 8, 8, 7, 0, 8, 7, -2, 5, 7, -2, 5, 7, -2, 3, 2, -7, 0, 0, 0, 0, 0, 0, -2, -4, -4, -4, -4, -2, -2, -4, -5, -7, -7, 0, 0, 0, 0, 3, 3, 0, -4, -4, -2, 0, -2, -4, 0, 0, 0, 3, 5, 3, 0, 3, 3, 3, 1, 0, 1, 0, -2, 0, -2, -4, -2, -2, 0, -2, -4, -7, -2, -2, 3, 3, -2, -2, 5, 5, 5, 3, 5, 5, 3, 5, 7, 8, 7, 7, -2, -2, 3, 3, -2, 3, -2, 5, 3, 5, 7, 8, 5, 7, 8, 3, 3, 10, 8, 5, 5, 5, 6, 8, 5, 7, 8, 3, 12, 10, 8, 10, 12, 12, 13, 12, 10, 8, 10, 8, 15, 12, 10, 8, 8, 15, 12, 8, 8, 8, 7, 3, 5, -4, 1, 1, 0, 1, 0, 1, 1, 0, -4};
noteTimesLeft = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 2, 2, 4, 8, 8, 8, 8, 8, 8, 8, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 6, 10, 16};
notesLeft = {2, -2, 0, -5, 2, -2, 0, -5, 2, -2, 0, -5, 2, -2, 0, -5, 2, -2, 0, -5, 2, 0, -5, 2, -5, -5, 0, 0, -2, -2, 0, 0, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 5, 5, 5, 5, 0, 0, 0, 0, 2, 2, 2, 2, -2, -2, -2, -2, 5, 5, 5, 5, 0, 0, 0, 0, 2, 2, 2, 2, -2, -2, -2, -2, 5, 5, 5, 5, 0, 0, 0, 0, 2, 2, 2, 2, -2, -2, -2, -2, -3, 0, -2}

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
