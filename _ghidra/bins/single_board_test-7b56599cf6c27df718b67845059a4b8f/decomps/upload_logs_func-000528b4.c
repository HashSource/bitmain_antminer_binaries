
void * upload_logs_func(void *arg)

{
  _Bool _Var1;
  int iVar2;
  bool bVar3;
  void *arg_local;
  char full_name [128];
  char uploaded_name [128];
  char logs [400] [128];
  _Bool is_cur_log_file;
  int log_cnt;
  int i;
  
  do {
    memset(logs,0,0xc800);
    i = refresh_log_list(logs,LOG_PREFIX_LOCAL);
    while (i = i + -1, -1 < i) {
      snprintf(full_name,0x80,"%s%s",LOG_DIR,logs + i);
      pthread_mutex_lock((pthread_mutex_t *)&upload_mutex);
      if ((g_cur_log_path[0] == '\0') ||
         (iVar2 = strncmp(g_cur_log_path,full_name,0x80), iVar2 != 0)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      pthread_mutex_unlock((pthread_mutex_t *)&upload_mutex);
      if ((!bVar3) && (_Var1 = upload_logs(full_name), _Var1)) {
        snprintf(uploaded_name,0x80,"%s%s_%s",LOG_DIR,LOG_PREFIX_UPLOADED,logs + i);
        rename(full_name,uploaded_name);
        clear_uploaded_logs();
      }
    }
    pthread_mutex_lock((pthread_mutex_t *)&upload_mutex);
    pthread_cond_wait((pthread_cond_t *)&upload_cond,(pthread_mutex_t *)&upload_mutex);
    pthread_mutex_unlock((pthread_mutex_t *)&upload_mutex);
  } while( true );
}

