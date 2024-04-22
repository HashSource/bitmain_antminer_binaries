
/* WARNING: Unknown calling convention */

void pool_resus(pool *pool)

{
  int iVar1;
  int iVar2;
  char tmp42 [2048];
  
  iVar1 = DAT_000247bc;
  pool->seq_getfails = 0;
  if ((*(int *)(iVar1 + 0x41c) == 0) && (iVar2 = pool->prio, iVar1 = cp_prio(), iVar2 < iVar1)) {
    if (((*DAT_000247c0 != '\0') || (*DAT_000247c4 != '\0')) || (3 < *DAT_000247cc)) {
      snprintf(tmp42,0x800,DAT_000247d0,pool->pool_no,pool->rpc_url);
      _applog(4,tmp42,false);
    }
  }
  else if ((*DAT_000247c0 != '\0') || ((*DAT_000247c4 != '\0' || (5 < *DAT_000247cc)))) {
    snprintf(tmp42,0x800,DAT_000247c8,pool->pool_no,pool->rpc_url);
    _applog(6,tmp42,false);
  }
  return;
}

