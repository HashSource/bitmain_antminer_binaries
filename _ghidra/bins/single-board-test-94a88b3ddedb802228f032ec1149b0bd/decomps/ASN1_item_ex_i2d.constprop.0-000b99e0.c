
uint ASN1_item_ex_i2d_constprop_0(ASN1_VALUE **param_1,ASN1_ITEM *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  ASN1_VALUE **ppAVar3;
  int iVar4;
  ASN1_TEMPLATE *tt;
  code *pcVar5;
  uint tag;
  code *pcVar6;
  ASN1_TEMPLATE *pAVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  uint local_24;
  
  pcVar5 = (code *)param_2->funcs;
  if ((param_2->itype != '\0') && (*param_1 == (ASN1_VALUE *)0x0)) {
    return 0;
  }
  pcVar6 = pcVar5;
  if (pcVar5 != (code *)0x0) {
    pcVar6 = *(code **)(pcVar5 + 0x10);
  }
  switch(param_2->itype) {
  case '\0':
    if (param_2->templates != (ASN1_TEMPLATE *)0x0) {
      uVar2 = asn1_template_ex_i2d_constprop_2(param_1,0,param_2->templates,param_3);
      return uVar2;
    }
    local_24 = param_2->utype;
    uVar2 = asn1_ex_i2c(param_1,(uchar *)0x0,(int *)&local_24,param_2);
    iVar1 = local_24 - 0x10;
    bVar11 = 0xfffffffc < local_24;
    bVar9 = local_24 != 0xfffffffd;
    if (bVar9) {
      bVar11 = iVar1 != 0;
    }
    bVar10 = iVar1 != 1;
    if (bVar11 && (bVar9 && bVar10)) {
      iVar1 = 0;
    }
    if (!bVar11 || (!bVar9 || !bVar10)) {
      iVar1 = 1;
    }
    if (uVar2 == 0xffffffff) {
      return 0;
    }
    if (uVar2 == 0xfffffffe) {
      iVar8 = 2;
      if (iVar1 != 0) {
        return 0;
      }
      uVar2 = 0;
      tag = local_24;
      goto LAB_000b9b02;
    }
LAB_000b9afc:
    iVar8 = 0;
    break;
  case '\x01':
    iVar8 = 1;
    goto LAB_000b9a3c;
  case '\x02':
    if ((pcVar6 != (code *)0x0) && (iVar8 = (*pcVar6)(6,param_1,param_2,0), iVar8 == 0)) {
      return 0;
    }
    iVar8 = asn1_get_choice_selector(param_1,param_2);
    if ((-1 < iVar8) && (iVar8 < param_2->tcount)) {
      pAVar7 = param_2->templates;
      ppAVar3 = asn1_get_field_ptr(param_1,pAVar7 + iVar8);
      uVar2 = asn1_template_ex_i2d_constprop_2(ppAVar3,0,pAVar7 + iVar8,param_3);
      return uVar2;
    }
    if (pcVar6 == (code *)0x0) {
      return 0;
    }
    (*pcVar6)(7,param_1,param_2,0);
    return 0;
  case '\x03':
    uVar2 = (**(code **)(pcVar5 + 0xc))(*param_1,0);
    return uVar2;
  case '\x04':
    uVar2 = (**(code **)(pcVar5 + 0x14))(param_1,0,param_2,0xffffffff,param_3);
    return uVar2;
  case '\x05':
    local_24 = param_2->utype;
    uVar2 = asn1_ex_i2c(param_1,(uchar *)0x0,(int *)&local_24,param_2);
    iVar1 = local_24 - 0x10;
    bVar11 = 0xfffffffc < local_24;
    bVar9 = local_24 != 0xfffffffd;
    if (bVar9) {
      bVar11 = iVar1 != 0;
    }
    bVar10 = iVar1 != 1;
    if (bVar11 && (bVar9 && bVar10)) {
      iVar1 = 0;
    }
    if (!bVar11 || (!bVar9 || !bVar10)) {
      iVar1 = 1;
    }
    if (uVar2 == 0xffffffff) {
      return 0;
    }
    if (uVar2 != 0xfffffffe) goto LAB_000b9afc;
    iVar8 = 2;
    uVar2 = 0;
    break;
  case '\x06':
    if ((param_3 & 0x800) == 0) {
      iVar8 = 1;
    }
    else {
      iVar8 = 2;
    }
LAB_000b9a3c:
    uVar2 = asn1_enc_restore((int *)&local_24,(uchar **)0x0,param_1,param_2);
    if ((int)uVar2 < 0) {
LAB_000b9a26:
      return 0;
    }
    if (uVar2 != 0) {
      return local_24;
    }
    local_24 = uVar2;
    if ((pcVar6 != (code *)0x0) && (iVar1 = (*pcVar6)(6,param_1,param_2,0), iVar1 == 0)) {
      return 0;
    }
    pAVar7 = param_2->templates;
    if (0 < param_2->tcount) {
      iVar1 = 0;
      do {
        iVar1 = iVar1 + 1;
        tt = asn1_do_adb(param_1,pAVar7,1);
        if (tt == (ASN1_TEMPLATE *)0x0) {
          return 0;
        }
        ppAVar3 = asn1_get_field_ptr(param_1,tt);
        pAVar7 = pAVar7 + 1;
        iVar4 = asn1_template_ex_i2d_constprop_2(ppAVar3,0,tt,param_3 & 0xffffff3f);
        local_24 = local_24 + iVar4;
      } while (iVar1 < param_2->tcount);
    }
    uVar2 = local_24;
    tag = 0x10;
    goto LAB_000b9b02;
  default:
    goto LAB_000b9a26;
  }
  tag = local_24;
  if (iVar1 != 0) {
    return uVar2;
  }
LAB_000b9b02:
  uVar2 = ASN1_object_size(iVar8,uVar2,tag);
  return uVar2;
}

