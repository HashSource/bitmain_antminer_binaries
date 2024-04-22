
int BN_GF2m_poly2arr(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
  iVar2 = param_1[1];
  if (iVar2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar7 = iVar2 + -1;
    if (iVar7 < 0) {
      iVar1 = 0;
    }
    else {
      iVar6 = iVar7 * 0x20;
      iVar1 = 0;
      puVar5 = (uint *)(*param_1 + iVar2 * 4);
      do {
        puVar5 = puVar5 + -1;
        uVar4 = *puVar5;
        if (uVar4 != 0) {
          uVar3 = 0x80000000;
          iVar2 = 0x1f;
          while( true ) {
            uVar4 = uVar4 & uVar3;
            uVar3 = uVar3 >> 1;
            if (uVar4 != 0) {
              if (iVar1 < param_3) {
                *(int *)(param_2 + iVar1 * 4) = iVar2 + iVar6;
              }
              iVar1 = iVar1 + 1;
            }
            bVar8 = iVar2 == 0;
            iVar2 = iVar2 + -1;
            if (bVar8) break;
            uVar4 = *puVar5;
          }
        }
        iVar7 = iVar7 + -1;
        iVar6 = iVar6 + -0x20;
      } while (iVar7 != -1);
    }
    if (iVar1 < param_3) {
      *(undefined4 *)(param_2 + iVar1 * 4) = 0xffffffff;
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}

