//-----------------------
#define BUZZER 12
#define BUTTON 8
#define SOURCE 13

#define USERPITCH 3
#define USERTEMPO 150
#define USERDELAY 3000
//-----------------------

//---BUERAK-PARAMETERS---
int sportivniyeOchkiNotes[] = {5, 5, 5, 4, 4, 4, 2, 2, 4, 4, 4, 3, 3, 3, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 6, 6, 6, 2, 2, 2};
int buerakNoteCount = sizeof(sportivniyeOchkiNotes)/sizeof(int);

int buerakBaseFreq = 100;
int buerakDeltaFreq = 20;
//------------------------

void playSportivniyeOchki(int pin, int pitch, int tempo);





void setup() 
{
  pinMode(SOURCE, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT);
  
  digitalWrite(SOURCE, HIGH);
}

void loop() 
{
  playSportivniyeOchki(BUZZER, USERPITCH, USERTEMPO);
  delay(USERDELAY);
}





void playSportivniyeOchki(int pin, int pitch = 3, int tempo = 150)
{
  for(int i = 0; i < buerakNoteCount; i++)
    {
      tone(pin, (buerakBaseFreq + buerakDeltaFreq*sportivniyeOchkiNotes[i])*pitch, tempo);
      delay(tempo);
    }
}
