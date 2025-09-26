
uint x509_signing_allowed(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x80);
  if ((*(uint *)(param_2 + 0x80) & 0x400) == 0) {
    if ((uVar1 & 2) != 0) {
      if ((*(uint *)(param_1 + 0x84) & 4) == 0) {
        uVar1 = 0x20;
      }
      else {
        uVar1 = 0;
      }
      return uVar1;
    }
  }
  else if ((uVar1 & 2) != 0) {
    if ((*(uint *)(param_1 + 0x84) & 0x80) == 0) {
      uVar1 = 0x27;
    }
    else {
      uVar1 = 0;
    }
    return uVar1;
  }
  return uVar1 & 2;
}

