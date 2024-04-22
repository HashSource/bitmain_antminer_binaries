
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * asctime(tm *__tp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* asctime@@GLIBC_2.4 */
  halt_baddata();
}

