
uchar bit_read(uchar *y,int x)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  int x_local;
  uchar *y_local;
  
  uVar2 = x & 7;
  if (x < 1) {
    uVar2 = -(-x & 7U);
  }
  switch(uVar2) {
  case 0:
    iVar1 = x + 7;
    if (-1 < x) {
      iVar1 = x;
    }
    bVar3 = (y[iVar1 >> 3] & 1) != 0;
    break;
  case 1:
    iVar1 = x + 7;
    if (-1 < x) {
      iVar1 = x;
    }
    bVar3 = (y[iVar1 >> 3] & 2) != 0;
    break;
  case 2:
    iVar1 = x + 7;
    if (-1 < x) {
      iVar1 = x;
    }
    bVar3 = (y[iVar1 >> 3] & 4) != 0;
    break;
  case 3:
    iVar1 = x + 7;
    if (-1 < x) {
      iVar1 = x;
    }
    bVar3 = (y[iVar1 >> 3] & 8) != 0;
    break;
  case 4:
    iVar1 = x + 7;
    if (-1 < x) {
      iVar1 = x;
    }
    bVar3 = (y[iVar1 >> 3] & 0x10) != 0;
    break;
  case 5:
    iVar1 = x + 7;
    if (-1 < x) {
      iVar1 = x;
    }
    bVar3 = (y[iVar1 >> 3] & 0x20) != 0;
    break;
  case 6:
    iVar1 = x + 7;
    if (-1 < x) {
      iVar1 = x;
    }
    bVar3 = (y[iVar1 >> 3] & 0x40) != 0;
    break;
  case 7:
    iVar1 = x + 7;
    if (-1 < x) {
      iVar1 = x;
    }
    bVar3 = (bool)(y[iVar1 >> 3] >> 7);
    break;
  default:
    bVar3 = false;
  }
  return bVar3;
}

