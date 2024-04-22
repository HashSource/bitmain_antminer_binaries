
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

pool * add_pool(void)

{
  pool *ppVar1;
  int iVar2;
  char tmp42 [2048];
  pool *pool;
  
  ppVar1 = (pool *)_cgcalloc(0x740,1,"cgminer.c","add_pool",0x2de);
  ppVar1->support_vil = false;
  if (ppVar1 == (pool *)0x0) {
    tmp42[0] = s_Failed_to_malloc_pool_in_add_poo_000712b0[0];
    tmp42[1] = s_Failed_to_malloc_pool_in_add_poo_000712b0[1];
    tmp42[2] = s_Failed_to_malloc_pool_in_add_poo_000712b0[2];
    tmp42[3] = s_Failed_to_malloc_pool_in_add_poo_000712b0[3];
    tmp42[4] = s_Failed_to_malloc_pool_in_add_poo_000712b0[4];
    tmp42[5] = s_Failed_to_malloc_pool_in_add_poo_000712b0[5];
    tmp42[6] = s_Failed_to_malloc_pool_in_add_poo_000712b0[6];
    tmp42[7] = s_Failed_to_malloc_pool_in_add_poo_000712b0[7];
    tmp42[8] = s_Failed_to_malloc_pool_in_add_poo_000712b0[8];
    tmp42[9] = s_Failed_to_malloc_pool_in_add_poo_000712b0[9];
    tmp42[10] = s_Failed_to_malloc_pool_in_add_poo_000712b0[10];
    tmp42[11] = s_Failed_to_malloc_pool_in_add_poo_000712b0[11];
    tmp42[12] = s_Failed_to_malloc_pool_in_add_poo_000712b0[12];
    tmp42[13] = s_Failed_to_malloc_pool_in_add_poo_000712b0[13];
    tmp42[14] = s_Failed_to_malloc_pool_in_add_poo_000712b0[14];
    tmp42[15] = s_Failed_to_malloc_pool_in_add_poo_000712b0[15];
    tmp42[16] = s_Failed_to_malloc_pool_in_add_poo_000712b0[16];
    tmp42[17] = s_Failed_to_malloc_pool_in_add_poo_000712b0[17];
    tmp42[18] = s_Failed_to_malloc_pool_in_add_poo_000712b0[18];
    tmp42[19] = s_Failed_to_malloc_pool_in_add_poo_000712b0[19];
    tmp42[20] = s_Failed_to_malloc_pool_in_add_poo_000712b0[20];
    tmp42[21] = s_Failed_to_malloc_pool_in_add_poo_000712b0[21];
    tmp42[22] = s_Failed_to_malloc_pool_in_add_poo_000712b0[22];
    tmp42[23] = s_Failed_to_malloc_pool_in_add_poo_000712b0[23];
    tmp42[24] = s_Failed_to_malloc_pool_in_add_poo_000712b0[24];
    tmp42[25] = s_Failed_to_malloc_pool_in_add_poo_000712b0[25];
    tmp42[26] = s_Failed_to_malloc_pool_in_add_poo_000712b0[26];
    tmp42[27] = s_Failed_to_malloc_pool_in_add_poo_000712b0[27];
    tmp42[28] = s_Failed_to_malloc_pool_in_add_poo_000712b0[28];
    tmp42[29] = s_Failed_to_malloc_pool_in_add_poo_000712b0[29];
    tmp42[30] = s_Failed_to_malloc_pool_in_add_poo_000712b0[30];
    tmp42[31] = s_Failed_to_malloc_pool_in_add_poo_000712b0[31];
    tmp42[32] = (char)(short)ram0x000712d0;
    tmp42[33] = (char)((ushort)(short)ram0x000712d0 >> 8);
    _applog(3,tmp42,true);
    _quit(1);
  }
  ppVar1->prio = total_pools;
  ppVar1->pool_no = ppVar1->prio;
  pools = (pool **)_cgrealloc(pools,(total_pools + 2) * 4,"cgminer.c","add_pool",0x2ea);
  pools[total_pools] = ppVar1;
  total_pools = total_pools + 1;
  _mutex_init(&ppVar1->pool_lock,"cgminer.c","add_pool",0x2ed);
  iVar2 = pthread_cond_init((pthread_cond_t *)&ppVar1->cr_cond,(pthread_condattr_t *)0x0);
  if (iVar2 != 0) {
    tmp42[0] = s_Failed_to_pthread_cond_init_in_a_000712d4[0];
    tmp42[1] = s_Failed_to_pthread_cond_init_in_a_000712d4[1];
    tmp42[2] = s_Failed_to_pthread_cond_init_in_a_000712d4[2];
    tmp42[3] = s_Failed_to_pthread_cond_init_in_a_000712d4[3];
    tmp42[4] = s_Failed_to_pthread_cond_init_in_a_000712d4[4];
    tmp42[5] = s_Failed_to_pthread_cond_init_in_a_000712d4[5];
    tmp42[6] = s_Failed_to_pthread_cond_init_in_a_000712d4[6];
    tmp42[7] = s_Failed_to_pthread_cond_init_in_a_000712d4[7];
    tmp42[8] = s_Failed_to_pthread_cond_init_in_a_000712d4[8];
    tmp42[9] = s_Failed_to_pthread_cond_init_in_a_000712d4[9];
    tmp42[10] = s_Failed_to_pthread_cond_init_in_a_000712d4[10];
    tmp42[11] = s_Failed_to_pthread_cond_init_in_a_000712d4[11];
    tmp42[12] = s_Failed_to_pthread_cond_init_in_a_000712d4[12];
    tmp42[13] = s_Failed_to_pthread_cond_init_in_a_000712d4[13];
    tmp42[14] = s_Failed_to_pthread_cond_init_in_a_000712d4[14];
    tmp42[15] = s_Failed_to_pthread_cond_init_in_a_000712d4[15];
    tmp42[16] = s_Failed_to_pthread_cond_init_in_a_000712d4[16];
    tmp42[17] = s_Failed_to_pthread_cond_init_in_a_000712d4[17];
    tmp42[18] = s_Failed_to_pthread_cond_init_in_a_000712d4[18];
    tmp42[19] = s_Failed_to_pthread_cond_init_in_a_000712d4[19];
    tmp42[20] = s_Failed_to_pthread_cond_init_in_a_000712d4[20];
    tmp42[21] = s_Failed_to_pthread_cond_init_in_a_000712d4[21];
    tmp42[22] = s_Failed_to_pthread_cond_init_in_a_000712d4[22];
    tmp42[23] = s_Failed_to_pthread_cond_init_in_a_000712d4[23];
    tmp42[24] = s_Failed_to_pthread_cond_init_in_a_000712d4[24];
    tmp42[25] = s_Failed_to_pthread_cond_init_in_a_000712d4[25];
    tmp42[26] = s_Failed_to_pthread_cond_init_in_a_000712d4[26];
    tmp42[27] = s_Failed_to_pthread_cond_init_in_a_000712d4[27];
    tmp42[28] = s_Failed_to_pthread_cond_init_in_a_000712d4[28];
    tmp42[29] = s_Failed_to_pthread_cond_init_in_a_000712d4[29];
    tmp42[30] = s_Failed_to_pthread_cond_init_in_a_000712d4[30];
    tmp42[31] = s_Failed_to_pthread_cond_init_in_a_000712d4[31];
    tmp42[32] = s_Failed_to_pthread_cond_init_in_a_000712d4[32];
    tmp42[33] = s_Failed_to_pthread_cond_init_in_a_000712d4[33];
    tmp42[34] = s_Failed_to_pthread_cond_init_in_a_000712d4[34];
    tmp42[35] = s_Failed_to_pthread_cond_init_in_a_000712d4[35];
    tmp42[36] = s_Failed_to_pthread_cond_init_in_a_000712d4[36];
    tmp42[37] = s_Failed_to_pthread_cond_init_in_a_000712d4[37];
    tmp42[38] = s_Failed_to_pthread_cond_init_in_a_000712d4[38];
    tmp42[39] = s_Failed_to_pthread_cond_init_in_a_000712d4[39];
    _applog(3,tmp42,true);
    _quit(1);
  }
  _cglock_init(&ppVar1->data_lock,"cgminer.c","add_pool",0x2f4);
  _mutex_init(&ppVar1->stratum_lock,"cgminer.c","add_pool",0x2f5);
  _cglock_init(&ppVar1->gbt_lock,"cgminer.c","add_pool",0x2f6);
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

