
undefined4 CMS_RecipientEncryptedKey_cert_cmp(int **param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = *param_1;
  if (*piVar2 == 0) {
    uVar1 = cms_ias_cert_cmp(piVar2[1]);
    return uVar1;
  }
  if (*piVar2 == 1) {
    uVar1 = cms_keyid_cert_cmp(*(undefined4 *)piVar2[1]);
    return uVar1;
  }
  return 0xffffffff;
}

