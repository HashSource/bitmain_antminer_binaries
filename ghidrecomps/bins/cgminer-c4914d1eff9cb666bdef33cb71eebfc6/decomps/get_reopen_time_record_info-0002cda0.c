
void get_reopen_time_record_info(char *infoStr)

{
  size_t sVar1;
  char *infoStr_local;
  uint32_t time_struct_size;
  uint32_t reopen_id;
  
  builtin_strncpy(infoStr,"reopen time:",0xd);
  if (re_open_core_times != 0) {
    sVar1 = strlen(reopen_time[0]);
    for (reopen_id = 0; reopen_id < re_open_core_times; reopen_id = reopen_id + 1) {
      sprintf(infoStr + reopen_id * (sVar1 + 5) + 0xc,"[%03d]%s,",reopen_id,reopen_time + reopen_id)
      ;
    }
  }
  return;
}

