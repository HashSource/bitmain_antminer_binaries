
byte * openssl_lh_strcasehash(byte *param_1)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  pbVar1 = param_1;
  if ((param_1 != (byte *)0x0) && (pbVar1 = (byte *)(uint)*param_1, pbVar1 != (byte *)0x0)) {
    uVar5 = 0x100;
    uVar4 = 0;
    do {
      uVar2 = ossl_tolower();
      uVar2 = uVar2 | uVar5;
      param_1 = param_1 + 1;
      uVar5 = uVar5 + 0x100;
      uVar3 = (uVar2 ^ uVar2 >> 2) & 0xf;
      uVar4 = (uVar4 >> (0x20 - uVar3 & 0xff) | uVar4 << uVar3) ^ uVar2 * uVar2;
    } while (*param_1 != 0);
    return (byte *)(uVar4 ^ uVar4 >> 0x10);
  }
  return pbVar1;
}

