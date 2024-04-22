
/* WARNING: Type propagation algorithm not settling */

char * Curl_dedotdotify(char *param_1)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  char *__s;
  char *pcVar4;
  int iVar5;
  char cVar6;
  char *__s2;
  char *pcVar7;
  char *pcVar8;
  char *__dest;
  char *pcVar9;
  
  sVar2 = strlen(param_1);
  pcVar3 = (char *)(**DAT_00056864)(sVar2 + 1);
  if (pcVar3 != (char *)0x0) {
    __s = (char *)(**DAT_00056868)(param_1);
    if ((__s == (char *)0x0) || (*__s == '\0')) {
      (**DAT_00056874)(pcVar3);
      pcVar3 = __s;
    }
    else {
      pcVar4 = strchr(__s,0x3f);
      __s2 = __s;
      __dest = pcVar3;
      if (pcVar4 != (char *)0x0) {
        *pcVar4 = '\0';
      }
LAB_000566fe:
      do {
        iVar5 = strncmp(DAT_0005686c,__s2,2);
        if (iVar5 == 0) {
LAB_00056750:
          cVar6 = __s2[2];
          pcVar7 = __s2 + 2;
        }
        else {
          iVar5 = strncmp(DAT_00056870,__s2,3);
          if (iVar5 == 0) {
            cVar6 = __s2[3];
            pcVar7 = __s2 + 3;
          }
          else {
            iVar5 = strncmp(DAT_00056878,__s2,3);
            if (iVar5 == 0) goto LAB_00056750;
            cVar6 = *__s2;
            if (cVar6 == '/') {
              cVar1 = __s2[1];
              if ((cVar1 == '.') && (__s2[2] == '\0')) {
                __s2[1] = '/';
                __s2 = __s2 + 1;
                goto LAB_000566fe;
              }
              iVar5 = strncmp(DAT_0005687c,__s2,4);
              if (iVar5 == 0) goto LAB_00056830;
              pcVar9 = __dest;
              if (((cVar1 == '.') && (__s2[2] == '.')) && (__s2[3] == '\0')) {
                pcVar7 = __s2 + 2;
                *pcVar7 = '/';
                if (pcVar3 < __dest) {
                  cVar6 = __dest[-1];
                  __dest = __dest + -1;
                  while ((cVar6 != '/' && (__dest != pcVar3))) {
                    __dest = __dest + -1;
                    cVar6 = *__dest;
                  }
                }
                *__dest = '\0';
                cVar6 = __s2[2];
                goto joined_r0x00056720;
              }
            }
            else {
              iVar5 = strncmp(DAT_0005687c,__s2,4);
              if (iVar5 == 0) {
LAB_00056830:
                pcVar7 = __s2 + 3;
                if (pcVar3 < __dest) {
                  cVar6 = __dest[-1];
                  __dest = __dest + -1;
                  while ((cVar6 != '/' && (__dest != pcVar3))) {
                    __dest = __dest + -1;
                    cVar6 = *__dest;
                  }
                }
                *__dest = '\0';
                cVar6 = __s2[3];
                goto joined_r0x00056720;
              }
              pcVar9 = __dest;
              if ((cVar6 == '.') && ((__s2[1] == '\0' || ((__s2[1] == '.' && (__s2[2] == '\0'))))))
              {
                *__s2 = '\0';
                break;
              }
            }
            do {
              pcVar8 = __s2;
              __dest = pcVar9 + 1;
              *pcVar9 = cVar6;
              cVar6 = pcVar8[1];
              pcVar7 = pcVar8 + 1;
              __s2 = pcVar7;
              pcVar9 = __dest;
            } while (cVar6 != '/' && cVar6 != '\0');
            *__dest = '\0';
            cVar6 = pcVar8[1];
          }
        }
joined_r0x00056720:
        __s2 = pcVar7;
      } while (cVar6 != '\0');
      if (pcVar4 != (char *)0x0) {
        sVar2 = strlen(param_1 + ((int)pcVar4 - (int)__s));
        memcpy(__dest,param_1 + ((int)pcVar4 - (int)__s),sVar2 + 1);
      }
      (**DAT_00056874)(__s);
    }
  }
  return pcVar3;
}

