
undefined4 Curl_follow(int param_1,char *param_2,int param_3)

{
  int iVar1;
  char *__haystack;
  char *pcVar2;
  char *pcVar3;
  size_t __n;
  void *__dest;
  char *pcVar4;
  undefined *puVar5;
  char cVar6;
  char *__s;
  undefined1 uStack_39;
  undefined1 auStack_38 [20];
  
  if (param_3 == 3) {
    if ((*(int *)(param_1 + 0x180) != -1) &&
       (*(int *)(param_1 + 0x180) <= *(int *)(param_1 + 0x17c))) {
      Curl_failf(param_1,"Maximum (%ld) redirects followed");
      return 0x2f;
    }
    *(int *)(param_1 + 0x17c) = *(int *)(param_1 + 0x17c) + 1;
    *(undefined1 *)(param_1 + 0x85a8) = 1;
    if (*(char *)(param_1 + 0x306) != '\0') {
      if (*(char *)(param_1 + 0x45c) != '\0') {
        (*Curl_cfree)(*(undefined4 *)(param_1 + 0x458));
        *(undefined4 *)(param_1 + 0x458) = 0;
        *(undefined1 *)(param_1 + 0x45c) = 0;
      }
      iVar1 = (*Curl_cstrdup)(*(undefined4 *)(param_1 + 0x450));
      *(int *)(param_1 + 0x458) = iVar1;
      if (iVar1 == 0) {
        return 0x1b;
      }
      *(undefined1 *)(param_1 + 0x45c) = 1;
    }
  }
  iVar1 = __isoc99_sscanf(param_2,"%15[^?&/:]://%c",auStack_38,&uStack_39);
  if (iVar1 == 2) {
    iVar1 = strlen_url(param_2);
    __dest = (void *)(*Curl_cmalloc)(iVar1 + 1);
    if (__dest == (void *)0x0) {
      return 0x1b;
    }
    strcpy_url(__dest,param_2);
    (*Curl_cfree)(param_2);
    if (param_3 == 1) goto LAB_0004c0aa;
    *(undefined1 *)(param_1 + 0x85d4) = 0;
  }
  else {
    __haystack = (char *)(*Curl_cstrdup)(*(undefined4 *)(param_1 + 0x450));
    if (__haystack == (char *)0x0) {
      return 0x1b;
    }
    pcVar2 = strstr(__haystack,"//");
    __s = pcVar2 + 2;
    if (pcVar2 == (char *)0x0) {
      __s = __haystack;
    }
    cVar6 = *param_2;
    pcVar2 = param_2;
    if (cVar6 == '/') {
      if (param_2[1] == '/') {
        *__s = '\0';
        pcVar2 = param_2 + 2;
      }
      else {
        pcVar3 = strchr(__s,0x2f);
        if (pcVar3 == (char *)0x0) {
          pcVar3 = strchr(__s,0x3f);
          if (pcVar3 != (char *)0x0) {
            *pcVar3 = '\0';
          }
        }
        else {
          pcVar4 = strchr(__s,0x3f);
          if (pcVar4 != (char *)0x0 && pcVar4 < pcVar3) {
            pcVar3 = pcVar4;
          }
          *pcVar3 = '\0';
        }
      }
    }
    else {
      pcVar3 = strchr(__s,0x3f);
      if (pcVar3 != (char *)0x0) {
        *pcVar3 = '\0';
        cVar6 = *param_2;
      }
      if ((cVar6 != '?') && (pcVar3 = strrchr(__s,0x2f), pcVar3 != (char *)0x0)) {
        *pcVar3 = '\0';
        cVar6 = *param_2;
      }
      pcVar3 = strchr(__s,0x2f);
      __s = pcVar3 + 1;
      if (pcVar3 == (char *)0x0) {
        __s = (char *)0x0;
      }
      if (cVar6 == '.') {
        cVar6 = param_2[1];
        if (cVar6 == '/') {
          pcVar2 = param_2 + 2;
          if (param_2[2] == '.') {
            cVar6 = param_2[3];
            goto LAB_0004c136;
          }
        }
        else {
LAB_0004c136:
          if (cVar6 == '.') {
            iVar1 = 0;
            cVar6 = pcVar2[2];
            pcVar3 = pcVar2;
            while (pcVar2 = pcVar3, cVar6 == '/') {
              pcVar2 = pcVar3 + 3;
              iVar1 = iVar1 + 1;
              if ((*pcVar2 != '.') || (pcVar3[4] != '.')) break;
              cVar6 = pcVar3[5];
              pcVar3 = pcVar2;
            }
            goto LAB_0004bfa4;
          }
        }
        iVar1 = 0;
      }
      else {
        iVar1 = 0;
      }
LAB_0004bfa4:
      if (__s != (char *)0x0) {
        for (; iVar1 != 0; iVar1 = iVar1 + -1) {
          pcVar3 = strrchr(__s,0x2f);
          if (pcVar3 == (char *)0x0) {
            *__s = '\0';
            break;
          }
          *pcVar3 = '\0';
        }
      }
    }
    iVar1 = strlen_url(pcVar2);
    __n = strlen(__haystack);
    __dest = (void *)(*Curl_cmalloc)(__n + iVar1 + 2);
    if (__dest == (void *)0x0) {
      (*Curl_cfree)(__haystack);
      return 0x1b;
    }
    memcpy(__dest,__haystack,__n);
    if ((*pcVar2 != '/') && (((__s == (char *)0x0 || (*__s != '\0')) && (*pcVar2 != '?')))) {
      *(undefined1 *)((int)__dest + __n) = 0x2f;
      __n = __n + 1;
    }
    strcpy_url((int)__dest + __n,pcVar2);
    (*Curl_cfree)(__haystack);
    (*Curl_cfree)(param_2);
    if (param_3 == 1) {
LAB_0004c0aa:
      *(void **)(param_1 + 0x8720) = __dest;
      return 0;
    }
  }
  if (*(char *)(param_1 + 0x454) != '\0') {
    (*Curl_cfree)(*(undefined4 *)(param_1 + 0x450));
  }
  *(void **)(param_1 + 0x450) = __dest;
  *(undefined1 *)(param_1 + 0x454) = 1;
  Curl_infof(param_1,"Issue another request to this URL: \'%s\'\n",__dest);
  iVar1 = *(int *)(param_1 + 0x86f4);
  if (iVar1 == 0x12e) {
    if (1 < *(int *)(param_1 + 0x278) - 2U) goto LAB_0004c064;
    iVar1 = *(int *)(param_1 + 0x184) << 0x1e;
  }
  else {
    if (iVar1 == 0x12f) {
      if ((*(int *)(param_1 + 0x278) != 1) && (-1 < *(int *)(param_1 + 0x184) << 0x1d)) {
        puVar5 = &DAT_00135e90;
        *(undefined4 *)(param_1 + 0x278) = 1;
        if (*(char *)(param_1 + 0x307) != '\0') {
          puVar5 = &DAT_00135e88;
        }
        Curl_infof(param_1,"Disables POST, goes with %s\n",puVar5);
      }
      goto LAB_0004c064;
    }
    if ((iVar1 != 0x12d) || (1 < *(int *)(param_1 + 0x278) - 2U)) goto LAB_0004c064;
    iVar1 = *(int *)(param_1 + 0x184) << 0x1f;
  }
  if (-1 < iVar1) {
    Curl_infof(param_1,"Switch from POST to GET\n");
    *(undefined4 *)(param_1 + 0x278) = 1;
  }
LAB_0004c064:
  Curl_pgrsTime(param_1,10);
  Curl_pgrsResetTimesSizes(param_1);
  return 0;
}

