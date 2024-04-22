
void get_statline(char *param_1,uint param_2,int param_3)

{
  size_t sVar1;
  size_t sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  UDItype UVar7;
  UDItype UVar8;
  undefined4 in_stack_fffff738;
  undefined4 in_stack_fffff73c;
  undefined auStack_8a0 [16];
  undefined auStack_890 [16];
  char acStack_880 [64];
  char acStack_840 [2052];
  
  cgpu_runtime(param_3);
  __aeabi_l2d(*(undefined4 *)(param_3 + 0xc0),*(undefined4 *)(param_3 + 0xc4));
  UVar7 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff73c,in_stack_fffff738));
  UVar8 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff73c,in_stack_fffff738));
  suffix_string((int)UVar8,(int)(UVar8 >> 0x20),auStack_8a0,0x10,4);
  suffix_string((int)UVar7,(int)(UVar7 >> 0x20),auStack_890,0x10,4);
  snprintf(param_1,param_2,"%s%d ",*(undefined4 *)(*(int *)(param_3 + 4) + 8),
           *(undefined4 *)(param_3 + 8));
  (**(code **)(*(int *)(param_3 + 4) + 0x14))(param_1,param_2,param_3);
  sVar1 = strlen(param_1);
  uVar3 = *(undefined4 *)(param_3 + 0x2c);
  uVar6 = *(undefined8 *)(param_3 + 0xd0);
  uVar4 = *(undefined4 *)(param_3 + 200);
  uVar5 = *(undefined4 *)(param_3 + 0xcc);
  snprintf(acStack_880,0x40,"(%ds):%s (avg):%sh/s | A:%.0f R:%.0f HW:%d WU:%.1f/m",opt_log_interval,
           auStack_890,auStack_8a0,uVar4,uVar5,uVar6,uVar3);
  sVar2 = strlen(acStack_880);
  if (sVar2 + sVar1 < param_2) {
    strcat(param_1,acStack_880);
    (**(code **)(*(int *)(param_3 + 4) + 0x18))(param_1,param_2,param_3);
    return;
  }
  snprintf(acStack_840,0x800,"tailsprintf buffer overflow in %s %s line %d","cgminer.c",DAT_0001e008
           ,0xbf1,uVar4,uVar5,uVar6,uVar3);
  _applog(3,acStack_840,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

