
uint aes_gcm_cipher(EVP_CIPHER_CTX *param_1,void *param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  uchar *a;
  
  pvVar3 = param_1->cipher_data;
  if (*(int *)((int)pvVar3 + 0xf8) == 0) {
    return 0xffffffff;
  }
  if (*(int *)((int)pvVar3 + 0x288) < 0) {
    if (*(int *)((int)pvVar3 + 0xfc) == 0) {
      return 0xffffffff;
    }
    if (param_3 != 0) {
      if (param_2 == (void *)0x0) {
        iVar1 = CRYPTO_gcm128_aad((int)pvVar3 + 0x100,param_3,param_4);
      }
      else if (param_1->encrypt == 0) {
        if (*(int *)((int)pvVar3 + 0x28c) == 0) {
          iVar1 = CRYPTO_gcm128_decrypt((int)pvVar3 + 0x100,param_3,param_2);
        }
        else {
          iVar1 = CRYPTO_gcm128_decrypt_ctr32
                            ((int)pvVar3 + 0x100,param_3,param_2,param_4,
                             *(int *)((int)pvVar3 + 0x28c));
        }
      }
      else if (*(int *)((int)pvVar3 + 0x28c) == 0) {
        iVar1 = CRYPTO_gcm128_encrypt((int)pvVar3 + 0x100,param_3,param_2);
      }
      else {
        iVar1 = CRYPTO_gcm128_encrypt_ctr32
                          ((int)pvVar3 + 0x100,param_3,param_2,param_4,*(int *)((int)pvVar3 + 0x28c)
                          );
      }
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      return param_4;
    }
    if (param_1->encrypt != 0) {
      CRYPTO_gcm128_tag((int)pvVar3 + 0x100,param_1->buf,0x10);
      *(undefined4 *)((int)pvVar3 + 0xfc) = 0;
      *(undefined4 *)((int)pvVar3 + 0x280) = 0x10;
      return 0;
    }
    if (*(int *)((int)pvVar3 + 0x280) < 0) {
      return 0xffffffff;
    }
    iVar1 = CRYPTO_gcm128_finish((int)pvVar3 + 0x100,param_1->buf);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    *(undefined4 *)((int)pvVar3 + 0xfc) = 0;
    return 0;
  }
  uVar2 = (int)param_2 - param_3;
  if (uVar2 != 0) {
    uVar2 = 1;
  }
  if (param_4 < 0x18) {
    uVar2 = uVar2 | 1;
  }
  if (uVar2 != 0) {
    return 0xffffffff;
  }
  if (param_1->encrypt == 0) {
    iVar1 = 0x18;
  }
  else {
    iVar1 = 0x13;
  }
  iVar1 = EVP_CIPHER_CTX_ctrl(param_1,iVar1,8,param_2);
  if (0 < iVar1) {
    iVar4 = (int)pvVar3 + 0x100;
    a = param_1->buf;
    iVar1 = CRYPTO_gcm128_aad(iVar4,a,*(undefined4 *)((int)pvVar3 + 0x288));
    if (iVar1 == 0) {
      param_3 = param_3 + 8;
      param_2 = (void *)((int)param_2 + 8);
      uVar2 = param_4 - 0x18;
      if (param_1->encrypt == 0) {
        if (*(int *)((int)pvVar3 + 0x28c) == 0) {
          iVar1 = CRYPTO_gcm128_decrypt(iVar4,param_3,param_2,uVar2);
        }
        else {
          iVar1 = CRYPTO_gcm128_decrypt_ctr32
                            (iVar4,param_3,param_2,uVar2,*(int *)((int)pvVar3 + 0x28c));
        }
        if (iVar1 == 0) {
          CRYPTO_gcm128_tag(iVar4,a,0x10);
          iVar1 = CRYPTO_memcmp(a,(void *)(param_3 + uVar2),0x10);
          if (iVar1 == 0) goto LAB_000b0efa;
          OPENSSL_cleanse(param_2,uVar2);
        }
      }
      else {
        if (*(int *)((int)pvVar3 + 0x28c) == 0) {
          iVar1 = CRYPTO_gcm128_encrypt(iVar4,param_3,param_2,uVar2);
        }
        else {
          iVar1 = CRYPTO_gcm128_encrypt_ctr32
                            (iVar4,param_3,param_2,uVar2,*(int *)((int)pvVar3 + 0x28c));
        }
        if (iVar1 == 0) {
          CRYPTO_gcm128_tag(iVar4,(int)param_2 + uVar2,0x10);
          uVar2 = param_4;
          goto LAB_000b0efa;
        }
      }
    }
  }
  uVar2 = 0xffffffff;
LAB_000b0efa:
  *(undefined4 *)((int)pvVar3 + 0xfc) = 0;
  *(undefined4 *)((int)pvVar3 + 0x288) = 0xffffffff;
  return uVar2;
}

