
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __kill_work(void)

{
  if (successful_connect) {
    __kill_work();
    return;
  }
  return;
}

