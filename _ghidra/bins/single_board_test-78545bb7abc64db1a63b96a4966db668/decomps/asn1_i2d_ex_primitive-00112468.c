
code * asn1_i2d_ex_primitive(uint *param_1,uchar **param_2,char *param_3,uint param_4,int param_5)

{
  code *pcVar1;
  uint *puVar2;
  uchar **ppuVar3;
  undefined1 *__src;
  uint uVar4;
  uint *puVar5;
  size_t __n;
  int iVar6;
  size_t *psVar7;
  code *unaff_r5;
  code *unaff_r9;
  int constructed;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  undefined1 local_31;
  uint local_30;
  uchar *local_2c [2];
  
  uVar4 = *(uint *)(param_3 + 4);
  local_30 = uVar4;
  if ((*(int *)(param_3 + 0x10) != 0) &&
     (unaff_r5 = *(code **)(*(int *)(param_3 + 0x10) + 0x18), unaff_r5 != (code *)0x0)) {
    pcVar1 = (code *)(*unaff_r5)(param_1,0,&local_30,param_3);
    goto LAB_00112490;
  }
  puVar5 = param_1;
  if (*param_3 != '\0' || uVar4 != 1) {
    puVar2 = (uint *)*param_1;
    if (puVar2 == (uint *)0x0) {
      return (code *)0x0;
    }
    if (*param_3 == '\x05') {
      local_30 = puVar2[1];
    }
    else {
      unaff_r5 = (code *)(uVar4 + 4);
      if (unaff_r5 == (code *)0x0) {
        puVar5 = puVar2 + 1;
        local_30 = *puVar2;
      }
    }
  }
  if (local_30 - 1 < 10) {
    unaff_r5 = (code *)((int)&switchD_00112558::switchdataD_0011255c +
                       (&switchD_00112558::switchdataD_0011255c)[local_30 - 1]);
    switch(local_30) {
    case 1:
      if (*puVar5 == 0xffffffff) {
        return (code *)0x0;
      }
      if (uVar4 != 0xfffffffc) {
        if (*puVar5 == 0) {
          if (*(int *)(param_3 + 0x14) == 0) {
            return (code *)0x0;
          }
        }
        else if (0 < *(int *)(param_3 + 0x14)) {
          return (code *)0x0;
        }
        unaff_r5 = (code *)0x1;
        goto LAB_001125fe;
      }
      unaff_r5 = (code *)0x1;
      unaff_r9 = unaff_r5;
      goto LAB_001124b0;
    case 2:
    case 10:
      pcVar1 = (code *)i2c_ASN1_INTEGER((ASN1_INTEGER *)*puVar5,(uchar **)0x0);
      break;
    case 3:
      pcVar1 = (code *)i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*puVar5,(uchar **)0x0);
      break;
    default:
      goto switchD_00112558_caseD_4;
    case 5:
      unaff_r5 = (code *)0x0;
LAB_001125fe:
      unaff_r9 = (code *)0x1;
      goto LAB_001124aa;
    case 6:
      pcVar1 = *(code **)(*puVar5 + 0xc);
      if (pcVar1 == (code *)0x0 || *(int *)(*puVar5 + 0x10) == 0) {
        return (code *)0x0;
      }
      goto LAB_00112518;
    }
LAB_00112490:
    bVar10 = 0xfffffffc < local_30;
    bVar8 = local_30 != 0xfffffffd;
    if (bVar8) {
      bVar10 = local_30 != 0x10;
    }
    bVar9 = local_30 != 0x11;
    if (!bVar10 || (!bVar8 || !bVar9)) {
      unaff_r5 = pcVar1;
    }
    if (!bVar10 || (!bVar8 || !bVar9)) {
      unaff_r9 = (code *)0x0;
    }
    if (bVar10 && (bVar8 && bVar9)) {
LAB_00112518:
      unaff_r9 = (code *)0x1;
      unaff_r5 = pcVar1;
    }
    if (pcVar1 == (code *)0xffffffff) {
      return (code *)0x0;
    }
LAB_001124aa:
    if (unaff_r5 == (code *)0xfffffffe) {
      constructed = 2;
      unaff_r5 = (code *)0x0;
    }
    else {
LAB_001124b0:
      constructed = 0;
    }
  }
  else {
switchD_00112558_caseD_4:
    if ((*(int *)(param_3 + 0x14) != 0x800) ||
       (unaff_r5 = (code *)(((int *)*puVar5)[3] << 0x1b), -1 < (int)unaff_r5)) {
      pcVar1 = *(code **)*puVar5;
      goto LAB_00112490;
    }
    bVar10 = 0xfffffffc < local_30;
    if (local_30 != 0xfffffffd) {
      bVar10 = local_30 != 0x10;
    }
    if (bVar10 && (local_30 != 0xfffffffd && local_30 != 0x11)) {
      unaff_r5 = (code *)0xfffffffe;
      goto LAB_001125fe;
    }
    unaff_r9 = (code *)0x0;
    unaff_r5 = (code *)0x0;
    constructed = 2;
  }
  if (param_4 == 0xffffffff) {
    param_4 = local_30;
  }
  if (param_2 == (uchar **)0x0) goto LAB_001124f2;
  if (unaff_r9 != (code *)0x0) {
    ASN1_put_object(param_2,constructed,(int)unaff_r5,param_4,param_5);
  }
  local_2c[0] = *param_2;
  if ((*(int *)(param_3 + 0x10) == 0) ||
     (pcVar1 = *(code **)(*(int *)(param_3 + 0x10) + 0x18), pcVar1 == (code *)0x0)) {
    if (*param_3 == '\0') {
      iVar6 = *(int *)(param_3 + 4);
      if (iVar6 != 1) {
        puVar5 = (uint *)*param_1;
        if (puVar5 == (uint *)0x0) goto switchD_001125ac_caseD_5;
LAB_00112596:
        if (iVar6 == -4) {
          param_1 = puVar5 + 1;
          local_30 = *puVar5;
        }
      }
    }
    else {
      puVar5 = (uint *)*param_1;
      if (puVar5 == (uint *)0x0) goto switchD_001125ac_caseD_5;
      if (*param_3 != '\x05') {
        iVar6 = *(int *)(param_3 + 4);
        goto LAB_00112596;
      }
      local_30 = puVar5[1];
    }
    switch(local_30) {
    case 1:
      uVar4 = *param_1;
      if (uVar4 != 0xffffffff) {
        if (*(int *)(param_3 + 4) == -4) {
LAB_001126c2:
          __n = 1;
          __src = &local_31;
          local_31 = (undefined1)uVar4;
          goto LAB_00112688;
        }
        if (uVar4 == 0) {
          if (*(int *)(param_3 + 0x14) != 0) goto LAB_001126c2;
        }
        else if (*(int *)(param_3 + 0x14) < 1) goto LAB_001126c2;
      }
      break;
    case 2:
    case 10:
      ppuVar3 = local_2c;
      if (local_2c[0] == (uchar *)0x0) {
        ppuVar3 = (uchar **)0x0;
      }
      i2c_ASN1_INTEGER((ASN1_INTEGER *)*param_1,ppuVar3);
      break;
    case 3:
      ppuVar3 = local_2c;
      if (local_2c[0] == (uchar *)0x0) {
        ppuVar3 = (uchar **)0x0;
      }
      i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*param_1,ppuVar3);
      break;
    default:
      psVar7 = (size_t *)*param_1;
      if ((*(int *)(param_3 + 0x14) == 0x800) && ((int)(psVar7[3] << 0x1b) < 0)) {
        if (local_2c[0] != (uchar *)0x0) {
          psVar7[2] = (size_t)local_2c[0];
          *psVar7 = 0;
        }
      }
      else {
        __n = *psVar7;
        if (__n != 0 && local_2c[0] != (uchar *)0x0) {
          __src = (undefined1 *)psVar7[2];
          goto LAB_0011268e;
        }
      }
      break;
    case 5:
      break;
    case 6:
      __src = *(undefined1 **)(*param_1 + 0x10);
      __n = *(size_t *)(*param_1 + 0xc);
      if (__n != 0 && __src != (undefined1 *)0x0) {
LAB_00112688:
        if (local_2c[0] != (uchar *)0x0) {
LAB_0011268e:
          memcpy(local_2c[0],__src,__n);
        }
      }
    }
  }
  else {
    (*pcVar1)(param_1,local_2c[0],&local_30,param_3);
  }
switchD_001125ac_caseD_5:
  if (constructed == 0) {
    *param_2 = *param_2 + (int)unaff_r5;
  }
  else {
    ASN1_put_eoc(param_2);
  }
LAB_001124f2:
  if (unaff_r9 != (code *)0x0) {
    unaff_r5 = (code *)ASN1_object_size(constructed,(int)unaff_r5,param_4);
  }
  return unaff_r5;
}

