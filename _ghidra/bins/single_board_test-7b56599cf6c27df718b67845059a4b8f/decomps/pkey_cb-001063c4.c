
undefined4 pkey_cb(int param_1,int *param_2)

{
  size_t *psVar1;
  
  if (param_1 != 2) {
    return 1;
  }
  psVar1 = *(size_t **)(*param_2 + 8);
  if (psVar1 != (size_t *)0x0) {
    OPENSSL_cleanse((void *)psVar1[2],*psVar1);
  }
  return 1;
}

