
void minerstats(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  int local_44;
  char acStack_3c [24];
  
  message(param_1,0x46,0,0,param_4);
  if (param_4 == 0) {
    uVar1 = api_add_data_full(0,"BMMiner",1,"2.0.0",0);
    uVar1 = api_add_data_full(uVar1,"Miner",1,g_miner_version,0);
    uVar1 = api_add_data_full(uVar1,"CompileTime",1,g_miner_compiletime,0);
    uVar1 = api_add_data_full(uVar1,&DAT_000582a0,1,g_miner_type,0);
    print_data(param_1,uVar1,0,0);
    if (total_devices < 1) {
      return;
    }
    local_44 = 0;
  }
  else {
    local_44 = io_add(param_1,",\"STATS\":[");
    uVar1 = api_add_data_full(0,"BMMiner",1,"2.0.0",0);
    uVar1 = api_add_data_full(uVar1,"Miner",1,g_miner_version,0);
    uVar1 = api_add_data_full(uVar1,"CompileTime",1,g_miner_compiletime,0);
    uVar1 = api_add_data_full(uVar1,&DAT_000582a0,1,g_miner_type,0);
    print_data(param_1,uVar1,1,0);
    if (total_devices < 1) goto LAB_00018e4a;
  }
  iVar4 = 0;
  uVar1 = 0;
  do {
    iVar2 = get_devices(iVar4);
    if ((iVar2 != 0) && (iVar3 = *(int *)(iVar2 + 4), iVar3 != 0)) {
      pcVar5 = *(code **)(iVar3 + 0x1c);
      if (pcVar5 != (code *)0x0) {
        pcVar5 = (code *)(*pcVar5)();
        iVar3 = *(int *)(iVar2 + 4);
      }
      sprintf(acStack_3c,"%s%d",*(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar2 + 8));
      uVar1 = itemstats_isra_17(param_1,uVar1,acStack_3c,iVar2 + 0x124,pcVar5,param_4);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < total_devices);
LAB_00018e4a:
  if (local_44 != 0) {
    *(undefined *)(param_1 + 0xd) = 1;
  }
  return;
}

