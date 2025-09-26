
ulong bn_sub_part_words(ulong *param_1,ulong *param_2,ulong *param_3,int param_4,int param_5)

{
  ulong *puVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  
  uVar2 = bn_sub_words(param_1,param_2,param_3,param_4);
  if (param_5 != 0) {
    param_1 = param_1 + param_4;
    if (param_5 < 0) {
      param_3 = param_3 + param_4 + 4;
      while( true ) {
        iVar3 = uVar2 + param_3[-4];
        if (param_3[-4] != 0) {
          uVar2 = 1;
        }
        *param_1 = -iVar3;
        if (param_5 == -1) break;
        iVar3 = uVar2 + param_3[-3];
        if (param_3[-3] != 0) {
          uVar2 = 1;
        }
        param_1[1] = -iVar3;
        if (param_5 == -2) {
          return uVar2;
        }
        iVar3 = uVar2 + param_3[-2];
        if (param_3[-2] != 0) {
          uVar2 = 1;
        }
        param_1[2] = -iVar3;
        if (param_5 == -3) {
          return uVar2;
        }
        puVar1 = param_3 + -1;
        param_3 = param_3 + 4;
        iVar3 = uVar2 + *puVar1;
        if (*puVar1 != 0) {
          uVar2 = 1;
        }
        param_5 = param_5 + 4;
        param_1[3] = -iVar3;
        param_1 = param_1 + 4;
        if (param_5 == 0) {
          return uVar2;
        }
      }
    }
    else {
      param_2 = param_2 + param_4;
      do {
        if (uVar2 == 0) {
LAB_0011b23a:
          *param_1 = *param_2;
          if (((param_5 != 1) && (param_1[1] = param_2[1], param_5 != 2)) &&
             (param_1[2] = param_2[2], param_5 != 3)) {
            param_1[3] = param_2[3];
            while (((param_5 = param_5 + -4, param_5 != 0 && (param_1[4] = param_2[4], param_5 != 1)
                    ) && ((param_1[5] = param_2[5], param_5 != 2 &&
                          (param_1[6] = param_2[6], param_5 != 3))))) {
              puVar1 = param_2 + 7;
              param_2 = param_2 + 4;
              param_1[7] = *puVar1;
              param_1 = param_1 + 4;
            }
          }
          return 0;
        }
        uVar4 = *param_2 - uVar2;
        if (*param_2 != 0) {
          uVar2 = 0;
        }
        *param_1 = uVar4;
        if (param_5 == 1) {
          return uVar2;
        }
        uVar4 = param_2[1] - uVar2;
        if (param_2[1] != 0) {
          uVar2 = 0;
        }
        param_1[1] = uVar4;
        if (param_5 == 2) {
          return uVar2;
        }
        uVar4 = param_2[2] - uVar2;
        if (param_2[2] != 0) {
          uVar2 = 0;
        }
        param_1[2] = uVar4;
        if (param_5 == 3) {
          return uVar2;
        }
        uVar4 = param_2[3];
        param_1[3] = uVar4 - uVar2;
        if (uVar4 != 0) {
          param_5 = param_5 + -4;
          if (param_5 == 0) {
            return 0;
          }
          param_2 = param_2 + 4;
          param_1 = param_1 + 4;
          goto LAB_0011b23a;
        }
        param_5 = param_5 + -4;
        param_2 = param_2 + 4;
        param_1 = param_1 + 4;
      } while (param_5 != 0);
    }
  }
  return uVar2;
}

