
undefined4
_k_free_store(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char acStack_818 [2052];
  
  if (*(char *)(param_1 + 1) == '\0') {
    snprintf(acStack_818,0x800,"Store %s can\'t %s() the list - from %s %s() line %d in %s %s():%d",
             *param_1,DAT_00040afc,param_2,param_3,param_4,"klist.c",DAT_00040afc,0x1a8);
    _applog(3,acStack_818,1);
    _quit(1);
  }
  free(param_1);
  return 0;
}

