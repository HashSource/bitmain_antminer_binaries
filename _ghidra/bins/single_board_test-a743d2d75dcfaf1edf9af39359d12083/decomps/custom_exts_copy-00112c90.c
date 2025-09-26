
void * custom_exts_copy(undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
  pvVar1 = (void *)0x1;
  if (param_2[1] != 0) {
    pvVar1 = BUF_memdup((void *)*param_2,param_2[1] * 0x18);
    *param_1 = pvVar1;
    if (pvVar1 != (void *)0x0) {
      param_1[1] = param_2[1];
      return (void *)0x1;
    }
  }
  return pvVar1;
}

