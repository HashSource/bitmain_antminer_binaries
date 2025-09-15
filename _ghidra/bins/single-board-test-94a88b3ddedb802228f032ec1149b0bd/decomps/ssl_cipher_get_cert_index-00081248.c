
undefined4 ssl_cipher_get_cert_index(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0xc);
  uVar2 = *(uint *)(param_1 + 0x10);
  if (((uVar3 & 0x60) != 0) || ((int)(uVar2 << 0x19) < 0)) {
    return 5;
  }
  if ((int)(uVar3 << 0x1e) < 0) {
    return 3;
  }
  if (-1 < (int)(uVar3 << 0x1d)) {
    if ((uVar2 & 2) != 0) {
      return 2;
    }
    uVar1 = 0;
    if (-1 < (int)(uVar2 << 0x1f)) {
      if ((int)(uVar2 << 0x1a) < 0) {
        return 0xffffffff;
      }
      if (-1 < (int)(uVar2 << 0x17)) {
        if ((uVar2 & 0x200) == 0) {
          uVar1 = 0xffffffff;
        }
        else {
          uVar1 = 7;
        }
        return uVar1;
      }
      uVar1 = 6;
    }
    return uVar1;
  }
  return 4;
}

