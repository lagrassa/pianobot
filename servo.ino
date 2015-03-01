#include <Servo.h>

int movable[6];
movable[0] = 3;
movable[1] = 5;
movable[2] = 6;
movable[3] = 9;
movable[4] = 10;
movable[5] = 11;

const int rightHandLength = 174;
const int leftHandLength = 97;

int noteTimesRight[rightHandLength];
int notesRight[rightHandLength];
int noteTimesLeft[leftHandLength];
int notesLeft[leftHandLength];

noteTimesRight = {0, 1, 2, 3, 5, 8, 9, 10, 11, 13, 15, 16, 17, 18, 19, 21, 23, 24, 28, 32, 33, 34, 35, 37, 40, 41, 42, 43, 45, 47, 48, 49, 50, 51, 53, 55, 56, 60, 63, 64, 66, 68, 70, 71, 72, 73, 74, 75, 78, 79, 80, 81, 85, 86, 87, 95, 96, 97, 98, 99, 102, 103, 106, 110, 111, 112, 113, 117, 118, 119, 130, 131, 133, 135, 138, 140, 142, 144, 146, 147, 149, 151, 152, 162, 163, 164, 165, 167, 170, 171, 172, 174, 176, 194, 195, 197, 199, 202, 203, 205, 207, 210, 211, 212, 213, 215, 216, 217, 219, 221, 223, 226, 227, 229, 231, 234, 235, 237, 238, 253, 254, 256, 258, 268, 269, 270, 276, 277, 278, 285, 287, 289, 291, 292, 294, 300, 301, 302, 308, 309, 310, 316, 317, 318, 320, 322, 324, 325, 326, 327, 328, 335, 338, 341, 347, 349, 351, 354, 357, 365, 366, 367, 370, 373, 382, 383, 385, 386, 387, 388, 389, 390, 391, 392};
notesRight = {7, 8, 0, 7, 8, 7, 8, 0, 8, 7, -2, 5, 7, -2, 5, 7, -2, 3, 1, 7, 8, 0, 7, 8, 8, 7, 0, 8, 7, -2, 5, 7, -2, 5, 7, -2, 3, 2, -7, 0, 0, 0, 0, 0, 0, -2, -4, -4, -4, -4, -2, -2, -4, -5, -7, -7, 0, 0, 0, 0, 3, 3, 0, -4, -4, -2, 0, -2, -4, 0, 0, 0, 3, 5, 3, 0, 3, 3, 3, 1, 0, 1, 0, -2, 0, -2, -4, -2, -2, 0, -2, -4, -7, -2, -2, 3, 3, -2, -2, 5, 5, 5, 3, 5, 5, 3, 5, 7, 8, 7, 7, -2, -2, 3, 3, -2, 3, -2, 5, 3, 5, 7, 8, 5, 7, 8, 3, 3, 10, 8, 5, 5, 5, 6, 8, 5, 7, 8, 3, 12, 10, 8, 10, 12, 12, 13, 12, 10, 8, 10, 8, 15, 12, 10, 8, 8, 15, 12, 8, 8, 8, 7, 3, 5, -4, 1, 1, 0, 1, 0, 1, 1, 0, -4};
noteTimesLeft = {0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 128, 136, 144, 152, 160, 168, 176, 178, 180, 184, 192, 200, 208, 216, 224, 232, 240, 242, 244, 246, 248, 250, 252, 256, 258, 260, 262, 264, 266, 268, 272, 274, 276, 278, 280, 282, 284, 286, 288, 290, 292, 294, 296, 298, 300, 302, 304, 306, 308, 310, 312, 314, 316, 318, 320, 322, 324, 326, 328, 330, 332, 334, 336, 338, 340, 342, 344, 346, 348, 350, 352, 354, 356, 358, 360, 362, 364, 366, 368, 374, 384};
notesLeft = {2, -2, 0, -5, 2, -2, 0, -5, 2, -2, 0, -5, 2, -2, 0, -5, 2, -2, 0, -5, 2, 0, -5, 2, -5, -5, 0, 0, -2, -2, 0, 0, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 5, 5, 5, 5, 0, 0, 0, 0, 2, 2, 2, 2, -2, -2, -2, -2, 5, 5, 5, 5, 0, 0, 0, 0, 2, 2, 2, 2, -2, -2, -2, -2, 5, 5, 5, 5, 0, 0, 0, 0, 2, 2, 2, 2, -2, -2, -2, -2, -3, 0, -2}

int nextTimeRight = 0; // time of next note for right hand
int nextTimeLeft = 0; // time of next note for right hand
int nextIndexRight = 0; // time of next index of right hand note
int nextIndexLeft = 0; // time of next index of left hand note

void setup(){

}

void keypressLeft(){
  int noteFreq = notesLeft[nextIndexLeft];

  note.write(70);
  nextTimeLeft = noteTimesLeft[nextIndexLeft+1];
  nextIndexLeft++;
}

void keypressRight(){
  int noteFreq = notesRight[nextIndexRight];
  if(noteFreq==-7||noteFreq==-4||noteFreq==-2||noteFreq==0||noteFreq==1){
    
  }else if(noteFreq==2||noteFreq==3||noteFreq==5||noteFreq==7||noteFreq==8){
    
  }else{
    
  }
  note.write(70);
  nextTimeRight = noteTimesRight[nextIndexRight+1];
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
