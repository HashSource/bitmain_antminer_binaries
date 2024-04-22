
void set_lowprio(void)

{
  int iVar1;
  
  iVar1 = nice(10);
  if ((iVar1 == 0) && (((use_syslog != '\0' || (opt_log_output != '\0')) || (5 < opt_log_level)))) {
    set_lowprio_part_17();
    return;
  }
  return;
}

