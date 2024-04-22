
undefined4 CMS_RecipientInfo_kari_get0_reks(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 1) {
    uVar1 = *(undefined4 *)(param_1[1] + 0x10);
  }
  else {
    ERR_put_error(0x2e,0xac,0xb5,DAT_000d6b08,0x60);
    uVar1 = 0;
  }
  return uVar1;
}

