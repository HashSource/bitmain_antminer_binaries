
void re_send_last_job_part_15(void)

{
  pthread_mutex_lock((pthread_mutex_t *)reinit_mutex);
  send_job(last_job_buffer);
  pthread_mutex_unlock((pthread_mutex_t *)reinit_mutex);
  return;
}

