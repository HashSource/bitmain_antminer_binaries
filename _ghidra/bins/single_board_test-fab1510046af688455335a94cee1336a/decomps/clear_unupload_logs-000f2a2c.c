
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void clear_unupload_logs(void)

{
  char full_name [128];
  char tmp42 [2048];
  char logs [96] [128];
  int i;
  int log_cnt;
  
  memset(logs,0,0x3000);
  i = refresh_log_list(logs,LOG_PREFIX_LOCAL);
  if (0x30 < i) {
    while (i = i + -1, 0x2f < i) {
      snprintf(full_name,0x80,"%s%s",LOG_DIR,logs + i);
      remove(full_name);
      unlink(full_name);
      snprintf(tmp42,0x800,"remove file:%s\n",full_name);
      _applog(5,tmp42,false);
    }
  }
  return;
}

