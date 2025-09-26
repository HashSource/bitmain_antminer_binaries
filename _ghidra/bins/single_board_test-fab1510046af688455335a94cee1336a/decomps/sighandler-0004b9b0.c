
void sighandler(int sig)

{
  int sig_local;
  char time_stamp [48];
  char tmp1 [2048];
  
  sigaction(0xf,(sigaction *)&termhandler,(sigaction *)0x0);
  sigaction(2,(sigaction *)&inthandler,(sigaction *)0x0);
  sigaction(6,(sigaction *)&abrthandler,(sigaction *)0x0);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: sighandler power off hashboard singal is %d\n","sighandler",sig);
  snprintf(tmp1,0x800,"sighandler power off hashboard singal is %d",sig);
  log_to_file(tmp1,time_stamp);
  bitmain_power_off();
                    /* WARNING: Subroutine does not return */
  exit(0);
}

