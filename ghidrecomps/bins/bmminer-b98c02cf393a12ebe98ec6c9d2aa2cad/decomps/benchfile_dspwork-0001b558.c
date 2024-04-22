
void benchfile_dspwork(undefined4 param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined auStack_c08 [1024];
  char acStack_808 [2048];
  
  iVar1 = 4;
  iVar3 = 0;
  do {
    uVar2 = param_2 & 0xff;
    iVar1 = iVar1 + -1;
    param_2 = param_2 >> 8;
    iVar3 = uVar2 + iVar3 * 0x100;
  } while (iVar1 != 0);
  __bin2hex(auStack_c08,param_1,0x80);
  if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 3)) {
    return;
  }
  snprintf(acStack_808,0x800,"BENCHFILE nonce %u=0x%08x for work=%s",iVar3,iVar3,auStack_c08);
  _applog(3,acStack_808,0);
  return;
}

