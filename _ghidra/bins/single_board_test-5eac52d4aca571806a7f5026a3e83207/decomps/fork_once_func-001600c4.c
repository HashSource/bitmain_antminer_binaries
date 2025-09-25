
void fork_once_func(void)

{
  __pthread_atfork((__prepare *)0x1320d1,(__parent *)0x1320d5,(__child *)0x1320d9);
  return;
}

