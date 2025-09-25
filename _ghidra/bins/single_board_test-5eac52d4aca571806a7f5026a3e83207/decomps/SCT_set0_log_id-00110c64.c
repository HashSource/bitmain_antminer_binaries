
undefined4 SCT_set0_log_id(int *param_1,int param_2,int param_3)

{
  if (param_3 == 0x20 || *param_1 != 0) {
    CRYPTO_free((void *)param_1[3]);
    param_1[3] = param_2;
    param_1[4] = param_3;
    param_1[0xf] = 0;
    return 1;
  }
  ERR_put_error(0x32,0x65,100,"crypto/ct/ct_sct.c",0x53);
  return 0;
}

