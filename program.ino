#define co2zero 55
void setup() {
  pinMode(A0,INPUT);
  pinMode(D3,INPUT);
  Serial.begin(9600); // put your setup code here, to run once:

}

void loop() {
  int co2now[10];
  int co2raw=0;
  int co2comp=0;
  int co2ppm=0;
  int z=0;
  int x;
  if(Serial.available())
  {
    for(x=0;x<10;x++)
    co2now[x]=analogRead(A0);
    delay(100);
  }
  for(x=0;x<10;x++)
  {z=z+ co2now[x];
  }
  co2raw = z/10;
  co2comp = co2raw - co2zero;
  co2ppm = map(co2comp,0,1023,400,5000);
Serial.print("co2 level of the patient ");
 Serial.println(" ");
 Serial.print(co2ppm);
Serial.println("ppm");
if(co2ppm<900)

{
  Serial.println("balanced");
  }
  if(co2ppm>900){
  Serial.println("unbalanced");
  Serial.println("ALERT");
  }
}
 
 
  
