
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void init_stratum_threads(pool *pool)

{
  int iVar1;
  pool *pool_local;
  char tmp42 [2048];
  
  have_longpoll = true;
  iVar1 = pthread_create(&pool->stratum_sthread,(pthread_attr_t *)0x0,stratum_sthread + 1,pool);
  if (iVar1 != 0) {
    tmp42[0] = s_Failed_to_create_stratum_sthread_00073ad8[0];
    tmp42[1] = s_Failed_to_create_stratum_sthread_00073ad8[1];
    tmp42[2] = s_Failed_to_create_stratum_sthread_00073ad8[2];
    tmp42[3] = s_Failed_to_create_stratum_sthread_00073ad8[3];
    tmp42[4] = s_Failed_to_create_stratum_sthread_00073ad8[4];
    tmp42[5] = s_Failed_to_create_stratum_sthread_00073ad8[5];
    tmp42[6] = s_Failed_to_create_stratum_sthread_00073ad8[6];
    tmp42[7] = s_Failed_to_create_stratum_sthread_00073ad8[7];
    tmp42[8] = s_Failed_to_create_stratum_sthread_00073ad8[8];
    tmp42[9] = s_Failed_to_create_stratum_sthread_00073ad8[9];
    tmp42[10] = s_Failed_to_create_stratum_sthread_00073ad8[10];
    tmp42[11] = s_Failed_to_create_stratum_sthread_00073ad8[11];
    tmp42[12] = s_Failed_to_create_stratum_sthread_00073ad8[12];
    tmp42[13] = s_Failed_to_create_stratum_sthread_00073ad8[13];
    tmp42[14] = s_Failed_to_create_stratum_sthread_00073ad8[14];
    tmp42[15] = s_Failed_to_create_stratum_sthread_00073ad8[15];
    tmp42[16] = s_Failed_to_create_stratum_sthread_00073ad8[16];
    tmp42[17] = s_Failed_to_create_stratum_sthread_00073ad8[17];
    tmp42[18] = s_Failed_to_create_stratum_sthread_00073ad8[18];
    tmp42[19] = s_Failed_to_create_stratum_sthread_00073ad8[19];
    tmp42[20] = s_Failed_to_create_stratum_sthread_00073ad8[20];
    tmp42[21] = s_Failed_to_create_stratum_sthread_00073ad8[21];
    tmp42[22] = s_Failed_to_create_stratum_sthread_00073ad8[22];
    tmp42[23] = s_Failed_to_create_stratum_sthread_00073ad8[23];
    tmp42[24] = s_Failed_to_create_stratum_sthread_00073ad8[24];
    tmp42[25] = s_Failed_to_create_stratum_sthread_00073ad8[25];
    tmp42[26] = s_Failed_to_create_stratum_sthread_00073ad8[26];
    tmp42[27] = s_Failed_to_create_stratum_sthread_00073ad8[27];
    tmp42[28] = s_Failed_to_create_stratum_sthread_00073ad8[28];
    tmp42[29] = s_Failed_to_create_stratum_sthread_00073ad8[29];
    tmp42[30] = s_Failed_to_create_stratum_sthread_00073ad8[30];
    tmp42[31] = s_Failed_to_create_stratum_sthread_00073ad8[31];
    tmp42[32] = (char)ram0x00073af8;
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar1 = pthread_create(&pool->stratum_rthread,(pthread_attr_t *)0x0,stratum_rthread + 1,pool);
  if (iVar1 != 0) {
    tmp42[0] = s_Failed_to_create_stratum_rthread_00073afc[0];
    tmp42[1] = s_Failed_to_create_stratum_rthread_00073afc[1];
    tmp42[2] = s_Failed_to_create_stratum_rthread_00073afc[2];
    tmp42[3] = s_Failed_to_create_stratum_rthread_00073afc[3];
    tmp42[4] = s_Failed_to_create_stratum_rthread_00073afc[4];
    tmp42[5] = s_Failed_to_create_stratum_rthread_00073afc[5];
    tmp42[6] = s_Failed_to_create_stratum_rthread_00073afc[6];
    tmp42[7] = s_Failed_to_create_stratum_rthread_00073afc[7];
    tmp42[8] = s_Failed_to_create_stratum_rthread_00073afc[8];
    tmp42[9] = s_Failed_to_create_stratum_rthread_00073afc[9];
    tmp42[10] = s_Failed_to_create_stratum_rthread_00073afc[10];
    tmp42[11] = s_Failed_to_create_stratum_rthread_00073afc[11];
    tmp42[12] = s_Failed_to_create_stratum_rthread_00073afc[12];
    tmp42[13] = s_Failed_to_create_stratum_rthread_00073afc[13];
    tmp42[14] = s_Failed_to_create_stratum_rthread_00073afc[14];
    tmp42[15] = s_Failed_to_create_stratum_rthread_00073afc[15];
    tmp42[16] = s_Failed_to_create_stratum_rthread_00073afc[16];
    tmp42[17] = s_Failed_to_create_stratum_rthread_00073afc[17];
    tmp42[18] = s_Failed_to_create_stratum_rthread_00073afc[18];
    tmp42[19] = s_Failed_to_create_stratum_rthread_00073afc[19];
    tmp42[20] = s_Failed_to_create_stratum_rthread_00073afc[20];
    tmp42[21] = s_Failed_to_create_stratum_rthread_00073afc[21];
    tmp42[22] = s_Failed_to_create_stratum_rthread_00073afc[22];
    tmp42[23] = s_Failed_to_create_stratum_rthread_00073afc[23];
    tmp42[24] = s_Failed_to_create_stratum_rthread_00073afc[24];
    tmp42[25] = s_Failed_to_create_stratum_rthread_00073afc[25];
    tmp42[26] = s_Failed_to_create_stratum_rthread_00073afc[26];
    tmp42[27] = s_Failed_to_create_stratum_rthread_00073afc[27];
    tmp42[28] = s_Failed_to_create_stratum_rthread_00073afc[28];
    tmp42[29] = s_Failed_to_create_stratum_rthread_00073afc[29];
    tmp42[30] = s_Failed_to_create_stratum_rthread_00073afc[30];
    tmp42[31] = s_Failed_to_create_stratum_rthread_00073afc[31];
    tmp42[32] = (char)ram0x00073b1c;
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

