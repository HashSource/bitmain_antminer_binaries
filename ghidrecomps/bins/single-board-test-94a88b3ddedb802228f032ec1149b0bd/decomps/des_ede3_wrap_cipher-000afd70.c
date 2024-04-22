
size_t des_ede3_wrap_cipher(int param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  size_t sVar4;
  uchar *out;
  undefined4 *__dest;
  uchar auStack_4c [8];
  uchar auStack_44 [8];
  undefined4 local_3c;
  undefined4 uStack_38;
  
  if ((param_4 < 0x40000000) && ((param_4 & 7) == 0)) {
    if (*(int *)(param_1 + 8) == 0) {
      if (0x17 < param_4) {
        if (param_2 == (undefined4 *)0x0) {
          return param_4 - 0x10;
        }
        out = (uchar *)(param_1 + 0x20);
        uVar3 = DAT_000aff30[1];
        *(undefined4 *)(param_1 + 0x20) = *DAT_000aff30;
        *(undefined4 *)(param_1 + 0x24) = uVar3;
        des_ede_cbc_cipher(param_1,auStack_4c,param_3,8);
        if (param_2 == param_3) {
          param_3 = param_2 + -2;
          memmove(param_2,param_2 + 2,param_4 - 8);
        }
        sVar4 = param_4 - 0x10;
        des_ede_cbc_cipher(param_1,param_2,param_3 + 2,sVar4);
        des_ede_cbc_cipher(param_1,auStack_44,(int)param_3 + (param_4 - 8),8);
        BUF_reverse(auStack_4c,(uchar *)0x0,8);
        BUF_reverse((uchar *)param_2,(uchar *)0x0,sVar4);
        BUF_reverse(out,auStack_44,8);
        des_ede_cbc_cipher(param_1,param_2,param_2,sVar4);
        des_ede_cbc_cipher(param_1,auStack_4c,auStack_4c,8);
        SHA1((uchar *)param_2,sVar4,(uchar *)&local_3c);
        iVar2 = CRYPTO_memcmp(&local_3c,auStack_4c,8);
        if (iVar2 == 0) {
          OPENSSL_cleanse(auStack_4c,8);
          OPENSSL_cleanse(&local_3c,0x14);
          OPENSSL_cleanse(auStack_44,8);
          OPENSSL_cleanse(out,8);
          return sVar4;
        }
        OPENSSL_cleanse(auStack_4c,8);
        OPENSSL_cleanse(&local_3c,0x14);
        OPENSSL_cleanse(auStack_44,8);
        OPENSSL_cleanse(out,8);
        OPENSSL_cleanse(param_2,sVar4);
        return 0xffffffff;
      }
    }
    else {
      if (param_2 == (undefined4 *)0x0) {
        return param_4 + 0x10;
      }
      __dest = param_2 + 2;
      memmove(__dest,param_3,param_4);
      SHA1((uchar *)param_3,param_4,(uchar *)&local_3c);
      *(undefined4 *)((int)param_2 + param_4 + 8) = local_3c;
      *(undefined4 *)((int)param_2 + param_4 + 0xc) = uStack_38;
      OPENSSL_cleanse(&local_3c,0x14);
      iVar2 = RAND_bytes((uchar *)(param_1 + 0x20),8);
      puVar1 = DAT_000aff30;
      if (0 < iVar2) {
        uVar3 = *(undefined4 *)(param_1 + 0x24);
        sVar4 = param_4 + 0x10;
        *param_2 = *(undefined4 *)(param_1 + 0x20);
        param_2[1] = uVar3;
        des_ede_cbc_cipher(param_1,__dest,__dest,param_4 + 8);
        BUF_reverse((uchar *)param_2,(uchar *)0x0,sVar4);
        uVar3 = puVar1[1];
        *(undefined4 *)(param_1 + 0x20) = *puVar1;
        *(undefined4 *)(param_1 + 0x24) = uVar3;
        des_ede_cbc_cipher(param_1,param_2,param_2,sVar4);
        return sVar4;
      }
    }
  }
  return 0xffffffff;
}

