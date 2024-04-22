
undefined4 surewarehk_ctrl(undefined4 param_1,int param_2,undefined4 param_3,BIO *param_4)

{
  BIO **ppBVar1;
  BIO **ppBVar2;
  char *file;
  BIO *pBVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = DAT_000ddb3c;
  ppBVar1 = DAT_000ddb34;
  if (param_2 == 1) {
    CRYPTO_lock(9,0x1e,DAT_000ddb38,0x19a);
    if (*ppBVar1 != (BIO *)0x0) {
      BIO_free(*ppBVar1);
      *ppBVar1 = (BIO *)0x0;
    }
    iVar5 = CRYPTO_add_lock(&param_4->references,1,0x15,DAT_000ddb38,0x19f);
    ppBVar2 = DAT_000ddb34;
    if (iVar5 < 2) {
      pBVar3 = ppBVar1[1];
      if (pBVar3 == (BIO *)0x0) {
        pBVar3 = (BIO *)ERR_get_next_error_library();
        ppBVar2[1] = pBVar3;
      }
      ERR_put_error((int)pBVar3,100,100,DAT_000ddb38,0x1a3);
    }
    else {
      *ppBVar1 = param_4;
    }
    CRYPTO_lock(10,0x1e,DAT_000ddb38,0x1a5);
    uVar4 = 1;
  }
  else if (param_2 == 0x65) {
    CRYPTO_lock(9,0x1e,DAT_000ddb38,0x1af);
    file = DAT_000ddb38;
    *(undefined4 *)(iVar5 + 0xdc) = 0;
    CRYPTO_lock(10,0x1e,file,0x1b1);
    uVar4 = 1;
  }
  else {
    pBVar3 = DAT_000ddb34[1];
    if (pBVar3 == (BIO *)0x0) {
      pBVar3 = (BIO *)ERR_get_next_error_library();
      ppBVar1[1] = pBVar3;
    }
    ERR_put_error((int)pBVar3,100,0x77,DAT_000ddb38,0x1b7);
    uVar4 = 0;
  }
  return uVar4;
}

