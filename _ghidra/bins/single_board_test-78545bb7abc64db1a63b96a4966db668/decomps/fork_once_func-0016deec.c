
void fork_once_func(void)

{
  __pthread_atfork((__prepare *)0x13fef9,(__parent *)0x13fefd,(__child *)0x13ff01);
  return;
}

