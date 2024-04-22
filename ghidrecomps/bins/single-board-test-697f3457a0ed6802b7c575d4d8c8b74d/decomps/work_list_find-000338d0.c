
void work_list_find(uint8_t workid,uint8_t *work)

{
  uint8_t *work_local;
  uint8_t workid_local;
  int i;
  
  pthread_mutex_lock(DAT_0003393c);
  i = 0;
  do {
    if (9 < i) {
LAB_0003392c:
      pthread_mutex_unlock(DAT_0003393c);
      return;
    }
    if (workid == work_list_info.work_list[i].workid) {
      memcpy(work,work_list_info.work_list[i].work,work_list_info.work_len);
      goto LAB_0003392c;
    }
    i = i + 1;
  } while( true );
}

