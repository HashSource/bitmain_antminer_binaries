
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

int parse_one(int *argc,char **argv,uint *offset,_func_void_char_ptr_varargs *errlog)

{
  char **ppcVar1;
  char *pcVar2;
  char *pcVar3;
  size_t sVar4;
  int iVar5;
  opt_type oVar6;
  char *pcVar7;
  uint optnum;
  char **ppcVar8;
  char *arg;
  opt_table *poVar9;
  uint uVar10;
  uint uVar11;
  uint local_30;
  uint local_2c [2];
  
  pcVar2 = getenv("POSIXLY_CORRECT");
  if (pcVar2 == (char *)0x0) {
    pcVar2 = argv[1];
    if (pcVar2 == (char *)0x0) {
      return 0;
    }
    if (*pcVar2 == '-') {
      ppcVar8 = argv + 1;
      optnum = 1;
    }
    else {
      optnum = 1;
      ppcVar1 = argv + 2;
      do {
        ppcVar8 = ppcVar1;
        pcVar2 = *ppcVar8;
        optnum = optnum + 1;
        if (pcVar2 == (char *)0x0) {
          return 0;
        }
        ppcVar1 = ppcVar8 + 1;
      } while (*pcVar2 != '-');
    }
  }
  else {
    pcVar2 = argv[1];
    ppcVar8 = argv + 1;
    if (pcVar2 == (char *)0x0) {
      return 0;
    }
    if (*pcVar2 != '-') {
      return 0;
    }
    optnum = 1;
  }
  if (pcVar2[1] == '-') {
    if (pcVar2[2] == '\0') {
      consume_option(argc,argv,optnum);
      return 0;
    }
    if (*offset != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("*offset == 0","ccan/opt/parse.c",0x3b,"parse_one");
    }
    pcVar2 = first_lopt(&local_30,local_2c);
    sVar4 = local_2c[0];
    while (pcVar2 != (char *)0x0) {
      pcVar7 = *ppcVar8;
      local_2c[0] = sVar4;
      iVar5 = strncmp(pcVar7 + 2,pcVar2,sVar4);
      if (iVar5 == 0) {
        uVar11 = sVar4 + 2;
        if (pcVar7[uVar11] == '=') {
          arg = pcVar7 + sVar4 + 3;
          pcVar3 = pcVar2 + -2;
          poVar9 = opt_table + local_30;
          oVar6 = poVar9->type;
          if (oVar6 == OPT_NOARG) {
            local_2c[0] = uVar11;
            if (arg != (char *)0x0) {
              (*errlog)("%s: %.*s: %s",*argv,uVar11,pcVar3,"doesn\'t allow an argument");
              return -1;
            }
            goto LAB_0003b654;
          }
          local_2c[0] = uVar11;
          if (arg != (char *)0x0) goto LAB_0003b722;
        }
        else {
          if (pcVar7[uVar11] != '\0') goto LAB_0003b6a2;
          pcVar3 = pcVar2 + -2;
          poVar9 = opt_table + local_30;
          oVar6 = poVar9->type;
          local_2c[0] = uVar11;
          if (oVar6 == OPT_NOARG) goto LAB_0003b654;
        }
        poVar9 = opt_table + local_30;
        pcVar3 = pcVar2 + -2;
        uVar10 = *offset;
        local_2c[0] = uVar11;
        goto LAB_0003b708;
      }
LAB_0003b6a2:
      pcVar2 = next_lopt(pcVar2,&local_30,local_2c);
      sVar4 = local_2c[0];
    }
  }
  else {
    pcVar3 = first_sopt(&local_30);
    poVar9 = opt_table;
    while (opt_table = poVar9, pcVar3 != (char *)0x0) {
      pcVar7 = *ppcVar8;
      uVar10 = *offset + 1;
      if (pcVar7[uVar10] == *pcVar3) {
        pcVar3 = pcVar3 + -1;
        local_2c[0] = 2;
        *offset = uVar10;
        poVar9 = poVar9 + local_30;
        oVar6 = poVar9->type;
        if (oVar6 == OPT_NOARG) {
LAB_0003b654:
          arg = (char *)0x0;
          pcVar2 = (*poVar9->cb)((poVar9->u).carg);
        }
        else {
LAB_0003b708:
          if ((uVar10 == 0) || (arg = pcVar7 + uVar10 + 1, pcVar7[uVar10 + 1] == '\0')) {
            arg = argv[optnum + 1];
            if (arg == (char *)0x0) {
              (*errlog)("%s: %.*s: %s",*argv,local_2c[0],pcVar3,"requires an argument");
              return -1;
            }
          }
          else {
            *offset = 0;
          }
LAB_0003b722:
          if (oVar6 == OPT_PROCESSARG) {
            opt_set_charp(arg,(char **)(poVar9->u).carg);
          }
          pcVar2 = (*opt_table[local_30].cb_arg)(arg,opt_table[local_30].u.carg);
        }
        if (pcVar2 != (char *)0x0) {
          (*errlog)("%s: %.*s: %s",*argv,local_2c[0],pcVar3,pcVar2);
          free(pcVar2);
          return -1;
        }
        if (*offset != 0) {
          if ((*ppcVar8)[*offset + 1] != '\0') {
            return 1;
          }
          *offset = 0;
        }
        consume_option(argc,argv,optnum);
        if ((arg != (char *)0x0) && (*ppcVar8 == arg)) {
          consume_option(argc,argv,optnum);
        }
        return 1;
      }
      pcVar3 = next_sopt(pcVar3,&local_30);
      poVar9 = opt_table;
    }
  }
  pcVar2 = *ppcVar8;
  sVar4 = strlen(pcVar2);
  (*errlog)("%s: %.*s: %s",*argv,sVar4,pcVar2,"unrecognized option");
  return -1;
}

