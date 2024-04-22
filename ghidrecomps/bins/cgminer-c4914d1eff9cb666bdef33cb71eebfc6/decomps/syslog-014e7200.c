
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void syslog(int __pri,char *__fmt,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* syslog@@GLIBC_2.4 */
  halt_baddata();
}

