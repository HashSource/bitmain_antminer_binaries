
int ASN1_item_ex_i2d(ASN1_VALUE **pval,uchar **out,ASN1_ITEM *it,int tag,int aclass)

{
  ASN1_VALUE **ppAVar1;
  int iVar2;
  ASN1_TEMPLATE *pAVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  _STACK *p_Var7;
  byte *pbVar8;
  ASN1_TEMPLATE *pAVar9;
  uint uVar10;
  code *constructed;
  bool bVar11;
  int local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  void *local_2c [2];
  
  pcVar5 = (code *)it->funcs;
  if ((it->itype != '\0') && (*pval == (ASN1_VALUE *)0x0)) goto switchD_000ba10c_caseD_7;
  constructed = pcVar5;
  if (pcVar5 != (code *)0x0) {
    constructed = *(code **)(pcVar5 + 0x10);
  }
  switch(it->itype) {
  case '\0':
    pAVar9 = it->templates;
    if (pAVar9 == (ASN1_TEMPLATE *)0x0) {
      iVar6 = asn1_i2d_ex_primitive(pval,out,it,tag,aclass);
      return iVar6;
    }
    local_38 = pAVar9->flags;
    if ((local_38 & 0x18) == 0) {
      if (tag == -1) {
        local_40 = 0;
      }
      else {
        local_40 = aclass & 0xc0;
      }
    }
    else {
      if (tag != -1) {
        return -1;
      }
      local_40 = local_38 & 0xc0;
      tag = pAVar9->tag;
    }
    bVar11 = -1 < (int)(local_38 << 0x14);
    if (bVar11) {
      constructed = (code *)0x1;
    }
    uVar10 = aclass & 0xffffff3f;
    if (!bVar11) {
      if ((aclass & 0x800U) == 0) {
        constructed = (code *)0x1;
      }
      else {
        constructed = (code *)0x2;
      }
    }
    if ((local_38 & 6) == 0) {
      if (-1 < (int)(local_38 << 0x1b)) {
        iVar6 = ASN1_item_ex_i2d(pval,out,pAVar9->item,tag,local_40 | uVar10);
        return iVar6;
      }
      iVar2 = ASN1_item_ex_i2d_constprop_0(pval,pAVar9->item,uVar10);
      if (iVar2 == 0) {
        return 0;
      }
      iVar6 = ASN1_object_size((int)constructed,iVar2,tag);
      if (out == (uchar **)0x0) {
        return iVar6;
      }
      ASN1_put_object(out,(int)constructed,iVar2,tag,local_40);
      ASN1_item_ex_i2d_constprop_1(pval,out,pAVar9->item,uVar10);
      if (constructed != (code *)0x2) {
        return iVar6;
      }
    }
    else {
      p_Var7 = (_STACK *)*pval;
      if (p_Var7 == (_STACK *)0x0) goto switchD_000ba10c_caseD_7;
      if ((local_38 & 2) == 0) {
        local_3c = 0;
      }
      else if ((local_38 & 4) == 0) {
        local_3c = 1;
      }
      else {
        local_3c = 2;
      }
      if ((tag == -1) || ((local_38 & 0x10) != 0)) {
        local_34 = 0;
        if (local_3c == 0) {
          local_44 = 0x10;
        }
        else {
          local_44 = 0x11;
        }
      }
      else {
        local_34 = local_40;
        local_44 = tag;
      }
      local_38 = local_38 & 0x10;
      iVar2 = 0;
      iVar6 = 0;
      while( true ) {
        iVar4 = sk_num(p_Var7);
        if (iVar4 <= iVar6) break;
        local_2c[0] = sk_value(p_Var7,iVar6);
        iVar4 = ASN1_item_ex_i2d_constprop_0(local_2c,pAVar9->item,uVar10);
        iVar2 = iVar2 + iVar4;
        iVar6 = iVar6 + 1;
      }
      iVar4 = ASN1_object_size((int)constructed,iVar2,local_44);
      if (local_38 == 0) {
        iVar6 = iVar4;
        if (out == (uchar **)0x0) {
          return iVar4;
        }
      }
      else {
        iVar6 = ASN1_object_size((int)constructed,iVar4,tag);
        if (out == (uchar **)0x0) {
          return iVar6;
        }
        ASN1_put_object(out,(int)constructed,iVar4,tag,local_40);
      }
      ASN1_put_object(out,(int)constructed,iVar2,local_44,local_34);
      asn1_set_seq_out(p_Var7,out,iVar2,pAVar9->item,local_3c,uVar10);
      if (constructed != (code *)0x2) {
        return iVar6;
      }
      ASN1_put_eoc(out);
      if (local_38 == 0) {
        return iVar6;
      }
    }
    ASN1_put_eoc(out);
    break;
  case '\x01':
    local_40 = 1;
    goto LAB_000ba158;
  case '\x02':
    if ((constructed == (code *)0x0) || (iVar6 = (*constructed)(6,pval,it,0), iVar6 != 0)) {
      iVar6 = asn1_get_choice_selector(pval,it);
      if ((-1 < iVar6) && (iVar6 < it->tcount)) {
        pAVar9 = it->templates;
        ppAVar1 = asn1_get_field_ptr(pval,pAVar9 + iVar6);
        iVar6 = asn1_template_ex_i2d_constprop_2(ppAVar1,out,pAVar9 + iVar6,aclass);
        return iVar6;
      }
      if (constructed != (code *)0x0) {
        (*constructed)(7,pval,it,0);
        return 0;
      }
    }
  default:
switchD_000ba10c_caseD_7:
    iVar6 = 0;
    break;
  case '\x03':
    if (out == (uchar **)0x0) {
      iVar6 = (**(code **)(pcVar5 + 0xc))(*pval,0);
    }
    else {
      pbVar8 = *out;
      iVar6 = (**(code **)(pcVar5 + 0xc))();
      if (tag != -1) {
        *pbVar8 = (byte)aclass | *pbVar8 & 0x20 | (byte)tag;
      }
    }
    break;
  case '\x04':
    iVar6 = (**(code **)(pcVar5 + 0x14))(pval,out,it,tag,aclass);
    break;
  case '\x05':
    iVar6 = asn1_i2d_ex_primitive(pval,out,it,0xffffffff,aclass);
    break;
  case '\x06':
    if ((aclass & 0x800U) == 0) {
      local_40 = 1;
    }
    else {
      local_40 = 2;
    }
LAB_000ba158:
    iVar6 = asn1_enc_restore(&local_30,out,pval,it);
    if (-1 < iVar6) {
      if (iVar6 != 0) {
        return local_30;
      }
      if (tag == -1) {
        tag = 0x10;
        aclass = aclass & 0xffffff3f;
      }
      local_30 = iVar6;
      if ((constructed == (code *)0x0) || (iVar6 = (*constructed)(6,pval,it,0), iVar6 != 0)) {
        pAVar9 = it->templates;
        if (0 < it->tcount) {
          iVar6 = 0;
          do {
            iVar6 = iVar6 + 1;
            pAVar3 = asn1_do_adb(pval,pAVar9,1);
            if (pAVar3 == (ASN1_TEMPLATE *)0x0) goto switchD_000ba10c_caseD_7;
            ppAVar1 = asn1_get_field_ptr(pval,pAVar3);
            pAVar9 = pAVar9 + 1;
            iVar2 = asn1_template_ex_i2d_constprop_2(ppAVar1,0,pAVar3,aclass);
            local_30 = iVar2 + local_30;
          } while (iVar6 < it->tcount);
        }
        iVar6 = ASN1_object_size(local_40,local_30,tag);
        if (out == (uchar **)0x0) {
          return iVar6;
        }
        ASN1_put_object(out,local_40,local_30,tag,aclass);
        pAVar9 = it->templates;
        if (0 < it->tcount) {
          iVar2 = 0;
          do {
            iVar2 = iVar2 + 1;
            pAVar3 = asn1_do_adb(pval,pAVar9,1);
            if (pAVar3 == (ASN1_TEMPLATE *)0x0) goto switchD_000ba10c_caseD_7;
            ppAVar1 = asn1_get_field_ptr(pval,pAVar3);
            pAVar9 = pAVar9 + 1;
            asn1_template_ex_i2d_constprop_2(ppAVar1,out,pAVar3,aclass);
          } while (iVar2 < it->tcount);
        }
        if (local_40 == 2) {
          ASN1_put_eoc(out);
        }
        if (constructed == (code *)0x0) {
          return iVar6;
        }
        iVar2 = (*constructed)(7,pval,it,0);
        if (iVar2 != 0) {
          return iVar6;
        }
      }
    }
    goto switchD_000ba10c_caseD_7;
  }
  return iVar6;
}

