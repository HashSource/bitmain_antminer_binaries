
void _free_work_part_36(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char acStack_808 [2056];
  
  snprintf(acStack_808,0x800,"Free work called with NULL work from %s %s:%d",param_1,param_2,param_3
          );
  _applog(3,acStack_808,0);
  return;
}

