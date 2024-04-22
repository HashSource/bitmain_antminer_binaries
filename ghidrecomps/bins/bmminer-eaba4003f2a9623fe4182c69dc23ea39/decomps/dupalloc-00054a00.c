
void dupalloc(cgpu_info *cgpu,int timelimit)

{
  int *piVar1;
  K_LIST *pKVar2;
  int timelimit_local;
  cgpu_info *cgpu_local;
  char tmp42 [2048];
  dupdata *dup;
  
  piVar1 = (int *)calloc(1,0x20);
  if (piVar1 == (int *)0x0) {
    snprintf(tmp42,0x800,"Failed to calloc dupdata in %s %s():%d","noncedup.c","dupalloc",0x24);
    _applog(3,tmp42,true);
    _quit(1);
  }
  *piVar1 = timelimit;
  pKVar2 = _k_new_list("Nonces",0x10,0x400,0,true,"noncedup.c","dupalloc",0x27);
  piVar1[1] = (int)pKVar2;
  pKVar2 = k_new_store((K_LIST *)piVar1[1]);
  piVar1[2] = (int)pKVar2;
  cgpu->dup_data = piVar1;
  return;
}

