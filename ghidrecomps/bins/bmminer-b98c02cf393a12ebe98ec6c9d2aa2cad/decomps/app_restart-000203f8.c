
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void app_restart(void)

{
  undefined4 local_810;
  undefined4 uStack_80c;
  undefined4 uStack_808;
  undefined4 uStack_804;
  undefined4 local_800;
  undefined4 uStack_7fc;
  undefined4 uStack_7f8;
  undefined2 local_7f4;
  
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
    snprintf((char *)&local_810,0x800,"Attempting to restart %s",DAT_000204d0);
    _applog(4,&local_810,0);
  }
  cg_completion_timeout(0x20795,0,5000);
  clean_up(1);
  if (0 < forkpid) {
    kill(forkpid,0xf);
    forkpid = 0;
  }
  execv(*initial_args,initial_args);
  if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 4)) {
    return;
  }
  local_810._0_1_ = s_Failed_to_restart_application_0005d2a4[0];
  local_810._1_1_ = s_Failed_to_restart_application_0005d2a4[1];
  local_810._2_1_ = s_Failed_to_restart_application_0005d2a4[2];
  local_810._3_1_ = s_Failed_to_restart_application_0005d2a4[3];
  uStack_80c._0_1_ = s_Failed_to_restart_application_0005d2a4[4];
  uStack_80c._1_1_ = s_Failed_to_restart_application_0005d2a4[5];
  uStack_80c._2_1_ = s_Failed_to_restart_application_0005d2a4[6];
  uStack_80c._3_1_ = s_Failed_to_restart_application_0005d2a4[7];
  uStack_808._0_1_ = s_Failed_to_restart_application_0005d2a4[8];
  uStack_808._1_1_ = s_Failed_to_restart_application_0005d2a4[9];
  uStack_808._2_1_ = s_Failed_to_restart_application_0005d2a4[10];
  uStack_808._3_1_ = s_Failed_to_restart_application_0005d2a4[11];
  uStack_804._0_1_ = s_Failed_to_restart_application_0005d2a4[12];
  uStack_804._1_1_ = s_Failed_to_restart_application_0005d2a4[13];
  uStack_804._2_1_ = s_Failed_to_restart_application_0005d2a4[14];
  uStack_804._3_1_ = s_Failed_to_restart_application_0005d2a4[15];
  local_800._0_1_ = s_Failed_to_restart_application_0005d2a4[16];
  local_800._1_1_ = s_Failed_to_restart_application_0005d2a4[17];
  local_800._2_1_ = s_Failed_to_restart_application_0005d2a4[18];
  local_800._3_1_ = s_Failed_to_restart_application_0005d2a4[19];
  uStack_7fc._0_1_ = s_Failed_to_restart_application_0005d2a4[20];
  uStack_7fc._1_1_ = s_Failed_to_restart_application_0005d2a4[21];
  uStack_7fc._2_1_ = s_Failed_to_restart_application_0005d2a4[22];
  uStack_7fc._3_1_ = s_Failed_to_restart_application_0005d2a4[23];
  uStack_7f8._0_1_ = s_Failed_to_restart_application_0005d2a4[24];
  uStack_7f8._1_1_ = s_Failed_to_restart_application_0005d2a4[25];
  uStack_7f8._2_1_ = s_Failed_to_restart_application_0005d2a4[26];
  uStack_7f8._3_1_ = s_Failed_to_restart_application_0005d2a4[27];
  local_7f4 = (undefined2)ram0x0005d2c0;
  _applog(4,&local_810,0);
  return;
}

