
/* WARNING: Unknown calling convention */

int total_work_inc(void)

{
  uint uVar1;
  int ret;
  
  _cg_wlock(&control_lock,"cgminer.c","total_work_inc",0x88d);
  uVar1 = total_work;
  total_work = total_work + 1;
  _cg_wunlock(&control_lock,"cgminer.c","total_work_inc",0x88f);
  return uVar1;
}

