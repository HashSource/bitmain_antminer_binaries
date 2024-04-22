
undefined4 parse_one(undefined4 param_1,undefined4 *param_2,int *param_3,code *param_4)

{
  char **ppcVar1;
  char *pcVar2;
  char *__s2;
  int iVar3;
  int iVar4;
  void *__ptr;
  size_t sVar5;
  size_t sVar6;
  int iVar7;
  char **ppcVar8;
  char *pcVar9;
  int iVar10;
  char *local_38;
  int local_30;
  size_t local_2c [2];
  
  pcVar2 = getenv("POSIXLY_CORRECT");
  if (pcVar2 == (char *)0x0) {
    pcVar2 = (char *)param_2[1];
    if (pcVar2 == (char *)0x0) {
      return 0;
    }
    if (*pcVar2 == '-') {
      ppcVar8 = (char **)(param_2 + 1);
      iVar7 = 1;
    }
    else {
      iVar7 = 1;
      ppcVar1 = (char **)(param_2 + 2);
      do {
        ppcVar8 = ppcVar1;
        pcVar2 = *ppcVar8;
        iVar7 = iVar7 + 1;
        if (pcVar2 == (char *)0x0) {
          return 0;
        }
        ppcVar1 = ppcVar8 + 1;
      } while (*pcVar2 != '-');
    }
  }
  else {
    pcVar2 = (char *)param_2[1];
    ppcVar8 = (char **)(param_2 + 1);
    if (pcVar2 == (char *)0x0) {
      return 0;
    }
    if (*pcVar2 != '-') {
      return 0;
    }
    iVar7 = 1;
  }
  if (pcVar2[1] == '-') {
    if (pcVar2[2] == '\0') {
      consume_option(param_1,param_2,iVar7);
      return 0;
    }
    if (*param_3 != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("*offset == 0","ccan/opt/parse.c",0x3b,"parse_one");
    }
    __s2 = (char *)first_lopt(&local_30,local_2c);
    sVar5 = local_2c[0];
    while (__s2 != (char *)0x0) {
      pcVar2 = *ppcVar8;
      local_2c[0] = sVar5;
      iVar3 = strncmp(pcVar2 + 2,__s2,sVar5);
      if (iVar3 == 0) {
        sVar6 = sVar5 + 2;
        if (pcVar2[sVar6] == '=') {
          pcVar9 = pcVar2 + sVar5 + 3;
          local_38 = __s2 + -2;
          iVar4 = opt_table + local_30 * 0x1c;
          iVar10 = *(int *)(iVar4 + 4);
          if (iVar10 == 1) {
            local_2c[0] = sVar6;
            if (pcVar9 != (char *)0x0) {
              (*param_4)("%s: %.*s: %s",*param_2,sVar6,local_38,"doesn\'t allow an argument");
              return 0xffffffff;
            }
            goto LAB_0004e77a;
          }
          local_2c[0] = sVar6;
          if (pcVar9 != (char *)0x0) goto LAB_0004e6ba;
        }
        else {
          if (pcVar2[sVar6] != '\0') goto LAB_0004e786;
          local_38 = __s2 + -2;
          iVar4 = opt_table + local_30 * 0x1c;
          iVar10 = *(int *)(iVar4 + 4);
          local_2c[0] = sVar6;
          if (iVar10 == 1) goto LAB_0004e77a;
        }
        local_38 = __s2 + -2;
        iVar3 = *param_3;
        local_2c[0] = sVar6;
        goto LAB_0004e6a2;
      }
LAB_0004e786:
      __s2 = (char *)next_lopt(__s2,&local_30,local_2c);
      sVar5 = local_2c[0];
    }
  }
  else {
    local_38 = (char *)first_sopt(&local_30);
    if (local_38 != (char *)0x0) {
      pcVar2 = *ppcVar8;
      iVar3 = *param_3 + 1;
      if (pcVar2[iVar3] != *local_38) {
        do {
          local_38 = (char *)next_sopt(local_38,&local_30);
          if (local_38 == (char *)0x0) goto LAB_0004e798;
          pcVar2 = *ppcVar8;
          iVar3 = *param_3 + 1;
        } while (pcVar2[iVar3] != *local_38);
      }
      iVar4 = opt_table;
      local_38 = local_38 + -1;
      local_2c[0] = 2;
      *param_3 = iVar3;
      iVar4 = iVar4 + local_30 * 0x1c;
      iVar10 = *(int *)(iVar4 + 4);
      if (iVar10 == 1) {
LAB_0004e77a:
        pcVar9 = (char *)0x0;
        __ptr = (void *)(**(code **)(iVar4 + 8))(*(undefined4 *)(iVar4 + 0x14));
      }
      else {
LAB_0004e6a2:
        if ((iVar3 == 0) || (pcVar9 = pcVar2 + iVar3 + 1, pcVar2[iVar3 + 1] == '\0')) {
          pcVar9 = (char *)param_2[iVar7 + 1];
          if (pcVar9 == (char *)0x0) {
            (*param_4)("%s: %.*s: %s",*param_2,local_2c[0],local_38,"requires an argument");
            return 0xffffffff;
          }
        }
        else {
          *param_3 = 0;
        }
LAB_0004e6ba:
        if (iVar10 == 4) {
          opt_set_charp(pcVar9,*(undefined4 *)(iVar4 + 0x14));
        }
        iVar3 = opt_table + local_30 * 0x1c;
        __ptr = (void *)(**(code **)(iVar3 + 0xc))(pcVar9,*(undefined4 *)(iVar3 + 0x14));
      }
      if (__ptr != (void *)0x0) {
        (*param_4)("%s: %.*s: %s",*param_2,local_2c[0],local_38,__ptr);
        free(__ptr);
        return 0xffffffff;
      }
      if (*param_3 != 0) {
        if ((*ppcVar8)[*param_3 + 1] != '\0') {
          return 1;
        }
        *param_3 = 0;
      }
      consume_option(param_1,param_2,iVar7);
      if ((pcVar9 != (char *)0x0) && (pcVar9 == *ppcVar8)) {
        consume_option(param_1,param_2,iVar7);
      }
      return 1;
    }
  }
LAB_0004e798:
  pcVar2 = *ppcVar8;
  sVar5 = strlen(pcVar2);
  (*param_4)("%s: %.*s: %s",*param_2,sVar5,pcVar2,"unrecognized option");
  return 0xffffffff;
}

