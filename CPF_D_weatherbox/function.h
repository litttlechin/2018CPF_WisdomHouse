/*
  AQI指數  細顆粒物PM2.5（粒徑小於等於2.5μm）24小時平均/（μg/m3）  可吸入顆粒物PM10（粒徑小於等於10μm）24小時平均/（μg/m3
  0    0      0
 *50   12     54
 *100  35.4   154
 *150  55.4   254
 *200  150.4  354
 *300  250.4  424
  400  350.4  504
 *500  500.4  600

  空氣質量指數（AQI） 健康令人擔憂的程度  顏色
  ---------------------------------------------
  0   to 50           好                  綠色
  51  to 100          中等                黃色
  101 to 150          不適於敏感人群      橘色
  151 to 200          不健康              紅色
  201 to 300          非常不健康          紫色
  301 to 500          危險                棗紅色
*/
int aqitool(int a,int b){
  int aqin25  = 87;
  int aqin100 = 87;
  if(a >= 0 && a <= 12){
    aqin25 = 1;
  }
  else if(a > 12 && a <= 35){
    aqin25 = 2;
  }
  else if(a > 35 && a <= 55){
    aqin25 = 3;
  }
  else if(a > 55 && a <= 150){
    aqin25 = 4;
  }
  else if(a > 150 && a <= 250){
    aqin25 = 5;
  }
  else if(a > 250){
    aqin25 = 6;
  }
  else{
    aqin25 = -1;
  }

  if(b >= 0 && b <= 54){
    aqin100 = 1;
  }
  else if(b > 54 && b <= 154){
    aqin100 = 2;
  }
  else if(b > 154 && b <= 254){
    aqin100 = 3;
  }
  else if(b > 254 && b <= 354){
    aqin100 = 4;
  }
  else if(b > 354 && b <= 424){
    aqin100 = 5;
  }
  else if(b > 424){
    aqin100 = 6;
  }
  else{
    aqin100 = -1;
  }

  if(aqin25 > aqin100){
    return aqin25;
  }
  else if(aqin25 < aqin100){
    return aqin100;
  }
  else if(aqin25 == aqin100){
    return aqin100;
  }
  else if(aqin25 == -1 && aqin25 == -1){
    return -1;
  }
  else{
    return -2;
  }
}

float THI(float T,float Td){
  float out=T-0.55*(1-(exp((17.269*Td)/(Td+237.3)-(17.269*T)/(T+237.3)))*(T-14));
  return out;
}


static const uint8_t PROGMEM tux[] = {
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x1,0xfc,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x7,0xfe,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x1,0xf8,0x0,0xf,0xff,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x3,0xfc,0x0,0x1f,0xff,0x80,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x7,0xfe,0x0,0x1f,0xff,0xc0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x7,0xfe,0x0,0x3f,0xff,0xc0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xf,0xff,0x0,0x3f,0xff,0xe0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xf,0xff,0x0,0x7f,0xf,0xe0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xf,0xbf,0x80,0x7e,0x7,0xf0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xf,0xf,0x80,0x7c,0x7,0xf0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xe,0x7,0x80,0x78,0x3,0xf0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xe,0x7,0x80,0x78,0x3,0xf0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xe,0x7,0x80,0x78,0x3,0xf0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xe,0x3,0x80,0x78,0x3,0xf0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xe,0x3,0x0,0x38,0x3,0xf0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xe,0x0,0x0,0x0,0x3,0xf0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xe,0x0,0xff,0xc0,0x3,0xe0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x6,0x1,0xff,0xf8,0x3,0xe0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7,0x7,0xff,0xfc,0x7,0xe0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x3,0x8f,0xff,0xff,0x7,0xc0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x3,0x1f,0xff,0xff,0xc0,0x80,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x3f,0xff,0xff,0xf8,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0xff,0xff,0xff,0xff,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x1,0xff,0xff,0xff,0xff,0xc0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x3,0xff,0xff,0xff,0xff,0xe0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf,0xff,0xff,0xff,0xff,0xf0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xf,0xff,0xff,0xff,0xfe,0xf0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x19,0xff,0xff,0xff,0xf8,0x70,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x18,0xff,0xff,0xff,0xe0,0xf0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x1c,0x7f,0xff,0xff,0x87,0xf0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xe,0x3f,0xff,0xff,0xf,0xe0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x7,0x1f,0xff,0xfc,0x3f,0xc0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x7,0x87,0xff,0xf0,0xff,0x80,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x3,0xe1,0xff,0xc3,0xff,0x10,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0xf0,0x38,0xf,0xfe,0x38,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x7e,0x0,0x3f,0xf8,0x78,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x2,0x1f,0xe7,0xff,0xc1,0xf8,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x3,0x8f,0xff,0xff,0x7,0xfc,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x3,0xc7,0xff,0xfe,0x3f,0xfc,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x3,0xe3,0xff,0xf8,0x7f,0xfc,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x7,0xf0,0xff,0xe1,0xff,0xfe,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x7,0xfc,0x3f,0x7,0xff,0xfe,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x7,0xfe,0x0,0x1f,0xff,0xfe,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x7,0xff,0xc0,0xff,0xff,0xff,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x7,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0xf,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0xf,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x2,0x0,0x0,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x1,0x0,0x0,0x7f,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x80,0x0,0x3f,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x40,0x0,0x3f,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x20,0x0,0x1f,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0xf,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x10,0x0,0xf,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xc0,0x10,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x8,0x0,0x7,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0x80,0x20,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x7,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0x0,0x20,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x4,0x0,0x3,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0x0,0x40,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x2,0x0,0x1,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xfe,0x0,0x40,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x2,0x0,0x1,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xfe,0x0,0x80,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x1,0x0,0x0,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xfc,0x0,0x80,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x1,0x0,0x0,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xfc,0x1,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x1,0x80,0x0,0x7f,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xf8,0x1,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x80,0x0,0x7f,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xf8,0x2,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0xc0,0x0,0x7f,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xf0,0x2,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0xc0,0x0,0x3f,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xf0,0x6,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x40,0x0,0x3f,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xe0,0x4,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x60,0x0,0x1f,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xe0,0x4,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x60,0x0,0x1f,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xc0,0xc,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x60,0x0,0x1f,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xc0,0xc,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x60,0x0,0xf,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xc0,0x8,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x30,0x0,0xf,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0x80,0x8,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x30,0x0,0xf,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0x80,0x18,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x30,0x0,0x7,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0x80,0x18,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x30,0x0,0x7,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0x0,0x18,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x30,0x0,0x7,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0x0,0x18,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x30,0x0,0x7,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0x0,0x18,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x70,0x0,0x7,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfe,0x0,0x18,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x70,0x0,0x3,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfe,0x0,0x18,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x70,0x0,0x3,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfe,0x0,0x18,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x70,0x0,0x3,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfe,0x0,0x18,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0xf0,0x0,0x3,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfc,0x0,0x18,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x3,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfc,0x0,0x1c,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x3,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfc,0x0,0x1c,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x3,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfc,0x0,0x1c,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x3e,0x0,0x3,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfc,0x0,0x1e,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x7,0x80,0x3,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfc,0x0,0xe,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x1e,0x1,0xe0,0x3,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfc,0x0,0xf,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x3f,0xc0,0x70,0x3,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfc,0x0,0x7,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x7f,0xf0,0x38,0x3,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfc,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x7f,0xf8,0xc,0x3,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfc,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xff,0xfe,0x6,0x3,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfc,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0xff,0xff,0x2,0x7,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfc,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0xff,0xff,0x3,0x7,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfc,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x7f,0xff,0x3,0x7,0xff,0xff,0xf0,
0xff,0xff,0xff,0xfc,0x1e,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x84,0x7f,0xff,0x3,0x7,0xff,0xff,0xf0,
0xff,0xff,0xff,0xf8,0x7f,0x80,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc,0x7f,0xfe,0x2,0xf,0xff,0xff,0xf0,
0xff,0xff,0xff,0xf0,0xff,0xe0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x1e,0x7f,0xfe,0x0,0xf,0xff,0xff,0xf0,
0xff,0xff,0xff,0xe1,0xff,0xf0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x1e,0x3f,0xfc,0x0,0x3,0xff,0xff,0xf0,
0xff,0xff,0xff,0xc3,0xff,0xf8,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x3e,0x1f,0xf0,0x0,0x1,0xff,0xff,0xf0,
0xff,0xff,0xff,0xc7,0xff,0xfc,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x3e,0xf,0xe0,0xf,0xe0,0xff,0xff,0xf0,
0xff,0xff,0xff,0x87,0xff,0xfe,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x7f,0x2,0x0,0x1f,0xf8,0x7f,0xff,0xf0,
0xff,0xff,0xff,0xf,0xff,0xfe,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x7f,0x80,0x0,0x3f,0xfc,0x7f,0xff,0xf0,
0xff,0xff,0xfe,0x1f,0xff,0xff,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x7f,0x80,0x0,0xff,0xfc,0x3f,0xff,0xf0,
0xff,0xff,0xf8,0x3f,0xff,0xff,0x80,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x7f,0xc0,0x3,0xff,0xfe,0x3f,0xff,0xf0,
0xff,0xff,0xc0,0x7f,0xff,0xff,0x80,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xf0,0xf,0xff,0xfe,0x3f,0xff,0xf0,
0xff,0xff,0x0,0xff,0xff,0xff,0xc0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0x1f,0xff,0xf0,
0xff,0xfc,0x3,0xff,0xff,0xff,0xc0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0x1f,0xff,0xf0,
0xff,0xf0,0x1f,0xff,0xff,0xff,0xe0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0x1f,0xff,0xf0,
0xff,0xe0,0xff,0xff,0xff,0xff,0xe0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xf,0xff,0xf0,
0xff,0xe1,0xff,0xff,0xff,0xff,0xf0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0x8f,0xff,0xf0,
0xff,0xc3,0xff,0xff,0xff,0xff,0xf0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0x8f,0xff,0xf0,
0xff,0xc7,0xff,0xff,0xff,0xff,0xf8,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xf0,0xff,0xff,0xff,0xff,0xff,0x8f,0xff,0xf0,
0xff,0x87,0xff,0xff,0xff,0xff,0xf8,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xf1,0xff,0xff,0xff,0xff,0xff,0x87,0xff,0xf0,
0xff,0x8f,0xff,0xff,0xff,0xff,0xfc,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xf1,0xff,0xff,0xff,0xff,0xff,0xc7,0xff,0xf0,
0xff,0x8f,0xff,0xff,0xff,0xff,0xfc,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xf1,0xff,0xff,0xff,0xff,0xff,0xc3,0xff,0xf0,
0xff,0x8f,0xff,0xff,0xff,0xff,0xfe,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xf1,0xff,0xff,0xff,0xff,0xff,0xe1,0xff,0xf0,
0xff,0x8f,0xff,0xff,0xff,0xff,0xfe,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xf1,0xff,0xff,0xff,0xff,0xff,0xe1,0xff,0xf0,
0xff,0x8f,0xff,0xff,0xff,0xff,0xff,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xf1,0xff,0xff,0xff,0xff,0xff,0xf0,0xff,0xf0,
0xff,0x8f,0xff,0xff,0xff,0xff,0xff,0x80,0x1,0xff,0xff,0xff,0xff,0xff,0xf1,0xff,0xff,0xff,0xff,0xff,0xf8,0x7f,0xf0,
0xff,0x8f,0xff,0xff,0xff,0xff,0xff,0xc0,0x1,0xff,0xff,0xff,0xff,0xff,0xf1,0xff,0xff,0xff,0xff,0xff,0xfc,0x3f,0xf0,
0xff,0x87,0xff,0xff,0xff,0xff,0xff,0xc0,0x3,0xff,0xff,0xff,0xff,0xff,0xe1,0xff,0xff,0xff,0xff,0xff,0xfe,0x3f,0xf0,
0xff,0xc7,0xff,0xff,0xff,0xff,0xff,0xe0,0x7,0xff,0xff,0xff,0xff,0xff,0xe1,0xff,0xff,0xff,0xff,0xff,0xfe,0x1f,0xf0,
0xff,0xc7,0xff,0xff,0xff,0xff,0xff,0xf0,0xf,0xff,0xff,0xff,0xff,0xff,0xe3,0xff,0xff,0xff,0xff,0xff,0xff,0x1f,0xf0,
0xff,0xc7,0xff,0xff,0xff,0xff,0xff,0xf8,0x7f,0xff,0xff,0xff,0xff,0xff,0xe3,0xff,0xff,0xff,0xff,0xff,0xff,0xf,0xf0,
0xff,0xc7,0xff,0xff,0xff,0xff,0xff,0xf8,0x7f,0xff,0xff,0xff,0xff,0xff,0xc3,0xff,0xff,0xff,0xff,0xff,0xff,0x8f,0xf0,
0xff,0xc7,0xff,0xff,0xff,0xff,0xff,0xfc,0x3f,0xff,0xff,0xff,0xff,0xff,0xc7,0xff,0xff,0xff,0xff,0xff,0xff,0x8f,0xf0,
0xff,0xc7,0xff,0xff,0xff,0xff,0xff,0xfe,0x1f,0xff,0xff,0xff,0xff,0xff,0xc7,0xff,0xff,0xff,0xff,0xff,0xff,0x8f,0xf0,
0xff,0xc7,0xff,0xff,0xff,0xff,0xff,0xff,0xf,0xff,0xff,0xff,0xff,0xff,0xc7,0xff,0xff,0xff,0xff,0xff,0xff,0xf,0xf0,
0xff,0xc7,0xff,0xff,0xff,0xff,0xff,0xff,0x8f,0xff,0xff,0xff,0xff,0xff,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0x1f,0xf0,
0xff,0x8f,0xff,0xff,0xff,0xff,0xff,0xff,0x87,0xff,0xff,0xff,0xff,0xfe,0xf,0xff,0xff,0xff,0xff,0xff,0xfe,0x1f,0xf0,
0xff,0x8f,0xff,0xff,0xff,0xff,0xff,0xff,0xc3,0xff,0xff,0xff,0xff,0xf8,0xf,0xff,0xff,0xff,0xff,0xff,0xf8,0x3f,0xf0,
0xff,0x8f,0xff,0xff,0xff,0xff,0xff,0xff,0xe1,0xff,0xff,0xff,0xff,0xe0,0xf,0xff,0xff,0xff,0xff,0xff,0xf0,0x7f,0xf0,
0xff,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x7f,0xff,0xff,0xff,0x80,0x1f,0xff,0xff,0xff,0xff,0xff,0xc0,0xff,0xf0,
0xff,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x1f,0xff,0xff,0xfe,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0x3,0xff,0xf0,
0xff,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x3,0xff,0xff,0xf0,0x0,0x1f,0xff,0xff,0xff,0xff,0xfc,0x7,0xff,0xf0,
0xff,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x3f,0xfe,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xf0,0x1f,0xff,0xf0,
0xff,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xc0,0x7f,0xff,0xf0,
0xff,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0x1,0xff,0xff,0xf0,
0xff,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xfc,0x7,0xff,0xff,0xf0,
0xff,0x8f,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xf8,0x1f,0xff,0xff,0xf0,
0xff,0x87,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xf0,0x7f,0xff,0xff,0xf0,
0xff,0xc1,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xe0,0xff,0xff,0xff,0xf0,
0xff,0xe0,0xf,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xc3,0xff,0xff,0xff,0xf0,
0xff,0xf0,0x0,0xf,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0x87,0xff,0xff,0xff,0xf0,
0xff,0xfc,0x0,0x0,0x7f,0xff,0xff,0xff,0xf8,0x0,0x1f,0xff,0xf0,0x0,0x3f,0xff,0xff,0xff,0xf,0xff,0xff,0xff,0xf0,
0xff,0xff,0xe0,0x0,0x7,0xff,0xff,0xff,0xf8,0x7,0xff,0xff,0xff,0xfe,0x1f,0xff,0xff,0xfe,0x1f,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xc0,0x0,0xff,0xff,0xff,0xf1,0xff,0xff,0xff,0xff,0xff,0x1f,0xff,0xff,0xfc,0x3f,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0x0,0x3f,0xff,0xff,0xe1,0xff,0xff,0xff,0xff,0xff,0xf,0xff,0xff,0xf8,0x7f,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xf0,0xf,0xff,0xff,0xc3,0xff,0xff,0xff,0xff,0xff,0x8f,0xff,0xff,0xf0,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xfe,0x3,0xff,0xff,0x87,0xff,0xff,0xff,0xff,0xff,0x87,0xff,0xff,0xc1,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0x80,0x3f,0xfe,0xf,0xff,0xff,0xff,0xff,0xff,0xc3,0xff,0xff,0x83,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xe1,0xff,0xfe,0x7,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xf0,0x7f,0xf8,0x1f,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xf,0x80,0x3f,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x3f,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0
};