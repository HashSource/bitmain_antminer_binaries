
void work_list_insert(undefined param_1,void *param_2)

{
  pthread_mutex_lock((pthread_mutex_t *)g_work_list_mutex);
  g_work_list[g_work_list_insert_index * 0x8d] = param_1;
  memcpy(g_work_list + g_work_list_insert_index * 0x8d + 1,param_2,0x8c);
  g_work_list_insert_index = g_work_list_insert_index + 1;
  if (9 < g_work_list_insert_index) {
    g_work_list_insert_index = 0;
  }
  pthread_mutex_unlock((pthread_mutex_t *)g_work_list_mutex);
  return;
}

