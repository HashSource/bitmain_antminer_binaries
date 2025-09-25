
undefined4 OCSP_resp_get0_id(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (*(int *)(param_1 + 4) == 0) {
    *param_3 = *(undefined4 *)(param_1 + 8);
    *param_2 = 0;
    return 1;
  }
  if (*(int *)(param_1 + 4) == 1) {
    *param_2 = *(undefined4 *)(param_1 + 8);
    *param_3 = 0;
    return 1;
  }
  return 0;
}

