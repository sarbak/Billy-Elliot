#define memory 10

int sensorPinSmall = A0;
int sensorPinBig = A2;

int soundLevelSmall = 0;
int soundLevelBig = 0;


int soundMemorySmall[memory];
int soundMemoryBig[memory];

void setup() 
{
 Serial.begin(9600);
 pinMode(sensorPinSmall, INPUT);
 pinMode(sensorPinBig, INPUT);
} 


 
void loop() 
{
 listenSounds();
 //Serial.print(soundLevelSmall); Serial.print(", ");
 //Serial.println(soundLevelBig);
}  

void listenSounds(){

  //Listen the small sensor
  
  int valS = analogRead(sensorPinSmall);

  int minSoundS = 1200;
  int maxSoundS = 0;

  soundMemorySmall[memory-1] = valS;
  
  for(int i=0; i<memory-1;i++) {
    soundMemorySmall[i] = soundMemorySmall[i+1];
    if(soundMemorySmall[i] < minSoundS) minSoundS = soundMemorySmall[i];
    if(soundMemorySmall[i] > maxSoundS) maxSoundS = soundMemorySmall[i];
  }

  soundLevelSmall = maxSoundS - minSoundS;

  if(soundLevelSmall > 2){
    Serial.print ("Small: "); Serial.println (soundLevelSmall);
  }
  
  //Listen the big sensor

  int valB = analogRead(sensorPinBig);

  int minSoundB = 1200;
  int maxSoundB = 0;

  soundMemoryBig[memory-1] = valB;
  
  for(int i=0; i<memory-1;i++) {
    soundMemoryBig[i] = soundMemoryBig[i+1];
    if(soundMemoryBig[i] < minSoundB) minSoundB = soundMemoryBig[i];
    if(soundMemoryBig[i] > maxSoundB) maxSoundB = soundMemoryBig[i];
  }

  soundLevelBig = maxSoundB - minSoundB;

  if(soundLevelBig > 1){
    Serial.print ("Big: "); Serial.println (soundLevelBig);
  }
  
}
