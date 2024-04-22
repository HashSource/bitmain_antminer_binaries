
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void init_stratum_threads(pool *pool)

{
  int iVar1;
  pool *pool_local;
  char tmp42 [2048];
  
  have_longpoll = true;
  iVar1 = pthread_create(&pool->stratum_sthread,(pthread_attr_t *)0x0,stratum_sthread + 1,pool);
  if (iVar1 != 0) {
    tmp42[0] = s_Failed_to_create_stratum_sthread_0008d35c[0];
    tmp42[1] = s_Failed_to_create_stratum_sthread_0008d35c[1];
    tmp42[2] = s_Failed_to_create_stratum_sthread_0008d35c[2];
    tmp42[3] = s_Failed_to_create_stratum_sthread_0008d35c[3];
    tmp42[4] = s_Failed_to_create_stratum_sthread_0008d35c[4];
    tmp42[5] = s_Failed_to_create_stratum_sthread_0008d35c[5];
    tmp42[6] = s_Failed_to_create_stratum_sthread_0008d35c[6];
    tmp42[7] = s_Failed_to_create_stratum_sthread_0008d35c[7];
    tmp42[8] = s_Failed_to_create_stratum_sthread_0008d35c[8];
    tmp42[9] = s_Failed_to_create_stratum_sthread_0008d35c[9];
    tmp42[10] = s_Failed_to_create_stratum_sthread_0008d35c[10];
    tmp42[11] = s_Failed_to_create_stratum_sthread_0008d35c[11];
    tmp42[12] = s_Failed_to_create_stratum_sthread_0008d35c[12];
    tmp42[13] = s_Failed_to_create_stratum_sthread_0008d35c[13];
    tmp42[14] = s_Failed_to_create_stratum_sthread_0008d35c[14];
    tmp42[15] = s_Failed_to_create_stratum_sthread_0008d35c[15];
    tmp42[16] = s_Failed_to_create_stratum_sthread_0008d35c[16];
    tmp42[17] = s_Failed_to_create_stratum_sthread_0008d35c[17];
    tmp42[18] = s_Failed_to_create_stratum_sthread_0008d35c[18];
    tmp42[19] = s_Failed_to_create_stratum_sthread_0008d35c[19];
    tmp42[20] = s_Failed_to_create_stratum_sthread_0008d35c[20];
    tmp42[21] = s_Failed_to_create_stratum_sthread_0008d35c[21];
    tmp42[22] = s_Failed_to_create_stratum_sthread_0008d35c[22];
    tmp42[23] = s_Failed_to_create_stratum_sthread_0008d35c[23];
    tmp42[24] = s_Failed_to_create_stratum_sthread_0008d35c[24];
    tmp42[25] = s_Failed_to_create_stratum_sthread_0008d35c[25];
    tmp42[26] = s_Failed_to_create_stratum_sthread_0008d35c[26];
    tmp42[27] = s_Failed_to_create_stratum_sthread_0008d35c[27];
    tmp42[28] = s_Failed_to_create_stratum_sthread_0008d35c[28];
    tmp42[29] = s_Failed_to_create_stratum_sthread_0008d35c[29];
    tmp42[30] = s_Failed_to_create_stratum_sthread_0008d35c[30];
    tmp42[31] = s_Failed_to_create_stratum_sthread_0008d35c[31];
    tmp42[32] = (char)ram0x0008d37c;
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar1 = pthread_create(&pool->stratum_rthread,(pthread_attr_t *)0x0,stratum_rthread + 1,pool);
  if (iVar1 != 0) {
    tmp42[0] = s_Failed_to_create_stratum_rthread_0008d380[0];
    tmp42[1] = s_Failed_to_create_stratum_rthread_0008d380[1];
    tmp42[2] = s_Failed_to_create_stratum_rthread_0008d380[2];
    tmp42[3] = s_Failed_to_create_stratum_rthread_0008d380[3];
    tmp42[4] = s_Failed_to_create_stratum_rthread_0008d380[4];
    tmp42[5] = s_Failed_to_create_stratum_rthread_0008d380[5];
    tmp42[6] = s_Failed_to_create_stratum_rthread_0008d380[6];
    tmp42[7] = s_Failed_to_create_stratum_rthread_0008d380[7];
    tmp42[8] = s_Failed_to_create_stratum_rthread_0008d380[8];
    tmp42[9] = s_Failed_to_create_stratum_rthread_0008d380[9];
    tmp42[10] = s_Failed_to_create_stratum_rthread_0008d380[10];
    tmp42[11] = s_Failed_to_create_stratum_rthread_0008d380[11];
    tmp42[12] = s_Failed_to_create_stratum_rthread_0008d380[12];
    tmp42[13] = s_Failed_to_create_stratum_rthread_0008d380[13];
    tmp42[14] = s_Failed_to_create_stratum_rthread_0008d380[14];
    tmp42[15] = s_Failed_to_create_stratum_rthread_0008d380[15];
    tmp42[16] = s_Failed_to_create_stratum_rthread_0008d380[16];
    tmp42[17] = s_Failed_to_create_stratum_rthread_0008d380[17];
    tmp42[18] = s_Failed_to_create_stratum_rthread_0008d380[18];
    tmp42[19] = s_Failed_to_create_stratum_rthread_0008d380[19];
    tmp42[20] = s_Failed_to_create_stratum_rthread_0008d380[20];
    tmp42[21] = s_Failed_to_create_stratum_rthread_0008d380[21];
    tmp42[22] = s_Failed_to_create_stratum_rthread_0008d380[22];
    tmp42[23] = s_Failed_to_create_stratum_rthread_0008d380[23];
    tmp42[24] = s_Failed_to_create_stratum_rthread_0008d380[24];
    tmp42[25] = s_Failed_to_create_stratum_rthread_0008d380[25];
    tmp42[26] = s_Failed_to_create_stratum_rthread_0008d380[26];
    tmp42[27] = s_Failed_to_create_stratum_rthread_0008d380[27];
    tmp42[28] = s_Failed_to_create_stratum_rthread_0008d380[28];
    tmp42[29] = s_Failed_to_create_stratum_rthread_0008d380[29];
    tmp42[30] = s_Failed_to_create_stratum_rthread_0008d380[30];
    tmp42[31] = s_Failed_to_create_stratum_rthread_0008d380[31];
    tmp42[32] = (char)ram0x0008d3a0;
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

