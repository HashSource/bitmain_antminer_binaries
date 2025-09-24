
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mlock(void *__addr,size_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* mlock@@GLIBC_2.4 */
  halt_baddata();
}

