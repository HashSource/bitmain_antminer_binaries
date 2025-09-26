
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void submit_cur_log(void)

{
  char tmp42 [2048];
  
  snprintf(tmp42,0x800,"submit cur log:%s",g_cur_log_path);
  _applog(5,tmp42,false);
  pthread_mutex_lock((pthread_mutex_t *)&file_mutex);
  if (g_log_file != (FILE *)0x0) {
    fflush((FILE *)g_log_file);
    fclose((FILE *)g_log_file);
    g_log_file = (FILE *)0x0;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&file_mutex);
  builtin_strncpy(tmp42,"upload mutex signal.\n",0x16);
  _applog(5,tmp42,false);
  pthread_mutex_lock((pthread_mutex_t *)&upload_mutex);
  memset(g_cur_log_path,0,0x80);
  pthread_mutex_unlock((pthread_mutex_t *)&upload_mutex);
  pthread_cond_signal((pthread_cond_t *)&upload_cond);
  builtin_strncpy(tmp42,"upload mutex signal over",0x18);
  tmp42[0x18] = '\n';
  tmp42[0x19] = '\0';
  _applog(5,tmp42,false);
  return;
}

