
/* WARNING: Unknown calling convention */

void __quit(int status,_Bool clean)

{
  int iVar1;
  pthread_t local_14 [2];
  
  iVar1 = pthread_create(local_14,(pthread_attr_t *)0x0,(__start_routine *)0x1e1b5,(void *)0x0);
  if (iVar1 == 0) {
    if (clean) {
      clean_up(false);
    }
    if (0 < forkpid) {
      kill(forkpid,0xf);
      forkpid = 0;
    }
    pthread_cancel(local_14[0]);
                    /* WARNING: Subroutine does not return */
    exit(status);
  }
                    /* WARNING: Subroutine does not return */
  exit(1);
}

