
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* ioctl@@GLIBC_2.4 */
  halt_baddata();
}

