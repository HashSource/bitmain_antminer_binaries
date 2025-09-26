
uint aria_gcm_cipher(EVP_CIPHER_CTX *param_1,void *param_2,void *param_3,size_t param_4)

{
  int iVar1;
  int iVar2;
  void *a;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  size_t len;
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  if (*(int *)(iVar1 + 0x118) == 0) {
    return 0xffffffff;
  }
  if (*(int *)(iVar1 + 0x2d8) < 0) {
    if (*(int *)(iVar1 + 0x11c) == 0) {
      return 0xffffffff;
    }
    if (param_3 != (void *)0x0) {
      if (param_2 == (void *)0x0) {
        iVar1 = CRYPTO_gcm128_aad(iVar1 + 0x120,param_3,param_4);
      }
      else {
        iVar2 = EVP_CIPHER_CTX_encrypting(param_1);
        if (iVar2 == 0) {
          iVar1 = CRYPTO_gcm128_decrypt(iVar1 + 0x120,param_3,param_2,param_4);
        }
        else {
          iVar1 = CRYPTO_gcm128_encrypt(iVar1 + 0x120,param_3,param_2,param_4);
        }
      }
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      return param_4;
    }
    iVar2 = EVP_CIPHER_CTX_encrypting(param_1);
    if (iVar2 != 0) {
      uVar3 = EVP_CIPHER_CTX_buf_noconst(param_1);
      CRYPTO_gcm128_tag(iVar1 + 0x120,uVar3,0x10);
      *(undefined4 *)(iVar1 + 0x11c) = 0;
      *(undefined4 *)(iVar1 + 0x2d0) = 0x10;
      return 0;
    }
    if (*(int *)(iVar1 + 0x2d0) < 0) {
      return 0xffffffff;
    }
    uVar3 = EVP_CIPHER_CTX_buf_noconst(param_1);
    iVar2 = CRYPTO_gcm128_finish(iVar1 + 0x120,uVar3,*(undefined4 *)(iVar1 + 0x2d0));
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    *(undefined4 *)(iVar1 + 0x11c) = 0;
    return 0;
  }
  iVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
  if (param_2 != param_3 || param_4 < 0x18) {
    return 0xffffffff;
  }
  iVar2 = EVP_CIPHER_CTX_encrypting(param_1);
  if (iVar2 == 0) {
    iVar2 = 0x18;
  }
  else {
    iVar2 = 0x13;
  }
  iVar2 = EVP_CIPHER_CTX_ctrl(param_1,iVar2,8,param_2);
  if (0 < iVar2) {
    iVar5 = iVar1 + 0x120;
    uVar3 = EVP_CIPHER_CTX_buf_noconst(param_1);
    iVar2 = CRYPTO_gcm128_aad(iVar5,uVar3,*(undefined4 *)(iVar1 + 0x2d8));
    if (iVar2 == 0) {
      iVar4 = (int)param_3 + 8;
      param_2 = (void *)((int)param_2 + 8);
      len = param_4 - 0x18;
      iVar2 = EVP_CIPHER_CTX_encrypting(param_1);
      if (iVar2 == 0) {
        iVar2 = CRYPTO_gcm128_decrypt(iVar5,iVar4,param_2,len);
        if (iVar2 == 0) {
          uVar3 = EVP_CIPHER_CTX_buf_noconst(param_1);
          CRYPTO_gcm128_tag(iVar5,uVar3,0x10);
          a = (void *)EVP_CIPHER_CTX_buf_noconst(param_1);
          iVar2 = CRYPTO_memcmp(a,(void *)(iVar4 + len),0x10);
          param_4 = len;
          if (iVar2 == 0) goto LAB_001356a0;
          OPENSSL_cleanse(param_2,len);
        }
      }
      else {
        iVar2 = CRYPTO_gcm128_encrypt(iVar5,iVar4,param_2,len);
        if (iVar2 == 0) {
          CRYPTO_gcm128_tag(iVar5,(int)param_2 + len,0x10);
          goto LAB_001356a0;
        }
      }
    }
  }
  param_4 = 0xffffffff;
LAB_001356a0:
  *(undefined4 *)(iVar1 + 0x11c) = 0;
  *(undefined4 *)(iVar1 + 0x2d8) = 0xffffffff;
  return param_4;
}

