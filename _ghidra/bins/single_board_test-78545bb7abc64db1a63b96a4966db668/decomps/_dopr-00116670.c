
/* WARNING: Type propagation algorithm not settling */

undefined4
_dopr(int *param_1,uint param_2,uint *param_3,int *param_4,uint *param_5,byte *param_6,uint *param_7
     )

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  char *pcVar14;
  bool bVar15;
  uint local_58;
  uint *local_50;
  int local_44;
  uint local_3c;
  uint local_2c [2];
  
  iVar13 = 0;
  uVar11 = (uint)*param_6;
  local_50 = param_7;
  param_6 = param_6 + 1;
  uVar10 = 0;
  local_58 = 0xffffffff;
  local_2c[0] = 0;
  uVar12 = 0;
  uVar7 = 0;
joined_r0x001166a2:
  do {
    if (uVar11 == 0) goto LAB_001166a4;
    if ((param_2 == 0) && (uVar6 = *param_3, uVar6 <= local_2c[0])) goto LAB_00116a16;
    switch(uVar12) {
    case 0:
      if (uVar11 == 0x25) {
        uVar12 = 1;
      }
      else {
        if (param_2 == 0 && *param_1 == 0) {
          return 0;
        }
        iVar2 = doapr_outch_part_0(param_1,param_2,local_2c,param_3,uVar11);
        if (iVar2 == 0) {
          return 0;
        }
      }
      goto LAB_00116860;
    case 1:
      switch(uVar11) {
      case 0x20:
        uVar11 = (uint)*param_6;
        uVar7 = uVar7 | 4;
        param_6 = (byte *)((int)param_6 + 1);
        break;
      default:
        uVar12 = 2;
        break;
      case 0x23:
        uVar11 = (uint)*param_6;
        uVar7 = uVar7 | 8;
        param_6 = (byte *)((int)param_6 + 1);
        break;
      case 0x2b:
        uVar11 = (uint)*param_6;
        uVar7 = uVar7 | 2;
        param_6 = (byte *)((int)param_6 + 1);
        break;
      case 0x2d:
        uVar7 = uVar7 | 1;
LAB_00116860:
        bVar1 = *param_6;
joined_r0x001168d0:
        uVar11 = (uint)bVar1;
        param_6 = (byte *)((int)param_6 + 1);
        break;
      case 0x30:
        uVar11 = (uint)*param_6;
        uVar7 = uVar7 | 0x10;
        param_6 = (byte *)((int)param_6 + 1);
      }
      break;
    case 2:
      iVar2 = ossl_ctype_check(uVar11,4);
      if (iVar2 == 0) {
        if (uVar11 == 0x2a) {
          uVar12 = 3;
          uVar11 = (uint)*param_6;
          param_6 = (byte *)((int)param_6 + 1);
          uVar10 = *local_50;
          local_50 = (uint *)((int)local_50 + 4);
        }
        else {
          uVar12 = 3;
        }
      }
      else {
        iVar2 = uVar11 - 0x30;
        uVar11 = (uint)*param_6;
        param_6 = (byte *)((int)param_6 + 1);
        uVar10 = iVar2 + uVar10 * 10;
      }
      break;
    case 3:
      if (uVar11 != 0x2e) goto LAB_00116872;
      uVar11 = (uint)*param_6;
      uVar12 = 4;
      param_6 = (byte *)((int)param_6 + 1);
      break;
    case 4:
      iVar2 = ossl_ctype_check(uVar11,4);
      if (iVar2 == 0) {
        if (uVar11 == 0x2a) {
          uVar12 = 5;
          uVar11 = (uint)*param_6;
          param_6 = (byte *)((int)param_6 + 1);
          local_58 = *local_50;
          local_50 = (uint *)((int)local_50 + 4);
        }
        else {
LAB_00116872:
          uVar12 = 5;
        }
      }
      else {
        iVar2 = uVar11 - 0x30;
        uVar11 = (uint)*param_6;
        param_6 = (byte *)((int)param_6 + 1);
        local_58 = iVar2 + (local_58 & ~((int)local_58 >> 0x1f)) * 10;
      }
      break;
    case 5:
      switch(uVar11) {
      case 0x4c:
        uVar11 = (uint)*param_6;
        iVar13 = 3;
        param_6 = (byte *)((int)param_6 + 1);
        uVar12 = 6;
        goto joined_r0x001166a2;
      default:
        goto switchD_001167ae_caseD_4d;
      case 0x68:
        iVar13 = 1;
        uVar11 = (uint)*param_6;
        uVar12 = 6;
        param_6 = (byte *)((int)param_6 + 1);
        goto joined_r0x001166a2;
      case 0x6a:
      case 0x71:
        uVar11 = (uint)*param_6;
        iVar13 = 4;
        break;
      case 0x6c:
        uVar11 = (uint)*param_6;
        if (uVar11 == 0x6c) {
          uVar11 = (uint)*(byte *)((int)param_6 + 1);
          iVar13 = 4;
          param_6 = (byte *)((int)param_6 + 1);
        }
        else {
          iVar13 = 2;
        }
        break;
      case 0x7a:
        bVar1 = *param_6;
        iVar13 = 5;
        uVar12 = 6;
        goto joined_r0x001168d0;
      }
      param_6 = param_6 + 1;
switchD_001167ae_caseD_4d:
      uVar12 = 6;
      break;
    case 6:
      switch(uVar11) {
      case 0x25:
        if (param_2 == 0 && *param_1 == 0) {
          return 0;
        }
        iVar13 = doapr_outch_part_0(param_1,param_2,local_2c,param_3,0x25);
        break;
      default:
        goto switchD_001166f8_caseD_26;
      case 0x45:
        uVar7 = uVar7 | 0x20;
      case 0x65:
        puVar5 = (undefined8 *)((int)local_50 + 7U & 0xfffffff8);
        if (iVar13 == 3) {
          uVar4 = (undefined4)*puVar5;
        }
        else {
          uVar4 = (undefined4)*puVar5;
        }
        uVar3 = 1;
LAB_0011697c:
        local_50 = (uint *)(puVar5 + 1);
        iVar13 = fmtfp(uVar4,param_1,param_2,local_2c,param_3,uVar10,local_58,uVar7,uVar3);
        break;
      case 0x47:
        uVar7 = uVar7 | 0x20;
      case 0x67:
        puVar5 = (undefined8 *)((int)local_50 + 7U & 0xfffffff8);
        if (iVar13 == 3) {
          uVar4 = (undefined4)*puVar5;
        }
        else {
          uVar4 = (undefined4)*puVar5;
        }
        uVar3 = 2;
        goto LAB_0011697c;
      case 0x58:
        uVar7 = uVar7 | 0x20;
      case 0x6f:
      case 0x75:
      case 0x78:
        switch(iVar13) {
        case 1:
          uVar12 = 0;
          uVar6 = (uint)(ushort)*local_50;
          local_50 = (uint *)((int)local_50 + 4);
          break;
        default:
          uVar12 = 0;
          uVar6 = *local_50;
          local_50 = (uint *)((int)local_50 + 4);
          break;
        case 4:
          puVar8 = (uint *)((int)local_50 + 7U & 0xfffffff8);
          local_50 = puVar8 + 2;
          uVar6 = *puVar8;
          uVar12 = puVar8[1];
        }
        if (uVar11 == 0x6f) {
          uVar4 = 8;
        }
        else if (uVar11 == 0x75) {
          uVar4 = 10;
        }
        else {
          uVar4 = 0x10;
        }
        iVar13 = fmtint(param_1,param_2,local_2c,param_3,uVar6,uVar12,uVar4,uVar10,local_58,
                        uVar7 | 0x40);
        break;
      case 99:
        if (param_2 == 0 && *param_1 == 0) {
          return 0;
        }
        iVar13 = doapr_outch_part_0(param_1,param_2,local_2c,param_3,*local_50);
        local_50 = (uint *)((int)local_50 + 4);
        break;
      case 100:
      case 0x69:
        switch(iVar13) {
        case 1:
          uVar12 = (uint)(short)(ushort)*local_50;
          local_50 = (uint *)((int)local_50 + 4);
          uVar11 = (int)uVar12 >> 0x1f;
          break;
        default:
          uVar12 = *local_50;
          local_50 = (uint *)((int)local_50 + 4);
          uVar11 = (int)uVar12 >> 0x1f;
          break;
        case 4:
          puVar8 = (uint *)((int)local_50 + 7U & 0xfffffff8);
          local_50 = puVar8 + 2;
          uVar12 = *puVar8;
          uVar11 = puVar8[1];
        }
        iVar13 = fmtint(param_1,param_2,local_2c,param_3,uVar12,uVar11,10,uVar10,local_58,uVar7);
        break;
      case 0x66:
        puVar5 = (undefined8 *)((int)local_50 + 7U & 0xfffffff8);
        if (iVar13 == 3) {
          uVar4 = (undefined4)*puVar5;
        }
        else {
          uVar4 = (undefined4)*puVar5;
        }
        local_50 = (uint *)(puVar5 + 1);
        iVar13 = fmtfp(uVar4,param_1,param_2,local_2c,param_3,uVar10,local_58,uVar7,0);
        break;
      case 0x6e:
        *(uint *)*local_50 = local_2c[0];
        local_50 = (uint *)((int)local_50 + 4);
        goto switchD_001166f8_caseD_26;
      case 0x70:
        iVar13 = fmtint(param_1,param_2,local_2c,param_3,*local_50,0,0x10,uVar10,local_58,uVar7 | 8)
        ;
        local_50 = (uint *)((int)local_50 + 4);
        break;
      case 0x73:
        puVar8 = (uint *)((int)local_50 + 4);
        pcVar14 = (char *)*local_50;
        local_50 = puVar8;
        if ((int)local_58 < 0) {
          if (param_2 != 0) {
            local_58 = 0x7fffffff;
            goto LAB_00116ab0;
          }
          local_58 = *param_3;
          if (pcVar14 == (char *)0x0) {
            pcVar14 = "<NULL>";
          }
          if (-1 < (int)local_58) goto LAB_00116ab8;
          local_44 = OPENSSL_strnlen(pcVar14,0xffffffff);
          uVar12 = uVar10 - local_44;
          if (-1 < (int)(uVar12 | uVar10)) goto LAB_00116ae6;
          if ((uVar7 & 1) == 0) {
            iVar13 = 0;
            uVar12 = 0;
            goto LAB_00116db8;
          }
          uVar12 = 0;
LAB_00116d06:
          uVar12 = -uVar12;
          if (local_44 == 0) {
LAB_00116dd6:
            if ((int)uVar12 < 0) {
              uVar11 = local_58 >> 0x1f;
              if (local_44 < (int)local_58) {
                uVar11 = 1;
              }
              if (uVar11 != 0) {
                iVar13 = local_44 - uVar12;
                uVar12 = param_2;
                if (param_2 != 0) {
                  uVar12 = 1;
                }
                do {
                  local_44 = local_44 + 1;
                  uVar11 = uVar12;
                  if (*param_1 != 0) {
                    uVar11 = uVar12 | 1;
                  }
                  if (uVar11 == 0) {
                    return 0;
                  }
                  iVar2 = doapr_outch_part_0(param_1,param_2,local_2c,param_3,0x20);
                  if (iVar2 == 0) {
                    return 0;
                  }
                  if (local_44 == iVar13) break;
                  uVar11 = local_58 >> 0x1f;
                  if (local_44 < (int)local_58) {
                    uVar11 = 1;
                  }
                } while (uVar11 != 0);
              }
            }
            goto switchD_001166f8_caseD_26;
          }
          iVar13 = 0;
          local_3c = local_58 >> 0x1f;
        }
        else {
LAB_00116ab0:
          if (pcVar14 == (char *)0x0) {
            pcVar14 = "<NULL>";
          }
LAB_00116ab8:
          local_44 = OPENSSL_strnlen(pcVar14,local_58);
          uVar12 = uVar10 - local_44;
          iVar13 = 0x7fffffff;
          if ((int)(uVar10 | uVar12) < 0) {
            uVar12 = 0;
          }
          else {
            iVar13 = 0x7fffffff - uVar12;
          }
          if ((int)local_58 < iVar13) {
            local_58 = local_58 + uVar12;
          }
          else {
            local_58 = 0x7fffffff;
          }
LAB_00116ae6:
          if ((uVar7 & 1) != 0) goto LAB_00116d06;
          if (uVar12 == 0) {
            iVar13 = 0;
            uVar12 = 0;
          }
          else {
            local_3c = local_58 >> 0x1f;
            if (local_58 == 0) goto switchD_001166f8_caseD_26;
            uVar11 = param_2;
            if (param_2 != 0) {
              uVar11 = 1;
            }
            iVar13 = 0;
            do {
              iVar13 = iVar13 + 1;
              uVar7 = uVar11;
              if (*param_1 != 0) {
                uVar7 = uVar11 | 1;
              }
              if (uVar7 == 0) {
                return 0;
              }
              iVar2 = doapr_outch_part_0(param_1,param_2,local_2c,param_3,0x20);
              if (iVar2 == 0) {
                return 0;
              }
              uVar12 = uVar12 - 1;
              if (uVar12 == 0) {
                if (local_44 != 0) goto LAB_00116d18;
                goto switchD_001166f8_caseD_26;
              }
              uVar7 = local_58 >> 0x1f;
              if (iVar13 < (int)local_58) {
                uVar7 = 1;
              }
            } while (uVar7 != 0);
          }
LAB_00116db8:
          if (local_44 == 0) goto switchD_001166f8_caseD_26;
          local_3c = local_58 >> 0x1f;
        }
LAB_00116d18:
        uVar11 = local_3c;
        if (iVar13 < (int)local_58) {
          uVar11 = 1;
        }
        if (uVar11 != 0) {
          uVar11 = param_2;
          if (param_2 != 0) {
            uVar11 = 1;
          }
          pcVar9 = pcVar14 + local_44;
          local_44 = iVar13;
          do {
            local_44 = local_44 + 1;
            uVar7 = uVar11;
            if (*param_1 != 0) {
              uVar7 = uVar11 | 1;
            }
            if (uVar7 == 0) {
              return 0;
            }
            iVar13 = doapr_outch_part_0(param_1,param_2,local_2c,param_3,*pcVar14);
            if (iVar13 == 0) {
              return 0;
            }
            if (pcVar14 + 1 == pcVar9) goto LAB_00116dd6;
            uVar7 = local_3c;
            if (local_44 < (int)local_58) {
              uVar7 = 1;
            }
            pcVar14 = pcVar14 + 1;
          } while (uVar7 != 0);
        }
        goto switchD_001166f8_caseD_26;
      case 0x77:
        param_6 = (byte *)((int)param_6 + 1);
        goto switchD_001166f8_caseD_26;
      }
      if (iVar13 == 0) {
        return 0;
      }
switchD_001166f8_caseD_26:
      iVar13 = 0;
      uVar10 = 0;
      uVar11 = (uint)*param_6;
      param_6 = param_6 + 1;
      local_58 = 0xffffffff;
      uVar12 = uVar10;
      uVar7 = uVar10;
      break;
    default:
      goto switchD_001166e2_default;
    }
  } while( true );
switchD_001166e2_default:
  if (uVar12 == 7) {
LAB_001166a4:
    if (param_2 == 0) {
      uVar6 = *param_3;
LAB_00116a16:
      bVar15 = uVar6 - 1 < local_2c[0];
      *param_5 = (uint)bVar15;
      if (bVar15) {
        local_2c[0] = *param_3 - 1;
      }
      if (*param_1 == 0) {
        return 0;
      }
    }
    iVar13 = doapr_outch_part_0(param_1,param_2,local_2c,param_3,0);
    if (iVar13 == 0) {
      return 0;
    }
    *param_4 = local_2c[0] - 1;
    return 1;
  }
  goto joined_r0x001166a2;
}

