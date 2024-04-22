
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pool_start_lp(pool *pool)

{
  int iVar1;
  pool *pool_local;
  char tmp42 [2048];
  
  if (pool->lp_started != true) {
    pool->lp_started = true;
    iVar1 = pthread_create(&pool->longpoll_thread,(pthread_attr_t *)0x0,longpoll_thread + 1,pool);
    if (iVar1 != 0) {
      tmp42[0] = s_Failed_to_create_pool_longpoll_t_0008d3c0[0];
      tmp42[1] = s_Failed_to_create_pool_longpoll_t_0008d3c0[1];
      tmp42[2] = s_Failed_to_create_pool_longpoll_t_0008d3c0[2];
      tmp42[3] = s_Failed_to_create_pool_longpoll_t_0008d3c0[3];
      tmp42[4] = s_Failed_to_create_pool_longpoll_t_0008d3c0[4];
      tmp42[5] = s_Failed_to_create_pool_longpoll_t_0008d3c0[5];
      tmp42[6] = s_Failed_to_create_pool_longpoll_t_0008d3c0[6];
      tmp42[7] = s_Failed_to_create_pool_longpoll_t_0008d3c0[7];
      tmp42[8] = s_Failed_to_create_pool_longpoll_t_0008d3c0[8];
      tmp42[9] = s_Failed_to_create_pool_longpoll_t_0008d3c0[9];
      tmp42[10] = s_Failed_to_create_pool_longpoll_t_0008d3c0[10];
      tmp42[11] = s_Failed_to_create_pool_longpoll_t_0008d3c0[11];
      tmp42[12] = s_Failed_to_create_pool_longpoll_t_0008d3c0[12];
      tmp42[13] = s_Failed_to_create_pool_longpoll_t_0008d3c0[13];
      tmp42[14] = s_Failed_to_create_pool_longpoll_t_0008d3c0[14];
      tmp42[15] = s_Failed_to_create_pool_longpoll_t_0008d3c0[15];
      tmp42[16] = s_Failed_to_create_pool_longpoll_t_0008d3c0[16];
      tmp42[17] = s_Failed_to_create_pool_longpoll_t_0008d3c0[17];
      tmp42[18] = s_Failed_to_create_pool_longpoll_t_0008d3c0[18];
      tmp42[19] = s_Failed_to_create_pool_longpoll_t_0008d3c0[19];
      tmp42[20] = s_Failed_to_create_pool_longpoll_t_0008d3c0[20];
      tmp42[21] = s_Failed_to_create_pool_longpoll_t_0008d3c0[21];
      tmp42[22] = s_Failed_to_create_pool_longpoll_t_0008d3c0[22];
      tmp42[23] = s_Failed_to_create_pool_longpoll_t_0008d3c0[23];
      tmp42[24] = s_Failed_to_create_pool_longpoll_t_0008d3c0[24];
      tmp42[25] = s_Failed_to_create_pool_longpoll_t_0008d3c0[25];
      tmp42[26] = s_Failed_to_create_pool_longpoll_t_0008d3c0[26];
      tmp42[27] = s_Failed_to_create_pool_longpoll_t_0008d3c0[27];
      tmp42[28] = s_Failed_to_create_pool_longpoll_t_0008d3c0[28];
      tmp42[29] = s_Failed_to_create_pool_longpoll_t_0008d3c0[29];
      tmp42[30] = s_Failed_to_create_pool_longpoll_t_0008d3c0[30];
      tmp42[31] = s_Failed_to_create_pool_longpoll_t_0008d3c0[31];
      tmp42[32] = s_Failed_to_create_pool_longpoll_t_0008d3c0[32];
      tmp42[33] = s_Failed_to_create_pool_longpoll_t_0008d3c0[33];
      tmp42[34] = s_Failed_to_create_pool_longpoll_t_0008d3c0[34];
      tmp42[35] = s_Failed_to_create_pool_longpoll_t_0008d3c0[35];
      tmp42._36_2_ = (undefined2)ram0x0008d3e4;
      _applog(3,tmp42,true);
      _quit(1);
    }
  }
  return;
}

