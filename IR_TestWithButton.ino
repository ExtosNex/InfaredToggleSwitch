// See the full tutorial at http://www.ladyada.net/learn/sensors/ir.html
// this code is public domain, please enjoy!
 
int IRledPin =  13;    // LED connected to digital pin 13
int ButtonOne = 2; //Button One
int ButtonTwo = 3; //ButtonTwo


// The setup() method runs once, when the sketch starts
void setup()   {
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT);
  pinMode(ButtonOne, INPUT);
  pinMode(ButtonTwo, INPUT);
 
  Serial.begin(9600);
}

//Start of Loop
void loop() {
  
  //Read the Value of ButtonOne
  int D_ONE = digitalRead(ButtonOne);

  //Read the Value of ButtonTwo
  int D_TWO = digitalRead(ButtonTwo);
  
  if (D_ONE == LOW) {
  //Sends IR Power
  IR_One();
  Serial.println("Sending IR_One");
  delay(150);
} else {
  //Keeps the LED LOW
  digitalWrite(IRledPin, LOW);
}
  
  if (D_TWO == LOW){
    //Sends IR Freeze
    IR_Two();
    Serial.println("Sending IR_Two");
    delay(150);
  } else {
    //Keeps the LED LOW
    digitalWrite(IRledPin, LOW);
  }
}
//End of Loop

 
// This procedure sends a 38KHz pulse to the IRledPin
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}
 
 
//Functions

void IR_One() {
  // IR_One button
pulseIR(8920);
delayMicroseconds(4160);
pulseIR(740);
delayMicroseconds(1460);
pulseIR(740);
delayMicroseconds(1440);
pulseIR(740);
delayMicroseconds(340);
pulseIR(760);
delayMicroseconds(340);
pulseIR(740);
delayMicroseconds(360);
pulseIR(740);
delayMicroseconds(340);
pulseIR(740);
delayMicroseconds(360);
pulseIR(740);
delayMicroseconds(1440);
pulseIR(720);
delayMicroseconds(1480);
pulseIR(680);
delayMicroseconds(420);
pulseIR(640);
delayMicroseconds(1540);
pulseIR(620);
delayMicroseconds(480);
pulseIR(600);
delayMicroseconds(1600);
pulseIR(580);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(1620);
pulseIR(540);
delayMicroseconds(560);
pulseIR(540);
delayMicroseconds(540);
pulseIR(540);
delayMicroseconds(560);
pulseIR(540);
delayMicroseconds(560);
pulseIR(540);
delayMicroseconds(540);
pulseIR(540);
delayMicroseconds(1660);
pulseIR(540);
delayMicroseconds(540);
pulseIR(540);
delayMicroseconds(560);
pulseIR(520);
delayMicroseconds(1660);
pulseIR(540);
delayMicroseconds(1640);
pulseIR(540);
delayMicroseconds(1660);
pulseIR(520);
delayMicroseconds(1660);
pulseIR(540);
delayMicroseconds(1640);
pulseIR(540);
delayMicroseconds(560);
pulseIR(540);
delayMicroseconds(1640);
pulseIR(540);
delayMicroseconds(1640);
pulseIR(540);
delayMicroseconds(560);
pulseIR(540);
}

//IR_Two Function
void IR_Two() {
pulseIR(8900);
delayMicroseconds(4200);
pulseIR(740);
delayMicroseconds(1440);
pulseIR(720);
delayMicroseconds(1460);
pulseIR(760);
delayMicroseconds(340);
pulseIR(720);
delayMicroseconds(360);
pulseIR(740);
delayMicroseconds(360);
pulseIR(740);
delayMicroseconds(340);
pulseIR(740);
delayMicroseconds(360);
pulseIR(740);
delayMicroseconds(1440);
pulseIR(740);
delayMicroseconds(1460);
pulseIR(720);
delayMicroseconds(360);
pulseIR(740);
delayMicroseconds(1440);
pulseIR(740);
delayMicroseconds(360);
pulseIR(720);
delayMicroseconds(1480);
pulseIR(660);
delayMicroseconds(440);
pulseIR(640);
delayMicroseconds(1540);
pulseIR(640);
delayMicroseconds(460);
pulseIR(620);
delayMicroseconds(460);
pulseIR(600);
delayMicroseconds(1600);
pulseIR(580);
delayMicroseconds(500);
pulseIR(580);
delayMicroseconds(520);
pulseIR(560);
delayMicroseconds(1640);
pulseIR(540);
delayMicroseconds(560);
pulseIR(540);
delayMicroseconds(540);
pulseIR(540);
delayMicroseconds(1660);
pulseIR(520);
delayMicroseconds(1660);
pulseIR(540);
delayMicroseconds(540);
pulseIR(560);
delayMicroseconds(1620);
pulseIR(560);
delayMicroseconds(1640);
pulseIR(540);
delayMicroseconds(540);
pulseIR(540);
delayMicroseconds(1660);
pulseIR(540);
delayMicroseconds(1640);
pulseIR(540);
delayMicroseconds(560);
pulseIR(520);
}


