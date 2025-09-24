
void fork_once_func(void)

{
  __pthread_atfork((__prepare *)0x136321,(__parent *)0x136325,(__child *)0x136329);
  return;
}

