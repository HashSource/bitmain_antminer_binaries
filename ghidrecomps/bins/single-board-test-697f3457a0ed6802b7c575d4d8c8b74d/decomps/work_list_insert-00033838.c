
void work_list_insert(uint8_t workid,uint8_t *work)

{
  uint8_t *work_local;
  uint8_t workid_local;
  
  pthread_mutex_lock(DAT_000338cc);
  work_list_info.work_list[work_list_info.work_list_insert_index].workid = workid;
  memcpy(work_list_info.work_list[work_list_info.work_list_insert_index].work,work,
         work_list_info.work_len);
  work_list_info.work_list_insert_index = work_list_info.work_list_insert_index + 1;
  if (9 < work_list_info.work_list_insert_index) {
    work_list_info.work_list_insert_index = 0;
  }
  pthread_mutex_unlock(DAT_000338cc);
  return;
}

