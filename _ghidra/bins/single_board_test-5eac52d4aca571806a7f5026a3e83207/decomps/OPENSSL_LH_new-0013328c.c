
int * OPENSSL_LH_new(code *param_1,code *param_2,undefined4 param_3,undefined4 param_4)

{
  int *ptr;
  int iVar1;
  
  ptr = (int *)CRYPTO_zalloc(0x60,"crypto/lhash/lhash.c",0x33,param_4,param_4);
  if (ptr == (int *)0x0) {
    return (int *)0x0;
  }
  iVar1 = CRYPTO_zalloc(0x40,"crypto/lhash/lhash.c",0x3b);
  *ptr = iVar1;
  if (iVar1 != 0) {
    if (param_2 == (code *)0x0) {
      param_2 = strcmp;
    }
    ptr[1] = (int)param_2;
    if (param_1 == (code *)0x0) {
      param_1 = (code *)0x133249;
    }
    ptr[2] = (int)param_1;
    ptr[3] = 8;
    ptr[6] = 8;
    ptr[4] = 0x10;
    ptr[7] = 0x200;
    ptr[8] = 0x100;
    return ptr;
  }
  CRYPTO_free((void *)0x0);
  CRYPTO_free(ptr);
  return (int *)0x0;
}

