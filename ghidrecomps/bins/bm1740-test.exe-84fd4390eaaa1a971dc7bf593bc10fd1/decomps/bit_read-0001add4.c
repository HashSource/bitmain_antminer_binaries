
bool bit_read(int param_1,int param_2)

{
  bool bVar1;
  
  switch(param_2 % 8) {
  case 0:
    if (param_2 < 0) {
      param_2 = param_2 + 7;
    }
    bVar1 = (*(byte *)(param_1 + (param_2 >> 3)) & 1) != 0;
    break;
  case 1:
    if (param_2 < 0) {
      param_2 = param_2 + 7;
    }
    bVar1 = (*(byte *)(param_1 + (param_2 >> 3)) & 2) != 0;
    break;
  case 2:
    if (param_2 < 0) {
      param_2 = param_2 + 7;
    }
    bVar1 = (*(byte *)(param_1 + (param_2 >> 3)) & 4) != 0;
    break;
  case 3:
    if (param_2 < 0) {
      param_2 = param_2 + 7;
    }
    bVar1 = (*(byte *)(param_1 + (param_2 >> 3)) & 8) != 0;
    break;
  case 4:
    if (param_2 < 0) {
      param_2 = param_2 + 7;
    }
    bVar1 = (*(byte *)(param_1 + (param_2 >> 3)) & 0x10) != 0;
    break;
  case 5:
    if (param_2 < 0) {
      param_2 = param_2 + 7;
    }
    bVar1 = (*(byte *)(param_1 + (param_2 >> 3)) & 0x20) != 0;
    break;
  case 6:
    if (param_2 < 0) {
      param_2 = param_2 + 7;
    }
    bVar1 = (*(byte *)(param_1 + (param_2 >> 3)) & 0x40) != 0;
    break;
  case 7:
    if (param_2 < 0) {
      param_2 = param_2 + 7;
    }
    bVar1 = (bool)(*(byte *)(param_1 + (param_2 >> 3)) >> 7);
    break;
  default:
    bVar1 = false;
  }
  return bVar1;
}

