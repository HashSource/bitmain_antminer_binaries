
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 set_sharelog(char *param_1)

{
  char *__fd;
  char *__format;
  bool bVar1;
  char *local_814;
  undefined4 local_810;
  undefined4 uStack_80c;
  undefined4 uStack_808;
  undefined4 uStack_804;
  undefined4 local_800;
  undefined4 uStack_7fc;
  undefined4 uStack_7f8;
  undefined4 uStack_7f4;
  undefined4 uStack_7f0;
  undefined2 local_7ec;
  
  local_814 = "";
  __fd = (char *)strtol(param_1,&local_814,10);
  bVar1 = __fd == (char *)0x0;
  if (-1 < (int)__fd) {
    bVar1 = *local_814 == '\0';
  }
  if (bVar1) {
    sharelog_file = fdopen((int)__fd,"a");
    if (sharelog_file != (FILE *)0x0) {
      return 0;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
      return 0;
    }
    __format = "Failed to open fd %u for share log";
    param_1 = __fd;
  }
  else {
    if ((*param_1 == '-') && (param_1[1] == '\0')) {
      sharelog_file = (FILE *)stdout;
      if (stdout != 0) {
        sharelog_file = (FILE *)stdout;
        return 0;
      }
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
        sharelog_file = (FILE *)stdout;
        return 0;
      }
      local_810._0_1_ = s_Standard_output_missing_for_shar_0005c2ec[0];
      local_810._1_1_ = s_Standard_output_missing_for_shar_0005c2ec[1];
      local_810._2_1_ = s_Standard_output_missing_for_shar_0005c2ec[2];
      local_810._3_1_ = s_Standard_output_missing_for_shar_0005c2ec[3];
      uStack_80c._0_1_ = s_Standard_output_missing_for_shar_0005c2ec[4];
      uStack_80c._1_1_ = s_Standard_output_missing_for_shar_0005c2ec[5];
      uStack_80c._2_1_ = s_Standard_output_missing_for_shar_0005c2ec[6];
      uStack_80c._3_1_ = s_Standard_output_missing_for_shar_0005c2ec[7];
      uStack_808._0_1_ = s_Standard_output_missing_for_shar_0005c2ec[8];
      uStack_808._1_1_ = s_Standard_output_missing_for_shar_0005c2ec[9];
      uStack_808._2_1_ = s_Standard_output_missing_for_shar_0005c2ec[10];
      uStack_808._3_1_ = s_Standard_output_missing_for_shar_0005c2ec[11];
      uStack_804._0_1_ = s_Standard_output_missing_for_shar_0005c2ec[12];
      uStack_804._1_1_ = s_Standard_output_missing_for_shar_0005c2ec[13];
      uStack_804._2_1_ = s_Standard_output_missing_for_shar_0005c2ec[14];
      uStack_804._3_1_ = s_Standard_output_missing_for_shar_0005c2ec[15];
      local_800._0_1_ = s_Standard_output_missing_for_shar_0005c2ec[16];
      local_800._1_1_ = s_Standard_output_missing_for_shar_0005c2ec[17];
      local_800._2_1_ = s_Standard_output_missing_for_shar_0005c2ec[18];
      local_800._3_1_ = s_Standard_output_missing_for_shar_0005c2ec[19];
      uStack_7fc._0_1_ = s_Standard_output_missing_for_shar_0005c2ec[20];
      uStack_7fc._1_1_ = s_Standard_output_missing_for_shar_0005c2ec[21];
      uStack_7fc._2_1_ = s_Standard_output_missing_for_shar_0005c2ec[22];
      uStack_7fc._3_1_ = s_Standard_output_missing_for_shar_0005c2ec[23];
      uStack_7f8._0_1_ = s_Standard_output_missing_for_shar_0005c2ec[24];
      uStack_7f8._1_1_ = s_Standard_output_missing_for_shar_0005c2ec[25];
      uStack_7f8._2_1_ = s_Standard_output_missing_for_shar_0005c2ec[26];
      uStack_7f8._3_1_ = s_Standard_output_missing_for_shar_0005c2ec[27];
      uStack_7f4._0_1_ = s_Standard_output_missing_for_shar_0005c2ec[28];
      uStack_7f4._1_1_ = s_Standard_output_missing_for_shar_0005c2ec[29];
      uStack_7f4._2_1_ = s_Standard_output_missing_for_shar_0005c2ec[30];
      uStack_7f4._3_1_ = s_Standard_output_missing_for_shar_0005c2ec[31];
      uStack_7f0._0_1_ = s_Standard_output_missing_for_shar_0005c2ec[32];
      uStack_7f0._1_1_ = s_Standard_output_missing_for_shar_0005c2ec[33];
      uStack_7f0._2_1_ = s_Standard_output_missing_for_shar_0005c2ec[34];
      uStack_7f0._3_1_ = s_Standard_output_missing_for_shar_0005c2ec[35];
      local_7ec = (undefined2)ram0x0005c310;
      _applog(3,&local_810,0);
      return 0;
    }
    sharelog_file = fopen(param_1,"a");
    if (sharelog_file != (FILE *)0x0) {
      return 0;
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
      return 0;
    }
    __format = "Failed to open %s for share log";
  }
  sharelog_file = (FILE *)0x0;
  snprintf((char *)&local_810,0x800,__format,param_1);
  _applog(3,&local_810,0);
  return 0;
}

