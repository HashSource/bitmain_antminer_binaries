
int Curl_pop3_write(uint *param_1,int param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  undefined8 uVar11;
  
  uVar3 = *param_1;
  uVar5 = param_1[0x100];
  iVar9 = param_3;
  if (param_3 != 0) {
    iVar8 = 0;
    bVar2 = false;
    iVar9 = 0;
    uVar4 = uVar3;
    uVar7 = uVar5;
    do {
      cVar1 = *(char *)(param_2 + iVar8);
      if (cVar1 == '\r') {
        if (uVar7 == 0) {
          param_1[0x100] = 1;
          uVar5 = 1;
          if (iVar8 != 0) {
            uVar11 = Curl_client_write(param_1,1,param_2 + iVar9,iVar8 - iVar9);
            uVar4 = (uint)((ulonglong)uVar11 >> 0x20);
            if ((int)uVar11 != 0) {
              return (int)uVar11;
            }
LAB_000516a2:
            uVar5 = param_1[0x100];
            iVar9 = iVar8;
          }
        }
        else {
          bVar10 = uVar7 == 3;
          uVar4 = 0xd;
          if (bVar10) {
            uVar4 = 4;
          }
          if (!bVar10) {
            param_1[0x100] = 1;
          }
          if (bVar10) {
            param_1[0x100] = uVar4;
          }
          else {
            uVar4 = 1;
          }
LAB_00051652:
          uVar5 = uVar4;
          if (uVar4 <= uVar7) goto LAB_00051656;
        }
      }
      else if (cVar1 == '.') {
        if (uVar7 == 2) {
          param_1[0x100] = 3;
          uVar4 = 3;
          goto LAB_00051652;
        }
        param_1[0x100] = 0;
        uVar4 = 0;
        if (uVar7 != 3) goto joined_r0x0005160e;
        bVar2 = true;
LAB_00051656:
        uVar6 = param_1[0x101];
        do {
          if (uVar6 == 0) {
            if (bVar2) {
              uVar7 = uVar7 - 1;
            }
            uVar11 = Curl_client_write(param_1,1,DAT_00051710,uVar7);
            uVar4 = (uint)((ulonglong)uVar11 >> 0x20);
            if ((int)uVar11 != 0) {
              return (int)uVar11;
            }
            bVar2 = false;
            goto LAB_000516a2;
          }
          uVar7 = uVar7 - 1;
          uVar6 = uVar6 - 1;
          param_1[0x101] = uVar6;
          uVar5 = uVar4;
        } while (uVar7 != 0);
      }
      else {
        if (cVar1 != '\n') {
          uVar4 = 0;
        }
        if (cVar1 != '\n') {
          param_1[0x100] = 0;
        }
        else {
          if (uVar7 == 1 || uVar7 == 4) {
            uVar4 = uVar7 + 1;
          }
          else {
            uVar4 = 0;
          }
          param_1[0x100] = uVar4;
        }
joined_r0x0005160e:
        uVar5 = uVar4;
        if (uVar7 != 0) goto LAB_00051652;
      }
      iVar8 = iVar8 + 1;
      uVar7 = uVar5;
    } while (iVar8 != param_3);
  }
  if (uVar5 == 5) {
    iVar9 = Curl_client_write(param_1,1,DAT_00051710,2);
    *(uint *)(uVar3 + 0x130) = *(uint *)(uVar3 + 0x130) & 0xfffffffe;
    param_1[0x100] = 0;
  }
  else if (uVar5 == 0) {
    if (param_3 != iVar9) {
      iVar9 = Curl_client_write(param_1,1,param_2 + iVar9,param_3 - iVar9);
      return iVar9;
    }
    iVar9 = 0;
  }
  else {
    iVar9 = 0;
  }
  return iVar9;
}

