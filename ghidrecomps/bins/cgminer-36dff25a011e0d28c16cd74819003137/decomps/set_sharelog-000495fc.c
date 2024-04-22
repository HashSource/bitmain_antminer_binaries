
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char * set_sharelog(char *arg)

{
  int iVar1;
  char *arg_local;
  char tmp42 [2048];
  char *r;
  long i;
  
  r = "";
  i = strtol(arg,&r,10);
  if ((*r == '\0') && (-1 < i)) {
    sharelog_file = (FILE *)fdopen(i,"a");
    if ((sharelog_file == (FILE *)0x0) &&
       (((use_syslog != false || (opt_log_output != false)) || (2 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Failed to open fd %u for share log",i);
      _applog(3,tmp42,false);
    }
  }
  else {
    iVar1 = strcmp(arg,"-");
    if (iVar1 == 0) {
      sharelog_file = stdout;
      if ((stdout == (FILE *)0x0) &&
         (((use_syslog != false || (opt_log_output != false)) || (2 < opt_log_level)))) {
        tmp42[0] = s_Standard_output_missing_for_shar_000a1fdc[0];
        tmp42[1] = s_Standard_output_missing_for_shar_000a1fdc[1];
        tmp42[2] = s_Standard_output_missing_for_shar_000a1fdc[2];
        tmp42[3] = s_Standard_output_missing_for_shar_000a1fdc[3];
        tmp42[4] = s_Standard_output_missing_for_shar_000a1fdc[4];
        tmp42[5] = s_Standard_output_missing_for_shar_000a1fdc[5];
        tmp42[6] = s_Standard_output_missing_for_shar_000a1fdc[6];
        tmp42[7] = s_Standard_output_missing_for_shar_000a1fdc[7];
        tmp42[8] = s_Standard_output_missing_for_shar_000a1fdc[8];
        tmp42[9] = s_Standard_output_missing_for_shar_000a1fdc[9];
        tmp42[10] = s_Standard_output_missing_for_shar_000a1fdc[10];
        tmp42[11] = s_Standard_output_missing_for_shar_000a1fdc[11];
        tmp42[12] = s_Standard_output_missing_for_shar_000a1fdc[12];
        tmp42[13] = s_Standard_output_missing_for_shar_000a1fdc[13];
        tmp42[14] = s_Standard_output_missing_for_shar_000a1fdc[14];
        tmp42[15] = s_Standard_output_missing_for_shar_000a1fdc[15];
        tmp42[16] = s_Standard_output_missing_for_shar_000a1fdc[16];
        tmp42[17] = s_Standard_output_missing_for_shar_000a1fdc[17];
        tmp42[18] = s_Standard_output_missing_for_shar_000a1fdc[18];
        tmp42[19] = s_Standard_output_missing_for_shar_000a1fdc[19];
        tmp42[20] = s_Standard_output_missing_for_shar_000a1fdc[20];
        tmp42[21] = s_Standard_output_missing_for_shar_000a1fdc[21];
        tmp42[22] = s_Standard_output_missing_for_shar_000a1fdc[22];
        tmp42[23] = s_Standard_output_missing_for_shar_000a1fdc[23];
        tmp42[24] = s_Standard_output_missing_for_shar_000a1fdc[24];
        tmp42[25] = s_Standard_output_missing_for_shar_000a1fdc[25];
        tmp42[26] = s_Standard_output_missing_for_shar_000a1fdc[26];
        tmp42[27] = s_Standard_output_missing_for_shar_000a1fdc[27];
        tmp42[28] = s_Standard_output_missing_for_shar_000a1fdc[28];
        tmp42[29] = s_Standard_output_missing_for_shar_000a1fdc[29];
        tmp42[30] = s_Standard_output_missing_for_shar_000a1fdc[30];
        tmp42[31] = s_Standard_output_missing_for_shar_000a1fdc[31];
        tmp42[32] = s_Standard_output_missing_for_shar_000a1fdc[32];
        tmp42[33] = s_Standard_output_missing_for_shar_000a1fdc[33];
        tmp42[34] = s_Standard_output_missing_for_shar_000a1fdc[34];
        tmp42[35] = s_Standard_output_missing_for_shar_000a1fdc[35];
        tmp42._36_2_ = (undefined2)ram0x000a2000;
        _applog(3,tmp42,false);
      }
    }
    else {
      sharelog_file = (FILE *)fopen(arg,"a");
      if ((sharelog_file == (FILE *)0x0) &&
         (((use_syslog != false || (opt_log_output != false)) || (2 < opt_log_level)))) {
        snprintf(tmp42,0x800,"Failed to open %s for share log",arg);
        _applog(3,tmp42,false);
      }
    }
  }
  return (char *)0x0;
}

