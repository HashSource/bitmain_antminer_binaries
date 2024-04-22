
undefined4 CMS_RecipientInfo_kari_orig_id_cmp(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (*param_1 == 1) {
    piVar2 = *(int **)(param_1[1] + 4);
    if (*piVar2 == 0) {
      uVar1 = cms_ias_cert_cmp(piVar2[1]);
      return uVar1;
    }
    if (*piVar2 == 1) {
      uVar1 = cms_keyid_cert_cmp(piVar2[1]);
      return uVar1;
    }
    uVar1 = 0xffffffff;
  }
  else {
    ERR_put_error(0x2e,0xae,0xb5,DAT_000d6be8,0x95);
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}

