
void ssl_set_client_disabled(int param_1)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  
  iVar5 = *(int *)(param_1 + 0x98);
  iVar6 = *(int *)(*(int *)(param_1 + 8) + 100);
  *(undefined4 *)(iVar5 + 0xc) = 0;
  *(undefined4 *)(iVar5 + 8) = 0;
  if ((*(uint *)(iVar6 + 0x38) & 8) == 0) {
    if (*(int *)(param_1 + 0x110) < 0x303) goto LAB_0007105a;
LAB_00070fc4:
    uVar7 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x110) < 0xfefe) goto LAB_00070fc4;
LAB_0007105a:
    uVar7 = 4;
  }
  *(undefined4 *)(iVar5 + 0x18) = uVar7;
  uVar8 = *(uint *)(iVar5 + 0x38) & 0x30000;
  if (uVar8 == 0x20000) {
    uVar8 = 2;
    iVar6 = DAT_000710d0;
  }
  else {
    iVar6 = DAT_000710cc;
    if (uVar8 == 0x30000) {
      uVar8 = 4;
    }
    else if (uVar8 == 0x10000) {
      uVar8 = 2;
    }
    else {
      if ((*(int *)(param_1 + 0x24) == 0) || (iVar6 = *(int *)(iVar5 + 0x134), iVar6 == 0)) {
        iVar6 = *(int *)(iVar5 + 300);
        if (iVar6 == 0) {
          uVar8 = 0x1e;
          iVar6 = DAT_000710d4;
          goto LAB_00071062;
        }
        uVar8 = *(uint *)(iVar5 + 0x130);
      }
      else {
        uVar8 = *(uint *)(iVar5 + 0x138);
      }
      if (uVar8 == 0) {
        *(undefined4 *)(iVar5 + 0xc) = 1;
        *(undefined4 *)(iVar5 + 8) = 0x22;
        bVar4 = false;
        bVar3 = false;
        goto LAB_00071002;
      }
    }
  }
LAB_00071062:
  bVar4 = false;
  bVar3 = false;
  bVar2 = false;
  iVar9 = iVar6;
  do {
    cVar1 = *(char *)(iVar9 + 1);
    if (cVar1 == '\x02') {
      bVar3 = true;
    }
    else if (cVar1 == '\x03') {
      bVar4 = true;
    }
    else if (cVar1 == '\x01') {
      bVar2 = true;
    }
    iVar9 = iVar9 + 2;
  } while ((uint)(iVar9 - iVar6) < uVar8);
  if (!bVar2) {
    *(undefined4 *)(iVar5 + 0xc) = 1;
    *(undefined4 *)(iVar5 + 8) = 0x22;
  }
LAB_00071002:
  if (!bVar3) {
    *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 2;
    *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) | 4;
  }
  if (!bVar4) {
    *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 0x40;
    *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) | 0x40;
  }
  if (*(int *)(param_1 + 0xdc) == 0) {
    *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 0x80;
    *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) | 0x100;
  }
  if (-1 < *(int *)(param_1 + 0x1d0) << 0x15) {
    *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 0x400;
    *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) | 0x400;
  }
  *(undefined4 *)(iVar5 + 4) = 1;
  return;
}

