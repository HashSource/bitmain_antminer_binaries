
undefined4 cms_set1_SignerIdentifier(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    iVar1 = cms_set1_ias(param_1 + 1);
    if (iVar1 != 0) {
      *param_1 = 0;
      return 1;
    }
  }
  else if (param_3 == 1) {
    iVar1 = cms_set1_keyid(param_1 + 1);
    if (iVar1 != 0) {
      *param_1 = 1;
      return 1;
    }
  }
  else {
    ERR_put_error(0x2e,0x92,0x96,DAT_0011031c,0xd3);
  }
  return 0;
}

