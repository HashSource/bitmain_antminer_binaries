
void sendsuboption(int *param_1,int param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  ssize_t sVar3;
  int *piVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  void *__buf;
  undefined1 local_24;
  undefined1 uStack_23;
  undefined1 local_22;
  undefined1 uStack_21;
  
  iVar11 = *param_1;
  iVar6 = *(int *)(iVar11 + 0x14c);
  if (param_2 == 0x1f) {
    puVar10 = (undefined1 *)(iVar6 + 0x1cb1);
    puVar9 = (undefined1 *)(iVar6 + 0x1eb0);
    iVar7 = iVar6;
    if (puVar9 <= puVar10) {
      iVar7 = iVar6 + 0x1ca0;
    }
    *(undefined1 *)(iVar6 + 0x1cb0) = 0xff;
    __buf = (void *)(iVar6 + 0x1cb0);
    *(undefined1 **)(iVar6 + 0x1eb0) = puVar10;
    if (puVar10 < puVar9) {
      puVar8 = (undefined1 *)(iVar6 + 0x1cb2);
      puVar10 = puVar8;
      if (puVar8 < puVar9) {
        puVar10 = (undefined1 *)(iVar6 + 0x1cb3);
      }
      *(undefined1 *)(iVar6 + 0x1cb1) = 0xfa;
      *(undefined1 **)(iVar6 + 0x1eb0) = puVar8;
      if (puVar8 < puVar9) {
        *(undefined1 *)(iVar6 + 0x1cb2) = 0x1f;
      }
      if (puVar8 < puVar9) {
        *(undefined1 **)(iVar6 + 0x1eb0) = puVar10;
      }
    }
    else {
      puVar8 = (undefined1 *)(iVar7 + 0x12);
    }
    uVar1 = *(undefined2 *)(iVar6 + 0x1ca8);
    uVar2 = *(undefined2 *)(iVar6 + 0x1caa);
    puVar5 = puVar10;
    if (puVar10 < puVar9) {
      local_24 = (undefined1)((ushort)uVar1 >> 8);
      puVar5 = puVar10 + 1;
      *puVar10 = local_24;
      *(undefined1 **)(iVar6 + 0x1eb0) = puVar5;
      if (puVar5 < puVar9) {
        puVar5 = puVar10 + 2;
        uStack_23 = (undefined1)uVar1;
        puVar10[1] = uStack_23;
        *(undefined1 **)(iVar6 + 0x1eb0) = puVar5;
        if (puVar5 < puVar9) {
          puVar5 = puVar10 + 3;
          local_22 = (undefined1)((ushort)uVar2 >> 8);
          puVar10[2] = local_22;
          *(undefined1 **)(iVar6 + 0x1eb0) = puVar5;
          if (puVar5 < puVar9) {
            puVar5 = puVar10 + 4;
            uStack_21 = (undefined1)uVar2;
            puVar10[3] = uStack_21;
            *(undefined1 **)(iVar6 + 0x1eb0) = puVar5;
            if (puVar5 < puVar9) {
              puVar5 = puVar10 + 5;
              puVar10[4] = 0xff;
              *(undefined1 **)(iVar6 + 0x1eb0) = puVar5;
              if (puVar5 < puVar9) {
                puVar10[5] = 0xf0;
                puVar5 = puVar10 + 6;
              }
            }
          }
        }
      }
    }
    *(undefined1 **)(iVar6 + 0x1eb4) = puVar5;
    *(void **)(iVar6 + 0x1eb0) = __buf;
    printsub(iVar11,0x3e,puVar8,puVar5 + (-2 - (int)__buf));
    sVar3 = send(param_1[0x55],__buf,3,0x4000);
    if (sVar3 < 0) {
      piVar4 = __errno_location();
      Curl_failf(iVar11,"Sending data failed (%d)",*piVar4);
    }
    send_telnet_data(param_1,iVar6 + 0x1cb3,4);
    sVar3 = send(param_1[0x55],(void *)(iVar6 + 0x1cb7),2,0x4000);
    if (sVar3 < 0) {
      piVar4 = __errno_location();
      Curl_failf(iVar11,"Sending data failed (%d)",*piVar4);
      return;
    }
  }
  return;
}

