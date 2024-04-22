
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void set_highprio(void)

{
  int iVar1;
  char tmp42 [2048];
  int ret;
  
  iVar1 = nice(-10);
  if (((iVar1 == 0) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    tmp42[0] = s_Unable_to_set_thread_to_high_pri_000a4098[0];
    tmp42[1] = s_Unable_to_set_thread_to_high_pri_000a4098[1];
    tmp42[2] = s_Unable_to_set_thread_to_high_pri_000a4098[2];
    tmp42[3] = s_Unable_to_set_thread_to_high_pri_000a4098[3];
    tmp42[4] = s_Unable_to_set_thread_to_high_pri_000a4098[4];
    tmp42[5] = s_Unable_to_set_thread_to_high_pri_000a4098[5];
    tmp42[6] = s_Unable_to_set_thread_to_high_pri_000a4098[6];
    tmp42[7] = s_Unable_to_set_thread_to_high_pri_000a4098[7];
    tmp42[8] = s_Unable_to_set_thread_to_high_pri_000a4098[8];
    tmp42[9] = s_Unable_to_set_thread_to_high_pri_000a4098[9];
    tmp42[10] = s_Unable_to_set_thread_to_high_pri_000a4098[10];
    tmp42[11] = s_Unable_to_set_thread_to_high_pri_000a4098[11];
    tmp42[12] = s_Unable_to_set_thread_to_high_pri_000a4098[12];
    tmp42[13] = s_Unable_to_set_thread_to_high_pri_000a4098[13];
    tmp42[14] = s_Unable_to_set_thread_to_high_pri_000a4098[14];
    tmp42[15] = s_Unable_to_set_thread_to_high_pri_000a4098[15];
    tmp42[16] = s_Unable_to_set_thread_to_high_pri_000a4098[16];
    tmp42[17] = s_Unable_to_set_thread_to_high_pri_000a4098[17];
    tmp42[18] = s_Unable_to_set_thread_to_high_pri_000a4098[18];
    tmp42[19] = s_Unable_to_set_thread_to_high_pri_000a4098[19];
    tmp42[20] = s_Unable_to_set_thread_to_high_pri_000a4098[20];
    tmp42[21] = s_Unable_to_set_thread_to_high_pri_000a4098[21];
    tmp42[22] = s_Unable_to_set_thread_to_high_pri_000a4098[22];
    tmp42[23] = s_Unable_to_set_thread_to_high_pri_000a4098[23];
    tmp42[24] = s_Unable_to_set_thread_to_high_pri_000a4098[24];
    tmp42[25] = s_Unable_to_set_thread_to_high_pri_000a4098[25];
    tmp42[26] = s_Unable_to_set_thread_to_high_pri_000a4098[26];
    tmp42[27] = s_Unable_to_set_thread_to_high_pri_000a4098[27];
    tmp42[28] = s_Unable_to_set_thread_to_high_pri_000a4098[28];
    tmp42[29] = s_Unable_to_set_thread_to_high_pri_000a4098[29];
    tmp42[30] = s_Unable_to_set_thread_to_high_pri_000a4098[30];
    tmp42[31] = s_Unable_to_set_thread_to_high_pri_000a4098[31];
    tmp42[32] = s_Unable_to_set_thread_to_high_pri_000a4098[32];
    tmp42[33] = s_Unable_to_set_thread_to_high_pri_000a4098[33];
    tmp42[34] = s_Unable_to_set_thread_to_high_pri_000a4098[34];
    tmp42[35] = s_Unable_to_set_thread_to_high_pri_000a4098[35];
    tmp42._36_2_ = (undefined2)ram0x000a40bc;
    _applog(7,tmp42,false);
  }
  return;
}

