
undefined4 CMS_RecipientInfo_kari_get0_ctx(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == 1) {
    uVar1 = *(undefined4 *)(param_1[1] + 0x18);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

