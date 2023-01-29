int irsens = 9;
int buzzer = 8;
int yLed = 10;
int kLed = 11;
int irdeg;
int i;
int zaman;
int yarismaci = 0;
int dakika;
void setup() {
  Serial.begin(9600);
  pinMode(irsens, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(yLed, OUTPUT);
  pinMode(kLed, OUTPUT);
  digitalWrite(buzzer, HIGH);
  delay(300);
  Serial.println("3");
  digitalWrite(buzzer, LOW);
  delay(300);
  digitalWrite(buzzer, HIGH);
  delay(300);
  Serial.println("2");
  digitalWrite(buzzer, LOW);
  delay(300);
  Serial.println("1");
  digitalWrite(buzzer, HIGH);
  digitalWrite(kLed,HIGH);
  delay(800);
  Serial.println("BASLA");
  digitalWrite(kLed, LOW);
  digitalWrite(buzzer, LOW);
}

void loop() {
  irdeg = digitalRead(irsens);
  zaman = (millis() / 1000) - 2;
  if (irdeg < 1) {
    digitalWrite(yLed, HIGH);
    yarismaci += 1;
    Serial.print(yarismaci);
    Serial.print(". yarışmacı tamamladığı sure : ");
    if(zaman > 60){
      Serial.print(zaman/60);
      Serial.print(" dk ");  
    }
    Serial.print(zaman % 60);
    Serial.println(" sn");
    delay(500);
    digitalWrite(yLed , LOW);
  }
}