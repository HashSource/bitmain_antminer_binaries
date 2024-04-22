
undefined4 cms_RecipientInfo_kekri_encrypt(int param_1,int param_2)

{
  int iVar1;
  uchar *out;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  AES_KEY AStack_10c;
  
  iVar2 = *(int *)(param_2 + 4);
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  if (*(uchar **)(iVar2 + 0x10) == (uchar *)0x0) {
    ERR_put_error(0x2e,0x88,0x82,DAT_000d544c,0x2b6);
    uVar3 = 0;
  }
  else {
    iVar1 = AES_set_encrypt_key(*(uchar **)(iVar2 + 0x10),*(int *)(iVar2 + 0x14) << 3,&AStack_10c);
    if (iVar1 == 0) {
      out = (uchar *)CRYPTO_malloc(*(int *)(iVar4 + 0x14) + 8,DAT_000d544c,0x2c0);
      if (out == (uchar *)0x0) {
        ERR_put_error(0x2e,0x88,0x41,DAT_000d544c,0x2c3);
        uVar3 = 0;
      }
      else {
        iVar4 = AES_wrap_key(&AStack_10c,(uchar *)0x0,out,*(uchar **)(iVar4 + 0x10),
                             *(uint *)(iVar4 + 0x14));
        if (iVar4 < 1) {
          ERR_put_error(0x2e,0x88,0x9f,DAT_000d544c,0x2ca);
          CRYPTO_free(out);
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
          ASN1_STRING_set0(*(ASN1_STRING **)(iVar2 + 0xc),out,iVar4);
        }
      }
    }
    else {
      ERR_put_error(0x2e,0x88,0x73,DAT_000d544c,700);
      uVar3 = 0;
    }
    OPENSSL_cleanse(&AStack_10c,0xf4);
  }
  return uVar3;
}

