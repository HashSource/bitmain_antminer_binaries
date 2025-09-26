
/* WARNING: Type propagation algorithm not settling */

undefined1
asn1_item_print_ctx(BIO *param_1,int *param_2,int param_3,ASN1_ITEM *param_4,char *param_5,
                   char *param_6,int param_7,uint *param_8)

{
  ASN1_TEMPLATE *tt;
  ASN1_VALUE **ppAVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  ASN1_VALUE *pAVar6;
  ASN1_OBJECT *o;
  code *pcVar7;
  ASN1_TEMPLATE *pAVar8;
  ASN1_GENERALIZEDTIME *a;
  code *pcVar9;
  BIO *local_84;
  int local_80;
  uint *local_7c;
  char acStack_78 [84];
  
  pcVar7 = (code *)param_4->funcs;
  pcVar9 = pcVar7;
  if ((pcVar7 != (code *)0x0) && (pcVar9 = *(code **)(pcVar7 + 0x10), pcVar9 != (code *)0x0)) {
    local_7c = param_8;
    local_84 = param_1;
    local_80 = param_3;
  }
  if ((ASN1_VALUE *)*param_2 == (ASN1_VALUE *)0x0) {
    if (-1 < (int)(*param_8 << 0x1f)) {
      return 1;
    }
    if ((param_7 == 0) &&
       (iVar4 = asn1_print_fsname(param_1,param_3,param_5,param_6,param_8), iVar4 == 0)) {
      return 0;
    }
    iVar4 = BIO_puts(param_1,"<ABSENT>\n");
    return 0 < iVar4;
  }
  switch(param_4->itype) {
  case '\0':
    break;
  case '\x01':
  case '\x06':
    if ((param_7 == 0) &&
       (iVar4 = asn1_print_fsname(param_1,param_3,param_5,param_6,param_8), iVar4 == 0)) {
      return 0;
    }
    if (param_5 != (char *)0x0 || param_6 != (char *)0x0) {
      if ((int)(*param_8 << 0x1e) < 0) {
        iVar4 = BIO_puts(param_1," {\n");
      }
      else {
        iVar4 = BIO_puts(param_1,"\n");
      }
      if (iVar4 < 1) {
        return 0;
      }
    }
    if (pcVar9 != (code *)0x0) {
      iVar4 = (*pcVar9)(8,param_2,param_4,&local_84);
      if (iVar4 == 0) {
        return 0;
      }
      if (iVar4 == 2) {
        return 1;
      }
    }
    pAVar8 = param_4->templates;
    if (0 < param_4->tcount) {
      iVar4 = 0;
      do {
        iVar4 = iVar4 + 1;
        tt = asn1_do_adb((ASN1_VALUE **)param_2,pAVar8,1);
        if (tt == (ASN1_TEMPLATE *)0x0) {
          return 0;
        }
        ppAVar1 = asn1_get_field_ptr((ASN1_VALUE **)param_2,tt);
        iVar2 = asn1_template_print_ctx(param_1,ppAVar1,param_3 + 2,tt,param_8);
        if (iVar2 == 0) {
          return 0;
        }
        pAVar8 = pAVar8 + 1;
      } while (iVar4 < param_4->tcount);
    }
    if (((int)(*param_8 << 0x1e) < 0) &&
       (iVar4 = BIO_printf(param_1,"%*s}\n",param_3,""), iVar4 < 0)) {
      return 0;
    }
    if (pcVar9 == (code *)0x0) {
      return 1;
    }
    uVar3 = (*pcVar9)(9,param_2,param_4,&local_84);
    if (uVar3 != 0) {
      return 1;
    }
    return 0;
  case '\x02':
    iVar4 = asn1_get_choice_selector((ASN1_VALUE **)param_2,param_4);
    if ((-1 < iVar4) && (iVar4 < param_4->tcount)) {
      pAVar8 = param_4->templates;
      ppAVar1 = asn1_get_field_ptr((ASN1_VALUE **)param_2,pAVar8 + iVar4);
      uVar3 = asn1_template_print_ctx(param_1,ppAVar1,param_3,pAVar8 + iVar4,param_8);
      if (uVar3 != 0) {
        return 1;
      }
      return 0;
    }
    iVar4 = BIO_printf(param_1,"ERROR: selector [%d] invalid\n");
    return 0 < iVar4;
  default:
    BIO_printf(param_1,"Unprocessed type %d\n");
    return 0;
  case '\x04':
    if (param_7 == 0) {
      iVar4 = asn1_print_fsname(param_1,param_3,param_5,param_6,param_8);
      if (iVar4 == 0) {
        return 0;
      }
      pcVar7 = (code *)param_4->funcs;
    }
    if ((pcVar7 == (code *)0x0) || (*(code **)(pcVar7 + 0x18) == (code *)0x0)) {
      if (param_6 == (char *)0x0) {
        return 1;
      }
      iVar4 = BIO_printf(param_1,":EXTERNAL TYPE %s\n",param_6);
      return 0 < iVar4;
    }
    iVar4 = (**(code **)(pcVar7 + 0x18))(param_1,param_2,param_3,"",param_8);
    if (iVar4 == 0) {
      return 0;
    }
    if (iVar4 != 2) {
      return 1;
    }
    iVar4 = BIO_puts(param_1,"\n");
    return 0 < iVar4;
  case '\x05':
    goto switchD_001a2f2a_caseD_5;
  }
  if (param_4->templates != (ASN1_TEMPLATE *)0x0) {
    uVar3 = asn1_template_print_ctx(param_1,param_2,param_3,param_4->templates,param_8);
    if (uVar3 != 0) {
      return 1;
    }
    return 0;
  }
switchD_001a2f2a_caseD_5:
  iVar4 = param_3;
  if (0x14 < param_3) {
    do {
      iVar4 = iVar4 + -0x14;
      iVar2 = BIO_write(param_1,spaces_16322,0x14);
      if (iVar2 != 0x14) {
        return 0;
      }
    } while (0x14 < iVar4);
  }
  iVar2 = BIO_write(param_1,spaces_16322,iVar4);
  if (iVar4 != iVar2) {
    return 0;
  }
  uVar3 = *param_8;
  if ((int)(uVar3 << 0x17) < 0) {
    if ((uVar3 & 0x40) == 0) {
      param_6 = (char *)0x0;
      goto LAB_001a30ec;
    }
  }
  else {
    if ((int)(uVar3 << 0x19) < 0) {
      if (param_6 == (char *)0x0) goto LAB_001a3130;
LAB_001a3398:
      iVar4 = BIO_puts(param_1,param_6);
joined_r0x001a311c:
      if (iVar4 < 1) {
        return 0;
      }
    }
    else {
LAB_001a30ec:
      if (param_6 == (char *)0x0 && param_5 == (char *)0x0) goto LAB_001a3130;
      if (param_5 == (char *)0x0) {
        if (param_6 != (char *)0x0) goto LAB_001a3398;
      }
      else {
        iVar4 = BIO_puts(param_1,param_5);
        if (iVar4 < 1) {
          return 0;
        }
        if (param_6 != (char *)0x0) {
          iVar4 = BIO_printf(param_1," (%s)",param_6);
          goto joined_r0x001a311c;
        }
      }
    }
    iVar4 = BIO_write(param_1,": ",2);
    if (iVar4 != 2) {
      return 0;
    }
  }
LAB_001a3130:
  if ((pcVar7 != (code *)0x0) && (*(code **)(pcVar7 + 0x1c) != (code *)0x0)) {
    iVar4 = (**(code **)(pcVar7 + 0x1c))(param_1,param_2,param_4,param_3,param_8);
    if (iVar4 == 0) {
      return 0;
    }
    return 1;
  }
  a = (ASN1_GENERALIZEDTIME *)*param_2;
  if (param_4->itype == '\x05') {
    uVar3 = a->type & 0xfffffeff;
  }
  else {
    uVar3 = param_4->utype;
  }
  if (uVar3 == 0xfffffffc) {
    param_2 = &a->type;
    uVar3 = a->length;
    a = (ASN1_GENERALIZEDTIME *)a->type;
    if (-1 < (int)(*param_8 << 0x1b)) goto LAB_001a33b8;
LAB_001a31fe:
    if (uVar3 != 5) {
LAB_001a3206:
      switch(uVar3) {
      case 1:
        pAVar6 = (ASN1_VALUE *)*param_2;
        if (pAVar6 == (ASN1_VALUE *)0xffffffff) {
          pAVar6 = (ASN1_VALUE *)param_4->size;
        }
        if (pAVar6 + 1 < (ASN1_VALUE *)0x2) {
          pcVar5 = *(char **)(&CSWTCH_4 + (int)(pAVar6 + 1) * 4);
        }
        else {
          pcVar5 = "TRUE";
        }
        iVar4 = BIO_puts(param_1,pcVar5);
        uVar3 = (uint)(0 < iVar4);
        break;
      case 2:
      case 10:
        pcVar5 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,a);
        iVar4 = BIO_puts(param_1,pcVar5);
        uVar3 = (uint)(0 < iVar4);
        CRYPTO_free(pcVar5);
        break;
      case 3:
      case 4:
        if (a->type == 3) {
          iVar4 = BIO_printf(param_1," (%ld unused bits)\n",a->flags & 7);
        }
        else {
          iVar4 = BIO_puts(param_1,"\n");
        }
        if (iVar4 < 1) {
          return 0;
        }
        if (a->length < 1) {
          return 1;
        }
        iVar4 = BIO_dump_indent(param_1,a->data,a->length,param_3 + 2);
        if (0 < iVar4) {
          return 1;
        }
        return 0;
      case 6:
        o = (ASN1_OBJECT *)*param_2;
        iVar4 = OBJ_obj2nid(o);
        pcVar5 = OBJ_nid2ln(iVar4);
        if (pcVar5 == (char *)0x0) {
          pcVar5 = "";
        }
        OBJ_obj2txt(acStack_78,0x50,o,1);
        iVar4 = BIO_printf(param_1,"%s (%s)",pcVar5,acStack_78);
        uVar3 = (uint)(0 < iVar4);
        break;
      case 0x17:
        uVar3 = ASN1_UTCTIME_print(param_1,a);
        break;
      case 0x18:
        uVar3 = ASN1_GENERALIZEDTIME_print(param_1,a);
        break;
      case 0xfffffffd:
      case 0x10:
      case 0x11:
        iVar4 = BIO_puts(param_1,"\n");
        if (iVar4 < 1) {
          return 0;
        }
        iVar4 = ASN1_parse_dump(param_1,a->data,a->length,param_3,0);
        goto joined_r0x001a324c;
      default:
        uVar3 = ASN1_STRING_print_ex(param_1,a,param_8[4]);
      }
      if (uVar3 == 0) {
        return 0;
      }
      iVar4 = BIO_puts(param_1,"\n");
      goto joined_r0x001a324c;
    }
  }
  else {
    if (-1 < (int)(*param_8 << 0x1c)) goto LAB_001a31fe;
LAB_001a33b8:
    pcVar5 = ASN1_tag2str(uVar3);
    if (uVar3 != 5) {
      if (pcVar5 != (char *)0x0) {
        iVar4 = BIO_puts(param_1,pcVar5);
        if (iVar4 < 1) {
          return 0;
        }
        iVar4 = BIO_puts(param_1,":");
        if (iVar4 < 1) {
          return 0;
        }
      }
      goto LAB_001a3206;
    }
  }
  iVar4 = BIO_puts(param_1,"NULL\n");
joined_r0x001a324c:
  if (iVar4 < 1) {
    return 0;
  }
  return 1;
}

