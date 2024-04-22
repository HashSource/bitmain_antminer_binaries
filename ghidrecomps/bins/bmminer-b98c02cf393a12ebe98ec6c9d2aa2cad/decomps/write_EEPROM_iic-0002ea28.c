
void write_EEPROM_iic(int param_1,int param_2,int param_3,uint param_4,byte param_5)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 4;
  get_iic();
  do {
    usleep(1000);
    get_iic();
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x2000000;
  }
  if (param_2 != 0) {
    uVar1 = uVar1 | param_3 << 8 | 0x1000000;
  }
  set_iic(uVar1 | param_5 | 0xa00000 | (param_4 & 0xf) << 0x10);
  return;
}

