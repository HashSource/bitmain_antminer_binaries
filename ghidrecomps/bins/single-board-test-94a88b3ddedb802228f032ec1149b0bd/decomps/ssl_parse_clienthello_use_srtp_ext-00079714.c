
undefined4
ssl_parse_clienthello_use_srtp_ext(int param_1,undefined *param_2,int param_3,undefined4 *param_4)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  void *pvVar5;
  _STACK *p_Var6;
  uint uVar7;
  byte *pbVar8;
  int iVar9;
  
  if (param_3 < 3) {
    iVar9 = 0x125;
    iVar4 = 0x161;
  }
  else {
    param_3 = param_3 + -2;
    uVar7 = (uint)CONCAT11(*param_2,param_2[1]);
    if ((param_2[1] & 1) == 0) {
      if ((int)uVar7 < param_3) {
        if (param_1 == 0) {
          p_Var6 = (_STACK *)0x0;
        }
        else {
          p_Var6 = *(_STACK **)(param_1 + 0x17c);
          if ((p_Var6 == (_STACK *)0x0) && (*(int *)(param_1 + 0xe4) != 0)) {
            p_Var6 = *(_STACK **)(*(int *)(param_1 + 0xe4) + 0x1b4);
          }
        }
        pbVar8 = param_2 + 2;
        *(undefined4 *)(param_1 + 0x180) = 0;
        iVar4 = sk_num(p_Var6);
        if (uVar7 != 0) {
          pbVar3 = param_2 + 4;
          do {
            pbVar8 = pbVar3;
            bVar1 = pbVar8[-2];
            bVar2 = pbVar8[-1];
            uVar7 = uVar7 - 2;
            param_3 = param_3 + -2;
            if (0 < iVar4) {
              iVar9 = 0;
              do {
                pvVar5 = sk_value(p_Var6,iVar9);
                if (*(uint *)((int)pvVar5 + 4) == (uint)CONCAT11(bVar1,bVar2)) {
                  *(void **)(param_1 + 0x180) = pvVar5;
                  iVar4 = iVar9;
                  break;
                }
                iVar9 = iVar9 + 1;
              } while (iVar9 != iVar4);
            }
            pbVar3 = pbVar8 + 2;
          } while (uVar7 != 0);
        }
        if ((uint)*pbVar8 == param_3 - 1U) {
          return 0;
        }
        iVar4 = 0x160;
        iVar9 = 0x161;
      }
      else {
        iVar9 = 0x139;
        iVar4 = 0x161;
      }
    }
    else {
      iVar9 = 0x131;
      iVar4 = 0x161;
    }
  }
  ERR_put_error(0x14,0x136,iVar4,DAT_00079828,iVar9);
  *param_4 = 0x32;
  return 1;
}

