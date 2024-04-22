
int new_nonce_isra_10(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  char acStack_808 [2048];
  
  bVar2 = *(int *)(param_1 + 0xec) != param_2;
  iVar1 = param_1;
  if (bVar2) {
    iVar1 = 1;
  }
  if (bVar2) {
    *(int *)(param_1 + 0xec) = param_2;
  }
  else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (iVar1 = 0, 5 < opt_log_level)) {
    snprintf(acStack_808,0x800,"%s %d duplicate share detected as HW error",
             *(undefined4 *)(*(int *)(param_1 + 4) + 8),*(undefined4 *)(param_1 + 8));
    _applog(6,acStack_808,0);
    iVar1 = 0;
  }
  return iVar1;
}

