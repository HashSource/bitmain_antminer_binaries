
undefined4 ntlm_wb_response(int param_1,char *param_2,int param_3)

{
  code **ppcVar1;
  char *pcVar2;
  size_t __n;
  ssize_t sVar3;
  int *piVar4;
  char *pcVar5;
  undefined4 uVar6;
  uint uVar7;
  char *__buf;
  
  pcVar2 = (char *)(**DAT_0005495c)(0x400);
  __n = strlen(param_2);
  if (pcVar2 == (char *)0x0) {
    return 0x1b;
  }
  do {
    while( true ) {
      ppcVar1 = DAT_00054964;
      if (__n == 0) {
        uVar7 = 0;
        __buf = pcVar2;
        goto LAB_0005489a;
      }
      sVar3 = send(*(int *)(param_1 + 0x2a4),param_2,__n,0x4000);
      if (sVar3 == -1) break;
      param_2 = param_2 + sVar3;
      __n = __n - sVar3;
    }
    piVar4 = __errno_location();
  } while (*piVar4 == 4);
  goto LAB_00054880;
  while (piVar4 = __errno_location(), *piVar4 == 4) {
LAB_0005489a:
    sVar3 = recv(*(int *)(param_1 + 0x2a4),__buf,0x400,0);
    if (sVar3 != -1) {
      uVar7 = uVar7 + sVar3;
      if (sVar3 == 0) break;
      if (pcVar2[uVar7 - 1] == '\n') {
        pcVar2[uVar7 - 1] = '\0';
        if ((uVar7 == 3 && param_3 == 1) || (uVar7 < 4)) break;
        if (param_3 == 1) {
          if ((*pcVar2 != 'Y') || (pcVar2[1] != 'R')) break;
        }
        else {
          if (param_3 != 2) goto LAB_0005491a;
          if (*pcVar2 == 'K') {
            if (pcVar2[1] != 'K') break;
          }
          else if ((*pcVar2 != 'A') || (pcVar2[1] != 'F')) break;
        }
        if (pcVar2[2] == ' ') {
LAB_0005491a:
          uVar6 = curl_maprintf(DAT_00054968,uVar7 - 4,pcVar2 + 3);
          ppcVar1 = DAT_00054960;
          *(undefined4 *)(param_1 + 0x2b0) = uVar6;
          (**ppcVar1)(pcVar2);
          return 0;
        }
        break;
      }
      pcVar5 = (char *)(**ppcVar1)(pcVar2,uVar7 + 0x400);
      if (pcVar5 == (char *)0x0) {
        (**DAT_00054960)(pcVar2);
        return 0x1b;
      }
      __buf = pcVar5 + uVar7;
      pcVar2 = pcVar5;
      goto LAB_0005489a;
    }
  }
LAB_00054880:
  (**DAT_00054960)(pcVar2);
  return 9;
}

