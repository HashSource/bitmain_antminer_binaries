
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
        tmp42[0] = s_Standard_output_missing_for_shar_00071518[0];
        tmp42[1] = s_Standard_output_missing_for_shar_00071518[1];
        tmp42[2] = s_Standard_output_missing_for_shar_00071518[2];
        tmp42[3] = s_Standard_output_missing_for_shar_00071518[3];
        tmp42[4] = s_Standard_output_missing_for_shar_00071518[4];
        tmp42[5] = s_Standard_output_missing_for_shar_00071518[5];
        tmp42[6] = s_Standard_output_missing_for_shar_00071518[6];
        tmp42[7] = s_Standard_output_missing_for_shar_00071518[7];
        tmp42[8] = s_Standard_output_missing_for_shar_00071518[8];
        tmp42[9] = s_Standard_output_missing_for_shar_00071518[9];
        tmp42[10] = s_Standard_output_missing_for_shar_00071518[10];
        tmp42[11] = s_Standard_output_missing_for_shar_00071518[11];
        tmp42[12] = s_Standard_output_missing_for_shar_00071518[12];
        tmp42[13] = s_Standard_output_missing_for_shar_00071518[13];
        tmp42[14] = s_Standard_output_missing_for_shar_00071518[14];
        tmp42[15] = s_Standard_output_missing_for_shar_00071518[15];
        tmp42[16] = s_Standard_output_missing_for_shar_00071518[16];
        tmp42[17] = s_Standard_output_missing_for_shar_00071518[17];
        tmp42[18] = s_Standard_output_missing_for_shar_00071518[18];
        tmp42[19] = s_Standard_output_missing_for_shar_00071518[19];
        tmp42[20] = s_Standard_output_missing_for_shar_00071518[20];
        tmp42[21] = s_Standard_output_missing_for_shar_00071518[21];
        tmp42[22] = s_Standard_output_missing_for_shar_00071518[22];
        tmp42[23] = s_Standard_output_missing_for_shar_00071518[23];
        tmp42[24] = s_Standard_output_missing_for_shar_00071518[24];
        tmp42[25] = s_Standard_output_missing_for_shar_00071518[25];
        tmp42[26] = s_Standard_output_missing_for_shar_00071518[26];
        tmp42[27] = s_Standard_output_missing_for_shar_00071518[27];
        tmp42[28] = s_Standard_output_missing_for_shar_00071518[28];
        tmp42[29] = s_Standard_output_missing_for_shar_00071518[29];
        tmp42[30] = s_Standard_output_missing_for_shar_00071518[30];
        tmp42[31] = s_Standard_output_missing_for_shar_00071518[31];
        tmp42[32] = s_Standard_output_missing_for_shar_00071518[32];
        tmp42[33] = s_Standard_output_missing_for_shar_00071518[33];
        tmp42[34] = s_Standard_output_missing_for_shar_00071518[34];
        tmp42[35] = s_Standard_output_missing_for_shar_00071518[35];
        tmp42._36_2_ = (undefined2)ram0x0007153c;
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

