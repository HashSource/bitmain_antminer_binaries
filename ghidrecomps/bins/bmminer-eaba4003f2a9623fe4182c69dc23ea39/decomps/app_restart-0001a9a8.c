
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void app_restart(void)

{
  char tmp42 [2048];
  
  if (((use_syslog) || (opt_log_output)) || (3 < opt_log_level)) {
    snprintf(tmp42,0x800,"Attempting to restart %s",packagename);
    _applog(4,tmp42,false);
  }
  cg_completion_timeout(__kill_work + 1,(void *)0x0,5000);
  clean_up(true);
  if (0 < forkpid) {
    kill(forkpid,0xf);
    forkpid = 0;
  }
  execv(*initial_args,initial_args);
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    tmp42[0] = s_Failed_to_restart_application_00072ee8[0];
    tmp42[1] = s_Failed_to_restart_application_00072ee8[1];
    tmp42[2] = s_Failed_to_restart_application_00072ee8[2];
    tmp42[3] = s_Failed_to_restart_application_00072ee8[3];
    tmp42[4] = s_Failed_to_restart_application_00072ee8[4];
    tmp42[5] = s_Failed_to_restart_application_00072ee8[5];
    tmp42[6] = s_Failed_to_restart_application_00072ee8[6];
    tmp42[7] = s_Failed_to_restart_application_00072ee8[7];
    tmp42[8] = s_Failed_to_restart_application_00072ee8[8];
    tmp42[9] = s_Failed_to_restart_application_00072ee8[9];
    tmp42[10] = s_Failed_to_restart_application_00072ee8[10];
    tmp42[11] = s_Failed_to_restart_application_00072ee8[11];
    tmp42[12] = s_Failed_to_restart_application_00072ee8[12];
    tmp42[13] = s_Failed_to_restart_application_00072ee8[13];
    tmp42[14] = s_Failed_to_restart_application_00072ee8[14];
    tmp42[15] = s_Failed_to_restart_application_00072ee8[15];
    tmp42[16] = s_Failed_to_restart_application_00072ee8[16];
    tmp42[17] = s_Failed_to_restart_application_00072ee8[17];
    tmp42[18] = s_Failed_to_restart_application_00072ee8[18];
    tmp42[19] = s_Failed_to_restart_application_00072ee8[19];
    tmp42[20] = s_Failed_to_restart_application_00072ee8[20];
    tmp42[21] = s_Failed_to_restart_application_00072ee8[21];
    tmp42[22] = s_Failed_to_restart_application_00072ee8[22];
    tmp42[23] = s_Failed_to_restart_application_00072ee8[23];
    tmp42[24] = s_Failed_to_restart_application_00072ee8[24];
    tmp42[25] = s_Failed_to_restart_application_00072ee8[25];
    tmp42[26] = s_Failed_to_restart_application_00072ee8[26];
    tmp42[27] = s_Failed_to_restart_application_00072ee8[27];
    tmp42._28_2_ = (undefined2)ram0x00072f04;
    _applog(4,tmp42,false);
  }
  return;
}

