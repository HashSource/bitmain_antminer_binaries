
/* WARNING: Type propagation algorithm not settling */

char * parse_login_details(char *param_1,size_t param_2,undefined4 *param_3,char *param_4,
                          char *param_5)

{
  char *pcVar1;
  char *pcVar2;
  char *__dest;
  char *__dest_00;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  size_t sVar6;
  char *__n;
  void *__dest_01;
  
  pcVar1 = param_4;
  if ((param_4 != (char *)0x0) && (pcVar1 = strchr(param_1,0x3a), param_1 + param_2 <= pcVar1)) {
    pcVar1 = (char *)0x0;
  }
  sVar6 = param_2;
  if ((param_5 == (char *)0x0) || (pcVar2 = strchr(param_1,0x3b), param_1 + param_2 <= pcVar2)) {
    if (pcVar1 != (char *)0x0) {
      pcVar2 = (char *)0x0;
      uVar5 = 1;
      pcVar3 = (char *)0x0;
      sVar6 = (int)pcVar1 - (int)param_1;
      goto LAB_000433ea;
    }
    pcVar2 = (char *)0x0;
LAB_0004358a:
    pcVar3 = (char *)0x0;
LAB_00043446:
    if (pcVar2 == (char *)0x0) {
      __n = (char *)0x0;
      goto LAB_0004346a;
    }
    if (pcVar1 == (char *)0x0 || pcVar1 <= pcVar2) {
LAB_0004340a:
      __n = param_1 + (param_2 - (int)pcVar2) + -1;
      goto LAB_0004346a;
    }
  }
  else {
    if (pcVar1 == (char *)0x0) {
      if (pcVar2 != (char *)0x0) {
        sVar6 = (int)pcVar2 - (int)param_1;
      }
      goto LAB_0004358a;
    }
    pcVar3 = pcVar2;
    if (pcVar2 != (char *)0x0) {
      pcVar3 = (char *)0x1;
    }
    uVar5 = (uint)(pcVar2 < pcVar1);
    if ((uVar5 & (uint)pcVar3) == 0) {
      sVar6 = (int)pcVar1 - (int)param_1;
    }
    else {
      sVar6 = (int)pcVar2 - (int)param_1;
    }
LAB_000433ea:
    if (pcVar1 < pcVar2) {
      uVar4 = (uint)pcVar3 & 1;
    }
    else {
      uVar4 = 0;
    }
    if (uVar4 == 0) {
      pcVar3 = param_1 + (param_2 - (int)pcVar1) + -1;
      goto LAB_00043446;
    }
    if (pcVar1 == (char *)0x0) {
      uVar5 = 0;
    }
    pcVar3 = pcVar2 + (-1 - (int)pcVar1);
    if (uVar5 == 0) goto LAB_0004340a;
  }
  __n = pcVar1 + (-1 - (int)pcVar2);
LAB_0004346a:
  if (sVar6 == 0 || param_3 == (undefined4 *)0x0) {
    __dest_01 = (void *)0x0;
  }
  else {
    __dest_01 = (void *)(*Curl_cmalloc)(sVar6 + 1);
    if (__dest_01 == (void *)0x0) {
      return (char *)0x1b;
    }
  }
  __dest_00 = param_4;
  if (((param_4 == (char *)0x0) || (__dest_00 = pcVar3, pcVar3 == (char *)0x0)) ||
     (__dest_00 = (char *)(*Curl_cmalloc)(pcVar3 + 1), __dest_00 != (char *)0x0)) {
    __dest = param_5;
    if (((param_5 == (char *)0x0) || (__dest = __n, __n == (char *)0x0)) ||
       (__dest = (char *)(*Curl_cmalloc)(__n + 1), __dest != (char *)0x0)) {
      if (__dest_01 != (void *)0x0) {
        memcpy(__dest_01,param_1,sVar6);
        *(undefined1 *)((int)__dest_01 + sVar6) = 0;
        (*Curl_cfree)(*param_3);
        *param_3 = __dest_01;
      }
      if (__dest_00 != (char *)0x0) {
        memcpy(__dest_00,pcVar1 + 1,(size_t)pcVar3);
        __dest_00[(int)pcVar3] = '\0';
        (*Curl_cfree)(*(undefined4 *)param_4);
        *(char **)param_4 = __dest_00;
      }
      pcVar1 = __dest;
      if (__dest != (char *)0x0) {
        memcpy(__dest,pcVar2 + 1,(size_t)__n);
        __dest[(int)__n] = '\0';
        (*Curl_cfree)(*(undefined4 *)param_5);
        pcVar1 = (char *)0x0;
        *(char **)param_5 = __dest;
      }
    }
    else {
      (*Curl_cfree)(__dest_00);
      (*Curl_cfree)(__dest_01);
      pcVar1 = (char *)0x1b;
    }
  }
  else {
    (*Curl_cfree)(__dest_01);
    pcVar1 = (char *)0x1b;
  }
  return pcVar1;
}

