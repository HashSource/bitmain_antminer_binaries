
void re_send_last_job_part_15(void)

{
  pthread_mutex_t *ppVar1;
  
  ppVar1 = DAT_0003b21c;
  pthread_mutex_lock(DAT_0003b21c);
  send_job(DAT_0003b220);
  (*(code *)PTR_pthread_mutex_unlock_0007ce1c)(ppVar1);
  return;
}

