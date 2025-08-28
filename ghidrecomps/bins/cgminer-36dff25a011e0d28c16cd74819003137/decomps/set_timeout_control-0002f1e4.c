
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_timeout_control(void)

{
  if (opt_multi_version == 0) {
    set_time_out_control(dev->timeout * 10 & 0x1fffe | 0x80000000);
  }
  else {
    set_time_out_control(dev->timeout * 10 & 0x1fffe | 0x80000000);
  }
  return;
}

