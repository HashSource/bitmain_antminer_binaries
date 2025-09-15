
double get_pic_an_voltage2(uint8_t chain)

{
  double dVar1;
  uint8_t chain_local;
  
  dVar1 = dsPIC33EP16GS202_pic_get_an_voltage2(chain);
  return dVar1;
}

