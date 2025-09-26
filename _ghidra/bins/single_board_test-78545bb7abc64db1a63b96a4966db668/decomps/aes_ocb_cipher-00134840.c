
int aes_ocb_cipher(undefined4 param_1,int param_2,void *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  size_t *psVar5;
  uint uVar6;
  void *__dest;
  int local_2c;
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  if (*(int *)(iVar1 + 500) == 0) {
    return -1;
  }
  if (*(int *)(iVar1 + 0x1f0) == 0) {
    return -1;
  }
  if (param_3 == (void *)0x0) {
    iVar2 = 0;
    if (0 < *(int *)(iVar1 + 0x2c4)) {
      iVar2 = EVP_CIPHER_CTX_encrypting(param_1);
      if (iVar2 == 0) {
        iVar2 = CRYPTO_ocb128_decrypt(iVar1 + 0x1f8);
      }
      else {
        iVar2 = CRYPTO_ocb128_encrypt
                          (iVar1 + 0x1f8,iVar1 + 0x2a4,param_2,*(undefined4 *)(iVar1 + 0x2c4));
      }
      if (iVar2 == 0) {
        return -1;
      }
      iVar2 = *(int *)(iVar1 + 0x2c4);
      *(undefined4 *)(iVar1 + 0x2c4) = 0;
    }
    if (0 < *(int *)(iVar1 + 0x2c8)) {
      iVar4 = CRYPTO_ocb128_aad(iVar1 + 0x1f8,iVar1 + 0x2b4);
      if (iVar4 == 0) {
        return -1;
      }
      *(undefined4 *)(iVar1 + 0x2c8) = 0;
    }
    iVar4 = EVP_CIPHER_CTX_encrypting(param_1);
    if (iVar4 != 0) {
      iVar4 = CRYPTO_ocb128_tag(iVar1 + 0x1f8,iVar1 + 0x294,0x10);
      if (iVar4 == 1) {
        *(undefined4 *)(iVar1 + 500) = 0;
        return iVar2;
      }
      return -1;
    }
    if (*(int *)(iVar1 + 0x2d0) < 0) {
      return -1;
    }
    iVar4 = CRYPTO_ocb128_finish(iVar1 + 0x1f8,iVar1 + 0x294);
    if (iVar4 != 0) {
      return -1;
    }
    *(undefined4 *)(iVar1 + 500) = 0;
    return iVar2;
  }
  __dest = (void *)(iVar1 + 0x2b4);
  psVar5 = (size_t *)(iVar1 + 0x2c8);
  if (param_2 != 0) {
    __dest = (void *)(iVar1 + 0x2a4);
    psVar5 = (size_t *)(iVar1 + 0x2c4);
    iVar2 = is_partially_overlapping(*(int *)(iVar1 + 0x2c4) + param_2,param_3,param_4);
    if (iVar2 != 0) {
      ERR_put_error(6,0xa9,0xa2,"crypto/evp/e_aes.c",0x103a);
      return 0;
    }
  }
  sVar3 = *psVar5;
  if ((int)sVar3 < 1) {
    iVar2 = 0;
    local_2c = 0;
LAB_001348e0:
    uVar6 = param_4 & 0xf;
    if (param_4 == uVar6) goto LAB_00134912;
    if (param_2 == 0) goto LAB_00134a4a;
    iVar2 = param_4 - uVar6;
    iVar4 = EVP_CIPHER_CTX_encrypting(param_1);
    if (iVar4 == 0) {
      iVar1 = CRYPTO_ocb128_decrypt(iVar1 + 0x1f8,param_3,param_2,iVar2);
    }
    else {
      iVar1 = CRYPTO_ocb128_encrypt(iVar1 + 0x1f8,param_3,param_2,iVar2);
    }
  }
  else {
    uVar6 = 0x10 - sVar3;
    if (param_4 < uVar6) {
      memcpy((void *)(sVar3 + (int)__dest),param_3,param_4);
      *psVar5 = param_4 + *psVar5;
      return 0;
    }
    param_4 = param_4 - uVar6;
    memcpy((void *)(sVar3 + (int)__dest),param_3,uVar6);
    param_3 = (void *)((int)param_3 + uVar6);
    if (param_2 != 0) {
      iVar2 = EVP_CIPHER_CTX_encrypting(param_1);
      if (iVar2 == 0) {
        iVar2 = CRYPTO_ocb128_decrypt(iVar1 + 0x1f8,__dest,param_2,0x10);
      }
      else {
        iVar2 = CRYPTO_ocb128_encrypt(iVar1 + 0x1f8);
      }
      if (iVar2 == 0) {
        return -1;
      }
      *psVar5 = 0;
      param_2 = param_2 + 0x10;
      local_2c = 0x10;
      iVar2 = 0x10;
      goto LAB_001348e0;
    }
    iVar2 = CRYPTO_ocb128_aad(iVar1 + 0x1f8,__dest,0x10);
    if (iVar2 == 0) {
      return -1;
    }
    uVar6 = param_4 & 0xf;
    iVar2 = 0x10;
    *psVar5 = 0;
    if (param_4 == uVar6) goto LAB_00134912;
    local_2c = 0x10;
LAB_00134a4a:
    iVar2 = param_4 - uVar6;
    iVar1 = CRYPTO_ocb128_aad(iVar1 + 0x1f8,param_3,iVar2);
  }
  if (iVar1 == 0) {
    return -1;
  }
  param_3 = (void *)((int)param_3 + iVar2);
  iVar2 = local_2c + iVar2;
LAB_00134912:
  if (uVar6 == 0) {
    return iVar2;
  }
  memcpy(__dest,param_3,uVar6);
  *psVar5 = uVar6;
  return iVar2;
}

