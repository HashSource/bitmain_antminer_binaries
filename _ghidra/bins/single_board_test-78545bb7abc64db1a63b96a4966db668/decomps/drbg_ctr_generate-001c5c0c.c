
int drbg_ctr_generate(int param_1,uchar *param_2,size_t param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uchar *iv;
  uint uVar5;
  uint uVar6;
  uint local_2c [2];
  
  if (param_4 == 0 || param_5 == 0) {
    param_5 = 0;
  }
  else {
    uVar5 = *(byte *)(param_1 + 0xab) + 1;
    *(char *)(param_1 + 0xab) = (char)uVar5;
    uVar2 = (uint)*(byte *)(param_1 + 0xaa) + (uVar5 >> 8);
    uVar5 = (uint)*(byte *)(param_1 + 0xa9) + (uVar2 >> 8);
    *(char *)(param_1 + 0xaa) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0xa8) + (uVar5 >> 8);
    *(char *)(param_1 + 0xa9) = (char)uVar5;
    uVar5 = (uint)*(byte *)(param_1 + 0xa7) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa8) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0xa6) + (uVar5 >> 8);
    *(char *)(param_1 + 0xa7) = (char)uVar5;
    uVar5 = (uint)*(byte *)(param_1 + 0xa5) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa6) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0xa4) + (uVar5 >> 8);
    *(char *)(param_1 + 0xa5) = (char)uVar5;
    uVar5 = (uint)*(byte *)(param_1 + 0xa3) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa4) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0xa2) + (uVar5 >> 8);
    *(char *)(param_1 + 0xa3) = (char)uVar5;
    uVar5 = (uint)*(byte *)(param_1 + 0xa1) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa2) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0xa0) + (uVar5 >> 8);
    *(char *)(param_1 + 0xa1) = (char)uVar5;
    uVar6 = (uint)*(byte *)(param_1 + 0x9f) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa0) = (char)uVar2;
    uVar5 = (uint)*(byte *)(param_1 + 0x9e) + (uVar6 >> 8);
    *(char *)(param_1 + 0x9f) = (char)uVar6;
    iVar1 = (uint)*(byte *)(param_1 + 0x9d) + (uVar5 >> 8);
    *(char *)(param_1 + 0x9e) = (char)uVar5;
    *(char *)(param_1 + 0x9d) = (char)iVar1;
    *(char *)(param_1 + 0x9c) = *(char *)(param_1 + 0x9c) + (char)((uint)iVar1 >> 8);
    iVar1 = ctr_update(param_1,param_4,param_5,0,0,0,0);
    if (iVar1 == 0) {
      return 0;
    }
    if ((*(ushort *)(param_1 + 0x14) & 1) == 0) {
      param_4 = 0;
      param_5 = 1;
    }
  }
  iv = (uchar *)(param_1 + 0x9c);
  uVar5 = *(byte *)(param_1 + 0xab) + 1;
  *(char *)(param_1 + 0xab) = (char)uVar5;
  uVar5 = (uint)*(byte *)(param_1 + 0xaa) + (uVar5 >> 8);
  uVar2 = (uint)*(byte *)(param_1 + 0xa9) + (uVar5 >> 8);
  *(char *)(param_1 + 0xaa) = (char)uVar5;
  uVar5 = (uint)*(byte *)(param_1 + 0xa8) + (uVar2 >> 8);
  *(char *)(param_1 + 0xa9) = (char)uVar2;
  uVar2 = (uint)*(byte *)(param_1 + 0xa7) + (uVar5 >> 8);
  *(char *)(param_1 + 0xa8) = (char)uVar5;
  uVar5 = (uint)*(byte *)(param_1 + 0xa6) + (uVar2 >> 8);
  *(char *)(param_1 + 0xa7) = (char)uVar2;
  uVar2 = (uint)*(byte *)(param_1 + 0xa5) + (uVar5 >> 8);
  *(char *)(param_1 + 0xa6) = (char)uVar5;
  uVar5 = (uint)*(byte *)(param_1 + 0xa4) + (uVar2 >> 8);
  *(char *)(param_1 + 0xa5) = (char)uVar2;
  uVar2 = (uint)*(byte *)(param_1 + 0xa3) + (uVar5 >> 8);
  *(char *)(param_1 + 0xa4) = (char)uVar5;
  uVar5 = (uint)*(byte *)(param_1 + 0xa2) + (uVar2 >> 8);
  *(char *)(param_1 + 0xa3) = (char)uVar2;
  uVar2 = (uint)*(byte *)(param_1 + 0xa1) + (uVar5 >> 8);
  *(char *)(param_1 + 0xa2) = (char)uVar5;
  uVar5 = (uint)*(byte *)(param_1 + 0xa0) + (uVar2 >> 8);
  *(char *)(param_1 + 0xa1) = (char)uVar2;
  uVar2 = (uint)*(byte *)(param_1 + 0x9f) + (uVar5 >> 8);
  *(char *)(param_1 + 0xa0) = (char)uVar5;
  uVar5 = (uint)*(byte *)(param_1 + 0x9e) + (uVar2 >> 8);
  *(char *)(param_1 + 0x9f) = (char)uVar2;
  iVar1 = (uint)*(byte *)(param_1 + 0x9d) + (uVar5 >> 8);
  *(char *)(param_1 + 0x9e) = (char)uVar5;
  *(char *)(param_1 + 0x9d) = (char)iVar1;
  *iv = *iv + (char)((uint)iVar1 >> 8);
  if (param_3 == 0) {
    uVar5 = *(byte *)(param_1 + 0xab) + 1;
    uVar2 = (uint)*(byte *)(param_1 + 0xaa) + (uVar5 >> 8);
    *(char *)(param_1 + 0xab) = (char)uVar5;
    uVar5 = (uint)*(byte *)(param_1 + 0xa9) + (uVar2 >> 8);
    *(char *)(param_1 + 0xaa) = (char)uVar2;
    uVar6 = (uint)*(byte *)(param_1 + 0xa8) + (uVar5 >> 8);
    *(char *)(param_1 + 0xa9) = (char)uVar5;
    uVar2 = (uint)*(byte *)(param_1 + 0xa7) + (uVar6 >> 8);
    *(char *)(param_1 + 0xa8) = (char)uVar6;
    uVar5 = (uint)*(byte *)(param_1 + 0xa6) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa7) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0xa5) + (uVar5 >> 8);
    *(char *)(param_1 + 0xa6) = (char)uVar5;
    uVar5 = (uint)*(byte *)(param_1 + 0xa4) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa5) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0xa3) + (uVar5 >> 8);
    *(char *)(param_1 + 0xa4) = (char)uVar5;
    uVar5 = (uint)*(byte *)(param_1 + 0xa2) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa3) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0xa1) + (uVar5 >> 8);
    *(char *)(param_1 + 0xa2) = (char)uVar5;
    uVar5 = (uint)*(byte *)(param_1 + 0xa0) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa1) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0x9f) + (uVar5 >> 8);
    *(char *)(param_1 + 0xa0) = (char)uVar5;
    uVar5 = (uint)*(byte *)(param_1 + 0x9e) + (uVar2 >> 8);
    *(char *)(param_1 + 0x9f) = (char)uVar2;
    iVar1 = (uint)*(byte *)(param_1 + 0x9d) + (uVar5 >> 8);
    *(char *)(param_1 + 0x9e) = (char)uVar5;
    *(char *)(param_1 + 0x9d) = (char)iVar1;
    *iv = *iv + (char)((uint)iVar1 >> 8);
    iVar1 = ctr_update(param_1,param_4,param_5,0,0,0,0);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  else {
    memset(param_2,0,param_3);
    do {
      uVar5 = param_3;
      if (0x3fffffff < param_3) {
        uVar5 = 0x40000000;
      }
      iVar1 = EVP_CipherInit_ex(*(EVP_CIPHER_CTX **)(param_1 + 0x68),(EVP_CIPHER *)0x0,(ENGINE *)0x0
                                ,(uchar *)0x0,iv,-1);
      if (iVar1 == 0) {
        return 0;
      }
      uVar6 = *(uint *)(param_1 + 0xa8);
      uVar3 = (int)(uVar5 + 0xf) >> 4;
      uVar2 = 0;
      uVar6 = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
              uVar6 >> 0x18;
      uVar4 = uVar3 + uVar6;
      if (CARRY4(uVar3,uVar6)) {
        if (uVar4 != 0) {
          uVar5 = uVar6 * -0x10;
        }
        uVar6 = *(byte *)(param_1 + 0xa7) + 1;
        *(char *)(param_1 + 0xa7) = (char)uVar6;
        uVar6 = (uint)*(byte *)(param_1 + 0xa6) + (uVar6 >> 8);
        uVar3 = (uint)*(byte *)(param_1 + 0xa5) + (uVar6 >> 8);
        *(char *)(param_1 + 0xa6) = (char)uVar6;
        uVar6 = (uint)*(byte *)(param_1 + 0xa4) + (uVar3 >> 8);
        *(char *)(param_1 + 0xa5) = (char)uVar3;
        uVar3 = (uint)*(byte *)(param_1 + 0xa3) + (uVar6 >> 8);
        *(char *)(param_1 + 0xa4) = (char)uVar6;
        uVar6 = (uint)*(byte *)(param_1 + 0xa2) + (uVar3 >> 8);
        *(char *)(param_1 + 0xa3) = (char)uVar3;
        uVar3 = (uint)*(byte *)(param_1 + 0xa1) + (uVar6 >> 8);
        *(char *)(param_1 + 0xa2) = (char)uVar6;
        uVar6 = (uint)*(byte *)(param_1 + 0xa0) + (uVar3 >> 8);
        *(char *)(param_1 + 0xa1) = (char)uVar3;
        uVar3 = (uint)*(byte *)(param_1 + 0x9f) + (uVar6 >> 8);
        *(char *)(param_1 + 0xa0) = (char)uVar6;
        uVar6 = (uint)*(byte *)(param_1 + 0x9e) + (uVar3 >> 8);
        *(char *)(param_1 + 0x9f) = (char)uVar3;
        iVar1 = (uint)*(byte *)(param_1 + 0x9d) + (uVar6 >> 8);
        *(char *)(param_1 + 0x9e) = (char)uVar6;
        *(char *)(param_1 + 0x9d) = (char)iVar1;
        *(char *)(param_1 + 0x9c) = *(char *)(param_1 + 0x9c) + (char)((uint)iVar1 >> 8);
        uVar6 = uVar2;
        uVar3 = uVar2;
        uVar4 = uVar2;
      }
      else {
        uVar3 = uVar4 >> 0x18;
        uVar2 = uVar4 & 0xff;
        uVar6 = uVar4 * 0x100 >> 0x18;
        uVar4 = uVar4 * 0x10000 >> 0x18;
      }
      *(uint *)(param_1 + 0xa8) = uVar3 | uVar6 << 8 | uVar4 << 0x10 | uVar2 << 0x18;
      iVar1 = EVP_CipherUpdate(*(EVP_CIPHER_CTX **)(param_1 + 0x68),param_2,(int *)local_2c,param_2,
                               uVar5);
      if (iVar1 == 0) {
        return 0;
      }
      if (uVar5 != local_2c[0]) {
        return 0;
      }
      param_3 = param_3 - uVar5;
      param_2 = param_2 + uVar5;
    } while (param_3 != 0);
    iVar1 = ctr_update(param_1,param_4,param_5,0,0,0,0);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}

