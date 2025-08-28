
size_t i2d_ocsp_nonce(size_t *param_1,int *param_2)

{
  size_t sVar1;
  
  if (param_2 != (int *)0x0) {
    memcpy((void *)*param_2,(void *)param_1[2],*param_1);
    sVar1 = *param_1;
    *param_2 = *param_2 + sVar1;
    return sVar1;
  }
  return *param_1;
}

