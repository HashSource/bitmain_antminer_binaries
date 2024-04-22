
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_setschedparam(pthread_t __target_thread,int __policy,sched_param *__param)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* pthread_setschedparam@@GLIBC_2.4 */
  halt_baddata();
}

