
/* WARNING: Unknown calling convention */

void restart_threads(void)

{
  int iVar1;
  char tmp42 [2048];
  pthread_t rthread;
  
  cgtime(&restart_tv_start);
  iVar1 = pthread_create(&rthread,(pthread_attr_t *)0x0,restart_thread + 1,(void *)0x0);
  if (iVar1 != 0) {
    tmp42[0] = s_Failed_to_create_restart_thread_000730fc[0];
    tmp42[1] = s_Failed_to_create_restart_thread_000730fc[1];
    tmp42[2] = s_Failed_to_create_restart_thread_000730fc[2];
    tmp42[3] = s_Failed_to_create_restart_thread_000730fc[3];
    tmp42[4] = s_Failed_to_create_restart_thread_000730fc[4];
    tmp42[5] = s_Failed_to_create_restart_thread_000730fc[5];
    tmp42[6] = s_Failed_to_create_restart_thread_000730fc[6];
    tmp42[7] = s_Failed_to_create_restart_thread_000730fc[7];
    tmp42[8] = s_Failed_to_create_restart_thread_000730fc[8];
    tmp42[9] = s_Failed_to_create_restart_thread_000730fc[9];
    tmp42[10] = s_Failed_to_create_restart_thread_000730fc[10];
    tmp42[11] = s_Failed_to_create_restart_thread_000730fc[11];
    tmp42[12] = s_Failed_to_create_restart_thread_000730fc[12];
    tmp42[13] = s_Failed_to_create_restart_thread_000730fc[13];
    tmp42[14] = s_Failed_to_create_restart_thread_000730fc[14];
    tmp42[15] = s_Failed_to_create_restart_thread_000730fc[15];
    tmp42[16] = s_Failed_to_create_restart_thread_000730fc[16];
    tmp42[17] = s_Failed_to_create_restart_thread_000730fc[17];
    tmp42[18] = s_Failed_to_create_restart_thread_000730fc[18];
    tmp42[19] = s_Failed_to_create_restart_thread_000730fc[19];
    tmp42[20] = s_Failed_to_create_restart_thread_000730fc[20];
    tmp42[21] = s_Failed_to_create_restart_thread_000730fc[21];
    tmp42[22] = s_Failed_to_create_restart_thread_000730fc[22];
    tmp42[23] = s_Failed_to_create_restart_thread_000730fc[23];
    tmp42[24] = s_Failed_to_create_restart_thread_000730fc[24];
    tmp42[25] = s_Failed_to_create_restart_thread_000730fc[25];
    tmp42[26] = s_Failed_to_create_restart_thread_000730fc[26];
    tmp42[27] = s_Failed_to_create_restart_thread_000730fc[27];
    tmp42[28] = s_Failed_to_create_restart_thread_000730fc[28];
    tmp42[29] = s_Failed_to_create_restart_thread_000730fc[29];
    tmp42[30] = s_Failed_to_create_restart_thread_000730fc[30];
    tmp42[31] = s_Failed_to_create_restart_thread_000730fc[31];
    _applog(3,tmp42,true);
    _quit(1);
  }
  return;
}

