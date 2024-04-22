
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_init(pthread_rwlock_t *__rwlock,pthread_rwlockattr_t *__attr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* pthread_rwlock_init@@GLIBC_2.4 */
  halt_baddata();
}

