
void _wr_lock_part_54_constprop_73(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  char acStack_808 [2056];
  
  piVar1 = __errno_location();
  snprintf(acStack_808,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar1,"cgminer.c",
           param_1,param_2);
  _applog(3,acStack_808,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

