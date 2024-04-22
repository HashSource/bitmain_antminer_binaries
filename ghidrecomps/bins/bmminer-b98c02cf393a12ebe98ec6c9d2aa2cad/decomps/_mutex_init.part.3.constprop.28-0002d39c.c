
void _mutex_init_part_3_constprop_28(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  char acStack_810 [2052];
  
  uVar1 = DAT_0002d3e4;
  piVar2 = __errno_location();
  snprintf(acStack_810,0x800,"Failed to pthread_mutex_init errno=%d in %s %s():%d",*piVar2,
           "driver-btm-c5.c",uVar1,param_1);
  _applog(3,acStack_810,1);
  _quit(1);
  return;
}

