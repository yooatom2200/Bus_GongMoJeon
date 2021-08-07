#define FGate 2//앞문 자석센서 입력
#define BGate 3//뒷문 자석센서 입력
#define Trig1 23 //각 좌석별 에코, 트리거 번호들
#define Echo1 22
#define Trig2 27
#define Echo2 26
#define Trig3 31
#define Echo3 30
#define Trig4 35
#define Echo4 34

void setup() {
  Serial.begin(9600);
  pinMode(FGate, INPUT);
  pinMode(BGate, INPUT);
  pinMode(Trig1, OUTPUT);
  pinMode(Echo1, INPUT);
  pinMode(Trig2, OUTPUT);
  pinMode(Echo2, INPUT);
  pinMode(Trig3, OUTPUT);
  pinMode(Echo3, INPUT);
  pinMode(Trig4, OUTPUT);
  pinMode(Echo4, INPUT);
}

int people = 0; //버스승객수
bool seat[4] = {false,}; //좌석착석여부

bool isSeat(int x) {//착석여부판정함수
  long dura, dist;
  int t, e;
  switch(x+1){
    case 1:
      t = Trig1;
      e = Echo1;
      break;
    case 2:
      t = Trig2;
      e = Echo2;
      break;
    case 3:
      t = Trig3;
      e = Echo3;
      break;
    case 4:
      t = Trig4;
      e = Echo4;
      break;
    default:
      Serial.println("Error : 값오류!");
  }
  digitalWrite(t, LOW);
  delayMicroseconds(2);
  digitalWrite(t, HIGH);
  delayMicroseconds(10);
  digitalWrite(t, LOW);
  dura = pulseIn (e, HIGH);
  dist = dura * 17 / 1000; 
  if(dist <= 3 || dist > 1000)
    return true;
  else
    return false;
}

void loop() {
  if (digitalRead(FGate) == LOW) {//승객탑승분기
    people++;
    Serial.print("승객탑승 / 승객수 : ");
    Serial.println(people);
  }
  if (digitalRead(BGate) == LOW) {//승객하차분기
    people--;
    Serial.print("승객하차 / 승객수 : ");
    Serial.println(people);
  }

  for(int i = 0; i < 4; i++){ //좌석판정
    if(seat[i] != isSeat(i)){
      seat[i] = !seat[i];
      Serial.print(i+1);
      if(seat[i] == true)
        Serial.println("번좌석 자리없음");
      else
        Serial.println("번좌석 자리있음");
    }
  }
  
  delay(1200);//1.2초 딜레
}
