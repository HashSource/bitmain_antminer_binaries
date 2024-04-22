
void alarmfunc(void)

{
                    /* WARNING: Subroutine does not return */
  siglongjmp((__jmp_buf_tag *)curl_jmpenv,1);
}

