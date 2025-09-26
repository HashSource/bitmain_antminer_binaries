
uint read_string_inner(UI *param_1,UI_STRING *param_2,int param_3,int param_4)

{
  FILE *pFVar1;
  char *pcVar2;
  int iVar3;
  sigaction *psVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  char acStack_2030 [8];
  _union_1051 local_2028 [2049];
  
  intr_signal = 0;
  ps_21040 = 0;
  memset(local_2028,0,0x8c);
  local_2028[0] = (_union_1051)0x1cf6fd;
  uVar7 = 1;
  psVar4 = (sigaction *)(savsig + 0x8c);
  do {
    bVar8 = 0xb < uVar7;
    if (uVar7 != 0xc) {
      bVar8 = uVar7 != 9;
    }
    uVar5 = uVar7 + 1;
    if (bVar8 && (uVar7 != 0xc && uVar7 != 10)) {
      sigaction(uVar7,(sigaction *)local_2028,psVar4);
    }
    uVar7 = uVar5;
    psVar4 = psVar4 + 1;
  } while (uVar5 != 0x20);
  signal(0x1c,(__sighandler_t)0x0);
  pFVar1 = tty_in;
  ps_21040 = 1;
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
    if (is_a_tty == 0) goto LAB_001cf83c;
    iVar3 = fileno(tty_in);
    iVar3 = tcsetattr(iVar3,0,(termios *)tty_new);
    if (iVar3 != -1) goto LAB_001cf83c;
    uVar7 = 0xffffffff;
    if (intr_signal != 2) {
      uVar7 = 0;
    }
LAB_001cf8e2:
    fputc(10,tty_out);
    if (ps_21040 < 2) {
LAB_001cf972:
      if (ps_21040 < 1) goto LAB_001cf8a4;
    }
    else {
      tty_new._0_4_ = tty_orig._0_4_;
      tty_new._4_4_ = tty_orig._4_4_;
      tty_new._8_4_ = tty_orig._8_4_;
      tty_new._12_4_ = tty_orig._12_4_;
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
      if (is_a_tty != 0) {
        iVar3 = fileno(tty_in);
        iVar3 = tcsetattr(iVar3,0,(termios *)tty_new);
        if (iVar3 == -1) {
          uVar7 = 0;
        }
      }
    }
  }
  else {
LAB_001cf83c:
    local_2028[0].sa_handler = local_2028[0].sa_handler & 0xffffff00;
    ps_21040 = 2;
    pcVar2 = fgets((char *)local_2028,0x1fff,pFVar1);
    pFVar1 = tty_in;
    if (((pcVar2 == (char *)0x0) || (iVar3 = feof(tty_in), iVar3 != 0)) ||
       (iVar3 = ferror(pFVar1), iVar3 != 0)) {
LAB_001cf862:
      uVar7 = 0;
    }
    else {
      pcVar2 = strchr((char *)local_2028,10);
      if (pcVar2 == (char *)0x0) {
        do {
          pcVar2 = fgets(acStack_2030,4,pFVar1);
          if (pcVar2 == (char *)0x0) goto LAB_001cf862;
          pcVar2 = strchr(acStack_2030,10);
        } while (pcVar2 == (char *)0x0);
      }
      else if (param_4 != 0) {
        *pcVar2 = '\0';
      }
      uVar7 = UI_set_result(param_1,param_2,(char *)local_2028);
      uVar7 = ~uVar7 >> 0x1f;
    }
    if (intr_signal == 2) {
      uVar7 = 0xffffffff;
    }
    if (param_3 == 0) goto LAB_001cf8e2;
    if (ps_21040 < 2) goto LAB_001cf972;
  }
  psVar4 = (sigaction *)(savsig + 0x8c);
  iVar3 = 1;
  do {
    iVar6 = iVar3 + 1;
    if ((iVar3 - 10U & 0xfffffffd) != 0) {
      sigaction(iVar3,psVar4,(sigaction *)0x0);
    }
    psVar4 = psVar4 + 1;
    iVar3 = iVar6;
  } while (iVar6 != 0x20);
LAB_001cf8a4:
  OPENSSL_cleanse(local_2028,0x2000);
  return uVar7;
}

