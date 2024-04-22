
void * _cgmalloc(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  char acStack_818 [2048];
  
  if ((param_1 & 3) != 0) {
    param_1 = (param_1 & 0xfffffffc) + 4;
  }
  pvVar1 = malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    snprintf(acStack_818,0x800,"Failed to malloc size %d from %s %s:%d",param_1,param_2,param_3,
             param_4);
    _applog(3,acStack_818,1);
    _quit(1);
    return (void *)0x0;
  }
  return pvVar1;
}

