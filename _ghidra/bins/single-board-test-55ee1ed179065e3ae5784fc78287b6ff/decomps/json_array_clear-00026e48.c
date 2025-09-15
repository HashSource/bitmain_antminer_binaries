
undefined4 json_array_clear(int *param_1)

{
  undefined4 uVar1;
  uint local_c;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 1)) {
    uVar1 = 0xffffffff;
  }
  else {
    for (local_c = 0; local_c < (uint)param_1[3]; local_c = local_c + 1) {
      json_decref(*(undefined4 *)(param_1[4] + local_c * 4));
    }
    param_1[3] = 0;
    uVar1 = 0;
  }
  return uVar1;
}

