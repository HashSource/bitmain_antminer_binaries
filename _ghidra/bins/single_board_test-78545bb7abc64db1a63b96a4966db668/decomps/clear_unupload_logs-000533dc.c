
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void clear_unupload_logs(void)

{
  char full_name [128];
  char logs [400] [128];
  int i;
  int log_cnt;
  
  memset(logs,0,0xc800);
  i = refresh_log_list(logs,LOG_PREFIX_LOCAL);
  if (200 < i) {
    while (i = i + -1, 199 < i) {
      snprintf(full_name,0x80,"%s%s",LOG_DIR,logs + i);
      remove(full_name);
      unlink(full_name);
    }
  }
  return;
}

