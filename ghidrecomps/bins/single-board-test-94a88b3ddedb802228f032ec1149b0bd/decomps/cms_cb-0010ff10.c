
BIO * cms_cb(undefined4 param_1,CMS_ContentInfo **param_2,undefined4 param_3,BIO **param_4)

{
  BIO *pBVar1;
  int iVar2;
  CMS_ContentInfo *cms;
  
  if (param_2 != (CMS_ContentInfo **)0x0) {
    cms = *param_2;
    switch(param_1) {
    case 10:
      iVar2 = CMS_stream((uchar ***)(param_4 + 2),cms);
      if (iVar2 < 1) {
        return (BIO *)0x0;
      }
    case 0xc:
      pBVar1 = CMS_dataInit(cms,*param_4);
      param_4[1] = pBVar1;
      if (pBVar1 != (BIO *)0x0) {
        pBVar1 = (BIO *)0x1;
      }
      return pBVar1;
    case 0xb:
    case 0xd:
      iVar2 = CMS_dataFinal(cms,param_4[1]);
      return (BIO *)(uint)(0 < iVar2);
    }
  }
  return (BIO *)0x1;
}

