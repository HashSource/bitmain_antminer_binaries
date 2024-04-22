
/* WARNING: Unknown calling convention */

void sighandler(int sig)

{
  sigaction(0xf,(sigaction *)&termhandler,(sigaction *)0x0);
  sigaction(2,(sigaction *)&inthandler,(sigaction *)0x0);
  sigaction(6,(sigaction *)&abrthandler,(sigaction *)0x0);
  kill_work();
  return;
}

