
uint bn_add_part_words(ulong *param_1,ulong *param_2,ulong *param_3,int param_4,int param_5)

{
  uint uVar1;
  ulong uVar2;
  ulong *puVar3;
  ulong *puVar4;
  uint uVar5;
  ulong *puVar6;
  ulong *puVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  uVar1 = bn_add_words(param_1,param_2,param_3,param_4);
  if (param_5 != 0) {
    puVar7 = param_1 + param_4;
    if (param_5 < 0) {
      puVar4 = param_3 + param_4;
      if (uVar1 == 0) {
LAB_000f0bbc:
        *puVar7 = *puVar4;
        if (param_5 == -1) {
          return 0;
        }
        do {
          puVar7[1] = puVar4[1];
          if (param_5 == -2) {
            return 0;
          }
          puVar7[2] = puVar4[2];
          if (param_5 == -3) {
            return 0;
          }
          iVar8 = param_5 + 4;
          puVar7[3] = puVar4[3];
          if (iVar8 == 0) {
            return 0;
          }
          puVar4 = puVar4 + 4;
          puVar7 = puVar7 + 4;
          *puVar7 = *puVar4;
          iVar9 = param_5 + 5;
          param_5 = iVar8;
        } while (iVar9 < 0 != SCARRY4(iVar8,1));
        return 0;
      }
      uVar2 = uVar1 + param_3[param_4];
      uVar1 = (uint)(CARRY4(uVar1,param_3[param_4]) != false);
      param_1[param_4] = uVar2;
      if (param_5 != -1) {
        uVar5 = puVar4[1];
        puVar7[1] = uVar1 + uVar5;
        uVar1 = (uint)(CARRY4(uVar1,uVar5) != false);
        if (param_5 != -2) {
          iVar9 = (-param_5 - 3U & 0xfffffffc) + param_5;
          iVar8 = (-param_5 - 2U & 0xfffffffc) + param_5;
          puVar3 = puVar4;
          puVar6 = puVar7;
          do {
            uVar5 = puVar3[2];
            puVar6[2] = uVar1 + uVar5;
            uVar1 = (uint)(CARRY4(uVar1,uVar5) != false);
            if (param_5 + 3 < 0 == SCARRY4(param_5,3)) {
              return uVar1;
            }
            uVar5 = puVar3[3];
            puVar4 = puVar3 + 4;
            puVar6[3] = uVar1 + uVar5;
            uVar1 = (uint)(CARRY4(uVar1,uVar5) != false);
            param_5 = param_5 + 4;
            puVar7 = puVar6 + 4;
            if (param_5 == 0) {
              return uVar1;
            }
            if (uVar1 == 0) goto LAB_000f0bbc;
            uVar2 = *puVar4;
            *puVar7 = uVar2 + 1;
            uVar1 = (uint)(uVar2 == 0xffffffff);
            if (param_5 == iVar8 + 4) {
              return uVar1;
            }
            uVar5 = puVar3[5];
            puVar6[5] = uVar1 + uVar5;
            uVar1 = (uint)(CARRY4(uVar1,uVar5) != false);
            puVar3 = puVar4;
            puVar6 = puVar7;
          } while (param_5 != iVar9 + 4);
        }
      }
    }
    else {
      puVar4 = param_2 + param_4;
      if (uVar1 == 0) {
LAB_000f0ae6:
        *puVar7 = *puVar4;
        if (param_5 != 1) {
          do {
            puVar7[1] = puVar4[1];
            if (param_5 == 2) {
              return 0;
            }
            puVar7[2] = puVar4[2];
            if (param_5 == 3) {
              return 0;
            }
            param_5 = param_5 + -4;
            puVar7[3] = puVar4[3];
            if (param_5 == 0) {
              return 0;
            }
            puVar4 = puVar4 + 4;
            puVar7 = puVar7 + 4;
            *puVar7 = *puVar4;
          } while (1 < param_5);
        }
        return 0;
      }
      uVar5 = param_2[param_4];
      param_1[param_4] = uVar1 + uVar5;
      uVar1 = (uint)(CARRY4(uVar1,uVar5) != false);
      if (param_5 != 1) {
        uVar5 = puVar4[1];
        puVar7[1] = uVar1 + uVar5;
        uVar1 = (uint)(CARRY4(uVar1,uVar5) != false);
        if (param_5 != 2) {
          uVar5 = param_5 - 2;
          param_5 = param_5 + -4;
          iVar8 = param_5 - (uVar5 & 0xfffffffc);
          puVar3 = puVar4;
          puVar6 = puVar7;
          do {
            uVar5 = puVar3[2];
            puVar6[2] = uVar1 + uVar5;
            uVar1 = (uint)(CARRY4(uVar1,uVar5) != false);
            if (param_5 == -1) {
              return uVar1;
            }
            uVar5 = puVar3[3];
            puVar4 = puVar3 + 4;
            puVar6[3] = uVar1 + uVar5;
            uVar1 = (uint)(CARRY4(uVar1,uVar5) != false);
            if (param_5 == 0) {
              return uVar1;
            }
            puVar7 = puVar6 + 4;
            if (uVar1 == 0) {
              if (param_5 < 1) {
                return 0;
              }
              goto LAB_000f0ae6;
            }
            uVar2 = *puVar4;
            *puVar7 = uVar2 + 1;
            uVar1 = (uint)(uVar2 == 0xffffffff);
            bVar10 = param_5 == iVar8;
            param_5 = param_5 + -4;
            if (bVar10) {
              return uVar1;
            }
            uVar5 = puVar3[5];
            puVar6[5] = uVar1 + uVar5;
            uVar1 = (uint)(CARRY4(uVar1,uVar5) != false);
            puVar3 = puVar4;
            puVar6 = puVar7;
          } while (param_5 != -2);
        }
      }
    }
  }
  return uVar1;
}

