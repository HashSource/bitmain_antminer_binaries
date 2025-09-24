
undefined4
cms_SignerIdentifier_get0_signer_id
          (int *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  if (*param_1 == 0) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)param_1[1];
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)(param_1[1] + 4);
      return 1;
    }
  }
  else {
    if (*param_1 != 1) {
      return 0;
    }
    if (param_2 != (int *)0x0) {
      *param_2 = param_1[1];
      return 1;
    }
  }
  return 1;
}

