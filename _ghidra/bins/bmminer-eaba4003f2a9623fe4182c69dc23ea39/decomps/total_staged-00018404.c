
/* WARNING: Unknown calling convention */

int total_staged(void)

{
  int iVar1;
  int ret;
  
  _mutex_lock(stgd_lock,"cgminer.c","total_staged",0xb1f);
  iVar1 = __total_staged();
  _mutex_unlock(stgd_lock,"cgminer.c","total_staged",0xb21);
  return iVar1;
}

