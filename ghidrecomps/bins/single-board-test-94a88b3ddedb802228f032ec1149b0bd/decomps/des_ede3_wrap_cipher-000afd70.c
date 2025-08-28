
size_t des_ede3_wrap_cipher(int param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  uchar *puVar4;
  uchar auStack_4c [8];
  uchar auStack_44 [8];
  undefined4 local_3c;
  undefined4 uStack_38;
  
  if ((param_4 < 0x40000000) && ((param_4 & 7) == 0)) {
    if (*(int *)(param_1 + 8) == 0) {
      if (0x17 < param_4) {
        if (param_2 == (uchar *)0x0) {
          return param_4 - 0x10;
        }
        puVar4 = (uchar *)(param_1 + 0x20);
        *(undefined4 *)(param_1 + 0x20) = 0x2ca2dd4a;
        *(undefined4 *)(param_1 + 0x24) = 0x521e879;
        des_ede_cbc_cipher(param_1,auStack_4c,param_3,8);
        if (param_2 == param_3) {
          param_3 = param_2 + -8;
          memmove(param_2,param_2 + 8,param_4 - 8);
        }
        sVar2 = param_4 - 0x10;
        des_ede_cbc_cipher(param_1,param_2,param_3 + 8,sVar2);
        des_ede_cbc_cipher(param_1,auStack_44,param_3 + (param_4 - 8),8);
        BUF_reverse(auStack_4c,(uchar *)0x0,8);
        BUF_reverse(param_2,(uchar *)0x0,sVar2);
        BUF_reverse(puVar4,auStack_44,8);
        des_ede_cbc_cipher(param_1,param_2,param_2,sVar2);
        des_ede_cbc_cipher(param_1,auStack_4c,auStack_4c,8);
        SHA1(param_2,sVar2,(uchar *)&local_3c);
        iVar1 = CRYPTO_memcmp(&local_3c,auStack_4c,8);
        if (iVar1 == 0) {
          OPENSSL_cleanse(auStack_4c,8);
          OPENSSL_cleanse(&local_3c,0x14);
          OPENSSL_cleanse(auStack_44,8);
          OPENSSL_cleanse(puVar4,8);
          return sVar2;
        }
        OPENSSL_cleanse(auStack_4c,8);
        OPENSSL_cleanse(&local_3c,0x14);
        OPENSSL_cleanse(auStack_44,8);
        OPENSSL_cleanse(puVar4,8);
        OPENSSL_cleanse(param_2,sVar2);
        return 0xffffffff;
      }
    }
    else {
      if (param_2 == (uchar *)0x0) {
        return param_4 + 0x10;
      }
      puVar4 = param_2 + 8;
      memmove(puVar4,param_3,param_4);
      SHA1(param_3,param_4,(uchar *)&local_3c);
      *(undefined4 *)(param_2 + param_4 + 8) = local_3c;
      *(undefined4 *)(param_2 + param_4 + 0xc) = uStack_38;
      OPENSSL_cleanse(&local_3c,0x14);
      iVar1 = RAND_bytes((uchar *)(param_1 + 0x20),8);
      if (0 < iVar1) {
        uVar3 = *(undefined4 *)(param_1 + 0x24);
        sVar2 = param_4 + 0x10;
        *(undefined4 *)param_2 = *(undefined4 *)(param_1 + 0x20);
        *(undefined4 *)(param_2 + 4) = uVar3;
        des_ede_cbc_cipher(param_1,puVar4,puVar4,param_4 + 8);
        BUF_reverse(param_2,(uchar *)0x0,sVar2);
        *(undefined4 *)(param_1 + 0x20) = 0x2ca2dd4a;
        *(undefined4 *)(param_1 + 0x24) = 0x521e879;
        des_ede_cbc_cipher(param_1,param_2,param_2,sVar2);
        return sVar2;
      }
    }
  }
  return 0xffffffff;
}

