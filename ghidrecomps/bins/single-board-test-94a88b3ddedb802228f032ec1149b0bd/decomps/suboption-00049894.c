
void suboption(int *param_1)

{
  size_t sVar1;
  ssize_t sVar2;
  int *piVar3;
  char **ppcVar4;
  uint uVar5;
  char *__s;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 local_928;
  undefined auStack_924 [124];
  undefined4 local_8a8;
  undefined auStack_8a4 [124];
  undefined auStack_828 [2052];
  
  local_928 = 0;
  memset(auStack_924,0,0x7c);
  local_8a8 = 0;
  memset(auStack_8a4,0,0x7c);
  iVar8 = *param_1;
  iVar9 = *(int *)(iVar8 + 0x14c);
  printsub(iVar8,0x3c,iVar9 + 0x1cb0,(*(int *)(iVar9 + 0x1eb4) - *(int *)(iVar9 + 0x1eb0)) + 2);
  uVar5 = (uint)**(byte **)(iVar9 + 0x1eb0);
  *(byte **)(iVar9 + 0x1eb0) = *(byte **)(iVar9 + 0x1eb0) + 1;
  if (uVar5 == 0x23) {
    sVar1 = strlen((char *)(iVar9 + 0x1c28));
    curl_msnprintf(auStack_828,0x800,DAT_00049a78,0xff,0xfa,0x23,0,(char *)(iVar9 + 0x1c28),0xff,
                   0xf0);
    iVar9 = send(param_1[0x55],auStack_828,sVar1 + 6,0x4000);
  }
  else {
    if (uVar5 == 0x27) {
      puVar10 = (undefined4 *)0x0;
      curl_msnprintf(auStack_828,0x800,DAT_00049a7c,0xff,0xfa,0x27,0);
      ppcVar4 = *(char ***)(iVar9 + 0x1cac);
      if (ppcVar4 == (char **)0x0) {
        sVar1 = 6;
        iVar9 = 0x7fc;
        uVar7 = 4;
      }
      else {
        uVar7 = 4;
        do {
          while( true ) {
            __s = *ppcVar4;
            sVar1 = strlen(__s);
            uVar6 = sVar1 + uVar7 + 1;
            if ((0x7f9 < uVar6) ||
               (iVar9 = __isoc99_sscanf(__s,DAT_00049a80,&local_928,&local_8a8), iVar9 == 0)) break;
            puVar10 = &local_8a8;
            uVar5 = 1;
            curl_msnprintf(auStack_828 + uVar7,0x800 - uVar7,DAT_00049a84,0,&local_928,1,puVar10);
            ppcVar4 = (char **)ppcVar4[1];
            uVar7 = uVar6;
            if (ppcVar4 == (char **)0x0) goto LAB_000499c6;
          }
          ppcVar4 = (char **)ppcVar4[1];
        } while (ppcVar4 != (char **)0x0);
LAB_000499c6:
        iVar9 = 0x800 - uVar7;
        sVar1 = uVar7 + 2;
      }
      curl_msnprintf(auStack_828 + uVar7,iVar9,DAT_00049a88,0xff,0xf0,uVar5,puVar10);
      sVar2 = send(param_1[0x55],auStack_828,sVar1,0x4000);
      if (sVar2 < 0) {
        piVar3 = __errno_location();
        Curl_failf(iVar8,DAT_00049a8c,*piVar3);
      }
      printsub(iVar8,0x3e,auStack_828 + 2,uVar7);
      return;
    }
    if (uVar5 != 0x18) {
      return;
    }
    sVar1 = strlen((char *)(iVar9 + 0x1c08));
    curl_msnprintf(auStack_828,0x800,DAT_00049a78,0xff,0xfa,0x18,0,(char *)(iVar9 + 0x1c08),0xff,
                   0xf0);
    iVar9 = send(param_1[0x55],auStack_828,sVar1 + 6,0x4000);
  }
  if (iVar9 < 0) {
    piVar3 = __errno_location();
    Curl_failf(iVar8,DAT_00049a8c,*piVar3);
  }
  printsub(iVar8,0x3e,auStack_828 + 2,sVar1 + 4);
  return;
}

