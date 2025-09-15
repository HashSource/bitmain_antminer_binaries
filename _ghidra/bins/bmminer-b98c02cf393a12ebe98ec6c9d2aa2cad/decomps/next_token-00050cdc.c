
void next_token(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
  if (*(int *)(param_1 + 0x28) != 0) {
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x34);
    *(undefined4 *)(param_1 + 0x28) = 0;
    return;
  }
  pbVar1 = *(byte **)(param_1 + 4);
  iVar3 = *(int *)(param_1 + 0x44) + 1;
  *(int *)(param_1 + 0x44) = iVar3;
  iVar2 = *(int *)(param_1 + 0x48) + 1;
  *(int *)(param_1 + 0x48) = iVar2;
  bVar4 = *pbVar1;
  uVar5 = (uint)bVar4;
  iVar6 = *(int *)(param_1 + 0x40);
  if (uVar5 - 9 < 2 || (uVar5 == 0x3a || (uVar5 == 0x20 || uVar5 == 0x2c))) {
    do {
      bVar7 = uVar5 == 10;
      iVar2 = iVar2 + 1;
      if (bVar7) {
        iVar6 = iVar6 + 1;
        iVar3 = 10;
      }
      else {
        iVar3 = *(int *)(param_1 + 0x44);
      }
      if (bVar7) {
        *(undefined4 *)(param_1 + 0x44) = 1;
      }
      if (bVar7) {
        *(int *)(param_1 + 0x40) = iVar6;
      }
      else {
        iVar3 = iVar3 + 1;
      }
      *(int *)(param_1 + 0x48) = iVar2;
      if (!bVar7) {
        *(int *)(param_1 + 0x44) = iVar3;
      }
      pbVar1 = pbVar1 + 1;
      bVar4 = *pbVar1;
      uVar5 = (uint)bVar4;
    } while (uVar5 - 9 < 2 || (uVar5 == 0x3a || (uVar5 == 0x2c || uVar5 == 0x20)));
    iVar3 = *(int *)(param_1 + 0x44);
  }
  *(byte *)(param_1 + 0x24) = bVar4;
  *(byte **)(param_1 + 4) = pbVar1 + 1;
  *(int *)(param_1 + 0x18) = iVar6;
  *(int *)(param_1 + 0x1c) = iVar3;
  *(int *)(param_1 + 0x20) = iVar2;
  return;
}

