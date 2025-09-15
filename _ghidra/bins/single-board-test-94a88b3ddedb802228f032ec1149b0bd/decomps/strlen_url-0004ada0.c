
int strlen_url(byte *param_1)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  
  bVar3 = *param_1;
  if (bVar3 == 0) {
    return 0;
  }
  bVar1 = true;
  iVar2 = 0;
LAB_0004adc2:
  do {
    if (bVar3 == 0x20) {
      if (bVar1) {
        param_1 = param_1 + 1;
        bVar3 = *param_1;
        iVar2 = iVar2 + 3;
        if (bVar3 == 0) {
          return iVar2;
        }
        goto LAB_0004adc2;
      }
    }
    else if (bVar3 == 0x3f) {
      bVar1 = false;
    }
    else if ((int)((uint)bVar3 << 0x18) < 0) {
      iVar2 = iVar2 + 2;
    }
    param_1 = param_1 + 1;
    bVar3 = *param_1;
    iVar2 = iVar2 + 1;
    if (bVar3 == 0) {
      return iVar2;
    }
  } while( true );
}

