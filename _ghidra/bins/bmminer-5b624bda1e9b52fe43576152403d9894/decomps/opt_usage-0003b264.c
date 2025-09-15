
/* WARNING: Unknown calling convention */

char * opt_usage(char *argv0,char *extra)

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
  opt_table *poVar11;
  opt_table *poVar12;
  char *pcVar13;
  uint uVar14;
  uint uVar15;
  uint num;
  char *local_88;
  uint local_80;
  char buf [84];
  
  poVar12 = opt_table;
  uVar15 = opt_count;
  if (extra == (char *)0x0) {
    if (opt_count == 0) {
      sVar2 = strlen(argv0);
      local_88 = "";
      sVar2 = opt_num_short + 0x14 + sVar2;
      goto LAB_0003b2f2;
    }
    uVar14 = 0;
    poVar11 = opt_table;
    do {
      uVar14 = uVar14 + 1;
      if ((poVar11->cb == (_func_char_ptr_void_ptr *)0x3ac41) &&
         (local_88 = (char *)(poVar11->u).carg, local_88 != (char *)0x0)) {
        sVar2 = strlen(local_88);
        goto LAB_0003b4dc;
      }
      poVar11 = poVar11 + 1;
    } while (uVar14 != opt_count);
    sVar2 = 0;
    local_88 = "";
LAB_0003b4dc:
    sVar1 = strlen(argv0);
    sVar2 = opt_num_short + 0x14 + sVar1 + sVar2;
  }
  else {
    sVar1 = strlen(argv0);
    sVar2 = strlen(extra);
    sVar2 = opt_num_short + 0x14 + sVar1 + sVar2;
    poVar12 = opt_table;
    uVar15 = opt_count;
    local_88 = extra;
    if (opt_count == 0) goto LAB_0003b2f2;
  }
  uVar14 = 0;
  do {
    while (poVar12->type == OPT_SUBTABLE) {
      uVar14 = uVar14 + 1;
      sVar1 = strlen(poVar12->desc);
      sVar2 = sVar2 + 3 + sVar1;
      poVar12 = poVar12 + 1;
      if (uVar15 <= uVar14) goto LAB_0003b2f2;
    }
    pcVar4 = poVar12->desc;
    if (pcVar4 != opt_hidden) {
      sVar1 = strlen(poVar12->names);
      sVar3 = strlen(pcVar4);
      iVar5 = sVar3 + sVar2 + 6 + sVar1;
      iVar8 = iVar5 + 0x15;
      if (poVar12->show != (_func_void_char_ptr_void_ptr *)0x0) {
        iVar8 = iVar5 + 0x76;
      }
      sVar2 = iVar8 + 1;
    }
    uVar14 = uVar14 + 1;
    poVar12 = poVar12 + 1;
  } while (uVar14 < uVar15);
LAB_0003b2f2:
  pcVar4 = (char *)malloc(sVar2);
  if (pcVar4 != (char *)0x0) {
    iVar5 = sprintf(pcVar4,"Usage: %s",argv0);
    pcVar13 = pcVar4 + iVar5;
    builtin_strncpy(pcVar4 + iVar5," [-",4);
    pcVar6 = first_sopt(&local_80);
    pcVar9 = pcVar13;
    if (pcVar6 != (char *)0x0) {
      iVar5 = 0;
      do {
        if (opt_table[local_80].desc != opt_hidden) {
          pcVar13[iVar5 + 3] = *pcVar6;
          iVar5 = iVar5 + 1;
        }
        pcVar6 = next_sopt(pcVar6,&local_80);
      } while (pcVar6 != (char *)0x0);
      if (iVar5 != 0) {
        pcVar9 = pcVar13 + iVar5 + 4;
        (pcVar13 + iVar5 + 3)[0] = ']';
        (pcVar13 + iVar5 + 3)[1] = '\0';
      }
    }
    iVar5 = sprintf(pcVar9," %s",local_88);
    pcVar6 = pcVar9 + iVar5 + 1;
    (pcVar9 + iVar5)[0] = '\n';
    (pcVar9 + iVar5)[1] = '\0';
    if (opt_count != 0) {
      iVar5 = 0;
      uVar15 = 0;
LAB_0003b41a:
      do {
        puVar10 = (undefined4 *)((int)&opt_table->names + iVar5);
        if ((char *)puVar10[6] != opt_hidden) {
          if (puVar10[1] == 8) {
            iVar8 = sprintf(pcVar6,"%s:\n");
            uVar15 = uVar15 + 1;
            pcVar6 = pcVar6 + iVar8;
            iVar5 = iVar5 + 0x1c;
            if (opt_count <= uVar15) break;
            goto LAB_0003b41a;
          }
          uVar14 = sprintf(pcVar6,"%s",*puVar10);
          if (*(int *)((int)&opt_table->type + iVar5) == 2) {
            pcVar13 = *(char **)((int)&opt_table->names + iVar5);
            pcVar9 = strchr(pcVar13,0x20);
            if ((pcVar9 == (char *)0x0) && (pcVar9 = strchr(pcVar13,0x3d), pcVar9 == (char *)0x0)) {
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
                          *(undefined4 *)((int)&opt_table->desc + iVar5));
          iVar7 = uVar14 + iVar8 + iVar7;
          if (*(int *)((int)&opt_table->show + iVar5) != 0) {
            builtin_strncpy(buf + 0x50,"...",4);
            (**(code **)((int)&opt_table->show + iVar5))
                      (buf,*(undefined4 *)((int)&opt_table->u + iVar5));
            iVar8 = sprintf(pcVar6 + iVar7," (default: %s)",buf);
            iVar7 = iVar7 + iVar8;
          }
          (pcVar6 + iVar7)[0] = '\n';
          (pcVar6 + iVar7)[1] = '\0';
          pcVar6 = pcVar6 + iVar7 + 1;
        }
        uVar15 = uVar15 + 1;
        iVar5 = iVar5 + 0x1c;
      } while (uVar15 < opt_count);
    }
    *pcVar6 = '\0';
  }
  return pcVar4;
}

