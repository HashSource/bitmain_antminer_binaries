
char * opt_usage(char *param_1,char *param_2)

{
  undefined2 uVar1;
  char cVar2;
  size_t sVar3;
  size_t sVar4;
  size_t sVar5;
  char *__s;
  int iVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined4 *puVar12;
  char **ppcVar13;
  char **ppcVar14;
  char *pcVar15;
  uint uVar16;
  uint uVar17;
  char *local_94;
  int local_7c [20];
  undefined *local_2c;
  
  uVar16 = opt_count;
  ppcVar14 = opt_table;
  if (param_2 == (char *)0x0) {
    if (opt_count == 0) {
      sVar4 = strlen(param_1);
      local_94 = "";
      sVar4 = opt_num_short + 0x14 + sVar4;
      goto LAB_0004e99a;
    }
    uVar17 = 0;
    ppcVar13 = opt_table;
    do {
      uVar17 = uVar17 + 1;
      if (((code *)ppcVar13[2] == opt_usage_and_exit + 1) &&
         (local_94 = ppcVar13[5], local_94 != (char *)0x0)) {
        sVar3 = strlen(local_94);
        goto LAB_0004ebec;
      }
      ppcVar13 = ppcVar13 + 7;
    } while (uVar17 != opt_count);
    sVar3 = 0;
    local_94 = "";
LAB_0004ebec:
    sVar4 = strlen(param_1);
    sVar4 = sVar3 + opt_num_short + 0x14 + sVar4;
  }
  else {
    sVar3 = strlen(param_1);
    sVar4 = strlen(param_2);
    sVar4 = sVar3 + opt_num_short + 0x14 + sVar4;
    ppcVar14 = opt_table;
    uVar16 = opt_count;
    local_94 = param_2;
    if (opt_count == 0) goto LAB_0004e99a;
  }
  uVar17 = 0;
  do {
    while (ppcVar14[1] != (char *)0x8) {
      puVar12 = (undefined4 *)ppcVar14[6];
      if (puVar12 != &opt_hidden) {
        sVar3 = strlen(*ppcVar14);
        sVar5 = strlen((char *)puVar12);
        iVar6 = sVar5 + sVar4 + 6 + sVar3;
        iVar10 = iVar6 + 0x76;
        if (ppcVar14[4] == (char *)0x0) {
          iVar10 = iVar6 + 0x15;
        }
        sVar4 = iVar10 + 1;
      }
      uVar17 = uVar17 + 1;
      ppcVar14 = ppcVar14 + 7;
      if (uVar16 <= uVar17) goto LAB_0004e99a;
    }
    uVar17 = uVar17 + 1;
    sVar3 = strlen(ppcVar14[6]);
    sVar4 = sVar4 + 3 + sVar3;
    ppcVar14 = ppcVar14 + 7;
  } while (uVar17 < uVar16);
LAB_0004e99a:
  __s = (char *)malloc(sVar4);
  if (__s != (char *)0x0) {
    iVar6 = sprintf(__s,"Usage: %s",param_1);
    pcVar15 = __s + iVar6;
    *(undefined4 *)(__s + iVar6) = DAT_00069808;
    pcVar7 = (char *)first_sopt(local_7c);
    pcVar11 = pcVar15;
    if (pcVar7 != (char *)0x0) {
      iVar6 = 0;
      do {
        if ((undefined4 *)opt_table[local_7c[0] * 7 + 6] != &opt_hidden) {
          pcVar15[iVar6 + 3] = *pcVar7;
          iVar6 = iVar6 + 1;
        }
        pcVar7 = (char *)next_sopt(pcVar7,local_7c);
      } while (pcVar7 != (char *)0x0);
      if (iVar6 != 0) {
        pcVar11 = pcVar15 + iVar6 + 4;
        *(undefined2 *)(pcVar15 + iVar6 + 3) = s___02d__02d__02d__03d__0005e04c._20_2_;
      }
    }
    iVar6 = sprintf(pcVar11," %s",local_94);
    uVar16 = opt_count;
    pcVar7 = pcVar11 + iVar6 + 1;
    *(undefined2 *)(pcVar11 + iVar6) = DAT_00065a34;
    if (uVar16 != 0) {
      iVar6 = 0;
      uVar16 = 0;
      do {
        while (puVar12 = (undefined4 *)((int)opt_table + iVar6),
              (undefined4 *)puVar12[6] == &opt_hidden) {
LAB_0004eaf4:
          uVar16 = uVar16 + 1;
          iVar6 = iVar6 + 0x1c;
          if (opt_count <= uVar16) goto LAB_0004eb30;
        }
        if (puVar12[1] != 8) {
          iVar8 = sprintf(pcVar7,"%s",*puVar12);
          iVar10 = iVar8;
          if (*(int *)((int)opt_table + iVar6 + 4) == 2) {
            pcVar15 = *(char **)((int)opt_table + iVar6);
            pcVar11 = strchr(pcVar15,0x20);
            if ((pcVar11 == (char *)0x0) &&
               (pcVar11 = strchr(pcVar15,0x3d), cVar2 = DAT_00069812, uVar1 = DAT_00069810,
               pcVar11 == (char *)0x0)) {
              *(undefined4 *)(pcVar7 + iVar8) = DAT_0006980c;
              iVar10 = iVar8 + 6;
              *(undefined2 *)(pcVar7 + iVar8 + 4) = uVar1;
              pcVar7[iVar8 + 6] = cVar2;
            }
          }
          iVar8 = sprintf(pcVar7 + iVar10,"%.*s");
          iVar9 = sprintf(pcVar7 + iVar10 + iVar8,"%s",
                          *(undefined4 *)((int)opt_table + iVar6 + 0x18));
          iVar9 = iVar10 + iVar8 + iVar9;
          if (*(int *)((int)opt_table + iVar6 + 0x10) != 0) {
            local_2c = &DAT_002e2e2e;
            (**(code **)((int)opt_table + iVar6 + 0x10))
                      (local_7c,*(undefined4 *)((int)opt_table + iVar6 + 0x14));
            iVar10 = sprintf(pcVar7 + iVar9," (default: %s)",local_7c);
            iVar9 = iVar9 + iVar10;
          }
          *(undefined2 *)(pcVar7 + iVar9) = DAT_00065a34;
          pcVar7 = pcVar7 + iVar9 + 1;
          goto LAB_0004eaf4;
        }
        uVar16 = uVar16 + 1;
        iVar10 = sprintf(pcVar7,"%s:\n");
        pcVar7 = pcVar7 + iVar10;
        iVar6 = iVar6 + 0x1c;
      } while (uVar16 < opt_count);
    }
LAB_0004eb30:
    *pcVar7 = '\0';
  }
  return __s;
}

