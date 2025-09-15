
void sighandler(int sig)

{
  int sig_local;
  
  sigaction(0xf,(sigaction *)&termhandler,(sigaction *)0x0);
  sigaction(2,(sigaction *)&inthandler,(sigaction *)0x0);
  sigaction(6,(sigaction *)&abrthandler,(sigaction *)0x0);
  kill_work();
  return;
}

