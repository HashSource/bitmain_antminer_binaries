
undefined4 SCT_set_version(undefined4 *param_1,int param_2)

{
  if (param_2 == 0) {
    *param_1 = 0;
    param_1[0xf] = 0;
    return 1;
  }
  ERR_put_error(0x32,0x68,0x67,"crypto/ct/ct_sct.c",0x38);
  return 0;
}

