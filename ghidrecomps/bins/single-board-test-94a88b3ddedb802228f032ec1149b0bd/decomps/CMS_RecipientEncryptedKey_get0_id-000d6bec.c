
undefined4
CMS_RecipientEncryptedKey_get0_id
          (int **param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
          undefined4 *param_5,undefined4 *param_6)

{
  int *piVar1;
  
  piVar1 = *param_1;
  if (*piVar1 == 0) {
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = *(undefined4 *)piVar1[1];
    }
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = *(undefined4 *)(piVar1[1] + 4);
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0;
      return 1;
    }
  }
  else {
    if (*piVar1 != 1) {
      return 0;
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)piVar1[1];
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(piVar1[1] + 4);
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)(piVar1[1] + 8);
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0;
    }
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = 0;
      return 1;
    }
  }
  return 1;
}

