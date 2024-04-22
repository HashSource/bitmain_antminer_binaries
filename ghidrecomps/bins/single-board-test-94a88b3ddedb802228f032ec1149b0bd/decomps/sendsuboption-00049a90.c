
void sendsuboption(int *param_1,int param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  ssize_t sVar3;
  int *piVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined *puVar10;
  int iVar11;
  void *__buf;
  undefined local_24;
  undefined uStack_23;
  undefined local_22;
  undefined uStack_21;
  
  iVar11 = *param_1;
  iVar6 = *(int *)(iVar11 + 0x14c);
  if (param_2 == 0x1f) {
    puVar10 = (undefined *)(iVar6 + 0x1cb1);
    puVar9 = (undefined *)(iVar6 + 0x1eb0);
    iVar7 = iVar6;
    if (puVar9 <= puVar10) {
      iVar7 = iVar6 + 0x1ca0;
    }
    *(undefined *)(iVar6 + 0x1cb0) = 0xff;
    __buf = (void *)(iVar6 + 0x1cb0);
    *(undefined **)(iVar6 + 0x1eb0) = puVar10;
    if (puVar10 < puVar9) {
      puVar8 = (undefined *)(iVar6 + 0x1cb2);
      puVar10 = puVar8;
      if (puVar8 < puVar9) {
        puVar10 = (undefined *)(iVar6 + 0x1cb3);
      }
      *(undefined *)(iVar6 + 0x1cb1) = 0xfa;
      *(undefined **)(iVar6 + 0x1eb0) = puVar8;
      if (puVar8 < puVar9) {
        *(undefined *)(iVar6 + 0x1cb2) = 0x1f;
      }
      if (puVar8 < puVar9) {
        *(undefined **)(iVar6 + 0x1eb0) = puVar10;
      }
    }
    else {
      puVar8 = (undefined *)(iVar7 + 0x12);
    }
    uVar1 = *(undefined2 *)(iVar6 + 0x1ca8);
    uVar2 = *(undefined2 *)(iVar6 + 0x1caa);
    puVar5 = puVar10;
    if (puVar10 < puVar9) {
      local_24 = (undefined)((ushort)uVar1 >> 8);
      puVar5 = puVar10 + 1;
      *puVar10 = local_24;
      *(undefined **)(iVar6 + 0x1eb0) = puVar5;
      if (puVar5 < puVar9) {
        puVar5 = puVar10 + 2;
        uStack_23 = (undefined)uVar1;
        puVar10[1] = uStack_23;
        *(undefined **)(iVar6 + 0x1eb0) = puVar5;
        if (puVar5 < puVar9) {
          puVar5 = puVar10 + 3;
          local_22 = (undefined)((ushort)uVar2 >> 8);
          puVar10[2] = local_22;
          *(undefined **)(iVar6 + 0x1eb0) = puVar5;
          if (puVar5 < puVar9) {
            puVar5 = puVar10 + 4;
            uStack_21 = (undefined)uVar2;
            puVar10[3] = uStack_21;
            *(undefined **)(iVar6 + 0x1eb0) = puVar5;
            if (puVar5 < puVar9) {
              puVar5 = puVar10 + 5;
              puVar10[4] = 0xff;
              *(undefined **)(iVar6 + 0x1eb0) = puVar5;
              if (puVar5 < puVar9) {
                puVar10[5] = 0xf0;
                puVar5 = puVar10 + 6;
              }
            }
          }
        }
      }
    }
    *(undefined **)(iVar6 + 0x1eb4) = puVar5;
    *(void **)(iVar6 + 0x1eb0) = __buf;
    printsub(iVar11,0x3e,puVar8,puVar5 + (-2 - (int)__buf));
    sVar3 = send(param_1[0x55],__buf,3,0x4000);
    if (sVar3 < 0) {
      piVar4 = __errno_location();
      Curl_failf(iVar11,DAT_00049bd4,*piVar4);
    }
    send_telnet_data(param_1,iVar6 + 0x1cb3,4);
    sVar3 = send(param_1[0x55],(void *)(iVar6 + 0x1cb7),2,0x4000);
    if (sVar3 < 0) {
      piVar4 = __errno_location();
      Curl_failf(iVar11,DAT_00049bd4,*piVar4);
      return;
    }
  }
  return;
}

