
char * opt_usage(char *param_1,char *param_2)

{
  size_t sVar1;
  size_t sVar2;
  size_t sVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  char *pcVar12;
  uint uVar13;
  uint uVar14;
  char *local_94;
  int local_7c [20];
  undefined *local_2c;
  
  uVar13 = opt_count;
  puVar10 = opt_table;
  if (param_2 == (char *)0x0) {
    if (opt_count == 0) {
      sVar2 = strlen(param_1);
      local_94 = "";
      sVar2 = opt_num_short + 0x14 + sVar2;
      goto LAB_0004e99a;
    }
    uVar14 = 0;
    puVar11 = opt_table;
    do {
      uVar14 = uVar14 + 1;
      if ((puVar11[2] == 0x4dfc5) && (local_94 = (char *)puVar11[5], local_94 != (char *)0x0)) {
        sVar1 = strlen(local_94);
        goto LAB_0004ebec;
      }
      puVar11 = puVar11 + 7;
    } while (uVar14 != opt_count);
    sVar1 = 0;
    local_94 = "";
LAB_0004ebec:
    sVar2 = strlen(param_1);
    sVar2 = sVar1 + opt_num_short + 0x14 + sVar2;
  }
  else {
    sVar1 = strlen(param_1);
    sVar2 = strlen(param_2);
    sVar2 = sVar1 + opt_num_short + 0x14 + sVar2;
    puVar10 = opt_table;
    uVar13 = opt_count;
    local_94 = param_2;
    if (opt_count == 0) goto LAB_0004e99a;
  }
  uVar14 = 0;
  do {
    while (puVar10[1] == 8) {
      uVar14 = uVar14 + 1;
      sVar1 = strlen((char *)puVar10[6]);
      sVar2 = sVar2 + 3 + sVar1;
      puVar10 = puVar10 + 7;
      if (uVar13 <= uVar14) goto LAB_0004e99a;
    }
    pcVar4 = (char *)puVar10[6];
    if (pcVar4 != (char *)&opt_hidden) {
      sVar1 = strlen((char *)*puVar10);
      sVar3 = strlen(pcVar4);
      iVar5 = sVar3 + sVar2 + 6 + sVar1;
      iVar8 = iVar5 + 0x76;
      if (puVar10[4] == 0) {
        iVar8 = iVar5 + 0x15;
      }
      sVar2 = iVar8 + 1;
    }
    uVar14 = uVar14 + 1;
    puVar10 = puVar10 + 7;
  } while (uVar14 < uVar13);
LAB_0004e99a:
  pcVar4 = (char *)malloc(sVar2);
  if (pcVar4 != (char *)0x0) {
    iVar5 = sprintf(pcVar4,"Usage: %s",param_1);
    pcVar12 = pcVar4 + iVar5;
    *(undefined **)(pcVar4 + iVar5) = &DAT_002d5b20;
    pcVar6 = (char *)first_sopt(local_7c);
    pcVar9 = pcVar12;
    if (pcVar6 != (char *)0x0) {
      iVar5 = 0;
      do {
        if ((undefined4 *)opt_table[local_7c[0] * 7 + 6] != &opt_hidden) {
          pcVar12[iVar5 + 3] = *pcVar6;
          iVar5 = iVar5 + 1;
        }
        pcVar6 = (char *)next_sopt(pcVar6,local_7c);
      } while (pcVar6 != (char *)0x0);
      if (iVar5 != 0) {
        pcVar9 = pcVar12 + iVar5 + 4;
        (pcVar12 + iVar5 + 3)[0] = ']';
        (pcVar12 + iVar5 + 3)[1] = '\0';
      }
    }
    iVar5 = sprintf(pcVar9," %s",local_94);
    uVar13 = opt_count;
    pcVar6 = pcVar9 + iVar5 + 1;
    (pcVar9 + iVar5)[0] = '\n';
    (pcVar9 + iVar5)[1] = '\0';
    if (uVar13 != 0) {
      iVar5 = 0;
      uVar13 = 0;
LAB_0004eb02:
      do {
        puVar10 = (undefined4 *)((int)opt_table + iVar5);
        if ((undefined4 *)puVar10[6] != &opt_hidden) {
          if (puVar10[1] == 8) {
            uVar13 = uVar13 + 1;
            iVar8 = sprintf(pcVar6,"%s:\n");
            pcVar6 = pcVar6 + iVar8;
            iVar5 = iVar5 + 0x1c;
            if (opt_count <= uVar13) break;
            goto LAB_0004eb02;
          }
          uVar14 = sprintf(pcVar6,"%s",*puVar10);
          if (*(int *)((int)opt_table + iVar5 + 4) == 2) {
            pcVar12 = *(char **)((int)opt_table + iVar5);
            pcVar9 = strchr(pcVar12,0x20);
            if ((pcVar9 == (char *)0x0) && (pcVar9 = strchr(pcVar12,0x3d), pcVar9 == (char *)0x0)) {
              builtin_strncpy(pcVar6 + uVar14," <arg>",7);
              uVar14 = uVar14 + 6;
            }
          }
          if (uVar14 < 0x14) {
            iVar8 = 0x14 - uVar14;
          }
          else {
            iVar8 = 1;
          }
          iVar8 = sprintf(pcVar6 + uVar14,"%.*s",iVar8,"                    ");
          iVar7 = sprintf(pcVar6 + uVar14 + iVar8,"%s",
                          *(undefined4 *)((int)opt_table + iVar5 + 0x18));
          iVar7 = uVar14 + iVar8 + iVar7;
          if (*(int *)((int)opt_table + iVar5 + 0x10) != 0) {
            local_2c = &DAT_002e2e2e;
            (**(code **)((int)opt_table + iVar5 + 0x10))
                      (local_7c,*(undefined4 *)((int)opt_table + iVar5 + 0x14));
            iVar8 = sprintf(pcVar6 + iVar7," (default: %s)",local_7c);
            iVar7 = iVar7 + iVar8;
          }
          (pcVar6 + iVar7)[0] = '\n';
          (pcVar6 + iVar7)[1] = '\0';
          pcVar6 = pcVar6 + iVar7 + 1;
        }
        uVar13 = uVar13 + 1;
        iVar5 = iVar5 + 0x1c;
      } while (uVar13 < opt_count);
    }
    *pcVar6 = '\0';
  }
  return pcVar4;
}

