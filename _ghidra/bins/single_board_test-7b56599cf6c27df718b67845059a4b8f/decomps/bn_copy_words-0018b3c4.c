
undefined4 bn_copy_words(void *param_1,undefined4 *param_2,int param_3)

{
  if (param_3 < (int)param_2[1]) {
    return 0;
  }
  memset(param_1,0,param_3 << 2);
  if ((void *)*param_2 != (void *)0x0) {
    memcpy(param_1,(void *)*param_2,param_2[1] << 2);
    return 1;
  }
  return 1;
}

