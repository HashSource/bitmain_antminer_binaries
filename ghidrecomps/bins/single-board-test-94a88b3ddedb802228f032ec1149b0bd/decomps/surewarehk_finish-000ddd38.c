
undefined4 surewarehk_finish(void)

{
  BIO **ppBVar1;
  int iVar2;
  BIO *pBVar3;
  undefined4 uVar4;
  
  ppBVar1 = DAT_000dddbc;
  if (DAT_000dddbc[9] == (BIO *)0x0) {
    pBVar3 = DAT_000dddbc[1];
    if (pBVar3 == (BIO *)0x0) {
      pBVar3 = (BIO *)ERR_get_next_error_library();
      ppBVar1[1] = pBVar3;
    }
    uVar4 = 0;
    ERR_put_error((int)pBVar3,0x67,0x70,DAT_000dddc0,0x250);
  }
  else {
    uVar4 = 1;
    (*(code *)DAT_000dddbc[0xb])();
    iVar2 = DSO_free((DSO *)ppBVar1[9]);
    if (iVar2 == 0) {
      pBVar3 = ppBVar1[1];
      if (pBVar3 == (BIO *)0x0) {
        pBVar3 = (BIO *)ERR_get_next_error_library();
        ppBVar1[1] = pBVar3;
      }
      uVar4 = 0;
      ERR_put_error((int)pBVar3,0x67,0x68,DAT_000dddc0,0x256);
    }
  }
  if (*ppBVar1 != (BIO *)0x0) {
    BIO_free(*ppBVar1);
  }
  ppBVar1[9] = (BIO *)0x0;
  ppBVar1[10] = (BIO *)0x0;
  ppBVar1[0xb] = (BIO *)0x0;
  ppBVar1[0xc] = (BIO *)0x0;
  ppBVar1[3] = (BIO *)0x0;
  ppBVar1[8] = (BIO *)0x0;
  ppBVar1[5] = (BIO *)0x0;
  ppBVar1[2] = (BIO *)0x0;
  ppBVar1[0xd] = (BIO *)0x0;
  ppBVar1[0xe] = (BIO *)0x0;
  ppBVar1[0xf] = (BIO *)0x0;
  ppBVar1[7] = (BIO *)0x0;
  ppBVar1[6] = (BIO *)0x0;
  ppBVar1[4] = (BIO *)0x0;
  return uVar4;
}

