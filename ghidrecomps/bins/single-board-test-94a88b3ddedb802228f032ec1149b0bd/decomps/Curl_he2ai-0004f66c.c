
int Curl_he2ai(undefined4 *param_1,ushort param_2)

{
  ushort uVar1;
  code **ppcVar2;
  code **ppcVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  
  ppcVar3 = DAT_0004f788;
  if (param_1 == (undefined4 *)0x0) {
    iVar8 = 0;
  }
  else {
    puVar7 = *(undefined4 **)param_1[4];
    if (puVar7 == (undefined4 *)0x0) {
      iVar8 = 0;
    }
    else {
      iVar8 = 0;
      iVar6 = param_1[2];
      iVar11 = 4;
      uVar1 = (ushort)((param_2 & 0xff) << 8) | param_2 >> 8;
      iVar12 = 0;
      do {
        if (iVar6 == 10) {
          uVar10 = 0x1c;
        }
        else {
          uVar10 = 0x10;
        }
        iVar4 = (**ppcVar3)(1,0x20);
        if (iVar4 == 0) {
LAB_0004f750:
          Curl_freeaddrinfo(iVar8);
          return 0;
        }
        iVar6 = (*Curl_cstrdup)(*param_1);
        *(int *)(iVar4 + 0x14) = iVar6;
        if (iVar6 == 0) {
          (**DAT_0004f784)(iVar4);
          goto LAB_0004f750;
        }
        puVar5 = (undefined2 *)(*Curl_ccalloc)(1,uVar10);
        *(undefined2 **)(iVar4 + 0x18) = puVar5;
        ppcVar2 = DAT_0004f784;
        if (puVar5 == (undefined2 *)0x0) {
          (**DAT_0004f784)(*(undefined4 *)(iVar4 + 0x14));
          (**ppcVar2)(iVar4);
          Curl_freeaddrinfo(iVar8);
          return 0;
        }
        if (iVar8 == 0) {
          iVar8 = iVar4;
        }
        if (iVar12 != 0) {
          *(int *)(iVar12 + 0x1c) = iVar4;
        }
        iVar6 = param_1[2];
        *(undefined4 *)(iVar4 + 8) = 1;
        *(undefined4 *)(iVar4 + 0x10) = uVar10;
        *(int *)(iVar4 + 4) = iVar6;
        if (iVar6 == 2) {
          *(undefined4 *)(puVar5 + 2) = *puVar7;
          iVar6 = param_1[2];
          puVar5[1] = uVar1;
          *puVar5 = (short)iVar6;
        }
        else if (iVar6 == 10) {
          uVar13 = puVar7[1];
          uVar9 = puVar7[2];
          uVar10 = puVar7[3];
          *(undefined4 *)(puVar5 + 4) = *puVar7;
          *(undefined4 *)(puVar5 + 6) = uVar13;
          *(undefined4 *)(puVar5 + 8) = uVar9;
          *(undefined4 *)(puVar5 + 10) = uVar10;
          iVar6 = param_1[2];
          puVar5[1] = uVar1;
          *puVar5 = (short)iVar6;
        }
        puVar7 = *(undefined4 **)(param_1[4] + iVar11);
        iVar11 = iVar11 + 4;
        iVar12 = iVar4;
      } while (puVar7 != (undefined4 *)0x0);
    }
  }
  return iVar8;
}

