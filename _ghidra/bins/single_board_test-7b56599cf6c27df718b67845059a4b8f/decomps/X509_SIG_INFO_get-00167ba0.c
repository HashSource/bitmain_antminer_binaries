
uint X509_SIG_INFO_get(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,
                      undefined4 *param_4,undefined4 *param_5)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *param_1;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = param_1[1];
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = param_1[2];
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = param_1[3];
  }
  return param_1[3] & 1;
}

