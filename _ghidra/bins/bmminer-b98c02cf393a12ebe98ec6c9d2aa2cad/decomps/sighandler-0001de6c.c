
void sighandler(void)

{
  char *__s;
  size_t sVar1;
  size_t sVar2;
  uint __maxlen;
  int extraout_r2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 extraout_s1;
  DFtype a;
  undefined8 uVar6;
  UDItype UVar7;
  UDItype UVar8;
  undefined1 auStack_8a8 [16];
  undefined1 auStack_898 [16];
  char acStack_888 [64];
  char acStack_848 [2052];
  
  sigaction(0xf,(sigaction *)termhandler,(sigaction *)0x0);
  sigaction(2,(sigaction *)inthandler,(sigaction *)0x0);
  sigaction(6,(sigaction *)abrthandler,(sigaction *)0x0);
  uVar6 = kill_work();
  __maxlen = (uint)((ulonglong)uVar6 >> 0x20);
  __s = (char *)uVar6;
  cgpu_runtime(extraout_r2);
  uVar5 = __aeabi_l2d(*(undefined4 *)(extraout_r2 + 0xc0),*(undefined4 *)(extraout_r2 + 0xc4));
  UVar7 = __fixunsdfdi((DFtype)CONCAT44(extraout_s1,uVar5));
  UVar8 = __fixunsdfdi(a);
  suffix_string((int)UVar8,(int)(UVar8 >> 0x20),auStack_8a8,0x10,4);
  suffix_string((int)UVar7,(int)(UVar7 >> 0x20),auStack_898,0x10,4);
  snprintf(__s,__maxlen,"%s%d ",*(undefined4 *)(*(int *)(extraout_r2 + 4) + 8),
           *(undefined4 *)(extraout_r2 + 8));
  (**(code **)(*(int *)(extraout_r2 + 4) + 0x14))(__s,__maxlen,extraout_r2);
  sVar1 = strlen(__s);
  uVar5 = *(undefined4 *)(extraout_r2 + 0x2c);
  uVar6 = *(undefined8 *)(extraout_r2 + 0xd0);
  uVar3 = *(undefined4 *)(extraout_r2 + 200);
  uVar4 = *(undefined4 *)(extraout_r2 + 0xcc);
  snprintf(acStack_888,0x40,"(%ds):%s (avg):%sh/s | A:%.0f R:%.0f HW:%d WU:%.1f/m",opt_log_interval,
           auStack_898,auStack_8a8,uVar3,uVar4,uVar6,uVar5);
  sVar2 = strlen(acStack_888);
  if (sVar2 + sVar1 < __maxlen) {
    strcat(__s,acStack_888);
    (**(code **)(*(int *)(extraout_r2 + 4) + 0x18))(__s,__maxlen,extraout_r2);
    return;
  }
  snprintf(acStack_848,0x800,"tailsprintf buffer overflow in %s %s line %d","cgminer.c",
           "get_statline",0xbf1,uVar3,uVar4,uVar6,uVar5);
  _applog(3,acStack_848,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

