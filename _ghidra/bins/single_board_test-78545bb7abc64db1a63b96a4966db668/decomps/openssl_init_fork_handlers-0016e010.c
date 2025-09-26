
bool openssl_init_fork_handlers(void)

{
  int iVar1;
  
  iVar1 = pthread_once((pthread_once_t *)&fork_once_control,(__init_routine *)0x16deed);
  return iVar1 == 0;
}

