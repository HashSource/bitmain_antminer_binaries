
undefined4 err_string_data_cmp(uint *param_1,uint *param_2)

{
  if (*param_1 == *param_2) {
    return 0;
  }
  if (*param_2 < *param_1) {
    return 1;
  }
  return 0xffffffff;
}

