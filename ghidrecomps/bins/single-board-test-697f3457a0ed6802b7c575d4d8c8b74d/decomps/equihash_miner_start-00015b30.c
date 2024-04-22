
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void equihash_miner_start(runtime_base_t *runtime)

{
  int iVar1;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  
  iVar1 = pthread_create(&p_miner,(pthread_attr_t *)0x0,mining_mode + 1,runtime);
  if (iVar1 == 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      tmp42[0] = s_create_mining_mode_thread_succes_00034848[0];
      tmp42[1] = s_create_mining_mode_thread_succes_00034848[1];
      tmp42[2] = s_create_mining_mode_thread_succes_00034848[2];
      tmp42[3] = s_create_mining_mode_thread_succes_00034848[3];
      tmp42[4] = s_create_mining_mode_thread_succes_00034848[4];
      tmp42[5] = s_create_mining_mode_thread_succes_00034848[5];
      tmp42[6] = s_create_mining_mode_thread_succes_00034848[6];
      tmp42[7] = s_create_mining_mode_thread_succes_00034848[7];
      tmp42[8] = s_create_mining_mode_thread_succes_00034848[8];
      tmp42[9] = s_create_mining_mode_thread_succes_00034848[9];
      tmp42[10] = s_create_mining_mode_thread_succes_00034848[10];
      tmp42[11] = s_create_mining_mode_thread_succes_00034848[11];
      tmp42[12] = s_create_mining_mode_thread_succes_00034848[12];
      tmp42[13] = s_create_mining_mode_thread_succes_00034848[13];
      tmp42[14] = s_create_mining_mode_thread_succes_00034848[14];
      tmp42[15] = s_create_mining_mode_thread_succes_00034848[15];
      tmp42[16] = s_create_mining_mode_thread_succes_00034848[16];
      tmp42[17] = s_create_mining_mode_thread_succes_00034848[17];
      tmp42[18] = s_create_mining_mode_thread_succes_00034848[18];
      tmp42[19] = s_create_mining_mode_thread_succes_00034848[19];
      tmp42[20] = s_create_mining_mode_thread_succes_00034848[20];
      tmp42[21] = s_create_mining_mode_thread_succes_00034848[21];
      tmp42[22] = s_create_mining_mode_thread_succes_00034848[22];
      tmp42[23] = s_create_mining_mode_thread_succes_00034848[23];
      tmp42[24] = s_create_mining_mode_thread_succes_00034848[24];
      tmp42[25] = s_create_mining_mode_thread_succes_00034848[25];
      tmp42[26] = s_create_mining_mode_thread_succes_00034848[26];
      tmp42[27] = s_create_mining_mode_thread_succes_00034848[27];
      tmp42[28] = s_create_mining_mode_thread_succes_00034848[28];
      tmp42[29] = s_create_mining_mode_thread_succes_00034848[29];
      tmp42[30] = s_create_mining_mode_thread_succes_00034848[30];
      tmp42[31] = s_create_mining_mode_thread_succes_00034848[31];
      tmp42[32] = s_create_mining_mode_thread_succes_00034848[32];
      tmp42[33] = s_create_mining_mode_thread_succes_00034848[33];
      tmp42[34] = s_create_mining_mode_thread_succes_00034848[34];
      tmp42[35] = s_create_mining_mode_thread_succes_00034848[35];
      tmp42[36] = (char)ram0x0003486c;
      _applog(0,tmp42,false);
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
    tmp42[0] = s_create_mining_mode_thread_failed_00034824[0];
    tmp42[1] = s_create_mining_mode_thread_failed_00034824[1];
    tmp42[2] = s_create_mining_mode_thread_failed_00034824[2];
    tmp42[3] = s_create_mining_mode_thread_failed_00034824[3];
    tmp42[4] = s_create_mining_mode_thread_failed_00034824[4];
    tmp42[5] = s_create_mining_mode_thread_failed_00034824[5];
    tmp42[6] = s_create_mining_mode_thread_failed_00034824[6];
    tmp42[7] = s_create_mining_mode_thread_failed_00034824[7];
    tmp42[8] = s_create_mining_mode_thread_failed_00034824[8];
    tmp42[9] = s_create_mining_mode_thread_failed_00034824[9];
    tmp42[10] = s_create_mining_mode_thread_failed_00034824[10];
    tmp42[11] = s_create_mining_mode_thread_failed_00034824[11];
    tmp42[12] = s_create_mining_mode_thread_failed_00034824[12];
    tmp42[13] = s_create_mining_mode_thread_failed_00034824[13];
    tmp42[14] = s_create_mining_mode_thread_failed_00034824[14];
    tmp42[15] = s_create_mining_mode_thread_failed_00034824[15];
    tmp42[16] = s_create_mining_mode_thread_failed_00034824[16];
    tmp42[17] = s_create_mining_mode_thread_failed_00034824[17];
    tmp42[18] = s_create_mining_mode_thread_failed_00034824[18];
    tmp42[19] = s_create_mining_mode_thread_failed_00034824[19];
    tmp42[20] = s_create_mining_mode_thread_failed_00034824[20];
    tmp42[21] = s_create_mining_mode_thread_failed_00034824[21];
    tmp42[22] = s_create_mining_mode_thread_failed_00034824[22];
    tmp42[23] = s_create_mining_mode_thread_failed_00034824[23];
    tmp42[24] = s_create_mining_mode_thread_failed_00034824[24];
    tmp42[25] = s_create_mining_mode_thread_failed_00034824[25];
    tmp42[26] = s_create_mining_mode_thread_failed_00034824[26];
    tmp42[27] = s_create_mining_mode_thread_failed_00034824[27];
    tmp42[28] = s_create_mining_mode_thread_failed_00034824[28];
    tmp42[29] = s_create_mining_mode_thread_failed_00034824[29];
    tmp42[30] = s_create_mining_mode_thread_failed_00034824[30];
    tmp42[31] = s_create_mining_mode_thread_failed_00034824[31];
    tmp42[32] = (char)(short)ram0x00034844;
    tmp42[33] = (char)((ushort)(short)ram0x00034844 >> 8);
    _applog(0,tmp42,false);
  }
  return;
}

