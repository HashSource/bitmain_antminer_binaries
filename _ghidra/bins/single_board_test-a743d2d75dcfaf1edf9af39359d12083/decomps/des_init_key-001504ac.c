
undefined4 des_init_key(int param_1,const_DES_cblock *param_2)

{
  *(undefined4 *)(*(int *)(param_1 + 0x60) + 0x80) = 0;
  DES_set_key_unchecked(param_2,*(DES_key_schedule **)(param_1 + 0x60));
  return 1;
}

