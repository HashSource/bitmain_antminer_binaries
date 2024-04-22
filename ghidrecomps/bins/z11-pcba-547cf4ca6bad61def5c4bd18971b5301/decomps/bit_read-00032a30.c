
bool bit_read(int param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = param_2 & 7;
  if ((int)param_2 < 1) {
    uVar1 = -(-param_2 & 7);
  }
  switch(uVar1) {
  case 0:
    uVar1 = param_2 + 7;
    if (-1 < (int)param_2) {
      uVar1 = param_2;
    }
    bVar2 = (*(byte *)(param_1 + ((int)uVar1 >> 3)) & 1) != 0;
    break;
  case 1:
    uVar1 = param_2 + 7;
    if (-1 < (int)param_2) {
      uVar1 = param_2;
    }
    bVar2 = (*(byte *)(param_1 + ((int)uVar1 >> 3)) & 2) != 0;
    break;
  case 2:
    uVar1 = param_2 + 7;
    if (-1 < (int)param_2) {
      uVar1 = param_2;
    }
    bVar2 = (*(byte *)(param_1 + ((int)uVar1 >> 3)) & 4) != 0;
    break;
  case 3:
    uVar1 = param_2 + 7;
    if (-1 < (int)param_2) {
      uVar1 = param_2;
    }
    bVar2 = (*(byte *)(param_1 + ((int)uVar1 >> 3)) & 8) != 0;
    break;
  case 4:
    uVar1 = param_2 + 7;
    if (-1 < (int)param_2) {
      uVar1 = param_2;
    }
    bVar2 = (*(byte *)(param_1 + ((int)uVar1 >> 3)) & 0x10) != 0;
    break;
  case 5:
    uVar1 = param_2 + 7;
    if (-1 < (int)param_2) {
      uVar1 = param_2;
    }
    bVar2 = (*(byte *)(param_1 + ((int)uVar1 >> 3)) & 0x20) != 0;
    break;
  case 6:
    uVar1 = param_2 + 7;
    if (-1 < (int)param_2) {
      uVar1 = param_2;
    }
    bVar2 = (*(byte *)(param_1 + ((int)uVar1 >> 3)) & 0x40) != 0;
    break;
  case 7:
    uVar1 = param_2 + 7;
    if (-1 < (int)param_2) {
      uVar1 = param_2;
    }
    bVar2 = (bool)(*(byte *)(param_1 + ((int)uVar1 >> 3)) >> 7);
    break;
  default:
    bVar2 = false;
  }
  return bVar2;
}

