
undefined4 pkey_cb(int param_1,int *param_2)

{
  int *piVar1;
  size_t *psVar2;
  
  if ((((param_1 == 2) && (piVar1 = *(int **)(*param_2 + 0xc), piVar1 != (int *)0x0)) &&
      (*piVar1 == 4)) && (psVar2 = (size_t *)piVar1[1], psVar2 != (size_t *)0x0)) {
    OPENSSL_cleanse((void *)psVar2[2],*psVar2);
    return 1;
  }
  return 1;
}

