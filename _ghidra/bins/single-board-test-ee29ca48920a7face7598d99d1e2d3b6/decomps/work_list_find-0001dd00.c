
void work_list_find(char param_1,void *param_2)

{
  int local_c;
  
  pthread_mutex_lock((pthread_mutex_t *)g_work_list_mutex);
  local_c = 0;
  do {
    if (9 < local_c) {
LAB_0001dd64:
      pthread_mutex_unlock((pthread_mutex_t *)g_work_list_mutex);
      return;
    }
    if (param_1 == g_work_list[local_c * 0x8d]) {
      memcpy(param_2,g_work_list + local_c * 0x8d + 1,0x8c);
      goto LAB_0001dd64;
    }
    local_c = local_c + 1;
  } while( true );
}

