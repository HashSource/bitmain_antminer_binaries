
uint read_string_inner(UI *param_1,UI_STRING *param_2,int param_3,int param_4)

{
  FILE *__stream;
  char *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char acStack_20bc [8];
  _union_1051 local_20b4 [35];
  char local_2028 [8196];
  
  intr_signal = 0;
  iVar3 = 2;
  ps_8091 = 0;
  iVar2 = 1;
  memset(local_20b4,0,0x8c);
  local_20b4[0] = (_union_1051)0x1ab791;
  do {
    if ((iVar2 != 10) && (iVar2 != 0xc)) {
      if ((iVar2 != 9) &&
         (sigaction(iVar2,(sigaction *)local_20b4,(sigaction *)(savsig + iVar2 * 0x8c)),
         iVar3 == 0x20)) break;
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 1;
  } while( true );
  signal(0x1c,(__sighandler_t)0x0);
  ps_8091 = 1;
  if (param_3 == 0) {
    tty_new._0_4_ = tty_orig._0_4_;
    tty_new._4_4_ = tty_orig._4_4_;
    tty_new._8_4_ = tty_orig._8_4_;
    tty_new._12_4_ = tty_orig._12_4_ & 0xfffffff7;
    tty_new._16_4_ = tty_orig._16_4_;
    tty_new._20_4_ = tty_orig._20_4_;
    tty_new._24_4_ = tty_orig._24_4_;
    tty_new._28_4_ = tty_orig._28_4_;
    tty_new._32_4_ = tty_orig._32_4_;
    tty_new._36_4_ = tty_orig._36_4_;
    tty_new._40_4_ = tty_orig._40_4_;
    tty_new._44_4_ = tty_orig._44_4_;
    tty_new._48_4_ = tty_orig._48_4_;
    tty_new._52_4_ = tty_orig._52_4_;
    tty_new._56_4_ = tty_orig._56_4_;
    if (is_a_tty == 0) goto LAB_001ab8ba;
    iVar2 = fileno(tty_in);
    iVar2 = tcsetattr(iVar2,0,(termios *)tty_new);
    if (iVar2 != -1) goto LAB_001ab8ba;
LAB_001ab8e4:
    uVar4 = 0;
  }
  else {
LAB_001ab8ba:
    local_2028[0] = '\0';
    ps_8091 = 2;
    pcVar1 = fgets(local_2028,0x1fff,tty_in);
    __stream = tty_in;
    if (((pcVar1 == (char *)0x0) || (iVar2 = feof(tty_in), iVar2 != 0)) ||
       (iVar2 = ferror(__stream), iVar2 != 0)) goto LAB_001ab8e4;
    pcVar1 = strchr(local_2028,10);
    if (pcVar1 == (char *)0x0) {
      do {
        pcVar1 = fgets(acStack_20bc,4,__stream);
        if (pcVar1 == (char *)0x0) goto LAB_001ab8e4;
        pcVar1 = strchr(acStack_20bc,10);
      } while (pcVar1 == (char *)0x0);
    }
    else if (param_4 != 0) {
      *pcVar1 = '\0';
    }
    uVar4 = UI_set_result(param_1,param_2,local_2028);
    uVar4 = ~uVar4 >> 0x1f;
  }
  if (intr_signal == 2) {
    uVar4 = 0xffffffff;
  }
  if (param_3 == 0) {
    fputc(10,tty_out);
    if (ps_8091 < 2) goto LAB_001ab9fc;
    tty_new._0_4_ = tty_orig._0_4_;
    tty_new._4_4_ = tty_orig._4_4_;
    tty_new._8_4_ = tty_orig._8_4_;
    tty_new._16_4_ = tty_orig._16_4_;
    tty_new._20_4_ = tty_orig._20_4_;
    tty_new._24_4_ = tty_orig._24_4_;
    tty_new._28_4_ = tty_orig._28_4_;
    tty_new._12_4_ = tty_orig._12_4_ | 8;
    tty_new._32_4_ = tty_orig._32_4_;
    tty_new._36_4_ = tty_orig._36_4_;
    tty_new._40_4_ = tty_orig._40_4_;
    tty_new._44_4_ = tty_orig._44_4_;
    tty_new._48_4_ = tty_orig._48_4_;
    tty_new._52_4_ = tty_orig._52_4_;
    tty_new._56_4_ = tty_orig._56_4_;
    if (is_a_tty != 0) {
      iVar2 = fileno(tty_in);
      iVar2 = tcsetattr(iVar2,0,(termios *)tty_new);
      if (iVar2 == -1) {
        uVar4 = 0;
      }
    }
  }
  else if (ps_8091 < 2) {
LAB_001ab9fc:
    if (ps_8091 != 1) goto LAB_001ab92a;
  }
  iVar2 = 1;
  for (iVar3 = 2;
      ((iVar2 == 10 || (iVar2 == 0xc)) ||
      (sigaction(iVar2,(sigaction *)(savsig + iVar2 * 0x8c),(sigaction *)0x0), iVar3 != 0x20));
      iVar3 = iVar3 + 1) {
    iVar2 = iVar2 + 1;
  }
LAB_001ab92a:
  OPENSSL_cleanse(local_2028,0x2000);
  return uVar4;
}

