
byte * OPENSSL_LH_strhash(byte *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_1 != (byte *)0x0) {
    uVar4 = (uint)*param_1;
    if (uVar4 == 0) {
      param_1 = (byte *)0x0;
    }
    else {
      uVar3 = 0;
      uVar5 = 0x100;
      do {
        uVar2 = uVar4 | uVar5;
        param_1 = param_1 + 1;
        uVar4 = (uint)*param_1;
        uVar5 = uVar5 + 0x100;
        uVar1 = (uVar2 ^ uVar2 >> 2) & 0xf;
        uVar3 = (uVar3 >> (0x20 - uVar1 & 0xff) | uVar3 << uVar1) ^ uVar2 * uVar2;
      } while (uVar4 != 0);
      param_1 = (byte *)(uVar3 ^ uVar3 >> 0x10);
    }
  }
  return param_1;
}

