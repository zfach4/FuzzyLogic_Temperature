const int lm35_data = A0;
int enal = 3;
int nilai_analog; //int: bil. bulat c: 1-10
float nilai_suhu; //float: nilai sampai koma c: 29,44

void setup() {
  Serial.begin(9600);
  pinMode(enal, OUTPUT);
  pinMode(lm35_data, INPUT);
}

void loop() {
  nilai_analog = analogRead(lm35_data); //baca nilai analog pin A0 (ADC: 0-1023)
  nilai_suhu = (nilai_analog * 4.888);  //konversi analog
  nilai_suhu = (nilai_suhu * 10);       //suhu didapat dengan 10 mV/'C
  Serial.print("Suhu = ");              //tampil tulisan suhu
  Serial.print(nilai_suhu);             //tampil nilai suhu
  Serial.println(" Celcius");           //tampil tulisan Celcius
  delay(1);
  //reading data from labview via serial monitor
  if(Serial.available()){
    int pwmvalue = Serial.parseInt();
    if(Serial.read()==char(13)){ // char(13): akhir pembacaan
      analogWrite(enal, pwmvalue);
      }
    }
}
