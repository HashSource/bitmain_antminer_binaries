
int ssl3_get_message(undefined4 *param_1,int param_2,undefined4 param_3,uint param_4,uint param_5,
                    undefined4 *param_6)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  
  iVar1 = param_1[0x16];
  if (*(int *)(iVar1 + 0x354) == 0) {
    iVar5 = param_1[0xf];
    pbVar9 = *(byte **)(iVar5 + 4);
    if (param_1[0xd] == param_2) {
      iVar1 = param_1[0x11];
LAB_0006d45e:
      while (3 < iVar1) {
        if (param_1[9] != 0) {
          uVar7 = (uint)*pbVar9;
LAB_0006d49a:
          if ((-1 < (int)param_4) && (uVar7 != param_4)) {
            iVar1 = 0x196;
            goto LAB_0006d562;
          }
          iVar1 = param_1[0x16];
          *(uint *)(iVar1 + 0x340) = uVar7;
          uVar7 = (uint)pbVar9[2] << 8 | (uint)pbVar9[1] << 0x10 | (uint)pbVar9[3];
          if (param_5 < uVar7) {
            iVar1 = 0x19f;
          }
          else {
            if (uVar7 < 0x7ffffffc) {
              if (uVar7 != 0) {
                iVar1 = BUF_MEM_grow_clean((BUF_MEM *)param_1[0xf],uVar7 + 4);
                if (iVar1 == 0) {
                  ERR_put_error(0x14,0x8e,7,DAT_0006d5b0,0x1a8);
                  goto LAB_0006d57a;
                }
                iVar1 = param_1[0x16];
              }
              iVar5 = param_1[0xf];
              iVar6 = 0;
              *(uint *)(iVar1 + 0x33c) = uVar7;
              param_1[0xd] = param_3;
              iVar1 = *(int *)(iVar5 + 4);
              param_1[0x11] = 0;
              iVar1 = iVar1 + 4;
              param_1[0x10] = iVar1;
              goto LAB_0006d3de;
            }
            iVar1 = 0x1a4;
          }
          ERR_put_error(0x14,0x8e,0x98,DAT_0006d5b0,iVar1);
          uVar4 = 0x2f;
          goto LAB_0006d572;
        }
        uVar7 = (uint)*pbVar9;
        if ((((uVar7 != 0) || (pbVar9[1] != 0)) || (pbVar9[2] != 0)) || (pbVar9[3] != 0))
        goto LAB_0006d49a;
        param_1[0x11] = 0;
        if ((code *)param_1[0x19] == (code *)0x0) {
          iVar1 = 0;
          break;
        }
        (*(code *)param_1[0x19])(0,*param_1,0x16,pbVar9,4,param_1,param_1[0x1a]);
        iVar1 = param_1[0x11];
      }
      iVar1 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,pbVar9 + iVar1,4 - iVar1,0);
      if (0 < iVar1) {
        iVar1 = iVar1 + param_1[0x11];
        param_1[0x11] = iVar1;
        goto LAB_0006d45e;
      }
      param_1[6] = 3;
      *param_6 = 0;
    }
    else {
      iVar6 = param_1[0x11];
      uVar7 = *(uint *)(iVar1 + 0x33c);
      iVar1 = param_1[0x10];
LAB_0006d3de:
      iVar8 = uVar7 - iVar6;
      if (0 < iVar8) {
        do {
          iVar6 = (**(code **)(param_1[2] + 0x34))(param_1,0x16,iVar1 + iVar6,iVar8,0);
          iVar8 = iVar8 - iVar6;
          if (iVar6 < 1) {
            param_1[6] = 3;
            *param_6 = 0;
            return iVar6;
          }
          iVar6 = param_1[0x11] + iVar6;
          param_1[0x11] = iVar6;
        } while (0 < iVar8);
        iVar5 = param_1[0xf];
      }
      pcVar2 = *(char **)(iVar5 + 4);
      if ((*pcVar2 == '\x14') && (iVar1 = param_1[0x16], *(int *)(iVar1 + 0x344) != 0)) {
        iVar5 = *(int *)(param_1[2] + 100);
        if ((param_1[0xd] & 0x1000) == 0) {
          uVar4 = *(undefined4 *)(iVar5 + 0x20);
          uVar3 = *(undefined4 *)(iVar5 + 0x24);
        }
        else {
          uVar4 = *(undefined4 *)(iVar5 + 0x28);
          uVar3 = *(undefined4 *)(iVar5 + 0x2c);
        }
        uVar4 = (**(code **)(iVar5 + 0x14))(param_1,uVar4,uVar3,iVar1 + 0x2b8);
        iVar5 = param_1[0xf];
        iVar6 = param_1[0x11];
        *(undefined4 *)(iVar1 + 0x338) = uVar4;
        pcVar2 = *(char **)(iVar5 + 4);
      }
      ssl3_finish_mac(param_1,pcVar2,iVar6 + 4);
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])
                  (0,*param_1,0x16,*(undefined4 *)(param_1[0xf] + 4),param_1[0x11] + 4,param_1,
                   param_1[0x1a]);
      }
      *param_6 = 1;
      iVar1 = param_1[0x11];
    }
  }
  else {
    *(undefined4 *)(iVar1 + 0x354) = 0;
    if (((int)param_4 < 0) || (*(uint *)(iVar1 + 0x340) == param_4)) {
      iVar1 = *(int *)(iVar1 + 0x33c);
      iVar5 = *(int *)(param_1[0xf] + 4);
      *param_6 = 1;
      param_1[0xd] = param_3;
      param_1[0x11] = iVar1;
      param_1[0x10] = iVar5 + 4;
    }
    else {
      iVar1 = 0x162;
LAB_0006d562:
      ERR_put_error(0x14,0x8e,0xf4,DAT_0006d5b0,iVar1);
      uVar4 = 10;
LAB_0006d572:
      ssl3_send_alert(param_1,2,uVar4);
LAB_0006d57a:
      iVar1 = -1;
      *param_6 = 0;
    }
  }
  return iVar1;
}

