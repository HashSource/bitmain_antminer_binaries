
/* WARNING: Unknown calling convention */

_Bool cnx_needed(pool *pool)

{
  int iVar1;
  pool *ppVar2;
  pool *cp;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_000248f8;
  if (pool->enabled != POOL_ENABLED) {
    return false;
  }
  if (((((*(int *)(DAT_000248f8 + 0x41c) != 4) && (*(int *)(DAT_000248f8 + 0x41c) != 3)) &&
       ((pool->has_stratum == false || (pool->idle == false)))) &&
      ((ppVar2 = current_pool(), pool != ppVar2 && (pool->sshares == 0)))) &&
     ((*(int *)(iVar1 + 0x41c) != 0 || (iVar4 = pool->prio, iVar3 = cp_prio(), iVar3 <= iVar4)))) {
    return (_Bool)*(undefined *)(iVar1 + 0x45c);
  }
  return true;
}

