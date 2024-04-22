
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void set_lowprio(void)

{
  int iVar1;
  char tmp42 [2048];
  int ret;
  
  iVar1 = nice(10);
  if ((iVar1 == 0) && (((use_syslog != false || (opt_log_output != false)) || (5 < opt_log_level))))
  {
    tmp42[0] = s_Unable_to_set_thread_to_low_prio_000734cc[0];
    tmp42[1] = s_Unable_to_set_thread_to_low_prio_000734cc[1];
    tmp42[2] = s_Unable_to_set_thread_to_low_prio_000734cc[2];
    tmp42[3] = s_Unable_to_set_thread_to_low_prio_000734cc[3];
    tmp42[4] = s_Unable_to_set_thread_to_low_prio_000734cc[4];
    tmp42[5] = s_Unable_to_set_thread_to_low_prio_000734cc[5];
    tmp42[6] = s_Unable_to_set_thread_to_low_prio_000734cc[6];
    tmp42[7] = s_Unable_to_set_thread_to_low_prio_000734cc[7];
    tmp42[8] = s_Unable_to_set_thread_to_low_prio_000734cc[8];
    tmp42[9] = s_Unable_to_set_thread_to_low_prio_000734cc[9];
    tmp42[10] = s_Unable_to_set_thread_to_low_prio_000734cc[10];
    tmp42[11] = s_Unable_to_set_thread_to_low_prio_000734cc[11];
    tmp42[12] = s_Unable_to_set_thread_to_low_prio_000734cc[12];
    tmp42[13] = s_Unable_to_set_thread_to_low_prio_000734cc[13];
    tmp42[14] = s_Unable_to_set_thread_to_low_prio_000734cc[14];
    tmp42[15] = s_Unable_to_set_thread_to_low_prio_000734cc[15];
    tmp42[16] = s_Unable_to_set_thread_to_low_prio_000734cc[16];
    tmp42[17] = s_Unable_to_set_thread_to_low_prio_000734cc[17];
    tmp42[18] = s_Unable_to_set_thread_to_low_prio_000734cc[18];
    tmp42[19] = s_Unable_to_set_thread_to_low_prio_000734cc[19];
    tmp42[20] = s_Unable_to_set_thread_to_low_prio_000734cc[20];
    tmp42[21] = s_Unable_to_set_thread_to_low_prio_000734cc[21];
    tmp42[22] = s_Unable_to_set_thread_to_low_prio_000734cc[22];
    tmp42[23] = s_Unable_to_set_thread_to_low_prio_000734cc[23];
    tmp42[24] = s_Unable_to_set_thread_to_low_prio_000734cc[24];
    tmp42[25] = s_Unable_to_set_thread_to_low_prio_000734cc[25];
    tmp42[26] = s_Unable_to_set_thread_to_low_prio_000734cc[26];
    tmp42[27] = s_Unable_to_set_thread_to_low_prio_000734cc[27];
    tmp42[28] = s_Unable_to_set_thread_to_low_prio_000734cc[28];
    tmp42[29] = s_Unable_to_set_thread_to_low_prio_000734cc[29];
    tmp42[30] = s_Unable_to_set_thread_to_low_prio_000734cc[30];
    tmp42[31] = s_Unable_to_set_thread_to_low_prio_000734cc[31];
    tmp42[32] = s_Unable_to_set_thread_to_low_prio_000734cc[32];
    tmp42[33] = s_Unable_to_set_thread_to_low_prio_000734cc[33];
    tmp42[34] = s_Unable_to_set_thread_to_low_prio_000734cc[34];
    tmp42[35] = s_Unable_to_set_thread_to_low_prio_000734cc[35];
    tmp42[36] = (char)ram0x000734f0;
    _applog(6,tmp42,false);
  }
  return;
}

