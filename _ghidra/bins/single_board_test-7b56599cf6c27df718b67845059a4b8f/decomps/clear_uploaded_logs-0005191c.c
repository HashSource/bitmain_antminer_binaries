
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void clear_uploaded_logs(void)

{
  char full_name [128];
  char logs [200] [128];
  int i;
  int log_cnt;
  
  memset(logs,0,0x6400);
  i = refresh_log_list(logs,LOG_PREFIX_UPLOADED);
  if (100 < i) {
    while (i = i + -1, 99 < i) {
      snprintf(full_name,0x80,"%s%s",LOG_DIR,logs + i);
      remove(full_name);
      unlink(full_name);
    }
  }
  return;
}

