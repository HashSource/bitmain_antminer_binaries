
void read_temp_func_clean_up(void *arg)

{
  void *arg_local;
  
  pthread_mutex_unlock((pthread_mutex_t *)&reopen_core);
  return;
}

