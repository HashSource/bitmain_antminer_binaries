
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void re_send_last_job(void)

{
  if (last_job_buffer[0] == '\x17') {
    return;
  }
  pthread_mutex_lock((pthread_mutex_t *)&reinit_mutex);
  send_job(last_job_buffer);
  (*(code *)(undefined *)0x0)(&reinit_mutex);
  return;
}

