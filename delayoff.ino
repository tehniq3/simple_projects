/*
 * program mentine led aprins timp scurt la apasare buton
 * scris de Nicu FLORICA, 05.11.2018, Craiova
 */

#define buton 3
#define led 4
byte stare = 0;
unsigned long inceput = 0;
unsigned long gata = 2000;  // 2 secunde


void setup() {
  pinMode(buton, INPUT);
  digitalWrite(buton, HIGH);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW); 
  stare = 0;
  inceput = millis();
}

void loop() {
if ((digitalRead(buton) == LOW) and (stare == 0)) // daca butonul este apasat
{
  stare = 1;
  digitalWrite(led, HIGH); 
  inceput = millis();
}

if ((stare == 1) and (millis()-inceput > gata))
{
  digitalWrite(led, LOW); 
}

if (digitalRead(buton) == HIGH)  // daca butonul este liber
{
  digitalWrite(led, LOW); 
  stare = 0;
}
}  // sfarsit program
