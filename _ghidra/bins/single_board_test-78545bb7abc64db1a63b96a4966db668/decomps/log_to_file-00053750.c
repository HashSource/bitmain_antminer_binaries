
void log_to_file(char *str,char *str_time)

{
  size_t sVar1;
  size_t sVar2;
  char *str_time_local;
  char *str_local;
  int size;
  
  if (g_log_file != (FILE *)0x0) {
    pthread_mutex_lock((pthread_mutex_t *)&file_mutex);
    snprintf(log_to_file::buff,0x3ff,"%s%s\n",str_time,str);
    sVar1 = strlen(log_to_file::buff);
    sVar1 = fwrite(log_to_file::buff,1,sVar1,(FILE *)g_log_file);
    fflush((FILE *)g_log_file);
    sVar2 = strlen(log_to_file::buff);
    if (sVar1 != sVar2) {
      sVar2 = strlen(log_to_file::buff);
      printf("warning:write log failed,write:%d,target:%d\n",sVar1,sVar2);
    }
    pthread_mutex_unlock((pthread_mutex_t *)&file_mutex);
  }
  return;
}

