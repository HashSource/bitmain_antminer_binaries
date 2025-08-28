
void _mutex_init_part_3_constprop_28(undefined4 param_1)

{
  int *piVar1;
  char acStack_810 [2052];
  
  piVar1 = __errno_location();
  snprintf(acStack_810,0x800,"Failed to pthread_mutex_init errno=%d in %s %s():%d",*piVar1,
           "driver-btm-c5.c","bitmain_c5_prepare",param_1);
  _applog(3,acStack_810,1);
  _quit(1);
  return;
}

