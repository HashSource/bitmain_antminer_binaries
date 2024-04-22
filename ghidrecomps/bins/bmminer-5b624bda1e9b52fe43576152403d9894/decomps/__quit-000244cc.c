
/* WARNING: Unknown calling convention */

void __quit(int status,_Bool clean)

{
  int iVar1;
  pthread_t killall_t;
  
  iVar1 = pthread_create(&killall_t,(pthread_attr_t *)0x0,DAT_00024514,(void *)0x0);
  if (iVar1 == 0) {
    if (clean) {
      clean_up(false);
    }
    iVar1 = DAT_00024518;
    if (0 < *(__pid_t *)(DAT_00024518 + 0x6cc)) {
      kill(*(__pid_t *)(DAT_00024518 + 0x6cc),0xf);
      *(undefined4 *)(iVar1 + 0x6cc) = 0;
    }
    pthread_cancel(killall_t);
                    /* WARNING: Subroutine does not return */
    exit(status);
  }
                    /* WARNING: Subroutine does not return */
  exit(1);
}

