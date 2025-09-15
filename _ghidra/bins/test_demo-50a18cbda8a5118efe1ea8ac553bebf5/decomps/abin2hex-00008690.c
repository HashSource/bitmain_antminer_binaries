
void * abin2hex(undefined4 param_1,int param_2)

{
  void *pvVar1;
  
  pvVar1 = malloc(param_2 * 2 + 1);
  if (pvVar1 != (void *)0x0) {
    bin2hex(pvVar1,param_1,param_2);
  }
  return pvVar1;
}

