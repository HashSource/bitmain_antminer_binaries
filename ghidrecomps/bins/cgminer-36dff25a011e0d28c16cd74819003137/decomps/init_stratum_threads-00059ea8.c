
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void init_stratum_threads(pool *pool)

{
  int iVar1;
  pool *pool_local;
  char tmp42 [2048];
  
  have_longpoll = true;
  iVar1 = pthread_create(&pool->stratum_sthread,(pthread_attr_t *)0x0,stratum_sthread,pool);
  if (iVar1 != 0) {
    tmp42[0] = s_Failed_to_create_stratum_sthread_000a4718[0];
    tmp42[1] = s_Failed_to_create_stratum_sthread_000a4718[1];
    tmp42[2] = s_Failed_to_create_stratum_sthread_000a4718[2];
    tmp42[3] = s_Failed_to_create_stratum_sthread_000a4718[3];
    tmp42[4] = s_Failed_to_create_stratum_sthread_000a4718[4];
    tmp42[5] = s_Failed_to_create_stratum_sthread_000a4718[5];
    tmp42[6] = s_Failed_to_create_stratum_sthread_000a4718[6];
    tmp42[7] = s_Failed_to_create_stratum_sthread_000a4718[7];
    tmp42[8] = s_Failed_to_create_stratum_sthread_000a4718[8];
    tmp42[9] = s_Failed_to_create_stratum_sthread_000a4718[9];
    tmp42[10] = s_Failed_to_create_stratum_sthread_000a4718[10];
    tmp42[11] = s_Failed_to_create_stratum_sthread_000a4718[11];
    tmp42[12] = s_Failed_to_create_stratum_sthread_000a4718[12];
    tmp42[13] = s_Failed_to_create_stratum_sthread_000a4718[13];
    tmp42[14] = s_Failed_to_create_stratum_sthread_000a4718[14];
    tmp42[15] = s_Failed_to_create_stratum_sthread_000a4718[15];
    tmp42[16] = s_Failed_to_create_stratum_sthread_000a4718[16];
    tmp42[17] = s_Failed_to_create_stratum_sthread_000a4718[17];
    tmp42[18] = s_Failed_to_create_stratum_sthread_000a4718[18];
    tmp42[19] = s_Failed_to_create_stratum_sthread_000a4718[19];
    tmp42[20] = s_Failed_to_create_stratum_sthread_000a4718[20];
    tmp42[21] = s_Failed_to_create_stratum_sthread_000a4718[21];
    tmp42[22] = s_Failed_to_create_stratum_sthread_000a4718[22];
    tmp42[23] = s_Failed_to_create_stratum_sthread_000a4718[23];
    tmp42[24] = s_Failed_to_create_stratum_sthread_000a4718[24];
    tmp42[25] = s_Failed_to_create_stratum_sthread_000a4718[25];
    tmp42[26] = s_Failed_to_create_stratum_sthread_000a4718[26];
    tmp42[27] = s_Failed_to_create_stratum_sthread_000a4718[27];
    tmp42[28] = s_Failed_to_create_stratum_sthread_000a4718[28];
    tmp42[29] = s_Failed_to_create_stratum_sthread_000a4718[29];
    tmp42[30] = s_Failed_to_create_stratum_sthread_000a4718[30];
    tmp42[31] = s_Failed_to_create_stratum_sthread_000a4718[31];
    tmp42[32] = (char)ram0x000a4738;
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar1 = pthread_create(&pool->stratum_rthread,(pthread_attr_t *)0x0,stratum_rthread,pool);
  if (iVar1 != 0) {
    tmp42[0] = s_Failed_to_create_stratum_rthread_000a473c[0];
    tmp42[1] = s_Failed_to_create_stratum_rthread_000a473c[1];
    tmp42[2] = s_Failed_to_create_stratum_rthread_000a473c[2];
    tmp42[3] = s_Failed_to_create_stratum_rthread_000a473c[3];
    tmp42[4] = s_Failed_to_create_stratum_rthread_000a473c[4];
    tmp42[5] = s_Failed_to_create_stratum_rthread_000a473c[5];
    tmp42[6] = s_Failed_to_create_stratum_rthread_000a473c[6];
    tmp42[7] = s_Failed_to_create_stratum_rthread_000a473c[7];
    tmp42[8] = s_Failed_to_create_stratum_rthread_000a473c[8];
    tmp42[9] = s_Failed_to_create_stratum_rthread_000a473c[9];
    tmp42[10] = s_Failed_to_create_stratum_rthread_000a473c[10];
    tmp42[11] = s_Failed_to_create_stratum_rthread_000a473c[11];
    tmp42[12] = s_Failed_to_create_stratum_rthread_000a473c[12];
    tmp42[13] = s_Failed_to_create_stratum_rthread_000a473c[13];
    tmp42[14] = s_Failed_to_create_stratum_rthread_000a473c[14];
    tmp42[15] = s_Failed_to_create_stratum_rthread_000a473c[15];
    tmp42[16] = s_Failed_to_create_stratum_rthread_000a473c[16];
    tmp42[17] = s_Failed_to_create_stratum_rthread_000a473c[17];
    tmp42[18] = s_Failed_to_create_stratum_rthread_000a473c[18];
    tmp42[19] = s_Failed_to_create_stratum_rthread_000a473c[19];
    tmp42[20] = s_Failed_to_create_stratum_rthread_000a473c[20];
    tmp42[21] = s_Failed_to_create_stratum_rthread_000a473c[21];
    tmp42[22] = s_Failed_to_create_stratum_rthread_000a473c[22];
    tmp42[23] = s_Failed_to_create_stratum_rthread_000a473c[23];
    tmp42[24] = s_Failed_to_create_stratum_rthread_000a473c[24];
    tmp42[25] = s_Failed_to_create_stratum_rthread_000a473c[25];
    tmp42[26] = s_Failed_to_create_stratum_rthread_000a473c[26];
    tmp42[27] = s_Failed_to_create_stratum_rthread_000a473c[27];
    tmp42[28] = s_Failed_to_create_stratum_rthread_000a473c[28];
    tmp42[29] = s_Failed_to_create_stratum_rthread_000a473c[29];
    tmp42[30] = s_Failed_to_create_stratum_rthread_000a473c[30];
    tmp42[31] = s_Failed_to_create_stratum_rthread_000a473c[31];
    tmp42[32] = (char)ram0x000a475c;
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

