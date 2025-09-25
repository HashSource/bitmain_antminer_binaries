
BIO * cms_cb(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4)

{
  BIO *pBVar1;
  int iVar2;
  CMS_ContentInfo *cms;
  
  if (param_2 == (undefined4 *)0x0) {
    return (BIO *)0x1;
  }
  cms = (CMS_ContentInfo *)*param_2;
  switch(param_1) {
  case 10:
    iVar2 = CMS_stream((uchar ***)(param_4 + 2),cms);
    if (iVar2 < 1) {
      return (BIO *)0x0;
    }
switchD_0018b32e_caseD_c:
    pBVar1 = CMS_dataInit(cms,(BIO *)*param_4);
    param_4[1] = pBVar1;
    if (pBVar1 != (BIO *)0x0) {
      pBVar1 = (BIO *)0x1;
    }
    return pBVar1;
  case 0xb:
  case 0xd:
    iVar2 = CMS_dataFinal(cms,(BIO *)param_4[1]);
    return (BIO *)(uint)(0 < iVar2);
  case 0xc:
    goto switchD_0018b32e_caseD_c;
  default:
    return (BIO *)0x1;
  }
}

