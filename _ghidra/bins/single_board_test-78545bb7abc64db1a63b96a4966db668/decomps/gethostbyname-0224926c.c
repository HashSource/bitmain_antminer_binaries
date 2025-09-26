
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

hostent * gethostbyname(char *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* gethostbyname@@GLIBC_2.4 */
  halt_baddata();
}

