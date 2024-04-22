
void * custom_exts_copy(void **param_1,void **param_2)

{
  void *pvVar1;
  
  pvVar1 = (void *)0x1;
  if (param_2[1] != (void *)0x0) {
    pvVar1 = BUF_memdup(*param_2,(int)param_2[1] * 0x18);
    *param_1 = pvVar1;
    if (pvVar1 != (void *)0x0) {
      param_1[1] = param_2[1];
      return (void *)0x1;
    }
  }
  return pvVar1;
}

