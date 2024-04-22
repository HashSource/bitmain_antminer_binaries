
/* WARNING: Unknown calling convention */

void re_send_last_job(void)

{
  if (last_job_buffer[0] != '\x17') {
    pthread_mutex_lock((pthread_mutex_t *)&reinit_mutex);
    pthread_mutex_unlock((pthread_mutex_t *)&reinit_mutex);
  }
  return;
}

