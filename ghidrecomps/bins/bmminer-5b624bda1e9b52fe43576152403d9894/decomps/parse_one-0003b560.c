
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

int parse_one(int *argc,char **argv,uint *offset,_func_void_char_ptr_varargs *errlog)

{
  uchar **ppuVar1;
  char *pcVar2;
  uchar *__s1;
  uchar *puVar3;
  char *o;
  size_t sVar4;
  char *problem;
  int iVar5;
  int iVar6;
  void *__ptr;
  int *piVar7;
  uchar *puVar8;
  uint optnum;
  uchar **ppuVar9;
  uchar *arg;
  uint uVar10;
  uint uVar11;
  uint i;
  uint len;
  
  pcVar2 = getenv(DAT_0003b7fc);
  if (pcVar2 == (char *)0x0) {
    __s1 = (uchar *)argv[1];
    if (__s1 == (uchar *)0x0) {
      return 0;
    }
    if (*__s1 == '-') {
      ppuVar9 = (uchar **)(argv + 1);
      optnum = 1;
    }
    else {
      optnum = 1;
      ppuVar1 = (uchar **)(argv + 2);
      do {
        ppuVar9 = ppuVar1;
        __s1 = *ppuVar9;
        optnum = optnum + 1;
        if (__s1 == (uchar *)0x0) {
          return 0;
        }
        ppuVar1 = ppuVar9 + 1;
      } while (*__s1 != '-');
    }
  }
  else {
    __s1 = (uchar *)argv[1];
    ppuVar9 = (uchar **)(argv + 1);
    if (__s1 == (uchar *)0x0) {
      return 0;
    }
    if (*__s1 != '-') {
      return 0;
    }
    optnum = 1;
  }
  if (__s1[1] == '-') {
    if (__s1[2] == '\0') {
      consume_option(argc,argv,optnum);
      return 0;
    }
    if (*offset != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail(DAT_0003b814,DAT_0003b818,0x3b,DAT_0003b81c);
    }
    pcVar2 = first_lopt(&i,&len);
    sVar4 = len;
    while (pcVar2 != (char *)0x0) {
      puVar8 = *ppuVar9;
      len = sVar4;
      iVar5 = strncmp((char *)(puVar8 + 2),pcVar2,sVar4);
      if (iVar5 == 0) {
        uVar11 = sVar4 + 2;
        piVar7 = DAT_0003b808;
        if (puVar8[uVar11] == '=') {
          arg = puVar8 + sVar4 + 3;
          puVar3 = (uchar *)(pcVar2 + -2);
          iVar5 = *DAT_0003b808 + i * 0x1c;
          iVar6 = *(int *)(iVar5 + 4);
          if (iVar6 == 1) {
            len = uVar11;
            if (arg != (uchar *)0x0) {
              (*errlog)(DAT_0003b804,*argv,uVar11,puVar3,DAT_0003b810);
              return -1;
            }
            goto LAB_0003b654;
          }
          len = uVar11;
          if (arg != (uchar *)0x0) goto LAB_0003b722;
        }
        else {
          if (puVar8[uVar11] != '\0') goto LAB_0003b6a2;
          puVar3 = (uchar *)(pcVar2 + -2);
          iVar5 = i * 0x1c + *DAT_0003b808;
          iVar6 = *(int *)(iVar5 + 4);
          len = uVar11;
          if (iVar6 == 1) goto LAB_0003b654;
        }
        puVar3 = (uchar *)(pcVar2 + -2);
        uVar10 = *offset;
        len = uVar11;
        goto LAB_0003b708;
      }
LAB_0003b6a2:
      pcVar2 = next_lopt(pcVar2,&i,&len);
      sVar4 = len;
    }
  }
  else {
    puVar3 = (uchar *)first_sopt(&i);
    piVar7 = DAT_0003b808;
    while (DAT_0003b808 = piVar7, puVar3 != (uchar *)0x0) {
      puVar8 = *ppuVar9;
      uVar10 = *offset + 1;
      if (puVar8[uVar10] == *puVar3) {
        puVar3 = puVar3 + -1;
        len = 2;
        iVar5 = *piVar7;
        *offset = uVar10;
        iVar5 = iVar5 + i * 0x1c;
        iVar6 = *(int *)(iVar5 + 4);
        if (iVar6 == 1) {
LAB_0003b654:
          arg = (uchar *)0x0;
          __ptr = (void *)(**(code **)(iVar5 + 8))(*(undefined4 *)(iVar5 + 0x14));
        }
        else {
LAB_0003b708:
          if ((uVar10 == 0) || (arg = puVar8 + uVar10 + 1, puVar8[uVar10 + 1] == '\0')) {
            arg = (uchar *)argv[optnum + 1];
            if (arg == (uchar *)0x0) {
              (*errlog)(DAT_0003b804,*argv,len,puVar3,DAT_0003b80c);
              return -1;
            }
          }
          else {
            *offset = 0;
          }
LAB_0003b722:
          if (iVar6 == 4) {
            opt_set_charp((char *)arg,*(char ***)(iVar5 + 0x14));
          }
          iVar5 = *piVar7 + i * 0x1c;
          __ptr = (void *)(**(code **)(iVar5 + 0xc))(arg,*(undefined4 *)(iVar5 + 0x14));
        }
        if (__ptr != (void *)0x0) {
          (*errlog)(DAT_0003b804,*argv,len,puVar3,__ptr);
          free(__ptr);
          return -1;
        }
        if (*offset != 0) {
          if ((*ppuVar9)[*offset + 1] != '\0') {
            return 1;
          }
          *offset = 0;
        }
        consume_option(argc,argv,optnum);
        if ((arg != (uchar *)0x0) && (*ppuVar9 == arg)) {
          consume_option(argc,argv,optnum);
        }
        return 1;
      }
      puVar3 = (uchar *)next_sopt((char *)puVar3,&i);
      piVar7 = DAT_0003b808;
    }
  }
  puVar8 = *ppuVar9;
  sVar4 = strlen((char *)puVar8);
  (*errlog)(DAT_0003b804,*argv,sVar4,puVar8,DAT_0003b800);
  return -1;
}

