
undefined4 cms_set1_SignerIdentifier(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    iVar1 = cms_set1_ias(param_1 + 1);
  }
  else {
    if (param_3 != 1) {
      ERR_put_error(0x2e,0x92,0x96,"crypto/cms/cms_sd.c",0xba);
      return 0;
    }
    iVar1 = cms_set1_keyid(param_1 + 1);
  }
  if (iVar1 == 0) {
    return 0;
  }
  *param_1 = param_3;
  return 1;
}

