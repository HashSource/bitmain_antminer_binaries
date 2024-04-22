
void sighandler(void)

{
  char *__s;
  size_t sVar1;
  size_t sVar2;
  uint __maxlen;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  UDItype UVar8;
  UDItype UVar9;
  undefined4 in_stack_fffff730;
  undefined4 in_stack_fffff734;
  undefined auStack_8a8 [16];
  undefined auStack_898 [16];
  char acStack_888 [64];
  char acStack_848 [2052];
  
  sigaction(0xf,(sigaction *)termhandler,(sigaction *)0x0);
  sigaction(2,(sigaction *)inthandler,(sigaction *)0x0);
  iVar4 = 0;
  sigaction(6,(sigaction *)abrthandler,(sigaction *)0x0);
  uVar7 = kill_work();
  __maxlen = (uint)((ulonglong)uVar7 >> 0x20);
  __s = (char *)uVar7;
  cgpu_runtime(iVar4);
  __aeabi_l2d(*(undefined4 *)(iVar4 + 0xc0),*(undefined4 *)(iVar4 + 0xc4));
  UVar8 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff734,in_stack_fffff730));
  UVar9 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff734,in_stack_fffff730));
  suffix_string((int)UVar9,(int)(UVar9 >> 0x20),auStack_8a8,0x10,4);
  suffix_string((int)UVar8,(int)(UVar8 >> 0x20),auStack_898,0x10,4);
  snprintf(__s,__maxlen,"%s%d ",*(undefined4 *)(*(int *)(iVar4 + 4) + 8),*(undefined4 *)(iVar4 + 8))
  ;
  (**(code **)(*(int *)(iVar4 + 4) + 0x14))(__s,__maxlen,iVar4);
  sVar1 = strlen(__s);
  uVar3 = *(undefined4 *)(iVar4 + 0x2c);
  uVar7 = *(undefined8 *)(iVar4 + 0xd0);
  uVar5 = *(undefined4 *)(iVar4 + 200);
  uVar6 = *(undefined4 *)(iVar4 + 0xcc);
  snprintf(acStack_888,0x40,"(%ds):%s (avg):%sh/s | A:%.0f R:%.0f HW:%d WU:%.1f/m",opt_log_interval,
           auStack_898,auStack_8a8,uVar5,uVar6,uVar7,uVar3);
  sVar2 = strlen(acStack_888);
  if (sVar2 + sVar1 < __maxlen) {
    strcat(__s,acStack_888);
    (**(code **)(*(int *)(iVar4 + 4) + 0x18))(__s,__maxlen,iVar4);
    return;
  }
  snprintf(acStack_848,0x800,"tailsprintf buffer overflow in %s %s line %d","cgminer.c",DAT_0001e008
           ,0xbf1,uVar5,uVar6,uVar7,uVar3);
  _applog(3,acStack_848,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

