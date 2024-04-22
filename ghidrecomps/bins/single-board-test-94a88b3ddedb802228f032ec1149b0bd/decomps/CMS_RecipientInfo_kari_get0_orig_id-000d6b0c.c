
undefined4
CMS_RecipientInfo_kari_get0_orig_id
          (int *param_1,undefined4 *param_2,undefined4 *param_3,int *param_4,undefined4 *param_5,
          undefined4 *param_6)

{
  int iVar1;
  int *piVar2;
  
  if (*param_1 != 1) {
    ERR_put_error(0x2e,0xad,0xb5,DAT_000d6b98,0x70);
    return 0;
  }
  piVar2 = *(int **)(param_1[1] + 4);
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  iVar1 = *piVar2;
  if (iVar1 == 0) {
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = *(undefined4 *)piVar2[1];
    }
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = *(undefined4 *)(piVar2[1] + 4);
      return 1;
    }
  }
  else if (iVar1 == 1) {
    if (param_4 != (int *)0x0) {
      *param_4 = piVar2[1];
      return 1;
    }
  }
  else {
    if (iVar1 != 2) {
      return 0;
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)piVar2[1];
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(piVar2[1] + 4);
      return 1;
    }
  }
  return 1;
}

