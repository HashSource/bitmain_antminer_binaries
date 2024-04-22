
undefined4 by_dir_hash_cmp(uint **param_1,uint **param_2)

{
  if (**param_2 < **param_1) {
    return 1;
  }
  if (**param_2 <= **param_1) {
    return 0;
  }
  return 0xffffffff;
}

