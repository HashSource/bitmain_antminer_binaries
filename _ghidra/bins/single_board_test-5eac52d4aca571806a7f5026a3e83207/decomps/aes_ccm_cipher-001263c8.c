
uint aes_ccm_cipher(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  void *b;
  int iVar5;
  size_t len;
  int iVar6;
  undefined1 auStack_30 [20];
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  if (*(int *)(iVar1 + 0xf8) == 0) {
    return 0xffffffff;
  }
  if (-1 < *(int *)(iVar1 + 0x110)) {
    iVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
    if (param_2 != param_3) {
      return 0xffffffff;
    }
    if (param_4 < *(int *)(iVar1 + 0x10c) + 8U) {
      return 0xffffffff;
    }
    iVar6 = EVP_CIPHER_CTX_encrypting(param_1);
    if (iVar6 != 0) {
      puVar4 = (undefined4 *)EVP_CIPHER_CTX_buf_noconst(param_1);
      uVar3 = puVar4[1];
      *param_2 = *puVar4;
      param_2[1] = uVar3;
    }
    iVar2 = iVar1 + 0x118;
    iVar6 = EVP_CIPHER_CTX_iv_noconst(param_1);
    uVar3 = param_2[1];
    *(undefined4 *)(iVar6 + 4) = *param_2;
    *(undefined4 *)(iVar6 + 8) = uVar3;
    iVar6 = *(int *)(iVar1 + 0x10c);
    uVar3 = EVP_CIPHER_CTX_iv_noconst(param_1);
    len = (param_4 - iVar6) - 8;
    iVar6 = CRYPTO_ccm128_setiv(iVar2,uVar3,0xf - *(int *)(iVar1 + 0x108),len);
    if (iVar6 != 0) {
      return 0xffffffff;
    }
    param_2 = param_2 + 2;
    uVar3 = EVP_CIPHER_CTX_buf_noconst(param_1);
    CRYPTO_ccm128_aad(iVar2,uVar3,*(undefined4 *)(iVar1 + 0x110));
    iVar6 = EVP_CIPHER_CTX_encrypting(param_1);
    iVar5 = *(int *)(iVar1 + 0x148);
    if (iVar6 == 0) {
      if (iVar5 == 0) {
        iVar6 = CRYPTO_ccm128_decrypt(iVar2,param_2,param_2,len);
      }
      else {
        iVar6 = CRYPTO_ccm128_decrypt_ccm64(iVar2,param_2,param_2,len,iVar5);
      }
      if (iVar6 == 0) {
        iVar6 = CRYPTO_ccm128_tag(iVar2,auStack_30,*(undefined4 *)(iVar1 + 0x10c));
        if ((iVar6 != 0) &&
           (iVar1 = CRYPTO_memcmp(auStack_30,(void *)((int)param_2 + len),*(size_t *)(iVar1 + 0x10c)
                                 ), iVar1 == 0)) {
          return len;
        }
      }
      OPENSSL_cleanse(param_2,len);
      return 0xffffffff;
    }
    if (iVar5 == 0) {
      iVar6 = CRYPTO_ccm128_encrypt(iVar2,param_2,param_2,len);
      if (iVar6 != 0) {
        iVar6 = 1;
      }
    }
    else {
      iVar6 = CRYPTO_ccm128_encrypt_ccm64(iVar2,param_2,param_2,len,iVar5);
      if (iVar6 != 0) {
        iVar6 = 1;
      }
    }
    if (iVar6 != 0) {
      return 0xffffffff;
    }
    iVar6 = CRYPTO_ccm128_tag(iVar2,(int)param_2 + len,*(undefined4 *)(iVar1 + 0x10c));
    if (iVar6 == 0) {
      return 0xffffffff;
    }
    return *(int *)(iVar1 + 0x10c) + 8 + len;
  }
  if (param_2 != (undefined4 *)0x0 && param_3 == (undefined4 *)0x0) {
    return 0;
  }
  if (*(int *)(iVar1 + 0xfc) == 0) {
    return 0xffffffff;
  }
  iVar6 = iVar1 + 0x118;
  if (param_2 == (undefined4 *)0x0) {
    if (param_3 == (undefined4 *)0x0) {
      uVar3 = EVP_CIPHER_CTX_iv_noconst(param_1);
      iVar6 = CRYPTO_ccm128_setiv(iVar6,uVar3,0xf - *(int *)(iVar1 + 0x108),param_4);
      if (iVar6 != 0) {
        return 0xffffffff;
      }
      *(undefined4 *)(iVar1 + 0x104) = 1;
      return param_4;
    }
    if (param_4 != 0 && *(int *)(iVar1 + 0x104) == 0) {
      return 0xffffffff;
    }
    CRYPTO_ccm128_aad(iVar6,param_3,param_4);
    return param_4;
  }
  iVar2 = EVP_CIPHER_CTX_encrypting(param_1);
  if ((iVar2 == 0) && (*(int *)(iVar1 + 0x100) == 0)) {
    return 0xffffffff;
  }
  if (*(int *)(iVar1 + 0x104) == 0) {
    uVar3 = EVP_CIPHER_CTX_iv_noconst(param_1);
    iVar2 = CRYPTO_ccm128_setiv(iVar6,uVar3,0xf - *(int *)(iVar1 + 0x108),param_4);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    *(undefined4 *)(iVar1 + 0x104) = 1;
  }
  iVar2 = EVP_CIPHER_CTX_encrypting(param_1);
  iVar5 = *(int *)(iVar1 + 0x148);
  if (iVar2 != 0) {
    if (iVar5 == 0) {
      iVar6 = CRYPTO_ccm128_encrypt(iVar6,param_3,param_2,param_4);
      if (iVar6 != 0) {
        iVar6 = 1;
      }
    }
    else {
      iVar6 = CRYPTO_ccm128_encrypt_ccm64(iVar6,param_3,param_2,param_4,iVar5);
      if (iVar6 != 0) {
        iVar6 = 1;
      }
    }
    if (iVar6 != 0) {
      return 0xffffffff;
    }
    *(undefined4 *)(iVar1 + 0x100) = 1;
    return param_4;
  }
  if (iVar5 == 0) {
    iVar2 = CRYPTO_ccm128_decrypt(iVar6,param_3,param_2,param_4);
  }
  else {
    iVar2 = CRYPTO_ccm128_decrypt_ccm64(iVar6,param_3,param_2,param_4,iVar5);
  }
  if (iVar2 == 0) {
    iVar6 = CRYPTO_ccm128_tag(iVar6,auStack_30,*(undefined4 *)(iVar1 + 0x10c));
    if (iVar6 != 0) {
      b = (void *)EVP_CIPHER_CTX_buf_noconst(param_1);
      iVar6 = CRYPTO_memcmp(auStack_30,b,*(size_t *)(iVar1 + 0x10c));
      if ((iVar6 == 0) && (param_4 != 0xffffffff)) goto LAB_001265ba;
    }
  }
  OPENSSL_cleanse(param_2,param_4);
  param_4 = 0xffffffff;
LAB_001265ba:
  *(undefined4 *)(iVar1 + 0xfc) = 0;
  *(undefined4 *)(iVar1 + 0x100) = 0;
  *(undefined4 *)(iVar1 + 0x104) = 0;
  return param_4;
}

