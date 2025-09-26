
void create_new_log_file(char *test_type,char *sn,char *miner_type,char *board_name)

{
  __mode_t __mask;
  int iVar1;
  int *piVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *board_name_local;
  char *miner_type_local;
  char *sn_local;
  char *test_type_local;
  char file_path [128];
  char tmp42 [2048];
  char datetime [24];
  int res;
  mode_t old_mask;
  
  if (g_log_file == (FILE *)0x0) {
    get_format_time(datetime);
    __mask = umask(0);
    iVar1 = mkdir(LOG_DIR,0x1ff);
    umask(__mask);
    if (iVar1 != 0) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      snprintf(tmp42,0x800,"ERR:%s",pcVar3);
      _applog(2,tmp42,false);
    }
    memset(file_path,0,0x80);
    pcVar5 = datetime;
    pcVar3 = LOG_PREFIX_LOCAL;
    snprintf(file_path,0x80,"%s%s_%s_%s_%s_%s_%s",LOG_DIR,LOG_PREFIX_LOCAL,test_type,miner_type,
             board_name,sn,pcVar5);
    pcVar4 = get_test_type(file_path);
    if (pcVar4 == (char *)0x0) {
      builtin_strncpy(tmp42,"\nwarning:test type err,will not create test log file.\n\n",0x38);
      _applog(5,tmp42,false);
    }
    else {
      snprintf(tmp42,0x800,"new log_file:%s\n",file_path,pcVar3,test_type,miner_type,board_name,sn,
               pcVar5);
      _applog(5,tmp42,false);
      clear_unupload_logs();
      g_log_file = (FILE *)fopen(file_path,"a+");
      strcpy(g_cur_log_path,file_path);
    }
  }
  return;
}

