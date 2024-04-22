
uint ASN1_item_ex_i2d_constprop_0(ASN1_VALUE **param_1,ASN1_ITEM *param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  ASN1_VALUE **ppAVar4;
  int iVar5;
  ASN1_TEMPLATE *tt;
  code *pcVar6;
  uint tag;
  code *pcVar7;
  ASN1_TEMPLATE *pAVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  uint local_24;
  
  pcVar6 = (code *)param_2->funcs;
  if ((param_2->itype != '\0') && (*param_1 == (ASN1_VALUE *)0x0)) {
    return 0;
  }
  pcVar7 = pcVar6;
  if (pcVar6 != (code *)0x0) {
    pcVar7 = *(code **)(pcVar6 + 0x10);
  }
  switch(param_2->itype) {
  case '\0':
    if (param_2->templates != (ASN1_TEMPLATE *)0x0) {
      uVar3 = asn1_template_ex_i2d_constprop_2(param_1,0,param_2->templates,param_3);
      return uVar3;
    }
    local_24 = param_2->utype;
    uVar3 = asn1_ex_i2c(param_1,(uchar *)0x0,(int *)&local_24,param_2);
    iVar2 = local_24 - 0x10;
    bVar11 = 0xfffffffc < local_24;
    bVar10 = local_24 != 0xfffffffd;
    if (bVar10) {
      bVar11 = iVar2 != 0;
    }
    bVar1 = iVar2 != 1;
    if (bVar11 && (bVar10 && bVar1)) {
      iVar2 = 0;
    }
    if (!bVar11 || (!bVar10 || !bVar1)) {
      iVar2 = 1;
    }
    if (uVar3 == 0xffffffff) {
      return 0;
    }
    if (uVar3 == 0xfffffffe) {
      iVar9 = 2;
      if (iVar2 != 0) {
        return 0;
      }
      uVar3 = 0;
      tag = local_24;
      goto LAB_000b9b02;
    }
LAB_000b9afc:
    iVar9 = 0;
    break;
  case '\x01':
    iVar9 = 1;
    goto LAB_000b9a3c;
  case '\x02':
    if ((pcVar7 != (code *)0x0) && (iVar9 = (*pcVar7)(6,param_1,param_2,0), iVar9 == 0)) {
      return 0;
    }
    iVar9 = asn1_get_choice_selector(param_1,param_2);
    if ((-1 < iVar9) && (iVar9 < param_2->tcount)) {
      pAVar8 = param_2->templates;
      ppAVar4 = asn1_get_field_ptr(param_1,pAVar8 + iVar9);
      uVar3 = asn1_template_ex_i2d_constprop_2(ppAVar4,0,pAVar8 + iVar9,param_3);
      return uVar3;
    }
    if (pcVar7 == (code *)0x0) {
      return 0;
    }
    (*pcVar7)(7,param_1,param_2,0);
    return 0;
  case '\x03':
    uVar3 = (**(code **)(pcVar6 + 0xc))(*param_1,0);
    return uVar3;
  case '\x04':
    uVar3 = (**(code **)(pcVar6 + 0x14))(param_1,0,param_2,0xffffffff,param_3);
    return uVar3;
  case '\x05':
    local_24 = param_2->utype;
    uVar3 = asn1_ex_i2c(param_1,(uchar *)0x0,(int *)&local_24,param_2);
    iVar2 = local_24 - 0x10;
    bVar11 = 0xfffffffc < local_24;
    bVar10 = local_24 != 0xfffffffd;
    if (bVar10) {
      bVar11 = iVar2 != 0;
    }
    bVar1 = iVar2 != 1;
    if (bVar11 && (bVar10 && bVar1)) {
      iVar2 = 0;
    }
    if (!bVar11 || (!bVar10 || !bVar1)) {
      iVar2 = 1;
    }
    if (uVar3 == 0xffffffff) {
      return 0;
    }
    if (uVar3 != 0xfffffffe) goto LAB_000b9afc;
    iVar9 = 2;
    uVar3 = 0;
    break;
  case '\x06':
    if ((param_3 & 0x800) == 0) {
      iVar9 = 1;
    }
    else {
      iVar9 = 2;
    }
LAB_000b9a3c:
    uVar3 = asn1_enc_restore((int *)&local_24,(uchar **)0x0,param_1,param_2);
    if ((int)uVar3 < 0) {
LAB_000b9a26:
      return 0;
    }
    if (uVar3 != 0) {
      return local_24;
    }
    local_24 = uVar3;
    if ((pcVar7 != (code *)0x0) && (iVar2 = (*pcVar7)(6,param_1,param_2,0), iVar2 == 0)) {
      return 0;
    }
    pAVar8 = param_2->templates;
    if (0 < param_2->tcount) {
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 1;
        tt = asn1_do_adb(param_1,pAVar8,1);
        if (tt == (ASN1_TEMPLATE *)0x0) {
          return 0;
        }
        ppAVar4 = asn1_get_field_ptr(param_1,tt);
        pAVar8 = pAVar8 + 1;
        iVar5 = asn1_template_ex_i2d_constprop_2(ppAVar4,0,tt,param_3 & 0xffffff3f);
        local_24 = local_24 + iVar5;
      } while (iVar2 < param_2->tcount);
    }
    uVar3 = local_24;
    tag = 0x10;
    goto LAB_000b9b02;
  default:
    goto LAB_000b9a26;
  }
  tag = local_24;
  if (iVar2 != 0) {
    return uVar3;
  }
LAB_000b9b02:
  uVar3 = ASN1_object_size(iVar9,uVar3,tag);
  return uVar3;
}

