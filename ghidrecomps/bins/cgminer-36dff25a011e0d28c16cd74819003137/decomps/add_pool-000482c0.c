
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

pool * add_pool(void)

{
  pool *ppVar1;
  int iVar2;
  pool **pppVar3;
  char tmp42 [2048];
  pool *pool;
  
  ppVar1 = (pool *)_cgcalloc(0x738,1,"cgminer.c","add_pool",0x2e4);
  ppVar1->support_ab = false;
  if (ppVar1 == (pool *)0x0) {
    tmp42[0] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[0];
    tmp42[1] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[1];
    tmp42[2] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[2];
    tmp42[3] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[3];
    tmp42[4] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[4];
    tmp42[5] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[5];
    tmp42[6] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[6];
    tmp42[7] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[7];
    tmp42[8] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[8];
    tmp42[9] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[9];
    tmp42[10] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[10];
    tmp42[11] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[11];
    tmp42[12] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[12];
    tmp42[13] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[13];
    tmp42[14] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[14];
    tmp42[15] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[15];
    tmp42[16] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[16];
    tmp42[17] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[17];
    tmp42[18] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[18];
    tmp42[19] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[19];
    tmp42[20] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[20];
    tmp42[21] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[21];
    tmp42[22] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[22];
    tmp42[23] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[23];
    tmp42[24] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[24];
    tmp42[25] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[25];
    tmp42[26] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[26];
    tmp42[27] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[27];
    tmp42[28] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[28];
    tmp42[29] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[29];
    tmp42[30] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[30];
    tmp42[31] = s_Failed_to_malloc_pool_in_add_poo_000a1d74[31];
    tmp42[32] = (char)(short)ram0x000a1d94;
    tmp42[33] = (char)((ushort)(short)ram0x000a1d94 >> 8);
    _applog(3,tmp42,true);
    _quit(1);
  }
  ppVar1->prio = total_pools;
  ppVar1->pool_no = ppVar1->prio;
  pools = (pool **)_cgrealloc(pools,(total_pools + 2) * 4,"cgminer.c","add_pool",0x2f0);
  pppVar3 = pools + total_pools;
  total_pools = total_pools + 1;
  *pppVar3 = ppVar1;
  _mutex_init(&ppVar1->pool_lock,"cgminer.c","add_pool",0x2f3);
  iVar2 = pthread_cond_init((pthread_cond_t *)&ppVar1->cr_cond,(pthread_condattr_t *)0x0);
  if (iVar2 != 0) {
    tmp42[0] = s_Failed_to_pthread_cond_init_in_a_000a1d98[0];
    tmp42[1] = s_Failed_to_pthread_cond_init_in_a_000a1d98[1];
    tmp42[2] = s_Failed_to_pthread_cond_init_in_a_000a1d98[2];
    tmp42[3] = s_Failed_to_pthread_cond_init_in_a_000a1d98[3];
    tmp42[4] = s_Failed_to_pthread_cond_init_in_a_000a1d98[4];
    tmp42[5] = s_Failed_to_pthread_cond_init_in_a_000a1d98[5];
    tmp42[6] = s_Failed_to_pthread_cond_init_in_a_000a1d98[6];
    tmp42[7] = s_Failed_to_pthread_cond_init_in_a_000a1d98[7];
    tmp42[8] = s_Failed_to_pthread_cond_init_in_a_000a1d98[8];
    tmp42[9] = s_Failed_to_pthread_cond_init_in_a_000a1d98[9];
    tmp42[10] = s_Failed_to_pthread_cond_init_in_a_000a1d98[10];
    tmp42[11] = s_Failed_to_pthread_cond_init_in_a_000a1d98[11];
    tmp42[12] = s_Failed_to_pthread_cond_init_in_a_000a1d98[12];
    tmp42[13] = s_Failed_to_pthread_cond_init_in_a_000a1d98[13];
    tmp42[14] = s_Failed_to_pthread_cond_init_in_a_000a1d98[14];
    tmp42[15] = s_Failed_to_pthread_cond_init_in_a_000a1d98[15];
    tmp42[16] = s_Failed_to_pthread_cond_init_in_a_000a1d98[16];
    tmp42[17] = s_Failed_to_pthread_cond_init_in_a_000a1d98[17];
    tmp42[18] = s_Failed_to_pthread_cond_init_in_a_000a1d98[18];
    tmp42[19] = s_Failed_to_pthread_cond_init_in_a_000a1d98[19];
    tmp42[20] = s_Failed_to_pthread_cond_init_in_a_000a1d98[20];
    tmp42[21] = s_Failed_to_pthread_cond_init_in_a_000a1d98[21];
    tmp42[22] = s_Failed_to_pthread_cond_init_in_a_000a1d98[22];
    tmp42[23] = s_Failed_to_pthread_cond_init_in_a_000a1d98[23];
    tmp42[24] = s_Failed_to_pthread_cond_init_in_a_000a1d98[24];
    tmp42[25] = s_Failed_to_pthread_cond_init_in_a_000a1d98[25];
    tmp42[26] = s_Failed_to_pthread_cond_init_in_a_000a1d98[26];
    tmp42[27] = s_Failed_to_pthread_cond_init_in_a_000a1d98[27];
    tmp42[28] = s_Failed_to_pthread_cond_init_in_a_000a1d98[28];
    tmp42[29] = s_Failed_to_pthread_cond_init_in_a_000a1d98[29];
    tmp42[30] = s_Failed_to_pthread_cond_init_in_a_000a1d98[30];
    tmp42[31] = s_Failed_to_pthread_cond_init_in_a_000a1d98[31];
    tmp42[32] = s_Failed_to_pthread_cond_init_in_a_000a1d98[32];
    tmp42[33] = s_Failed_to_pthread_cond_init_in_a_000a1d98[33];
    tmp42[34] = s_Failed_to_pthread_cond_init_in_a_000a1d98[34];
    tmp42[35] = s_Failed_to_pthread_cond_init_in_a_000a1d98[35];
    tmp42[36] = s_Failed_to_pthread_cond_init_in_a_000a1d98[36];
    tmp42[37] = s_Failed_to_pthread_cond_init_in_a_000a1d98[37];
    tmp42[38] = s_Failed_to_pthread_cond_init_in_a_000a1d98[38];
    tmp42[39] = s_Failed_to_pthread_cond_init_in_a_000a1d98[39];
    _applog(3,tmp42,true);
    _quit(1);
  }
  _cglock_init(&ppVar1->data_lock,"cgminer.c","add_pool",0x2fa);
  _mutex_init(&ppVar1->stratum_lock,"cgminer.c","add_pool",0x2fb);
  _cglock_init(&ppVar1->gbt_lock,"cgminer.c","add_pool",0x2fc);
  (ppVar1->curlring).next = &ppVar1->curlring;
  (ppVar1->curlring).prev = &ppVar1->curlring;
  (ppVar1->tv_idle).tv_sec = -1;
  ppVar1->rpc_req = getwork_req;
  ppVar1->rpc_proxy = (char *)0x0;
  ppVar1->quota = 1;
  adjust_quota_gcd();
  ppVar1->extranonce_subscribe = false;
  return ppVar1;
}

