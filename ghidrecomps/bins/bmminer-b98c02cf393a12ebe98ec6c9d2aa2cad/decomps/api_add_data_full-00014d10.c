
undefined4 *
api_add_data_full(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 char param_5)

{
  undefined uVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  size_t sVar6;
  void *__dest;
  undefined4 *puVar7;
  undefined *puVar8;
  int iVar9;
  undefined4 uVar10;
  char acStack_820 [2052];
  
  puVar3 = (undefined4 *)malloc(0x18);
  uVar4 = __strdup(param_2);
  *puVar3 = param_3;
  puVar3[1] = uVar4;
  if (param_1 == (undefined4 *)0x0) {
    puVar3[4] = puVar3;
    puVar3[5] = puVar3;
    param_1 = puVar3;
  }
  else {
    iVar9 = param_1[4];
    puVar3[5] = param_1;
    param_1[4] = puVar3;
    puVar3[4] = iVar9;
    *(undefined4 **)(iVar9 + 0x14) = puVar3;
  }
  *(char *)(puVar3 + 3) = param_5;
  if (param_4 == (undefined4 *)0x0) {
    *(undefined *)(puVar3 + 3) = 0;
    param_4 = &DAT_00057984;
    *puVar3 = 2;
  }
  else if (param_5 != '\0') {
    switch(param_3) {
    case 0:
    case 1:
    case 2:
      sVar6 = strlen((char *)param_4);
      __dest = malloc(sVar6 + 1);
      puVar3[2] = __dest;
      memcpy(__dest,param_4,sVar6 + 1);
      return param_1;
    case 3:
      puVar8 = (undefined *)malloc(4);
      uVar1 = *(undefined *)param_4;
      puVar3[2] = puVar8;
      *puVar8 = uVar1;
      return param_1;
    case 4:
    case 5:
      puVar5 = (undefined2 *)malloc(4);
      uVar2 = *(undefined2 *)param_4;
      puVar3[2] = puVar5;
      *puVar5 = uVar2;
      return param_1;
    case 6:
    case 7:
    case 8:
    case 9:
    case 0x10:
      puVar7 = (undefined4 *)malloc(4);
      uVar4 = *param_4;
      puVar3[2] = puVar7;
      *puVar7 = uVar4;
      return param_1;
    case 10:
    case 0xb:
      puVar7 = (undefined4 *)malloc(8);
      uVar4 = *param_4;
      uVar10 = param_4[1];
      puVar3[2] = puVar7;
      *puVar7 = uVar4;
      puVar7[1] = uVar10;
      return param_1;
    case 0xc:
    case 0xd:
    case 0x11:
    case 0x12:
    case 0x14:
    case 0x15:
    case 0x17:
    case 0x18:
    case 0x19:
      puVar7 = (undefined4 *)malloc(8);
      uVar4 = *param_4;
      uVar10 = param_4[1];
      puVar3[2] = puVar7;
      *puVar7 = uVar4;
      puVar7[1] = uVar10;
      return param_1;
    case 0xe:
      puVar8 = (undefined *)malloc(1);
      uVar1 = *(undefined *)param_4;
      puVar3[2] = puVar8;
      *puVar8 = uVar1;
      return param_1;
    case 0xf:
      puVar7 = (undefined4 *)malloc(8);
      uVar10 = param_4[1];
      uVar4 = *param_4;
      puVar3[2] = puVar7;
      *puVar7 = uVar4;
      puVar7[1] = uVar10;
      return param_1;
    case 0x13:
    case 0x16:
    case 0x1a:
      puVar7 = (undefined4 *)malloc(4);
      uVar4 = *param_4;
      puVar3[2] = puVar7;
      *puVar7 = uVar4;
      return param_1;
    }
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      snprintf(acStack_820,0x800,"API: unknown1 data type %d ignored",param_3);
      _applog(3,acStack_820,0);
    }
    puVar3[2] = "Unknown";
    *puVar3 = 1;
    *(undefined *)(puVar3 + 3) = 0;
    return param_1;
  }
  puVar3[2] = param_4;
  return param_1;
}

