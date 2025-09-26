
int drbg_ctr_instantiate
              (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
              undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 == 0) {
    return 0;
  }
  memset((uchar *)(param_1 + 0x7c),0,0x20);
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  iVar1 = EVP_CipherInit_ex(*(EVP_CIPHER_CTX **)(param_1 + 100),(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                            (uchar *)(param_1 + 0x7c),(uchar *)0x0,-1);
  if (iVar1 != 0) {
    uVar3 = *(byte *)(param_1 + 0xab) + 1;
    *(char *)(param_1 + 0xab) = (char)uVar3;
    uVar3 = (uint)*(byte *)(param_1 + 0xaa) + (uVar3 >> 8);
    uVar2 = (uint)*(byte *)(param_1 + 0xa9) + (uVar3 >> 8);
    *(char *)(param_1 + 0xaa) = (char)uVar3;
    uVar3 = (uint)*(byte *)(param_1 + 0xa8) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa9) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0xa7) + (uVar3 >> 8);
    *(char *)(param_1 + 0xa8) = (char)uVar3;
    uVar3 = (uint)*(byte *)(param_1 + 0xa6) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa7) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0xa5) + (uVar3 >> 8);
    *(char *)(param_1 + 0xa6) = (char)uVar3;
    uVar3 = (uint)*(byte *)(param_1 + 0xa4) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa5) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0xa3) + (uVar3 >> 8);
    *(char *)(param_1 + 0xa4) = (char)uVar3;
    uVar3 = (uint)*(byte *)(param_1 + 0xa2) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa3) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0xa1) + (uVar3 >> 8);
    *(char *)(param_1 + 0xa2) = (char)uVar3;
    uVar3 = (uint)*(byte *)(param_1 + 0xa0) + (uVar2 >> 8);
    *(char *)(param_1 + 0xa1) = (char)uVar2;
    uVar2 = (uint)*(byte *)(param_1 + 0x9f) + (uVar3 >> 8);
    *(char *)(param_1 + 0xa0) = (char)uVar3;
    uVar3 = (uint)*(byte *)(param_1 + 0x9e) + (uVar2 >> 8);
    *(char *)(param_1 + 0x9f) = (char)uVar2;
    iVar1 = (uint)*(byte *)(param_1 + 0x9d) + (uVar3 >> 8);
    *(char *)(param_1 + 0x9e) = (char)uVar3;
    *(char *)(param_1 + 0x9d) = (char)iVar1;
    *(char *)(param_1 + 0x9c) = *(char *)(param_1 + 0x9c) + (char)((uint)iVar1 >> 8);
    iVar1 = ctr_update(param_1,param_2,param_3,param_6,param_7,param_4,param_5);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  return 0;
}

