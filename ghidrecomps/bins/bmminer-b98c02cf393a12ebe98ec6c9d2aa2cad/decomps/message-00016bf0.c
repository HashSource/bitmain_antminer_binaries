
void message(undefined4 param_1,int param_2,int param_3,undefined4 param_4,char param_5)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 *puVar6;
  int local_2024 [2];
  undefined4 local_201c;
  char acStack_2018 [8192];
  
  local_2024[0] = param_2;
  if (param_5 != '\0') {
    io_add(param_1,"{\"STATUS\":[");
  }
  if (codes == 4) {
LAB_00016c42:
    uVar2 = api_add_data_full(0,"STATUS",1,&DAT_00058044,0);
    uVar2 = api_add_data_full(uVar2,&DAT_00058024,0x10,DAT_00016e6c,0);
    local_201c = 0xffffffff;
    uVar2 = api_add_data_full(uVar2,&DAT_0005802c,6,&local_201c,0);
    sprintf(acStack_2018,"%d",local_2024[0]);
  }
  else {
    if (local_2024[0] == DAT_0007d0c4) {
      iVar3 = 0;
      iVar4 = codes;
    }
    else {
      iVar3 = 0;
      puVar6 = &codes;
      do {
        iVar4 = puVar6[4];
        iVar3 = iVar3 + 1;
        if (iVar4 == 4) goto LAB_00016c42;
        piVar1 = puVar6 + 5;
        puVar6 = puVar6 + 4;
      } while (*piVar1 != local_2024[0]);
    }
    if (iVar4 == 2) {
      local_201c = CONCAT31(local_201c._1_3_,0x49);
    }
    else if (iVar4 == 3) {
      local_201c = CONCAT31(local_201c._1_3_,0x53);
    }
    else if (iVar4 == 1) {
      local_201c = CONCAT31(local_201c._1_3_,0x57);
    }
    else {
      local_201c = CONCAT31(local_201c._1_3_,0x45);
    }
    local_201c._0_2_ = (ushort)(byte)local_201c;
    switch((&DAT_0007d0c8)[iVar3 * 4]) {
    case 0:
    case 1:
    case 2:
    case 0xe:
      sprintf(acStack_2018,(char *)(&DAT_0007d0cc)[iVar3 * 4],param_3);
      break;
    default:
      strcpy(acStack_2018,(char *)(&DAT_0007d0cc)[iVar3 * 4]);
      break;
    case 5:
      sprintf(acStack_2018,(char *)(&DAT_0007d0cc)[iVar3 * 4],total_pools);
      break;
    case 6:
      sprintf(acStack_2018,(char *)(&DAT_0007d0cc)[iVar3 * 4],param_3,total_pools + -1);
      break;
    case 7:
      sprintf(acStack_2018,(char *)(&DAT_0007d0cc)[iVar3 * 4]);
      break;
    case 8:
      sprintf(acStack_2018,(char *)(&DAT_0007d0cc)[iVar3 * 4],"command");
      break;
    case 9:
      sprintf(acStack_2018,(char *)(&DAT_0007d0cc)[iVar3 * 4],param_3,
              *(undefined4 *)(*(int *)(pools + param_3 * 4) + 0xa4));
      break;
    case 10:
      sprintf(acStack_2018,(char *)(&DAT_0007d0cc)[iVar3 * 4],param_4);
      break;
    case 0xb:
      sprintf(acStack_2018,(char *)(&DAT_0007d0cc)[iVar3 * 4],param_3,param_4);
      break;
    case 0xc:
      pcVar5 = "true";
      if (param_3 == 0) {
        pcVar5 = "false";
      }
      sprintf(acStack_2018,(char *)(&DAT_0007d0cc)[iVar3 * 4],pcVar5);
      break;
    case 0xd:
      sprintf(acStack_2018,(char *)(&DAT_0007d0cc)[iVar3 * 4],param_4,param_3);
    }
    uVar2 = api_add_data_full(0,"STATUS",1,&local_201c,0);
    uVar2 = api_add_data_full(uVar2,&DAT_00058024,0x10,DAT_00016e6c,0);
    uVar2 = api_add_data_full(uVar2,&DAT_0005802c,6,local_2024,0);
  }
  uVar2 = api_add_data_full(uVar2,&DAT_00058034,0,acStack_2018,0);
  uVar2 = api_add_data_full(uVar2,"Description",0,opt_api_description,0);
  print_data(param_1,uVar2,param_5,0);
  if (param_5 != '\0') {
    io_add(param_1,"]");
  }
  return;
}

