
void sighandler(int sig)

{
  int sig_local;
  char time_stamp [48];
  char tmp1 [256];
  
  sigaction(0xf,(sigaction *)&termhandler,(sigaction *)0x0);
  sigaction(2,(sigaction *)&inthandler,(sigaction *)0x0);
  sigaction(6,(sigaction *)&abrthandler,(sigaction *)0x0);
  sigaction(0xb,(sigaction *)&abrthandler,(sigaction *)0x0);
  sigaction(4,(sigaction *)&abrthandler,(sigaction *)0x0);
  sigaction(8,(sigaction *)&abrthandler,(sigaction *)0x0);
  printf("sig:%d",sig);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : sig:%d\n","sighandler",sig);
  snprintf(tmp1,0x100,"sig:%d",sig);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : sighandler power off hashboard\n","sighandler");
  builtin_strncpy(tmp1,"sighandler power off hashboa",0x1c);
  tmp1[0x1c] = 'r';
  tmp1[0x1d] = 'd';
  tmp1[0x1e] = '\0';
  log_to_file(tmp1,time_stamp);
  bitmain_power_off();
                    /* WARNING: Subroutine does not return */
  exit(0);
}

