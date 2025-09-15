
undefined4 CMS_RecipientInfo_get0_pkey_ctx(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 0) {
    return *(undefined4 *)(param_1[1] + 0x18);
  }
  if (*param_1 == 1) {
    uVar1 = *(undefined4 *)(param_1[1] + 0x14);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

