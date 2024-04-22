
void poolstatus(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  double dVar1;
  time_t tVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined *puVar7;
  int iVar8;
  char *pcVar9;
  double dVar10;
  double dVar11;
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
  dVar1 = DAT_00018498;
  local_144 = 0;
  local_160 = 0;
  local_154 = &DAT_000580f0;
  do {
    iVar8 = *(int *)(pools + local_144 * 4);
    if (*(char *)(iVar8 + 0x69) == '\0') {
      iVar6 = *(int *)(iVar8 + 100);
      if (iVar6 == 1) {
        pcVar9 = "Alive";
        if (*(char *)(iVar8 + 0x61) != '\0') {
          pcVar9 = "Dead";
        }
      }
      else if (iVar6 == 0) {
        pcVar9 = "Disabled";
      }
      else {
        pcVar9 = "Rejecting";
        if (iVar6 != 2) {
          pcVar9 = "Unknown";
        }
      }
      puVar7 = &DAT_000580ec;
      if (*(int *)(iVar8 + 0x6c) == 0) {
        puVar7 = local_154;
      }
      if (*(int *)(iVar8 + 0x160) < 1) {
        local_130[0] = 0x30;
      }
      else {
        tVar2 = time((time_t *)0x0);
        uVar3 = tVar2 - *(int *)(iVar8 + 0x160);
        uVar3 = uVar3 & ~((int)uVar3 >> 0x1f);
        iVar6 = (int)uVar3 % 0xe10;
        sprintf((char *)local_130,"%d:%02d:%02d",(int)uVar3 / 0xe10,iVar6 / 0x3c,iVar6 % 0x3c);
      }
      uVar4 = api_add_data_full(local_160,&DAT_00058360,6,&local_144,0);
      uVar4 = api_add_data_full(uVar4,"URL",0,*(undefined4 *)(iVar8 + 0xa4),0);
      uVar4 = api_add_data_full(uVar4,"Status",1,pcVar9,0);
      uVar4 = api_add_data_full(uVar4,"Priority",6,iVar8 + 4,0);
      uVar4 = api_add_data_full(uVar4,"Quota",6,iVar8 + 0x38,0);
      uVar4 = api_add_data_full(uVar4,"Long Poll",1,puVar7,0);
      uVar4 = api_add_data_full(uVar4,"Getworks",7,iVar8 + 0x74,0);
      uVar4 = api_add_data_full(uVar4,"Accepted",0xb,iVar8 + 8,0);
      uVar4 = api_add_data_full(uVar4,"Rejected",0xb,iVar8 + 0x10,0);
      uVar4 = api_add_data_full(uVar4,"Discarded",7,iVar8 + 0x7c,0);
      uVar4 = api_add_data_full(uVar4,"Stale",7,iVar8 + 0x78,0);
      uVar4 = api_add_data_full(uVar4,"Get Failures",7,iVar8 + 0x80,0);
      uVar4 = api_add_data_full(uVar4,"Remote Failures",7,iVar8 + 0x84,0);
      uVar4 = api_add_data_full(uVar4,&DAT_000583dc,0,*(undefined4 *)(iVar8 + 0xac),0);
      uVar4 = api_add_data_full(uVar4,"Last Share Time",1,local_130,0);
      uVar4 = api_add_data_full(uVar4,&DAT_000583f4,1,iVar8 + 0x30,0);
      uVar4 = api_add_data_full(uVar4,"Diff1 Shares",0xb,iVar8 + 0x28,0);
      if (*(int *)(iVar8 + 0xb8) == 0) {
        uVar4 = api_add_data_full(uVar4,"Proxy Type",2,&DAT_000609ec,0);
        uVar4 = api_add_data_full(uVar4,"Proxy",2,&DAT_000609ec,0);
      }
      else {
        uVar5 = proxytype(*(undefined4 *)(iVar8 + 0xb4));
        uVar4 = api_add_data_full(uVar4,"Proxy Type",2,uVar5,0);
        uVar4 = api_add_data_full(uVar4,"Proxy",0,*(undefined4 *)(iVar8 + 0xb8),0);
      }
      uVar4 = api_add_data_full(uVar4,"Difficulty Accepted",0x18,iVar8 + 0x48,0);
      uVar4 = api_add_data_full(uVar4,"Difficulty Rejected",0x18,iVar8 + 0x50,0);
      uVar4 = api_add_data_full(uVar4,"Difficulty Stale",0x18,iVar8 + 0x58,0);
      uVar4 = api_add_data_full(uVar4,"Last Share Difficulty",0x18,iVar8 + 0x168,0);
      uVar4 = api_add_data_full(uVar4,"Has Stratum",0xe,iVar8 + 0x280,0);
      uVar4 = api_add_data_full(uVar4,"Stratum Active",0xe,iVar8 + 0x281,0);
      if (*(char *)(iVar8 + 0x281) == '\0') {
        uVar4 = api_add_data_full(uVar4,"Stratum URL",2,&DAT_000609ec,0);
      }
      else {
        uVar4 = api_add_data_full(uVar4,"Stratum URL",0,*(undefined4 *)(iVar8 + 0x240),0);
      }
      uVar4 = api_add_data_full(uVar4,"Has GBT",0xe,iVar8 + 0x2e0,0);
      uVar4 = api_add_data_full(uVar4,"Best Share",10,iVar8 + 0x170,1);
      dVar11 = *(double *)(iVar8 + 0x50) + *(double *)(iVar8 + 0x48) + *(double *)(iVar8 + 0x58);
      dVar10 = dVar1;
      if (dVar11 != 0.0) {
        dVar10 = *(double *)(iVar8 + 0x50) / dVar11;
      }
      uStack_13c = (undefined4)((ulonglong)dVar10 >> 0x20);
      local_140 = SUB84(dVar10,0);
      uVar4 = api_add_data_full(uVar4,"Pool Rejected%",0x19,&local_140,0);
      dVar11 = *(double *)(iVar8 + 0x48) + *(double *)(iVar8 + 0x50) + *(double *)(iVar8 + 0x58);
      dVar10 = dVar1;
      if (dVar11 != 0.0) {
        dVar10 = *(double *)(iVar8 + 0x58) / dVar11;
      }
      uStack_134 = (undefined4)((ulonglong)dVar10 >> 0x20);
      local_138 = SUB84(dVar10,0);
      uVar5 = api_add_data_full(uVar4,"Pool Stale%",0x19,&local_138,0);
      uVar4 = 0;
      if (param_4 != 0) {
        if (local_144 < 1) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
      }
      local_160 = print_data(param_1,uVar5,param_4,uVar4);
    }
    local_144 = local_144 + 1;
  } while (local_144 < total_pools);
LAB_000188c6:
  if (local_14c != 0) {
    *(undefined *)(param_1 + 0xd) = 1;
  }
  return;
}

