
void __quit(int status,_Bool clean)

{
  int iVar1;
  _Bool clean_local;
  int status_local;
  pthread_t killall_t;
  
  iVar1 = pthread_create(&killall_t,(pthread_attr_t *)0x0,killall_thread + 1,(void *)0x0);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if (clean) {
    clean_up(false);
  }
  if (0 < forkpid) {
    kill(forkpid,0xf);
    forkpid = 0;
  }
  pthread_cancel(killall_t);
                    /* WARNING: Subroutine does not return */
  exit(status);
}

