
undefined4 Curl_follow(int param_1,char *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  char *__haystack;
  char *pcVar3;
  char *pcVar4;
  size_t __n;
  void *__dest;
  char *pcVar5;
  undefined4 uVar6;
  char cVar7;
  char *__s;
  code **ppcVar8;
  undefined uStack_39;
  undefined auStack_38 [20];
  
  if (param_3 == 3) {
    if ((*(int *)(param_1 + 0x180) != -1) &&
       (*(int *)(param_1 + 0x180) <= *(int *)(param_1 + 0x17c))) {
      Curl_failf(param_1,DAT_0004c1f4);
      return 0x2f;
    }
    *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + 1;
    *(undefined *)(param_1 + 0x85a8) = 1;
    if (*(char *)(param_1 + 0x306) != '\0') {
      if (*(char *)(param_1 + 0x45c) != '\0') {
        (**DAT_0004c288)(*(undefined4 *)(param_1 + 0x458));
        *(undefined4 *)(param_1 + 0x458) = 0;
        *(undefined *)(param_1 + 0x45c) = 0;
      }
      iVar2 = (**DAT_0004c1e0)(*(undefined4 *)(param_1 + 0x450));
      *(int *)(param_1 + 0x458) = iVar2;
      if (iVar2 == 0) {
        return 0x1b;
      }
      *(undefined *)(param_1 + 0x45c) = 1;
    }
  }
  iVar2 = __isoc99_sscanf(param_2,DAT_0004c1dc,auStack_38,&uStack_39);
  if (iVar2 == 2) {
    iVar2 = strlen_url(param_2);
    __dest = (void *)(**DAT_0004c1e8)(iVar2 + 1);
    ppcVar8 = DAT_0004c1ec;
    if (__dest == (void *)0x0) {
      return 0x1b;
    }
    strcpy_url(__dest,param_2);
    (**ppcVar8)(param_2);
    if (param_3 == 1) goto LAB_0004c0aa;
    *(undefined *)(param_1 + 0x85d4) = 0;
  }
  else {
    __haystack = (char *)(**DAT_0004c1e0)(*(undefined4 *)(param_1 + 0x450));
    if (__haystack == (char *)0x0) {
      return 0x1b;
    }
    pcVar3 = strstr(__haystack,DAT_0004c1e4);
    __s = pcVar3 + 2;
    if (pcVar3 == (char *)0x0) {
      __s = __haystack;
    }
    cVar7 = *param_2;
    pcVar3 = param_2;
    if (cVar7 == '/') {
      if (param_2[1] == '/') {
        *__s = '\0';
        pcVar3 = param_2 + 2;
      }
      else {
        pcVar4 = strchr(__s,0x2f);
        if (pcVar4 == (char *)0x0) {
          pcVar4 = strchr(__s,0x3f);
          if (pcVar4 != (char *)0x0) {
            *pcVar4 = '\0';
          }
        }
        else {
          pcVar5 = strchr(__s,0x3f);
          if ((pcVar5 == (char *)0x0 || pcVar5 <= pcVar4) &&
              (pcVar5 != (char *)0x0 && pcVar4 != pcVar5)) {
            pcVar4 = pcVar5;
          }
          *pcVar4 = '\0';
        }
      }
    }
    else {
      pcVar4 = strchr(__s,0x3f);
      if (pcVar4 != (char *)0x0) {
        *pcVar4 = '\0';
        cVar7 = *param_2;
      }
      if ((cVar7 != '?') && (pcVar4 = strrchr(__s,0x2f), pcVar4 != (char *)0x0)) {
        *pcVar4 = '\0';
        cVar7 = *param_2;
      }
      pcVar4 = strchr(__s,0x2f);
      __s = pcVar4 + 1;
      if (pcVar4 == (char *)0x0) {
        __s = (char *)0x0;
      }
      if (cVar7 == '.') {
        cVar7 = param_2[1];
        if (cVar7 == '/') {
          pcVar3 = param_2 + 2;
          if (param_2[2] == '.') {
            cVar7 = param_2[3];
            goto LAB_0004c136;
          }
        }
        else {
LAB_0004c136:
          if (cVar7 == '.') {
            iVar2 = 0;
            cVar7 = pcVar3[2];
            pcVar4 = pcVar3;
            while (pcVar3 = pcVar4, cVar7 == '/') {
              pcVar3 = pcVar4 + 3;
              iVar2 = iVar2 + 1;
              if ((*pcVar3 != '.') || (pcVar4[4] != '.')) break;
              cVar7 = pcVar4[5];
              pcVar4 = pcVar3;
            }
            goto LAB_0004bfa4;
          }
        }
        iVar2 = 0;
      }
      else {
        iVar2 = 0;
      }
LAB_0004bfa4:
      if (__s != (char *)0x0) {
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          pcVar4 = strrchr(__s,0x2f);
          if (pcVar4 == (char *)0x0) {
            *__s = '\0';
            break;
          }
          *pcVar4 = '\0';
        }
      }
    }
    iVar2 = strlen_url(pcVar3);
    __n = strlen(__haystack);
    __dest = (void *)(**DAT_0004c1e8)(__n + iVar2 + 2);
    if (__dest == (void *)0x0) {
      (**DAT_0004c1ec)(__haystack);
      return 0x1b;
    }
    memcpy(__dest,__haystack,__n);
    if ((*pcVar3 != '/') && (((__s == (char *)0x0 || (*__s != '\0')) && (*pcVar3 != '?')))) {
      *(undefined *)((int)__dest + __n) = 0x2f;
      __n = __n + 1;
    }
    ppcVar8 = DAT_0004c1ec;
    strcpy_url((int)__dest + __n,pcVar3);
    (**ppcVar8)(__haystack);
    (**ppcVar8)(param_2);
    if (param_3 == 1) {
LAB_0004c0aa:
      *(void **)(param_1 + 0x8720) = __dest;
      return 0;
    }
  }
  if (*(char *)(param_1 + 0x454) != '\0') {
    (**ppcVar8)(*(undefined4 *)(param_1 + 0x450));
  }
  *(void **)(param_1 + 0x450) = __dest;
  *(undefined *)(param_1 + 0x454) = 1;
  Curl_infof(param_1,DAT_0004c1f0,__dest);
  uVar6 = DAT_0004c1fc;
  uVar1 = DAT_0004c1f8;
  iVar2 = *(int *)(param_1 + 0x86f4);
  if (iVar2 == 0x12e) {
    if (1 < *(int *)(param_1 + 0x278) - 2U) goto LAB_0004c064;
    iVar2 = *(int *)(param_1 + 0x184) << 0x1e;
  }
  else {
    if (iVar2 == 0x12f) {
      if ((*(int *)(param_1 + 0x278) != 1) && (-1 < *(int *)(param_1 + 0x184) << 0x1d)) {
        *(undefined4 *)(param_1 + 0x278) = 1;
        if (*(char *)(param_1 + 0x307) != '\0') {
          uVar6 = uVar1;
        }
        Curl_infof(param_1,DAT_0004c200,uVar6);
      }
      goto LAB_0004c064;
    }
    if ((iVar2 != 0x12d) || (1 < *(int *)(param_1 + 0x278) - 2U)) goto LAB_0004c064;
    iVar2 = *(int *)(param_1 + 0x184) << 0x1f;
  }
  if (-1 < iVar2) {
    Curl_infof(param_1,DAT_0004c204);
    *(undefined4 *)(param_1 + 0x278) = 1;
  }
LAB_0004c064:
  Curl_pgrsTime(param_1,10);
  Curl_pgrsResetTimesSizes(param_1);
  return 0;
}

