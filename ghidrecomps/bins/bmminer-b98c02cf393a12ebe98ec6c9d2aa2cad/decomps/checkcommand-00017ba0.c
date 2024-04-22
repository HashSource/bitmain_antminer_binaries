
void checkcommand(int param_1,undefined4 param_2,char *param_3,uint param_4,byte param_5)

{
  int iVar1;
  __int32_t **pp_Var2;
  uint uVar3;
  undefined4 uVar4;
  __int32_t *p_Var5;
  undefined uVar6;
  undefined *puVar7;
  undefined1 *puVar8;
  char *pcVar9;
  bool bVar10;
  char acStack_7c [100];
  
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    message(param_1,0x47,0,0,param_4);
    return;
  }
  if (cmds._0_4_ != 0) {
    puVar8 = cmds;
    pcVar9 = (char *)cmds._0_4_;
    do {
      iVar1 = strcmp(pcVar9,param_3);
      if (iVar1 == 0) {
        sprintf(acStack_7c,"|%s|",param_3);
        pp_Var2 = __ctype_toupper_loc();
        p_Var5 = *pp_Var2;
        if (p_Var5[param_5] == p_Var5[0x57]) {
          pcVar9 = (char *)0x1;
        }
        else {
          pcVar9 = strstr(*(char **)(apigroups + (p_Var5[param_5] - p_Var5[0x41]) * 4),acStack_7c);
          if (pcVar9 != (char *)0x0) {
            pcVar9 = (char *)0x1;
          }
        }
        message(param_1,0x48,0,0,param_4);
        if (param_4 == 0) {
          uVar3 = io_add(param_1,"CHECK,");
        }
        else {
          uVar3 = io_add(param_1,",\"CHECK\":[");
        }
        uVar4 = api_add_data_full(0,"Exists",2,&DAT_000580ec,0);
        puVar7 = &DAT_000580ec;
        if (pcVar9 == (char *)0x0) {
          puVar7 = &DAT_000580f0;
        }
        goto LAB_00017cd0;
      }
      puVar8 = (undefined1 *)((int)puVar8 + 0xc);
      pcVar9 = *(char **)puVar8;
    } while (pcVar9 != (char *)0x0);
  }
  message(param_1,0x48,0,0,param_4);
  if (param_4 == 0) {
    uVar3 = io_add(param_1,"CHECK,");
  }
  else {
    uVar3 = io_add(param_1,",\"CHECK\":[");
  }
  uVar4 = api_add_data_full(0,"Exists",2,&DAT_000580f0,0);
  puVar7 = &DAT_000580f0;
LAB_00017cd0:
  uVar4 = api_add_data_full(uVar4,"Access",2,puVar7,0);
  uVar6 = 0;
  print_data(param_1,uVar4,param_4);
  bVar10 = (param_4 & uVar3) != 0;
  if (bVar10) {
    uVar6 = 1;
  }
  if (bVar10) {
    *(undefined *)(param_1 + 0xd) = uVar6;
  }
  return;
}

