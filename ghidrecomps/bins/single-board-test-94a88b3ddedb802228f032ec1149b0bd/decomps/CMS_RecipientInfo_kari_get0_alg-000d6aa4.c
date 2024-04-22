
undefined4 CMS_RecipientInfo_kari_get0_alg(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (*param_1 == 1) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1[1] + 0xc);
    }
    if (param_3 == (undefined4 *)0x0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 1;
      *param_3 = *(undefined4 *)(param_1[1] + 8);
    }
  }
  else {
    ERR_put_error(0x2e,0xaf,0xb5,DAT_000d6adc,0x4f);
    uVar1 = 0;
  }
  return uVar1;
}

