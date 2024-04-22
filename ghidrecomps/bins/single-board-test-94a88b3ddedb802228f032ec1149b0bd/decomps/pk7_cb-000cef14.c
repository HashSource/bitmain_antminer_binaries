
BIO * pk7_cb(undefined4 param_1,PKCS7 **param_2,undefined4 param_3,BIO **param_4)

{
  BIO *pBVar1;
  int iVar2;
  
  switch(param_1) {
  case 10:
    iVar2 = PKCS7_stream((uchar ***)(param_4 + 2),*param_2);
    if (iVar2 < 1) {
      return (BIO *)0x0;
    }
switchD_000cef20_caseD_c:
    pBVar1 = PKCS7_dataInit(*param_2,*param_4);
    param_4[1] = pBVar1;
    if (pBVar1 != (BIO *)0x0) {
      pBVar1 = (BIO *)0x1;
    }
    return pBVar1;
  case 0xb:
  case 0xd:
    iVar2 = PKCS7_dataFinal(*param_2,param_4[1]);
    return (BIO *)(uint)(0 < iVar2);
  case 0xc:
    goto switchD_000cef20_caseD_c;
  default:
    return (BIO *)0x1;
  }
}

