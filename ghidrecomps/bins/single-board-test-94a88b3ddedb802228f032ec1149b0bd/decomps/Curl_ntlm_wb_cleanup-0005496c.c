
void Curl_ntlm_wb_cleanup(int param_1)

{
  code *pcVar1;
  __pid_t __pid;
  __pid_t _Var2;
  int *piVar3;
  int __sig;
  int iVar4;
  
  if (*(int *)(param_1 + 0x2a4) != -1) {
    close(*(int *)(param_1 + 0x2a4));
    *(undefined4 *)(param_1 + 0x2a4) = 0xffffffff;
  }
  __pid = *(int *)(param_1 + 0x2a8);
  if (__pid != 0) {
    iVar4 = 1;
    while( true ) {
      _Var2 = waitpid(__pid,(int *)0x0,1);
      __pid = *(int *)(param_1 + 0x2a8);
      if (__pid == _Var2) break;
      piVar3 = __errno_location();
      if (*piVar3 == 10) break;
      if (iVar4 == 2) {
        Curl_wait_ms(1);
        __pid = *(__pid_t *)(param_1 + 0x2a8);
      }
      else {
        if (iVar4 == 3) {
          __sig = 9;
        }
        else {
          __sig = 0xf;
          if (iVar4 != 1) {
            if (iVar4 != 4) goto LAB_000549be;
            break;
          }
        }
        kill(__pid,__sig);
        __pid = *(__pid_t *)(param_1 + 0x2a8);
      }
LAB_000549be:
      iVar4 = iVar4 + 1;
    }
    *(undefined4 *)(param_1 + 0x2a8) = 0;
  }
  (*Curl_cfree)(*(undefined4 *)(param_1 + 0x2ac));
  pcVar1 = Curl_cfree;
  *(undefined4 *)(param_1 + 0x2ac) = 0;
  (*pcVar1)(*(undefined4 *)(param_1 + 0x2b0));
  *(undefined4 *)(param_1 + 0x2b0) = 0;
  return;
}

