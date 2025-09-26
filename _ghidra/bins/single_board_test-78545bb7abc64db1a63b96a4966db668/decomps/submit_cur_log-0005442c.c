
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void submit_cur_log(void)

{
  pthread_mutex_lock((pthread_mutex_t *)&file_mutex);
  if (g_log_file != (FILE *)0x0) {
    fflush((FILE *)g_log_file);
    fclose((FILE *)g_log_file);
    g_log_file = (FILE *)0x0;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&file_mutex);
  pthread_mutex_lock((pthread_mutex_t *)&upload_mutex);
  memset(g_cur_log_path,0,0x80);
  pthread_mutex_unlock((pthread_mutex_t *)&upload_mutex);
  pthread_cond_signal((pthread_cond_t *)&upload_cond);
  return;
}

