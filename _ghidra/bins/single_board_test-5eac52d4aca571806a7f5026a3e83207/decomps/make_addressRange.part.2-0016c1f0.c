
undefined4 make_addressRange_part_2(undefined4 *param_1,void *param_2,void *param_3,int param_4)

{
  byte *pbVar1;
  IPAddressOrRange *a;
  IPAddressRange *pIVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int unaff_r5;
  byte *pbVar6;
  ASN1_BIT_STRING *pAVar7;
  
  a = IPAddressOrRange_new();
  if (a == (IPAddressOrRange *)0x0) {
    return 0;
  }
  a->type = 1;
  pIVar2 = IPAddressRange_new();
  (a->u).addressRange = pIVar2;
  if (pIVar2 != (IPAddressRange *)0x0) {
    if (pIVar2->min == (ASN1_BIT_STRING *)0x0) {
      pAVar7 = ASN1_BIT_STRING_new();
      pIVar2->min = pAVar7;
      if (pAVar7 == (ASN1_BIT_STRING *)0x0) goto LAB_0016c258;
      pIVar2 = (a->u).addressRange;
    }
    if (pIVar2->max == (ASN1_BIT_STRING **)0x0) {
      pAVar7 = ASN1_BIT_STRING_new();
      pIVar2->max = (ASN1_BIT_STRING **)pAVar7;
      if (pAVar7 == (ASN1_BIT_STRING *)0x0) goto LAB_0016c258;
      pIVar2 = (a->u).addressRange;
    }
    iVar3 = param_4;
    if (param_4 < 1) {
LAB_0016c24c:
      iVar3 = ASN1_BIT_STRING_set(pIVar2->min,param_2,iVar3);
      if (iVar3 == 0) goto LAB_0016c258;
      pIVar2 = (a->u).addressRange;
      if (0 < param_4) {
        unaff_r5 = param_4 + -1;
      }
      pIVar2->min->flags = pIVar2->min->flags & 0xfffffff8U | 8;
      if (param_4 < 1) {
LAB_0016c2d0:
        iVar3 = ASN1_BIT_STRING_set((ASN1_STRING *)pIVar2->max,param_3,param_4);
        if (iVar3 == 0) goto LAB_0016c258;
        iVar3 = ((a->u).addressPrefix)->type;
        *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) & 0xfffffff8 | 8;
        goto LAB_0016c350;
      }
    }
    else {
      unaff_r5 = param_4 + -1;
      pbVar6 = (byte *)((int)param_2 + unaff_r5);
      if (*(char *)((int)param_2 + unaff_r5) == '\0') {
        pbVar1 = (byte *)(param_4 + -2 + (int)param_2);
        do {
          pbVar6 = pbVar1;
          iVar3 = iVar3 + -1;
          if (iVar3 == 0) goto LAB_0016c24c;
          pbVar1 = pbVar6 + -1;
        } while (*pbVar6 == 0);
      }
      iVar3 = ASN1_BIT_STRING_set(pIVar2->min,param_2,iVar3);
      if (iVar3 == 0) goto LAB_0016c258;
      pIVar2 = (a->u).addressRange;
      pAVar7 = pIVar2->min;
      uVar5 = pAVar7->flags & 0xfffffff8U | 8;
      pAVar7->flags = uVar5;
      if ((*pbVar6 & 0x7f) == 0) {
        uVar4 = 7;
      }
      else {
        uVar4 = 1;
        do {
          uVar4 = uVar4 + 1;
        } while ((0xffU >> (uVar4 & 0xff) & (uint)*pbVar6) != 0);
        uVar4 = 8 - uVar4;
      }
      pAVar7->flags = uVar5 | uVar4;
    }
    pbVar6 = (byte *)(unaff_r5 + (int)param_3);
    if (*(char *)((int)param_3 + unaff_r5) == -1) {
      pbVar1 = (byte *)(param_4 + -2 + (int)param_3);
      do {
        pbVar6 = pbVar1;
        param_4 = param_4 + -1;
        if (param_4 == 0) goto LAB_0016c2d0;
        pbVar1 = pbVar6 + -1;
      } while (*pbVar6 == 0xff);
    }
    iVar3 = ASN1_BIT_STRING_set((ASN1_STRING *)pIVar2->max,param_3,param_4);
    if (iVar3 != 0) {
      iVar3 = ((a->u).addressPrefix)->type;
      uVar5 = *(uint *)(iVar3 + 0xc) & 0xfffffff8 | 8;
      *(uint *)(iVar3 + 0xc) = uVar5;
      if ((*pbVar6 & 0x7f) == 0x7f) {
        uVar4 = 7;
      }
      else {
        uVar4 = 1;
        do {
          uVar4 = uVar4 + 1;
        } while ((0xffU >> (uVar4 & 0xff) & ~(uint)*pbVar6) != 0);
        uVar4 = 8 - uVar4;
      }
      *(uint *)(iVar3 + 0xc) = uVar4 | uVar5;
LAB_0016c350:
      *param_1 = a;
      return 1;
    }
  }
LAB_0016c258:
  IPAddressOrRange_free(a);
  return 0;
}

