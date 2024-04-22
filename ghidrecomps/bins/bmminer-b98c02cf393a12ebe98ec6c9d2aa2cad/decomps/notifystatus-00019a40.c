
void notifystatus(undefined4 param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  int local_1c;
  
  pcVar3 = "None";
  if (*(int *)(param_3 + 0xf4) != 0) {
    if (*(uint *)(param_3 + 0xf8) < 9) {
      pcVar3 = *(char **)(CSWTCH_516 + *(uint *)(param_3 + 0xf8) * 4);
    }
    else {
      pcVar3 = "Unknown reason - code bug";
    }
  }
  local_1c = param_2;
  uVar1 = api_add_data_full(0,"NOTIFY",6,&local_1c,0);
  uVar1 = api_add_data_full(uVar1,&DAT_0005813c,1,*(undefined4 *)(*(int *)(param_3 + 4) + 8),0);
  uVar1 = api_add_data_full(uVar1,"ID",6,param_3 + 8,0);
  uVar1 = api_add_data_full(uVar1,"Last Well",0x10,param_3 + 0xf0,0);
  uVar1 = api_add_data_full(uVar1,"Last Not Well",0x10,param_3 + 0xf4,0);
  uVar1 = api_add_data_full(uVar1,"Reason Not Well",1,pcVar3,0);
  uVar1 = api_add_data_full(uVar1,"*Thread Fail Init",6,param_3 + 0xfc,0);
  uVar1 = api_add_data_full(uVar1,"*Thread Zero Hash",6,param_3 + 0x100,0);
  uVar1 = api_add_data_full(uVar1,"*Thread Fail Queue",6,param_3 + 0x104,0);
  uVar1 = api_add_data_full(uVar1,"*Dev Sick Idle 60s",6,param_3 + 0x108,0);
  uVar1 = api_add_data_full(uVar1,"*Dev Dead Idle 600s",6,param_3 + 0x10c,0);
  uVar1 = api_add_data_full(uVar1,"*Dev Nostart",6,param_3 + 0x110,0);
  uVar1 = api_add_data_full(uVar1,"*Dev Over Heat",6,param_3 + 0x114,0);
  uVar1 = api_add_data_full(uVar1,"*Dev Thermal Cutoff",6,param_3 + 0x118,0);
  uVar1 = api_add_data_full(uVar1,"*Dev Comms Error",6,param_3 + 0x11c,0);
  uVar1 = api_add_data_full(uVar1,"*Dev Throttle",6,param_3 + 0x120,0);
  iVar2 = param_4;
  if (param_4 != 0) {
    if (local_1c < 1) {
      iVar2 = 0;
    }
    else {
      iVar2 = 1;
    }
  }
  print_data(param_1,uVar1,param_4,iVar2);
  return;
}

