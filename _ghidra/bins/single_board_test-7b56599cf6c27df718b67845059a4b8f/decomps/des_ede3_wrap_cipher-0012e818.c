
size_t des_ede3_wrap_cipher(undefined4 param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uchar *puVar3;
  void *pvVar4;
  size_t sVar5;
  uchar *__dest;
  undefined4 uVar6;
  uchar auStack_44 [8];
  uchar auStack_3c [8];
  undefined4 local_34;
  undefined4 uStack_30;
  
  if (0x3fffffff < param_4) {
    return 0xffffffff;
  }
  if ((param_4 & 7) == 0) {
    iVar1 = is_partially_overlapping(param_2,param_3,param_4);
    if (iVar1 != 0) {
      ERR_put_error(6,0xab,0xa2,"crypto/evp/e_des3.c",0x18e);
      return 0;
    }
    iVar1 = EVP_CIPHER_CTX_encrypting(param_1);
    if (iVar1 == 0) {
      if (0x17 < param_4) {
        if (param_2 != (uchar *)0x0) {
          puVar2 = (undefined4 *)EVP_CIPHER_CTX_iv_noconst(param_1);
          *puVar2 = 0x2ca2dd4a;
          puVar2[1] = 0x521e879;
          des_ede_cbc_cipher_constprop_4(param_1,auStack_44,param_3,"crypto/evp/e_des3.c");
          if (param_2 == param_3) {
            param_3 = param_2 + -8;
            memmove(param_2,param_2 + 8,param_4 - 8);
          }
          sVar5 = param_4 - 0x10;
          des_ede_cbc_cipher(param_1,param_2,param_3 + 8,sVar5);
          des_ede_cbc_cipher_constprop_4(param_1,auStack_3c,param_3 + (param_4 - 8));
          BUF_reverse(auStack_44,(uchar *)0x0,8);
          BUF_reverse(param_2,(uchar *)0x0,sVar5);
          puVar3 = (uchar *)EVP_CIPHER_CTX_iv_noconst(param_1);
          BUF_reverse(puVar3,auStack_3c,8);
          des_ede_cbc_cipher(param_1,param_2,param_2,sVar5);
          des_ede_cbc_cipher_constprop_4(param_1,auStack_44,auStack_44);
          SHA1(param_2,sVar5,(uchar *)&local_34);
          iVar1 = CRYPTO_memcmp(&local_34,auStack_44,8);
          if (iVar1 != 0) {
            OPENSSL_cleanse(auStack_44,8);
            OPENSSL_cleanse(&local_34,0x14);
            OPENSSL_cleanse(auStack_3c,8);
            pvVar4 = (void *)EVP_CIPHER_CTX_iv_noconst(param_1);
            OPENSSL_cleanse(pvVar4,8);
            OPENSSL_cleanse(param_2,sVar5);
            return 0xffffffff;
          }
          OPENSSL_cleanse(auStack_44,8);
          OPENSSL_cleanse(&local_34,0x14);
          OPENSSL_cleanse(auStack_3c,8);
          pvVar4 = (void *)EVP_CIPHER_CTX_iv_noconst(param_1);
          OPENSSL_cleanse(pvVar4,8);
        }
        return param_4 - 0x10;
      }
    }
    else {
      if (param_2 == (uchar *)0x0) {
        return param_4 + 0x10;
      }
      __dest = param_2 + 8;
      memmove(__dest,param_3,param_4);
      SHA1(param_3,param_4,(uchar *)&local_34);
      *(undefined4 *)(param_2 + param_4 + 8) = local_34;
      *(undefined4 *)(param_2 + param_4 + 0xc) = uStack_30;
      OPENSSL_cleanse(&local_34,0x14);
      puVar3 = (uchar *)EVP_CIPHER_CTX_iv_noconst(param_1);
      iVar1 = RAND_bytes(puVar3,8);
      if (0 < iVar1) {
        sVar5 = param_4 + 0x10;
        puVar2 = (undefined4 *)EVP_CIPHER_CTX_iv_noconst(param_1);
        uVar6 = *puVar2;
        *(undefined4 *)(param_2 + 4) = puVar2[1];
        *(undefined4 *)param_2 = uVar6;
        des_ede_cbc_cipher(param_1,__dest,__dest,param_4 + 8);
        BUF_reverse(param_2,(uchar *)0x0,sVar5);
        puVar2 = (undefined4 *)EVP_CIPHER_CTX_iv_noconst(param_1);
        *puVar2 = 0x2ca2dd4a;
        puVar2[1] = 0x521e879;
        des_ede_cbc_cipher(param_1,param_2,param_2,sVar5);
        return sVar5;
      }
    }
  }
  return 0xffffffff;
}

