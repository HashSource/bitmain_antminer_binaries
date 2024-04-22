
void __quit(int param_1,int param_2)

{
  int iVar1;
  pthread_t local_c [3];
  
  iVar1 = pthread_create(local_c,(pthread_attr_t *)0x0,killall_thread + 1,(void *)0x0);
  if (iVar1 == 0) {
    if (param_2 != 0) {
      clean_up();
    }
    if (0 < forkpid) {
      kill(forkpid,0xf);
      forkpid = 0;
    }
    pthread_cancel(local_c[0]);
                    /* WARNING: Subroutine does not return */
    exit(param_1);
  }
                    /* WARNING: Subroutine does not return */
  exit(1);
}

