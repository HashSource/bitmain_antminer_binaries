
/* WARNING: Unknown calling convention */

pool * current_pool(void)

{
  pool *ppVar1;
  pool *pool;
  
  _cg_rlock(&control_lock,"cgminer.c","current_pool",0x331);
  ppVar1 = currentpool;
  _cg_runlock(&control_lock,"cgminer.c","current_pool",0x335);
  return ppVar1;
}

