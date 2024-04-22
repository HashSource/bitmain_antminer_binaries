
void bm1744_app_exit(void)

{
  char acStack_40c [1024];
  int local_c;
  
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_40c,0x400,"%s\n","bm1744_app_exit");
    _applog(2,acStack_40c,0);
  }
  reg_scan_exit();
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    pthread_cancel(*(pthread_t *)(g_chain + local_c * 0x20 + 0x18));
    pthread_join(*(pthread_t *)(g_chain + local_c * 0x20 + 0x18),(void **)0x0);
  }
  pthread_cancel(p_scanhash);
  pthread_join(p_scanhash,(void **)0x0);
  return;
}

