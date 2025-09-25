
undefined4 drbg_ctr_init(int param_1)

{
  EVP_CIPHER *pEVar1;
  EVP_CIPHER_CTX *pEVar2;
  EVP_CIPHER_CTX *pEVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar5 = *(int *)(param_1 + 0xc);
  if (iVar5 == 0x389) {
    pEVar1 = EVP_aes_192_ecb();
    *(EVP_CIPHER **)(param_1 + 0x70) = pEVar1;
    uVar6 = 0x28;
    pEVar1 = EVP_aes_192_ctr();
    uVar7 = 0xc0;
    *(EVP_CIPHER **)(param_1 + 0x74) = pEVar1;
    uVar4 = 0x18;
  }
  else if (iVar5 == 0x38a) {
    pEVar1 = EVP_aes_256_ecb();
    *(EVP_CIPHER **)(param_1 + 0x70) = pEVar1;
    uVar6 = 0x30;
    pEVar1 = EVP_aes_256_ctr();
    uVar7 = 0x100;
    uVar4 = 0x20;
    *(EVP_CIPHER **)(param_1 + 0x74) = pEVar1;
  }
  else {
    if (iVar5 != 0x388) {
      return 0;
    }
    pEVar1 = EVP_aes_128_ecb();
    *(EVP_CIPHER **)(param_1 + 0x70) = pEVar1;
    uVar6 = 0x20;
    pEVar1 = EVP_aes_128_ctr();
    uVar7 = 0x80;
    uVar4 = 0x10;
    *(EVP_CIPHER **)(param_1 + 0x74) = pEVar1;
  }
  pEVar2 = *(EVP_CIPHER_CTX **)(param_1 + 100);
  *(undefined4 *)(param_1 + 0x78) = uVar4;
  *(undefined ***)(param_1 + 0xf0) = &drbg_ctr_meth;
  if (pEVar2 == (EVP_CIPHER_CTX *)0x0) {
    pEVar2 = EVP_CIPHER_CTX_new();
    *(EVP_CIPHER_CTX **)(param_1 + 100) = pEVar2;
    pEVar3 = pEVar2;
    if (*(int *)(param_1 + 0x68) == 0) goto LAB_001b849c;
  }
  else {
    if (*(int *)(param_1 + 0x68) != 0) goto LAB_001b83e8;
LAB_001b849c:
    pEVar3 = EVP_CIPHER_CTX_new();
    pEVar2 = *(EVP_CIPHER_CTX **)(param_1 + 100);
    *(EVP_CIPHER_CTX **)(param_1 + 0x68) = pEVar3;
    if (pEVar2 == (EVP_CIPHER_CTX *)0x0) {
      return 0;
    }
  }
  if (pEVar3 == (EVP_CIPHER_CTX *)0x0) {
    return 0;
  }
LAB_001b83e8:
  iVar5 = EVP_CipherInit_ex(pEVar2,*(EVP_CIPHER **)(param_1 + 0x70),(ENGINE *)0x0,(uchar *)0x0,
                            (uchar *)0x0,1);
  if ((iVar5 == 0) ||
     (iVar5 = EVP_CipherInit_ex(*(EVP_CIPHER_CTX **)(param_1 + 0x68),
                                *(EVP_CIPHER **)(param_1 + 0x74),(ENGINE *)0x0,(uchar *)0x0,
                                (uchar *)0x0,1), iVar5 == 0)) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0x20) = uVar7;
  *(undefined4 *)(param_1 + 0x58) = uVar6;
  *(undefined ***)(param_1 + 0xf0) = &drbg_ctr_meth;
  if ((int)((uint)*(ushort *)(param_1 + 0x14) << 0x1f) < 0) {
    *(undefined4 *)(param_1 + 0x28) = uVar6;
    *(undefined4 *)(param_1 + 0x2c) = uVar6;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x38) = uVar6;
    *(undefined4 *)(param_1 + 0x3c) = uVar6;
  }
  else {
    pEVar2 = *(EVP_CIPHER_CTX **)(param_1 + 0x6c);
    if (pEVar2 == (EVP_CIPHER_CTX *)0x0) {
      pEVar2 = EVP_CIPHER_CTX_new();
      *(EVP_CIPHER_CTX **)(param_1 + 0x6c) = pEVar2;
      if (pEVar2 == (EVP_CIPHER_CTX *)0x0) {
        return 0;
      }
    }
    iVar5 = EVP_CipherInit_ex(pEVar2,*(EVP_CIPHER **)(param_1 + 0x70),(ENGINE *)0x0,"",(uchar *)0x0,
                              1);
    if (iVar5 == 0) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x2c) = 0x7fffffff;
    *(undefined4 *)(param_1 + 0x34) = 0x7fffffff;
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x78);
    *(undefined4 *)(param_1 + 0x38) = 0x7fffffff;
    *(undefined4 *)(param_1 + 0x3c) = 0x7fffffff;
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x78) >> 1;
  }
  *(undefined4 *)(param_1 + 0x24) = 0x10000;
  return 1;
}

