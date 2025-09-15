
undefined4 by_dir_hash_cmp(undefined4 *param_1,undefined4 *param_2)

{
  if (*(uint *)*param_2 < *(uint *)*param_1) {
    return 1;
  }
  if (*(uint *)*param_2 <= *(uint *)*param_1) {
    return 0;
  }
  return 0xffffffff;
}

