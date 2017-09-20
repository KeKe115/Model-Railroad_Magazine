void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}
int speed = 0;    // 速度格納
int position(int val);

void loop() {
  int cnt = 0;
  int pos = 0;
  while(1) {
    int val = analogRead(0);
    int s = position(val);
    if ( s != pos ) {
      pos = s;
      cnt = 0;
    } else {
      cnt++;
    }
    if ( cnt == 10 ) {
      break;
    }
    delay(5);
  }

  /*
  int val = analogRead(0);
  int pos = position(val);
  */
  
  speed += pos;             // 速度を更新
  speed = constrain(speed, 0, 200); // 値の整合
  analogWrite(3, speed);    // PWMの出力
  digitalWrite(4, LOW);
  delay(300);               // 0.3秒待つ 
}

int position(int val) {
  if (val < 70) {          // 力行3
    return 3;
  } else if (val < 200) {  // 力行2
    return 2;
  } else if (val < 410) {  // 力行1
    return 1;
  } else if (val < 500) {  // 惰性走行
    return 0;
  } else if (val < 630) {  // ブレーキ1
    return -2;
  } else if (val < 800) {  // ブレーキ2
    return -4;
  } else if (val < 920) {  // ブレーキ3
    return -6;
  } else {                 // 非常ブレーキ(緊急時、即座に停止)
    return -20;
  }
}

