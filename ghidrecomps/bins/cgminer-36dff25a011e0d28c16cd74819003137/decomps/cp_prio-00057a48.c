
/* WARNING: Unknown calling convention */

int cp_prio(void)

{
  int iVar1;
  int prio;
  
  _cg_rlock(&control_lock,"cgminer.c","cp_prio",0x1cdb);
  iVar1 = currentpool->prio;
  _cg_runlock(&control_lock,"cgminer.c","cp_prio",0x1cdd);
  return iVar1;
}

