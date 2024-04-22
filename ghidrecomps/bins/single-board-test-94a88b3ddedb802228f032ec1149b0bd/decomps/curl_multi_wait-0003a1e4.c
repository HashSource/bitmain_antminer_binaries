
undefined4 curl_multi_wait(int *param_1,int param_2,uint param_3,int param_4,int *param_5)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  bool bVar13;
  int local_44;
  int local_40;
  int local_3c [6];
  
  if ((param_1 == (int *)0x0) || (*param_1 != 0xbab1e)) {
    uVar2 = 1;
  }
  else {
    local_44 = param_4;
    if (param_1[0x11] == 0) {
      local_40 = -1;
    }
    else {
      multi_timeout_part_1(param_1,&local_40);
      if ((-1 < local_40) && (local_40 <= param_4)) {
        local_44 = local_40;
      }
    }
    piVar11 = (int *)param_1[1];
    if (piVar11 == (int *)0x0) {
      iVar10 = 0;
    }
    else {
      iVar10 = 0;
      do {
        iVar3 = multi_getsock_constprop_6(piVar11,local_3c);
        iVar6 = 0;
        uVar8 = 0;
        do {
          uVar12 = uVar8 + 0x10;
          iVar9 = -1;
          if ((iVar3 >> (uVar8 & 0xff)) << 0x1f < 0) {
            iVar9 = *(int *)((int)local_3c + iVar6);
            iVar10 = iVar10 + 1;
          }
          uVar8 = uVar8 + 1;
          if ((iVar3 >> (uVar12 & 0xff) & 1U) != 0) {
            iVar9 = *(int *)((int)local_3c + iVar6);
            iVar10 = iVar10 + 1;
          }
          iVar6 = iVar6 + 4;
        } while ((iVar9 != -1) && (uVar8 != 5));
        piVar11 = (int *)*piVar11;
      } while (piVar11 != (int *)0x0);
    }
    uVar8 = iVar10 + param_3 | param_3;
    if ((uVar8 != 0) && (uVar8 = (**DAT_0003a3f4)((iVar10 + param_3) * 8), uVar8 == 0)) {
      return 3;
    }
    if (iVar10 == 0) {
      iVar3 = 0;
    }
    else {
      piVar11 = (int *)param_1[1];
      if (piVar11 == (int *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = 0;
        do {
          iVar6 = multi_getsock_constprop_6(piVar11,local_3c);
          iVar9 = 0;
          uVar12 = 0;
          do {
            uVar4 = uVar12 + 0x10;
            bVar13 = (iVar6 >> (uVar12 & 0xff) & 1U) != 0;
            iVar7 = -1;
            if (bVar13) {
              iVar7 = *(int *)((int)local_3c + iVar9);
            }
            uVar12 = uVar12 + 1;
            if (bVar13) {
              *(undefined2 *)(uVar8 + iVar3 * 8 + 4) = 1;
              *(int *)(uVar8 + iVar3 * 8) = iVar7;
              iVar3 = iVar3 + 1;
              iVar7 = *(int *)((int)local_3c + iVar9);
            }
            if ((iVar6 >> (uVar4 & 0xff) & 1U) != 0) {
              uVar2 = *(undefined4 *)((int)local_3c + iVar9);
              *(undefined2 *)(uVar8 + iVar3 * 8 + 4) = 4;
              *(undefined4 *)(uVar8 + iVar3 * 8) = uVar2;
              iVar3 = iVar3 + 1;
              iVar7 = *(int *)((int)local_3c + iVar9);
            }
            iVar9 = iVar9 + 4;
          } while ((iVar7 != -1) && (uVar12 != 5));
          piVar11 = (int *)*piVar11;
        } while (piVar11 != (int *)0x0);
      }
    }
    if (param_3 != 0) {
      iVar6 = 0;
      iVar9 = uVar8 + iVar3 * 8;
      do {
        uVar12 = (uint)*(ushort *)(param_2 + iVar6 + 4);
        iVar7 = iVar9 + iVar6;
        *(undefined4 *)(iVar9 + iVar6) = *(undefined4 *)(param_2 + iVar6);
        iVar6 = iVar6 + 8;
        *(undefined2 *)(iVar7 + 4) = 0;
        if ((int)(uVar12 << 0x1f) < 0) {
          *(undefined2 *)(iVar7 + 4) = 1;
        }
        uVar4 = uVar12 << 0x1e;
        bVar13 = (int)uVar4 < 0;
        if (bVar13) {
          uVar4 = (uint)*(ushort *)(iVar7 + 4);
        }
        uVar1 = (ushort)uVar4;
        if (bVar13) {
          uVar1 = uVar1 | 2;
        }
        if (bVar13) {
          *(ushort *)(iVar7 + 4) = uVar1;
        }
        uVar12 = uVar12 << 0x1d;
        bVar13 = (int)uVar12 < 0;
        if (bVar13) {
          uVar12 = *(ushort *)(iVar7 + 4) | 4;
        }
        if (bVar13) {
          *(short *)(iVar7 + 4) = (short)uVar12;
        }
      } while (iVar6 != param_3 << 3);
      iVar3 = iVar3 + param_3;
    }
    if ((iVar3 == 0) || (iVar3 = Curl_poll(uVar8,iVar3,local_44), iVar3 < 1)) {
      iVar3 = 0;
    }
    else if (param_3 != 0) {
      iVar6 = 0;
      do {
        iVar9 = param_2 + iVar6;
        uVar1 = *(ushort *)(uVar8 + iVar10 * 8 + iVar6 + 6);
        iVar6 = iVar6 + 8;
        uVar5 = uVar1 & 1;
        if ((uVar1 & 4) != 0) {
          uVar5 = uVar1 & 1 | 4;
        }
        if ((int)((uint)uVar1 << 0x1e) < 0) {
          uVar5 = uVar5 | 2;
        }
        *(ushort *)(iVar9 + 6) = uVar5;
      } while (iVar6 != param_3 << 3);
    }
    (**DAT_0003a3f0)(uVar8);
    if (param_5 == (int *)0x0) {
      uVar2 = 0;
    }
    else {
      *param_5 = iVar3;
      uVar2 = 0;
    }
  }
  return uVar2;
}

