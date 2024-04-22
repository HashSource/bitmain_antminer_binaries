
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

pool * add_pool(void)

{
  pool *ppVar1;
  int iVar2;
  pool **pppVar3;
  char tmp42 [2048];
  pool *pool;
  
  ppVar1 = (pool *)_cgcalloc(0x738,1,"cgminer.c","add_pool",0x2e5);
  ppVar1->support_ab = false;
  if (ppVar1 == (pool *)0x0) {
    tmp42[0] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[0];
    tmp42[1] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[1];
    tmp42[2] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[2];
    tmp42[3] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[3];
    tmp42[4] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[4];
    tmp42[5] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[5];
    tmp42[6] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[6];
    tmp42[7] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[7];
    tmp42[8] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[8];
    tmp42[9] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[9];
    tmp42[10] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[10];
    tmp42[11] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[11];
    tmp42[12] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[12];
    tmp42[13] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[13];
    tmp42[14] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[14];
    tmp42[15] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[15];
    tmp42[16] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[16];
    tmp42[17] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[17];
    tmp42[18] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[18];
    tmp42[19] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[19];
    tmp42[20] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[20];
    tmp42[21] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[21];
    tmp42[22] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[22];
    tmp42[23] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[23];
    tmp42[24] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[24];
    tmp42[25] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[25];
    tmp42[26] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[26];
    tmp42[27] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[27];
    tmp42[28] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[28];
    tmp42[29] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[29];
    tmp42[30] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[30];
    tmp42[31] = s_Failed_to_malloc_pool_in_add_poo_0008a9c8[31];
    tmp42[32] = (char)(short)ram0x0008a9e8;
    tmp42[33] = (char)((ushort)(short)ram0x0008a9e8 >> 8);
    _applog(3,tmp42,true);
    _quit(1);
  }
  ppVar1->prio = total_pools;
  ppVar1->pool_no = ppVar1->prio;
  pools = (pool **)_cgrealloc(pools,(total_pools + 2) * 4,"cgminer.c","add_pool",0x2f1);
  pppVar3 = pools + total_pools;
  total_pools = total_pools + 1;
  *pppVar3 = ppVar1;
  _mutex_init(&ppVar1->pool_lock,"cgminer.c","add_pool",0x2f4);
  iVar2 = pthread_cond_init((pthread_cond_t *)&ppVar1->cr_cond,(pthread_condattr_t *)0x0);
  if (iVar2 != 0) {
    tmp42[0] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[0];
    tmp42[1] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[1];
    tmp42[2] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[2];
    tmp42[3] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[3];
    tmp42[4] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[4];
    tmp42[5] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[5];
    tmp42[6] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[6];
    tmp42[7] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[7];
    tmp42[8] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[8];
    tmp42[9] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[9];
    tmp42[10] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[10];
    tmp42[11] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[11];
    tmp42[12] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[12];
    tmp42[13] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[13];
    tmp42[14] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[14];
    tmp42[15] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[15];
    tmp42[16] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[16];
    tmp42[17] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[17];
    tmp42[18] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[18];
    tmp42[19] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[19];
    tmp42[20] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[20];
    tmp42[21] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[21];
    tmp42[22] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[22];
    tmp42[23] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[23];
    tmp42[24] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[24];
    tmp42[25] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[25];
    tmp42[26] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[26];
    tmp42[27] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[27];
    tmp42[28] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[28];
    tmp42[29] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[29];
    tmp42[30] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[30];
    tmp42[31] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[31];
    tmp42[32] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[32];
    tmp42[33] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[33];
    tmp42[34] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[34];
    tmp42[35] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[35];
    tmp42[36] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[36];
    tmp42[37] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[37];
    tmp42[38] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[38];
    tmp42[39] = s_Failed_to_pthread_cond_init_in_a_0008a9ec[39];
    _applog(3,tmp42,true);
    _quit(1);
  }
  _cglock_init(&ppVar1->data_lock,"cgminer.c","add_pool",0x2fb);
  _mutex_init(&ppVar1->stratum_lock,"cgminer.c","add_pool",0x2fc);
  _cglock_init(&ppVar1->gbt_lock,"cgminer.c","add_pool",0x2fd);
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

