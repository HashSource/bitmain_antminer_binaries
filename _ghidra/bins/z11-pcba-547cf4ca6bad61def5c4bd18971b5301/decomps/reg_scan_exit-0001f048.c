
void reg_scan_exit(void)

{
  alive = 0;
  usleep(1500000);
  pthread_cancel(p_reg_scan);
  pthread_join(p_reg_scan,(void **)0x0);
  return;
}

