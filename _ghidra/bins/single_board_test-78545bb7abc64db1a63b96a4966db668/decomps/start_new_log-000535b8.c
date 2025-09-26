
void start_new_log(char *test_type,char *sn,char *miner_type,char *board_name)

{
  char *board_name_local;
  char *miner_type_local;
  char *sn_local;
  char *test_type_local;
  
  pthread_mutex_lock((pthread_mutex_t *)&file_mutex);
  if (g_log_file != (FILE *)0x0) {
    fflush((FILE *)g_log_file);
    fclose((FILE *)g_log_file);
    g_log_file = (FILE *)0x0;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&file_mutex);
  pthread_mutex_lock((pthread_mutex_t *)&upload_mutex);
  memset(g_cur_log_path,0,0x80);
  create_new_log_file(test_type,sn,miner_type,board_name);
  pthread_mutex_unlock((pthread_mutex_t *)&upload_mutex);
  pthread_cond_signal((pthread_cond_t *)&upload_cond);
  return;
}

