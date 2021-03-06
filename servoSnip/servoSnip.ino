#include <Servo.h>

const int rightHandLength = 16;
const int leftHandLength = 1;
int currentTime = 0;

/*
 *int noteTimesRight[rightHandLength];
 *Servo notesRight[rightHandLength];
 *int noteTimesLeft[leftHandLength];
 *Servo notesLeft[leftHandLength];
 */

Servo chnote;
Servo dnote;
Servo enote;
Servo fsnote;
Servo gnote;
Servo anote;

Servo currentLeftNote;
Servo currentRightNote;

int[] noteTimesRight = {0,1,2,3,9,10,11,18,19,20,22,24,26,27,29,30};
Servo[] notesRight = {enote,enote,fsnote,gnote,dnote,dnote,anote,gnote,fsnote,enote,enote,enote,fsnote,gnote,anote,gnote};
int[] noteTimesLeft = {0};
Servo[] notesLeft = {chnote};

int nextTimeRight = 0; // time of next note for right hand
int nextTimeLeft = 0; // time of next note for right hand
int nextIndexRight = 0; // time of next index of right hand note
int nextIndexLeft = 0; // time of next index of left hand note

void setup(){
  chnote.attach(3);
  dnote.attach(5);
  enote.attach(6);
  fsnote.attach(9);
  gnote.attach(10);
  anote.attach(11);
}

void keypressLeft(){
  Servo note = notesLeft[nextIndexLeft];
  currentLeftNote.write(0);
  note.write(70);
  nextTimeLeft = noteTimesLeft[nextIndexLeft+1];
  nextIndexLeft++;
  currentLeftNote = note;
}

void keypressRight(){
  Servo note = notesRight[nextIndexRight];
  currentRightNote.write(0);
  note.write(70);
  nextTimeRight = noteTimesRight[nextIndexRight+1];
  nextIndexRight++;
  currentRightNote = note;
}

void loop(){
  currentTime++;
  if(currentTime > nextTimeRight && currentTime > nextTimeLeft){
    keypressLeft();
    keypressRight();
  }else if(currentTime > nextTimeRight){
    keypressRight();
  }else if(currentTime > nextTimeLeft){
    keypressLeft();
  }
}
