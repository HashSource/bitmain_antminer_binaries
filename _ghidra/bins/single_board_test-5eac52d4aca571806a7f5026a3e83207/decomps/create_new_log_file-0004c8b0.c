
void create_new_log_file(char *test_type,char *sn,char *miner_type,char *board_name)

{
  __mode_t __mask;
  char *pcVar1;
  char *board_name_local;
  char *miner_type_local;
  char *sn_local;
  char *test_type_local;
  char file_path [128];
  char datetime [24];
  int res;
  mode_t old_mask;
  
  if (g_log_file == (FILE *)0x0) {
    get_format_time(datetime);
    __mask = umask(0);
    mkdir(LOG_DIR,0x1ff);
    umask(__mask);
    memset(file_path,0,0x80);
    snprintf(file_path,0x80,"%s%s_%s_%s_%s_%s_%s",LOG_DIR,LOG_PREFIX_LOCAL,test_type,miner_type,
             board_name,sn,datetime);
    pcVar1 = get_test_type(file_path);
    if (pcVar1 != (char *)0x0) {
      clear_unupload_logs();
      g_log_file = (FILE *)fopen(file_path,"a+");
      strcpy(g_cur_log_path,file_path);
    }
  }
  return;
}

