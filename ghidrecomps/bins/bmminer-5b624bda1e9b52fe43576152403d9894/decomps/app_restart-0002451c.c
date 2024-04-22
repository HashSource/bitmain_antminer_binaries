
/* WARNING: Unknown calling convention */

void app_restart(void)

{
  char *pcVar1;
  int iVar2;
  char tmp42 [2048];
  
  pcVar1 = DAT_000245bc;
  if (((*DAT_000245bc != '\0') || (*DAT_000245c0 != '\0')) || (3 < *DAT_000245d8)) {
    snprintf(tmp42,0x800,DAT_000245c4,DAT_000245c8);
    _applog(4,tmp42,false);
  }
  iVar2 = DAT_000245cc;
  cg_completion_timeout(DAT_000245d0,(void *)0x0,5000);
  clean_up(true);
  if (0 < *(__pid_t *)(iVar2 + 0x6cc)) {
    kill(*(__pid_t *)(iVar2 + 0x6cc),0xf);
    *(undefined4 *)(iVar2 + 0x6cc) = 0;
  }
  execv(**(char ***)(iVar2 + 0x6d0),*(char ***)(iVar2 + 0x6d0));
  if (((*pcVar1 != '\0') || (*DAT_000245c0 != '\0')) || (3 < *DAT_000245d8)) {
    tmp42._0_4_ = *DAT_000245d4;
    tmp42._4_4_ = DAT_000245d4[1];
    tmp42._8_4_ = DAT_000245d4[2];
    tmp42._12_4_ = DAT_000245d4[3];
    tmp42._16_4_ = DAT_000245d4[4];
    tmp42._20_4_ = DAT_000245d4[5];
    tmp42._24_4_ = DAT_000245d4[6];
    tmp42._28_2_ = (undefined2)DAT_000245d4[7];
    _applog(4,tmp42,false);
  }
  return;
}

