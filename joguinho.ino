#include <LiquidCrystal.h>

#define ledverde A2
#define ledvermelho A1
#define ledamarelo A0
#define pinbotaoverde A5
#define pinbotaovermelho A4
#define pinbotaoamarelo A3 
#define buzzer 2  
#define botaocomecar 3
#define botaodificuldade 4
                                                     
int erros = 0;
int valorbotaoverde = 0; 
int valorbotaovermelho = 0;
int valorbotaoamarelo = 0;
int sorteado = 0;
int pontos = 0;
int teste = 0;
int ok = 0;
int comeco = 0;
int jogo = 0;
int x = 0;
int y = 0;
int vezesp = 0;
int vezesv = 0;
bool dificuldade;
bool botaoant;
char dificul = 'F';
bool perdeu = false;
bool venceu = false;

unsigned long delay1 = 0;
unsigned long tempoinc = 0;
unsigned long tempoapertado = 0;

LiquidCrystal lcd( 8, 9, 10, 11, 12, 13);

void setup() {
 
pinMode(botaocomecar, INPUT);
pinMode(pinbotaoverde, INPUT);
pinMode(pinbotaovermelho, INPUT);
pinMode(pinbotaoamarelo, INPUT);
pinMode(ledverde, OUTPUT);
pinMode(ledvermelho, OUTPUT);
pinMode(ledamarelo, OUTPUT);
pinMode(buzzer, OUTPUT);

Serial.begin (9600);

lcd.begin( 16, 2);

lcd.setCursor( 3, 0);
lcd.print("Bem vindo!");
lcd.setCursor( 3, 1);
lcd.print("Press azul");



}

void loop() {

dificuldade = digitalRead(botaodificuldade);
comeco = digitalRead(botaocomecar);
valorbotaoverde = analogRead( pinbotaoverde);
valorbotaovermelho = analogRead( pinbotaovermelho);
valorbotaoamarelo = analogRead( pinbotaoamarelo);

if(comeco == 1)
 jogo = 1;

if( jogo == 1 && perdeu == false && venceu == false){

if( dificul == 'F' && dificuldade == 1){
  pontos = 0;
  vezesp = 0;
  erros = 0; 
  vezesv = 0;
  lcd.clear();
  lcd.print(pontos);
  lcd.setCursor( 0, 1);
  lcd.print(erros);
  lcd.setCursor(10, 1);
  lcd.print("P= ");
  lcd.print(vezesp);
  lcd.setCursor(10, 0);
  lcd.print("V= ");
  lcd.print(vezesv);
}

if( dificuldade == 1){
  dificul = 'F';
  lcd.clear();
  lcd.print("Pontos: ");
  lcd.print(pontos);
  lcd.setCursor( 11, 1);
  lcd.println("Facil");
  lcd.setCursor(0 , 1);
  lcd.print("Erros: ");
  lcd.print(erros);
  if( tempoinc == 0){
    tempoinc = millis();
  }
}

if(tempoinc > 500){
  if( dificuldade == 0 ){
    tempoapertado = millis() - tempoinc;
    tempoinc = 0;
  }
}

if(tempoapertado > 500 && tempoapertado <= 5000){
  tempoapertado = 0;
  lcd.clear();
  lcd.print("Pontos: ");
  lcd.print(pontos);
  lcd.setCursor( 11, 1);
  lcd.println("Medio"); 
  lcd.setCursor(0 , 1);
  lcd.print("Erros: ");
  lcd.print(erros);

  dificul = 'M'; 
}

if(tempoapertado > 5000){
  tempoapertado = 0;
  lcd.clear();
  lcd.print("Pontos: ");
  lcd.print(pontos);
  lcd.setCursor( 9, 1);
  lcd.println("Dificil"); 
  lcd.setCursor(0 , 1);
  lcd.print("Erros: ");
  lcd.print(erros);

  dificul = 'D'; 
}

if(y == 0){
  lcd.clear();
  lcd.print("Pontos: ");
  lcd.print(pontos);
  lcd.setCursor(0 , 1);
  lcd.print("Erros: ");
  lcd.print(erros);
  lcd.setCursor( 15, 1);
  lcd.print("F");
  lcd.setCursor(10, 1);
  lcd.print("P= ");
  lcd.print(vezesp);
  lcd.setCursor(10, 0);
  lcd.print("V= ");
  lcd.print(vezesv);
  y = 1;
}

if(valorbotaoverde <= 511 && valorbotaovermelho <= 511 && valorbotaoamarelo <= 511){
  ok = 0;
}
if(dificul == 'F'){
  
  if((millis() - delay1) >=  2000){
  sorteado = random( 1, 4);
  delay1 = millis();
}
}else if(dificul == 'M'){
  if((millis() - delay1) >=  1200){
  sorteado = random( 1, 4);
  delay1 = millis();
}
}else if(dificul == 'D'){
  if((millis() - delay1) >=  500){
  sorteado = random( 1, 4);
  delay1 = millis();
}
}

if (sorteado == 1){

  digitalWrite (ledverde, HIGH);
}
else{
  digitalWrite (ledverde, LOW);
  
}

if (sorteado == 2){

  digitalWrite (ledvermelho, HIGH);
}
else{
  digitalWrite (ledvermelho, LOW);

}

if (sorteado == 3){
  digitalWrite (ledamarelo, HIGH);
}
else{
  digitalWrite (ledamarelo, LOW);

}

if (sorteado == 1 && valorbotaoverde >= 511 && ok == 0){
  ok = 1;
  lcd.clear();
  lcd.print("Pontos: ");
  lcd.print(pontos + 1);
  lcd.setCursor(0, 1);
  lcd.print("Erros: ");
  lcd.print(erros);
  lcd.setCursor( 15, 1);
  lcd.print(dificul);
  lcd.setCursor(10, 1);
  lcd.print("P= ");
  lcd.print(vezesp);
  lcd.setCursor(10, 0);
  lcd.print("V= ");
  lcd.print(vezesv);
  pontos = pontos+1;
} 
else if (sorteado == 2 && valorbotaovermelho >= 511 && ok == 0){
  ok = 1;
  lcd.clear();
  lcd.print("Pontos: ");
  lcd.print(pontos + 1);
  lcd.setCursor(0, 1);
  lcd.print("Erros: ");
  lcd.print(erros);
  lcd.setCursor( 15, 1);
  lcd.print(dificul);
  lcd.setCursor(10, 1);
  lcd.print("P= ");
  lcd.print(vezesp);
  lcd.setCursor(10, 0);
  lcd.print("V= ");
  lcd.print(vezesv);
  pontos = pontos+1;
} 
else if ( sorteado == 3 && valorbotaoamarelo >= 511 && ok == 0){
  ok = 1;
  lcd.clear();
  lcd.print("Pontos: ");
  lcd.print(pontos + 1);
  lcd.setCursor(0, 1);
  lcd.print("Erros: ");
  lcd.print(erros);
  lcd.setCursor( 15, 1);
  lcd.print(dificul);
  lcd.setCursor(10, 1);
  lcd.print("P= ");
  lcd.print(vezesp);
  lcd.setCursor(10, 0);
  lcd.print("V= ");
  lcd.print(vezesv);
  pontos = pontos+1;
}

if (sorteado != 1 && valorbotaoverde >= 511 && ok == 0){
  Serial.println("1");
 tone(buzzer, 240, 250 );
 ok = 1;
 lcd.clear();
 lcd.print("Pontos: ");
 lcd.print(pontos);
 lcd.setCursor(0, 1);
 lcd.print("Erros: ");
 lcd.print(erros + 1);
 erros = erros+1;
 lcd.setCursor( 15, 1);
 lcd.print(dificul);
 lcd.setCursor(10, 1);
 lcd.print("P= ");
 lcd.print(vezesp);
 lcd.setCursor(10, 0);
 lcd.print("V= ");
 lcd.print(vezesv);
 pontos = pontos+1;
 
} else if (sorteado != 2 && valorbotaovermelho >= 511 && ok == 0){
 tone(buzzer, 240, 250 );
 ok = 1;
 lcd.clear();
 lcd.print("Pontos: ");
 lcd.print(pontos);
 lcd.setCursor(0, 1);
 lcd.print("Erros: ");
 lcd.print(erros + 1);
 erros = erros+1;
 lcd.setCursor( 15, 1);
 lcd.print(dificul);
 lcd.setCursor(10, 1);
 lcd.print("P= ");
 lcd.print(vezesp);
 lcd.setCursor(10, 0);
 lcd.print("V= ");
 lcd.print(vezesv);
 pontos = pontos+1;
 
} else if (sorteado != 3 && valorbotaoamarelo >= 511 && ok == 0){
 tone(buzzer, 240, 250 );
 ok = 1;
 lcd.clear();
 lcd.print("Pontos: ");
 lcd.print(pontos);
 lcd.setCursor(0, 1);
 lcd.print("Erros: ");
 lcd.print(erros + 1);
 erros = erros+1;
 lcd.setCursor( 15, 1);
 lcd.print(dificul);
 lcd.setCursor(10, 1);
 lcd.print("P= ");
 lcd.print(vezesp);
 lcd.setCursor(10, 0);
 lcd.print("V= ");
 lcd.print(vezesv);
 pontos = pontos+1;
}

if( dificul == 'F' && erros == 5 ){
  pontos = 0;
  erros = 0;
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("!Voce!");
  lcd.setCursor(4, 1);
  lcd.print("!Perdeu!");
  perdeu = true;
}
if( dificul == 'M' && erros == 4 ){
  pontos = 0;
  erros = 0;
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("!Voce!");
  lcd.setCursor(4, 1);
  lcd.print("!Perdeu!");
  perdeu = true;
}
if( dificul == 'D' && erros == 3 ){
  pontos = 0;
  erros = 0;
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("!Voce!");
  lcd.setCursor(4, 1);
  lcd.print("!Perdeu!");
  perdeu = true;
}
if( perdeu == true){
  digitalWrite (ledverde, LOW);
  digitalWrite (ledvermelho, LOW);
  digitalWrite (ledamarelo, LOW);
  vezesp = vezesp + 1;
  delay(3000);
  lcd.clear();
  lcd.print("Pontos: ");
  lcd.print(pontos);
  lcd.setCursor(0 , 1);
  lcd.print("Erros: ");
  lcd.print(erros);
  lcd.setCursor( 15, 1);
  lcd.print(dificul);
  lcd.setCursor(10, 1);
  lcd.print("P= ");
  lcd.print(vezesp);
  lcd.setCursor(10, 0);
  lcd.print("V= ");
  lcd.print(vezesv);
  perdeu = false;
}
if( dificul == 'F' && pontos == 40){
  pontos = 0;
  erros = 0;
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("!Voce!");
  lcd.setCursor(4, 1);
  lcd.print("!Venceu!");
  venceu = true;
}
if( dificul == 'M' && pontos == 30){
  pontos = 0;
  erros = 0;
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("!Voce!");
  lcd.setCursor(4, 1);
  lcd.print("!Venceu!");
  venceu = true;
}
if( dificul == 'D' && pontos == 20){
  pontos = 0;
  erros = 0;
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("!Voce!");
  lcd.setCursor(4, 1);
  lcd.print("!Venceu!");
  venceu = true;
}
if(venceu == true){
  digitalWrite (ledverde, LOW);
  digitalWrite (ledvermelho, LOW);
  digitalWrite (ledamarelo, LOW);
  vezesv = vezesv + 1;
  delay(3000);
  lcd.clear();
  lcd.print("Pontos: ");
  lcd.print(pontos);
  lcd.setCursor(0 , 1);
  lcd.print("Erros: ");
  lcd.print(erros);
  lcd.setCursor( 15, 1);
  lcd.print(dificul);
  lcd.setCursor(10, 1);
  lcd.print("P= ");
  lcd.print(vezesp);
  lcd.setCursor(10, 0);
  lcd.print("V= ");
  lcd.print(vezesv);
  venceu = false;
}
}
}
