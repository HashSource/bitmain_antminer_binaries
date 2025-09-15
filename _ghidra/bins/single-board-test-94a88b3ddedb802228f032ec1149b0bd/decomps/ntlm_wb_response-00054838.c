
undefined4 ntlm_wb_response(int param_1,char *param_2,int param_3)

{
  char *pcVar1;
  size_t __n;
  ssize_t sVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  char *__buf;
  
  pcVar1 = (char *)(*Curl_cmalloc)(0x400);
  __n = strlen(param_2);
  if (pcVar1 == (char *)0x0) {
    return 0x1b;
  }
  do {
    while( true ) {
      if (__n == 0) {
        uVar6 = 0;
        __buf = pcVar1;
        goto LAB_0005489a;
      }
      sVar2 = send(*(int *)(param_1 + 0x2a4),param_2,__n,0x4000);
      if (sVar2 == -1) break;
      param_2 = param_2 + sVar2;
      __n = __n - sVar2;
    }
    piVar3 = __errno_location();
  } while (*piVar3 == 4);
  goto LAB_00054880;
  while (piVar3 = __errno_location(), *piVar3 == 4) {
LAB_0005489a:
    sVar2 = recv(*(int *)(param_1 + 0x2a4),__buf,0x400,0);
    if (sVar2 != -1) {
      uVar6 = uVar6 + sVar2;
      if (sVar2 == 0) break;
      if (pcVar1[uVar6 - 1] == '\n') {
        pcVar1[uVar6 - 1] = '\0';
        if ((uVar6 == 3 && param_3 == 1) || (uVar6 < 4)) break;
        if (param_3 == 1) {
          if ((*pcVar1 != 'Y') || (pcVar1[1] != 'R')) break;
        }
        else {
          if (param_3 != 2) goto LAB_0005491a;
          if (*pcVar1 == 'K') {
            if (pcVar1[1] != 'K') break;
          }
          else if ((*pcVar1 != 'A') || (pcVar1[1] != 'F')) break;
        }
        if (pcVar1[2] == ' ') {
LAB_0005491a:
          uVar5 = curl_maprintf("NTLM %.*s",uVar6 - 4,pcVar1 + 3);
          *(undefined4 *)(param_1 + 0x2b0) = uVar5;
          (*Curl_cfree)(pcVar1);
          return 0;
        }
        break;
      }
      pcVar4 = (char *)(*Curl_crealloc)(pcVar1,uVar6 + 0x400);
      if (pcVar4 == (char *)0x0) {
        (*Curl_cfree)(pcVar1);
        return 0x1b;
      }
      __buf = pcVar4 + uVar6;
      pcVar1 = pcVar4;
      goto LAB_0005489a;
    }
  }
LAB_00054880:
  (*Curl_cfree)(pcVar1);
  return 9;
}

