
int ASN1_item_ex_i2d(ASN1_VALUE **pval,uchar **out,ASN1_ITEM *it,int tag,int aclass)

{
  int iVar1;
  ASN1_VALUE **ppAVar2;
  int iVar3;
  ASN1_TEMPLATE *pAVar4;
  code *pcVar5;
  int iVar6;
  ASN1_TEMPLATE *pAVar7;
  code *pcVar8;
  int local_38;
  int local_2c [2];
  
  pcVar5 = (code *)it->funcs;
  if (it->itype != '\0') {
    if (*pval == (ASN1_VALUE *)0x0) {
      return 0;
    }
    pcVar8 = pcVar5;
    if (pcVar5 != (code *)0x0) {
LAB_00104946:
      pcVar8 = *(code **)(pcVar5 + 0x10);
    }
    switch(it->itype) {
    case '\0':
      goto switchD_0010494e_caseD_0;
    case '\x01':
      local_38 = 1;
      break;
    case '\x02':
      if (tag == -1) {
        if (pcVar8 == (code *)0x0) {
          iVar1 = asn1_get_choice_selector(pval,it);
          if (iVar1 < 0) {
            return 0;
          }
          if (it->tcount <= iVar1) {
            return 0;
          }
        }
        else {
          iVar1 = (*pcVar8)(6,pval,it,0);
          if (iVar1 == 0) {
            return 0;
          }
          iVar1 = asn1_get_choice_selector(pval,it);
          if ((iVar1 < 0) || (it->tcount <= iVar1)) {
            (*pcVar8)(7,pval,it,0);
            return 0;
          }
        }
        pAVar7 = it->templates;
        ppAVar2 = asn1_get_field_ptr(pval,pAVar7 + iVar1);
        iVar1 = asn1_template_ex_i2d(ppAVar2,out,pAVar7 + iVar1,0xffffffff,aclass);
        return iVar1;
      }
      iVar1 = 0x7a;
LAB_00104ae6:
      ERR_put_error(0xd,0x90,0xe6,"crypto/asn1/tasn_enc.c",iVar1);
      return -1;
    default:
      goto LAB_001049b4;
    case '\x04':
      iVar1 = (**(code **)(pcVar5 + 0x14))(pval,out,it,tag,aclass);
      return iVar1;
    case '\x05':
      if (tag != -1) {
        iVar1 = 0x6f;
        goto LAB_00104ae6;
      }
      goto LAB_001049e6;
    case '\x06':
      if ((aclass & 0x800U) == 0) {
        local_38 = 1;
      }
      else {
        local_38 = 2;
      }
    }
    iVar1 = asn1_enc_restore(local_2c,out,pval,it);
    if (-1 < iVar1) {
      if (iVar1 != 0) {
        return local_2c[0];
      }
      if (tag == -1) {
        tag = 0x10;
        aclass = aclass & 0xffffff3f;
      }
      local_2c[0] = iVar1;
      if ((pcVar8 == (code *)0x0) || (iVar1 = (*pcVar8)(6,pval,it,0), iVar1 != 0)) {
        pAVar7 = it->templates;
        if (0 < it->tcount) {
          iVar1 = 0;
          do {
            iVar1 = iVar1 + 1;
            pAVar4 = asn1_do_adb(pval,pAVar7,1);
            pAVar7 = pAVar7 + 1;
            if (pAVar4 == (ASN1_TEMPLATE *)0x0) {
              return 0;
            }
            ppAVar2 = asn1_get_field_ptr(pval,pAVar4);
            iVar3 = asn1_template_ex_i2d(ppAVar2,0,pAVar4,0xffffffff,aclass);
            if (iVar3 == -1) {
              return -1;
            }
            iVar6 = 0x7fffffff - local_2c[0];
            local_2c[0] = local_2c[0] + iVar3;
            if (iVar6 < iVar3) {
              return -1;
            }
          } while (iVar1 < it->tcount);
        }
        iVar1 = ASN1_object_size(local_38,local_2c[0],tag);
        if (iVar1 == -1 || out == (uchar **)0x0) {
          return iVar1;
        }
        ASN1_put_object(out,local_38,local_2c[0],tag,aclass);
        pAVar7 = it->templates;
        if (0 < it->tcount) {
          iVar3 = 0;
          do {
            iVar3 = iVar3 + 1;
            pAVar4 = asn1_do_adb(pval,pAVar7,1);
            pAVar7 = pAVar7 + 1;
            if (pAVar4 == (ASN1_TEMPLATE *)0x0) {
              return 0;
            }
            ppAVar2 = asn1_get_field_ptr(pval,pAVar4);
            asn1_template_ex_i2d(ppAVar2,out,pAVar4,0xffffffff,aclass);
          } while (iVar3 < it->tcount);
        }
        if (local_38 == 2) {
          ASN1_put_eoc(out);
        }
        if (pcVar8 == (code *)0x0) {
          return iVar1;
        }
        iVar3 = (*pcVar8)(7,pval,it,0);
        if (iVar3 != 0) {
          return iVar1;
        }
      }
    }
LAB_001049b4:
    return 0;
  }
  if (pcVar5 != (code *)0x0) goto LAB_00104946;
switchD_0010494e_caseD_0:
  if (it->templates != (ASN1_TEMPLATE *)0x0) {
    iVar1 = asn1_template_ex_i2d(pval,out);
    return iVar1;
  }
LAB_001049e6:
  iVar1 = asn1_i2d_ex_primitive(pval,out,it,tag,aclass);
  return iVar1;
}

