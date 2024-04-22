
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
      tmp42[0] = s_Failed_to_create_pool_longpoll_t_00073b3c[0];
      tmp42[1] = s_Failed_to_create_pool_longpoll_t_00073b3c[1];
      tmp42[2] = s_Failed_to_create_pool_longpoll_t_00073b3c[2];
      tmp42[3] = s_Failed_to_create_pool_longpoll_t_00073b3c[3];
      tmp42[4] = s_Failed_to_create_pool_longpoll_t_00073b3c[4];
      tmp42[5] = s_Failed_to_create_pool_longpoll_t_00073b3c[5];
      tmp42[6] = s_Failed_to_create_pool_longpoll_t_00073b3c[6];
      tmp42[7] = s_Failed_to_create_pool_longpoll_t_00073b3c[7];
      tmp42[8] = s_Failed_to_create_pool_longpoll_t_00073b3c[8];
      tmp42[9] = s_Failed_to_create_pool_longpoll_t_00073b3c[9];
      tmp42[10] = s_Failed_to_create_pool_longpoll_t_00073b3c[10];
      tmp42[11] = s_Failed_to_create_pool_longpoll_t_00073b3c[11];
      tmp42[12] = s_Failed_to_create_pool_longpoll_t_00073b3c[12];
      tmp42[13] = s_Failed_to_create_pool_longpoll_t_00073b3c[13];
      tmp42[14] = s_Failed_to_create_pool_longpoll_t_00073b3c[14];
      tmp42[15] = s_Failed_to_create_pool_longpoll_t_00073b3c[15];
      tmp42[16] = s_Failed_to_create_pool_longpoll_t_00073b3c[16];
      tmp42[17] = s_Failed_to_create_pool_longpoll_t_00073b3c[17];
      tmp42[18] = s_Failed_to_create_pool_longpoll_t_00073b3c[18];
      tmp42[19] = s_Failed_to_create_pool_longpoll_t_00073b3c[19];
      tmp42[20] = s_Failed_to_create_pool_longpoll_t_00073b3c[20];
      tmp42[21] = s_Failed_to_create_pool_longpoll_t_00073b3c[21];
      tmp42[22] = s_Failed_to_create_pool_longpoll_t_00073b3c[22];
      tmp42[23] = s_Failed_to_create_pool_longpoll_t_00073b3c[23];
      tmp42[24] = s_Failed_to_create_pool_longpoll_t_00073b3c[24];
      tmp42[25] = s_Failed_to_create_pool_longpoll_t_00073b3c[25];
      tmp42[26] = s_Failed_to_create_pool_longpoll_t_00073b3c[26];
      tmp42[27] = s_Failed_to_create_pool_longpoll_t_00073b3c[27];
      tmp42[28] = s_Failed_to_create_pool_longpoll_t_00073b3c[28];
      tmp42[29] = s_Failed_to_create_pool_longpoll_t_00073b3c[29];
      tmp42[30] = s_Failed_to_create_pool_longpoll_t_00073b3c[30];
      tmp42[31] = s_Failed_to_create_pool_longpoll_t_00073b3c[31];
      tmp42[32] = s_Failed_to_create_pool_longpoll_t_00073b3c[32];
      tmp42[33] = s_Failed_to_create_pool_longpoll_t_00073b3c[33];
      tmp42[34] = s_Failed_to_create_pool_longpoll_t_00073b3c[34];
      tmp42[35] = s_Failed_to_create_pool_longpoll_t_00073b3c[35];
      tmp42._36_2_ = (undefined2)ram0x00073b60;
      _applog(3,tmp42,true);
      _quit(1);
    }
  }
  return;
}

