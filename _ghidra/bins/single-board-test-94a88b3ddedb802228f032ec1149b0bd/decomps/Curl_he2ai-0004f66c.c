
int Curl_he2ai(undefined4 *param_1,ushort param_2)

{
  ushort uVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar6 = 0;
  }
  else {
    puVar5 = *(undefined4 **)param_1[4];
    if (puVar5 == (undefined4 *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = 0;
      iVar4 = param_1[2];
      iVar9 = 4;
      uVar1 = param_2 << 8 | param_2 >> 8;
      iVar10 = 0;
      do {
        if (iVar4 == 10) {
          uVar8 = 0x1c;
        }
        else {
          uVar8 = 0x10;
        }
        iVar2 = (*Curl_ccalloc)(1,0x20);
        if (iVar2 == 0) {
LAB_0004f750:
          Curl_freeaddrinfo(iVar6);
          return 0;
        }
        iVar4 = (*Curl_cstrdup)(*param_1);
        *(int *)(iVar2 + 0x14) = iVar4;
        if (iVar4 == 0) {
          (*Curl_cfree)(iVar2);
          goto LAB_0004f750;
        }
        puVar3 = (undefined2 *)(*Curl_ccalloc)(1,uVar8);
        *(undefined2 **)(iVar2 + 0x18) = puVar3;
        if (puVar3 == (undefined2 *)0x0) {
          (*Curl_cfree)(*(undefined4 *)(iVar2 + 0x14));
          (*Curl_cfree)(iVar2);
          Curl_freeaddrinfo(iVar6);
          return 0;
        }
        if (iVar6 == 0) {
          iVar6 = iVar2;
        }
        if (iVar10 != 0) {
          *(int *)(iVar10 + 0x1c) = iVar2;
        }
        iVar4 = param_1[2];
        *(undefined4 *)(iVar2 + 8) = 1;
        *(undefined4 *)(iVar2 + 0x10) = uVar8;
        *(int *)(iVar2 + 4) = iVar4;
        if (iVar4 == 2) {
          *(undefined4 *)(puVar3 + 2) = *puVar5;
          iVar4 = param_1[2];
          puVar3[1] = uVar1;
          *puVar3 = (short)iVar4;
        }
        else if (iVar4 == 10) {
          uVar11 = puVar5[1];
          uVar7 = puVar5[2];
          uVar8 = puVar5[3];
          *(undefined4 *)(puVar3 + 4) = *puVar5;
          *(undefined4 *)(puVar3 + 6) = uVar11;
          *(undefined4 *)(puVar3 + 8) = uVar7;
          *(undefined4 *)(puVar3 + 10) = uVar8;
          iVar4 = param_1[2];
          puVar3[1] = uVar1;
          *puVar3 = (short)iVar4;
        }
        puVar5 = *(undefined4 **)(param_1[4] + iVar9);
        iVar9 = iVar9 + 4;
        iVar10 = iVar2;
      } while (puVar5 != (undefined4 *)0x0);
    }
  }
  return iVar6;
}

