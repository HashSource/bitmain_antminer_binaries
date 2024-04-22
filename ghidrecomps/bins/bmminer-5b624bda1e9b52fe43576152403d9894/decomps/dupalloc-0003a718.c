
/* WARNING: Unknown calling convention */

void dupalloc(cgpu_info *cgpu,int timelimit)

{
  char *func;
  char *file;
  int *piVar1;
  dupdata *dup;
  K_LIST *pKVar2;
  char tmp42 [2048];
  
  piVar1 = (int *)calloc(1,0x20);
  func = DAT_0003a790;
  if (piVar1 == (int *)0x0) {
    snprintf(tmp42,0x800,DAT_0003a79c,DAT_0003a794,DAT_0003a790,0x24);
    _applog(3,tmp42,true);
    _quit(1);
  }
  file = DAT_0003a794;
  *piVar1 = timelimit;
  pKVar2 = _k_new_list(DAT_0003a798,0x10,0x400,0,true,file,func,0x27);
  piVar1[1] = (int)pKVar2;
  pKVar2 = k_new_store(pKVar2);
  piVar1[2] = (int)pKVar2;
  cgpu->dup_data = piVar1;
  return;
}

