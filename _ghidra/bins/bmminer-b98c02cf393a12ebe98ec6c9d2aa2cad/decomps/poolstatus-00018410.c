
void poolstatus(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  time_t tVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  char *pcVar8;
  double dVar9;
  double dVar10;
  undefined4 local_160;
  undefined *local_154;
  int local_14c;
  int local_144;
  undefined4 local_140;
  undefined4 uStack_13c;
  undefined4 local_138;
  undefined4 uStack_134;
  undefined2 local_130 [130];
  
  memset(local_130,0,0x100);
  if (total_pools == 0) {
    message(param_1,8,0,0,param_4);
    return;
  }
  message(param_1,7,0,0,param_4);
  if (param_4 == 0) {
    if (total_pools < 1) {
      return;
    }
    local_14c = 0;
  }
  else {
    local_14c = io_add(param_1,",\"POOLS\":[");
    if (total_pools < 1) goto LAB_000188c6;
  }
  local_144 = 0;
  local_160 = 0;
  local_154 = &DAT_000580f0;
  do {
    iVar7 = *(int *)(pools + local_144 * 4);
    if (*(char *)(iVar7 + 0x69) == '\0') {
      iVar5 = *(int *)(iVar7 + 100);
      if (iVar5 == 1) {
        pcVar8 = "Alive";
        if (*(char *)(iVar7 + 0x61) != '\0') {
          pcVar8 = "Dead";
        }
      }
      else if (iVar5 == 0) {
        pcVar8 = "Disabled";
      }
      else {
        pcVar8 = "Rejecting";
        if (iVar5 != 2) {
          pcVar8 = "Unknown";
        }
      }
      puVar6 = &DAT_000580ec;
      if (*(int *)(iVar7 + 0x6c) == 0) {
        puVar6 = local_154;
      }
      if (*(int *)(iVar7 + 0x160) < 1) {
        local_130[0] = 0x30;
      }
      else {
        tVar1 = time((time_t *)0x0);
        uVar2 = tVar1 - *(int *)(iVar7 + 0x160);
        uVar2 = uVar2 & ~((int)uVar2 >> 0x1f);
        iVar5 = (int)uVar2 % 0xe10;
        sprintf((char *)local_130,"%d:%02d:%02d",(int)uVar2 / 0xe10,iVar5 / 0x3c,iVar5 % 0x3c);
      }
      uVar3 = api_add_data_full(local_160,&DAT_00058360,6,&local_144,0);
      uVar3 = api_add_data_full(uVar3,"URL",0,*(undefined4 *)(iVar7 + 0xa4),0);
      uVar3 = api_add_data_full(uVar3,"Status",1,pcVar8,0);
      uVar3 = api_add_data_full(uVar3,"Priority",6,iVar7 + 4,0);
      uVar3 = api_add_data_full(uVar3,"Quota",6,iVar7 + 0x38,0);
      uVar3 = api_add_data_full(uVar3,"Long Poll",1,puVar6,0);
      uVar3 = api_add_data_full(uVar3,"Getworks",7,iVar7 + 0x74,0);
      uVar3 = api_add_data_full(uVar3,"Accepted",0xb,iVar7 + 8,0);
      uVar3 = api_add_data_full(uVar3,"Rejected",0xb,iVar7 + 0x10,0);
      uVar3 = api_add_data_full(uVar3,"Discarded",7,iVar7 + 0x7c,0);
      uVar3 = api_add_data_full(uVar3,"Stale",7,iVar7 + 0x78,0);
      uVar3 = api_add_data_full(uVar3,"Get Failures",7,iVar7 + 0x80,0);
      uVar3 = api_add_data_full(uVar3,"Remote Failures",7,iVar7 + 0x84,0);
      uVar3 = api_add_data_full(uVar3,&DAT_000583dc,0,*(undefined4 *)(iVar7 + 0xac),0);
      uVar3 = api_add_data_full(uVar3,"Last Share Time",1,local_130,0);
      uVar3 = api_add_data_full(uVar3,&DAT_000583f4,1,iVar7 + 0x30,0);
      uVar3 = api_add_data_full(uVar3,"Diff1 Shares",0xb,iVar7 + 0x28,0);
      if (*(int *)(iVar7 + 0xb8) == 0) {
        uVar3 = api_add_data_full(uVar3,"Proxy Type",2,&DAT_000609ec,0);
        uVar3 = api_add_data_full(uVar3,"Proxy",2,&DAT_000609ec,0);
      }
      else {
        uVar4 = proxytype(*(undefined4 *)(iVar7 + 0xb4));
        uVar3 = api_add_data_full(uVar3,"Proxy Type",2,uVar4,0);
        uVar3 = api_add_data_full(uVar3,"Proxy",0,*(undefined4 *)(iVar7 + 0xb8),0);
      }
      uVar3 = api_add_data_full(uVar3,"Difficulty Accepted",0x18,iVar7 + 0x48,0);
      uVar3 = api_add_data_full(uVar3,"Difficulty Rejected",0x18,iVar7 + 0x50,0);
      uVar3 = api_add_data_full(uVar3,"Difficulty Stale",0x18,iVar7 + 0x58,0);
      uVar3 = api_add_data_full(uVar3,"Last Share Difficulty",0x18,iVar7 + 0x168,0);
      uVar3 = api_add_data_full(uVar3,"Has Stratum",0xe,iVar7 + 0x280,0);
      uVar3 = api_add_data_full(uVar3,"Stratum Active",0xe,iVar7 + 0x281,0);
      if (*(char *)(iVar7 + 0x281) == '\0') {
        uVar3 = api_add_data_full(uVar3,"Stratum URL",2,&DAT_000609ec,0);
      }
      else {
        uVar3 = api_add_data_full(uVar3,"Stratum URL",0,*(undefined4 *)(iVar7 + 0x240),0);
      }
      uVar3 = api_add_data_full(uVar3,"Has GBT",0xe,iVar7 + 0x2e0,0);
      uVar3 = api_add_data_full(uVar3,"Best Share",10,iVar7 + 0x170,1);
      dVar10 = *(double *)(iVar7 + 0x50) + *(double *)(iVar7 + 0x48) + *(double *)(iVar7 + 0x58);
      dVar9 = 0.0;
      if (dVar10 != 0.0) {
        dVar9 = *(double *)(iVar7 + 0x50) / dVar10;
      }
      uStack_13c = (undefined4)((ulonglong)dVar9 >> 0x20);
      local_140 = SUB84(dVar9,0);
      uVar3 = api_add_data_full(uVar3,"Pool Rejected%",0x19,&local_140,0);
      dVar10 = *(double *)(iVar7 + 0x48) + *(double *)(iVar7 + 0x50) + *(double *)(iVar7 + 0x58);
      dVar9 = 0.0;
      if (dVar10 != 0.0) {
        dVar9 = *(double *)(iVar7 + 0x58) / dVar10;
      }
      uStack_134 = (undefined4)((ulonglong)dVar9 >> 0x20);
      local_138 = SUB84(dVar9,0);
      uVar4 = api_add_data_full(uVar3,"Pool Stale%",0x19,&local_138,0);
      uVar3 = 0;
      if (param_4 != 0) {
        if (local_144 < 1) {
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
      }
      local_160 = print_data(param_1,uVar4,param_4,uVar3);
    }
    local_144 = local_144 + 1;
  } while (local_144 < total_pools);
LAB_000188c6:
  if (local_14c != 0) {
    *(undefined1 *)(param_1 + 0xd) = 1;
  }
  return;
}

