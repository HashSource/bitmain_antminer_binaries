
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sem_timedwait(sem_t *__sem,timespec *__abstime)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* sem_timedwait@@GLIBC_2.4 */
  halt_baddata();
}

