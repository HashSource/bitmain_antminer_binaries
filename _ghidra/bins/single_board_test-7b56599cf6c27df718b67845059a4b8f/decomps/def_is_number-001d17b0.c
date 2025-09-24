
byte def_is_number(int param_1,int param_2)

{
  byte bVar1;
  
  if (param_2 << 0x18 < 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = *(byte *)(*(int *)(param_1 + 4) + param_2 * 2) & 1;
  }
  return bVar1;
}

