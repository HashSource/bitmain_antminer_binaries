
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int clock_nanosleep(clockid_t __clock_id,int __flags,timespec *__req,timespec *__rem)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* clock_nanosleep@@GLIBC_2.4 */
  halt_baddata();
}

