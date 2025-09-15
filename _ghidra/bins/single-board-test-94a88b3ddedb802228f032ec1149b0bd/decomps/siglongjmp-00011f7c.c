
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void siglongjmp(__jmp_buf_tag *__env,int __val)

{
                    /* WARNING: Subroutine does not return */
  siglongjmp(__env,__val);
}

