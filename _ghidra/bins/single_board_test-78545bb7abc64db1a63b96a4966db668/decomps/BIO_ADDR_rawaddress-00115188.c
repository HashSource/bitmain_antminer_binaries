
undefined4 BIO_ADDR_rawaddress(short *param_1,void *param_2,size_t *param_3)

{
  short sVar1;
  size_t __n;
  
  sVar1 = *param_1;
  if (sVar1 == 2) {
    param_1 = param_1 + 2;
    __n = 4;
  }
  else if (sVar1 == 10) {
    param_1 = param_1 + 4;
    __n = 0x10;
  }
  else {
    if (sVar1 != 1) {
      return 0;
    }
    param_1 = param_1 + 1;
    __n = strlen((char *)param_1);
  }
  if (param_2 != (void *)0x0) {
    memcpy(param_2,param_1,__n);
  }
  if (param_3 == (size_t *)0x0) {
    return 1;
  }
  *param_3 = __n;
  return 1;
}

