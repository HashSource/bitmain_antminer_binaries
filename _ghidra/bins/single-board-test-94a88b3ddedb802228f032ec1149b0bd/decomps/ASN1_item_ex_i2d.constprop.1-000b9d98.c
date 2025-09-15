
int ASN1_item_ex_i2d_constprop_1
              (ASN1_VALUE **param_1,uchar **param_2,ASN1_ITEM *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  ASN1_VALUE **ppAVar3;
  ASN1_TEMPLATE *pAVar4;
  code *pcVar5;
  ASN1_TEMPLATE *pAVar6;
  code *pcVar7;
  int local_34;
  int local_2c [2];
  
  pcVar5 = (code *)param_3->funcs;
  if ((param_3->itype != '\0') && (*param_1 == (ASN1_VALUE *)0x0)) {
    return 0;
  }
  pcVar7 = pcVar5;
  if (pcVar5 != (code *)0x0) {
    pcVar7 = *(code **)(pcVar5 + 0x10);
  }
  switch(param_3->itype) {
  case '\0':
    if (param_3->templates != (ASN1_TEMPLATE *)0x0) {
      iVar2 = asn1_template_ex_i2d_constprop_2(param_1,param_2,param_3->templates,param_4);
      return iVar2;
    }
  case '\x05':
    iVar2 = asn1_i2d_ex_primitive(param_1,param_2,param_3,0xffffffff,param_4);
    return iVar2;
  case '\x01':
    local_34 = 1;
    break;
  case '\x02':
    if ((pcVar7 != (code *)0x0) && (iVar2 = (*pcVar7)(6,param_1,param_3,0), iVar2 == 0)) {
      return 0;
    }
    iVar2 = asn1_get_choice_selector(param_1,param_3);
    if ((-1 < iVar2) && (iVar2 < param_3->tcount)) {
      pAVar6 = param_3->templates;
      ppAVar3 = asn1_get_field_ptr(param_1,pAVar6 + iVar2);
      iVar2 = asn1_template_ex_i2d_constprop_2(ppAVar3,param_2,pAVar6 + iVar2,param_4);
      return iVar2;
    }
    if (pcVar7 == (code *)0x0) {
      return 0;
    }
    (*pcVar7)(7,param_1,param_3,0);
    return 0;
  case '\x03':
    iVar2 = (**(code **)(pcVar5 + 0xc))(*param_1,param_2);
    return iVar2;
  case '\x04':
    iVar2 = (**(code **)(pcVar5 + 0x14))(param_1,param_2,param_3,0xffffffff,param_4);
    return iVar2;
  case '\x06':
    if ((param_4 & 0x800) == 0) {
      local_34 = 1;
    }
    else {
      local_34 = 2;
    }
    break;
  default:
    goto LAB_000b9de8;
  }
  iVar2 = asn1_enc_restore(local_2c,param_2,param_1,param_3);
  if (-1 < iVar2) {
    if (iVar2 != 0) {
      return local_2c[0];
    }
    local_2c[0] = iVar2;
    if ((pcVar7 == (code *)0x0) || (iVar2 = (*pcVar7)(6,param_1,param_3,0), iVar2 != 0)) {
      param_4 = param_4 & 0xffffff3f;
      pAVar6 = param_3->templates;
      if (0 < param_3->tcount) {
        iVar2 = 0;
        do {
          iVar2 = iVar2 + 1;
          pAVar4 = asn1_do_adb(param_1,pAVar6,1);
          if (pAVar4 == (ASN1_TEMPLATE *)0x0) {
            return 0;
          }
          pAVar6 = pAVar6 + 1;
          ppAVar3 = asn1_get_field_ptr(param_1,pAVar4);
          iVar1 = asn1_template_ex_i2d_constprop_2(ppAVar3,0,pAVar4,param_4);
          local_2c[0] = iVar1 + local_2c[0];
        } while (iVar2 < param_3->tcount);
      }
      iVar2 = ASN1_object_size(local_34,local_2c[0],0x10);
      if (param_2 == (uchar **)0x0) {
        return iVar2;
      }
      ASN1_put_object(param_2,local_34,local_2c[0],0x10,param_4);
      pAVar6 = param_3->templates;
      iVar1 = 0;
      if (0 < param_3->tcount) {
        do {
          iVar1 = iVar1 + 1;
          pAVar4 = asn1_do_adb(param_1,pAVar6,1);
          if (pAVar4 == (ASN1_TEMPLATE *)0x0) {
            return 0;
          }
          pAVar6 = pAVar6 + 1;
          ppAVar3 = asn1_get_field_ptr(param_1,pAVar4);
          asn1_template_ex_i2d_constprop_2(ppAVar3,param_2,pAVar4,param_4);
        } while (iVar1 < param_3->tcount);
      }
      if (local_34 == 2) {
        ASN1_put_eoc(param_2);
      }
      if (pcVar7 == (code *)0x0) {
        return iVar2;
      }
      iVar1 = (*pcVar7)(7,param_1,param_3,0);
      if (iVar1 != 0) {
        return iVar2;
      }
    }
  }
LAB_000b9de8:
  return 0;
}

