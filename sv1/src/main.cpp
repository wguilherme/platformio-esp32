
#include <Arduino.h>
int freq = 2000;
int channel = 0;
int resolution = 8;

void playScale(uint8_t pin, uint8_t channel)
{
  uint8_t octave = 4;

  ledcAttachPin(pin, channel);

  note_t melody[] = {NOTE_C, NOTE_C, NOTE_C, NOTE_F, NOTE_F, NOTE_F, NOTE_D, NOTE_D, NOTE_D};
  note_t melody2[] = {
      NOTE_F,
      NOTE_F,
      NOTE_F,
      NOTE_D,
      NOTE_D,
      NOTE_D,
      NOTE_C,
      NOTE_C,
      NOTE_C,
  };

  for (int i = 0; i <= sizeof(melody); i++)
  {
    ledcWriteNote(channel, melody[i], octave);
    ledcWriteNote(1, melody2[i], octave);
    delay(100);
  }
  ledcDetachPin(pin);
}

void setup()
{

  Serial.begin(115200);
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(25, channel);
}

void loop()
{

  // ledcWriteTone(channel, 2000);

  playScale(25, 0);
  // ledcWrite(channel, 125);

  delay(1000);
}