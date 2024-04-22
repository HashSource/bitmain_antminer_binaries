
void reg_scan_exit(void)

{
  pthread_cancel(p_reg_scan);
  pthread_join(p_reg_scan,(void **)0x0);
  pthread_mutex_destroy((pthread_mutex_t *)reg_scan_mutex);
  return;
}

