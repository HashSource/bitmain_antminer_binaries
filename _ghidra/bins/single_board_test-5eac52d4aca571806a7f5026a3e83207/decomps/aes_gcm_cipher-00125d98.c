
uint aes_gcm_cipher(EVP_CIPHER_CTX *param_1,void *param_2,void *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint len;
  int iVar4;
  uchar *a;
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  if (*(int *)(iVar1 + 0xf8) == 0) {
    return 0xffffffff;
  }
  if (*(int *)(iVar1 + 0x2b8) < 0) {
    if (*(int *)(iVar1 + 0xfc) == 0) {
      return 0xffffffff;
    }
    if (param_3 != (void *)0x0) {
      if (param_2 == (void *)0x0) {
        iVar1 = CRYPTO_gcm128_aad(iVar1 + 0x100,param_3,param_4);
      }
      else if (param_1->encrypt == 0) {
        if (*(int *)(iVar1 + 700) == 0) {
          iVar1 = CRYPTO_gcm128_decrypt(iVar1 + 0x100,param_3,param_2,param_4);
        }
        else {
          iVar1 = CRYPTO_gcm128_decrypt_ctr32
                            (iVar1 + 0x100,param_3,param_2,param_4,*(int *)(iVar1 + 700));
        }
      }
      else if (*(int *)(iVar1 + 700) == 0) {
        iVar1 = CRYPTO_gcm128_encrypt(iVar1 + 0x100,param_3,param_2,param_4);
      }
      else {
        iVar1 = CRYPTO_gcm128_encrypt_ctr32
                          (iVar1 + 0x100,param_3,param_2,param_4,*(int *)(iVar1 + 700));
      }
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      return param_4;
    }
    if (param_1->encrypt != 0) {
      CRYPTO_gcm128_tag(iVar1 + 0x100,param_1->buf,0x10);
      *(undefined4 *)(iVar1 + 0xfc) = 0;
      *(undefined4 *)(iVar1 + 0x2b0) = 0x10;
      return 0;
    }
    if (-1 < *(int *)(iVar1 + 0x2b0)) {
      iVar2 = CRYPTO_gcm128_finish(iVar1 + 0x100,param_1->buf);
      if (iVar2 == 0) {
        *(undefined4 *)(iVar1 + 0xfc) = 0;
        return 0;
      }
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  iVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
  if (param_2 != param_3 || param_4 < 0x18) {
    return 0xffffffff;
  }
  if (param_1->encrypt == 0) {
    iVar2 = 0x18;
  }
  else {
    iVar2 = 0x13;
  }
  iVar2 = EVP_CIPHER_CTX_ctrl(param_1,iVar2,8,param_2);
  if (0 < iVar2) {
    iVar4 = iVar1 + 0x100;
    a = param_1->buf;
    iVar2 = CRYPTO_gcm128_aad(iVar4,a,*(undefined4 *)(iVar1 + 0x2b8));
    if (iVar2 == 0) {
      iVar2 = (int)param_3 + 8;
      param_2 = (void *)((int)param_2 + 8);
      len = param_4 - 0x18;
      if (param_1->encrypt == 0) {
        if (*(int *)(iVar1 + 700) == 0) {
          iVar3 = CRYPTO_gcm128_decrypt(iVar4,iVar2,param_2,len);
        }
        else {
          iVar3 = CRYPTO_gcm128_decrypt_ctr32(iVar4,iVar2,param_2,len,*(int *)(iVar1 + 700));
        }
        if (iVar3 == 0) {
          CRYPTO_gcm128_tag(iVar4,a,0x10);
          iVar2 = CRYPTO_memcmp(a,(void *)(iVar2 + len),0x10);
          if (iVar2 == 0) goto LAB_00125e48;
          OPENSSL_cleanse(param_2,len);
        }
      }
      else {
        if (*(int *)(iVar1 + 700) == 0) {
          iVar2 = CRYPTO_gcm128_encrypt(iVar4,iVar2,param_2,len);
        }
        else {
          iVar2 = CRYPTO_gcm128_encrypt_ctr32(iVar4,iVar2,param_2,len,*(int *)(iVar1 + 700));
        }
        if (iVar2 == 0) {
          CRYPTO_gcm128_tag(iVar4,(int)param_2 + len,0x10);
          len = param_4;
          goto LAB_00125e48;
        }
      }
    }
  }
  len = 0xffffffff;
LAB_00125e48:
  *(undefined4 *)(iVar1 + 0xfc) = 0;
  *(undefined4 *)(iVar1 + 0x2b8) = 0xffffffff;
  return len;
}

