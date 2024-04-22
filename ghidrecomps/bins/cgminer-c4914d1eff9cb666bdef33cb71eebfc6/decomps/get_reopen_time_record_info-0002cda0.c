
void get_reopen_time_record_info(char *infoStr)

{
  undefined4 uVar1;
  undefined4 uVar2;
  size_t sVar3;
  char *infoStr_local;
  uint32_t time_struct_size;
  uint32_t reopen_id;
  
  uVar2 = s_reopen_time__000842b8._8_4_;
  uVar1 = s_reopen_time__000842b8._4_4_;
  *(undefined4 *)infoStr = s_reopen_time__000842b8._0_4_;
  *(undefined4 *)(infoStr + 4) = uVar1;
  *(undefined4 *)(infoStr + 8) = uVar2;
  infoStr[0xc] = s_reopen_time__000842b8[12];
  if (re_open_core_times != 0) {
    sVar3 = strlen(reopen_time[0]);
    for (reopen_id = 0; reopen_id < re_open_core_times; reopen_id = reopen_id + 1) {
      sprintf(infoStr + reopen_id * (sVar3 + 5) + 0xc,"[%03d]%s,",reopen_id,reopen_time + reopen_id)
      ;
    }
  }
  return;
}

