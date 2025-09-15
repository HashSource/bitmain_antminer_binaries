
void x86_tty_close(void)

{
  char acStack_40c [1024];
  int local_c;
  
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_40c,0x400,"uart close %s\n",local_c * 0x20 + 0x47ed1);
      _applog(2,acStack_40c,0);
    }
    uart_close(*(undefined4 *)(g_chain + local_c * 0x20));
  }
  return;
}

