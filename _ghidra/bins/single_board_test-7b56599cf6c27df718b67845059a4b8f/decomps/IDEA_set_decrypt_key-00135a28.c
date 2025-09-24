
void IDEA_set_decrypt_key(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int extraout_r1;
  int extraout_r1_00;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar6 = *(int *)(param_1 + 0xc0);
  piVar1 = (int *)(param_1 + 0xa8);
  iVar2 = param_2 + 0x18;
  while( true ) {
    if (iVar6 != 0) {
      iVar3 = 1;
      iVar7 = 0x10001;
      iVar8 = iVar6;
      iVar9 = 0;
      while (iVar6 = iVar3, __aeabi_idivmod(iVar7,iVar8), extraout_r1 != 0) {
        iVar3 = __aeabi_idiv(iVar7 - extraout_r1,iVar8);
        iVar3 = iVar9 - iVar6 * iVar3;
        iVar7 = iVar8;
        iVar8 = extraout_r1;
        iVar9 = iVar6;
      }
      if (iVar6 < 0) {
        iVar6 = iVar6 + 0x10001;
      }
    }
    *(int *)(iVar2 + -0x18) = iVar6;
    *(uint *)(iVar2 + -0x14) = -piVar1[8] & 0xffff;
    *(uint *)(iVar2 + -0x10) = -piVar1[7] & 0xffff;
    iVar6 = piVar1[9];
    if (iVar6 != 0) {
      iVar3 = 1;
      iVar7 = 0x10001;
      iVar8 = iVar6;
      iVar9 = 0;
      while (iVar6 = iVar3, __aeabi_idivmod(iVar7,iVar8), extraout_r1_00 != 0) {
        iVar3 = __aeabi_idiv(iVar7 - extraout_r1_00,iVar8);
        iVar3 = iVar9 - iVar6 * iVar3;
        iVar7 = iVar8;
        iVar8 = extraout_r1_00;
        iVar9 = iVar6;
      }
      if (iVar6 < 0) {
        iVar6 = iVar6 + 0x10001;
      }
    }
    *(int *)(iVar2 + -0xc) = iVar6;
    if (piVar1 + -6 == (int *)(param_1 + -0x30)) break;
    *(int *)(iVar2 + -8) = piVar1[4];
    *(int *)(iVar2 + -4) = piVar1[5];
    iVar6 = *piVar1;
    piVar1 = piVar1 + -6;
    iVar2 = iVar2 + 0x18;
  }
  uVar4 = *(undefined4 *)(param_2 + 8);
  uVar5 = *(undefined4 *)(param_2 + 200);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_2 + 4) = uVar4;
  *(undefined4 *)(param_2 + 200) = *(undefined4 *)(param_2 + 0xc4);
  *(undefined4 *)(param_2 + 0xc4) = uVar5;
  return;
}

