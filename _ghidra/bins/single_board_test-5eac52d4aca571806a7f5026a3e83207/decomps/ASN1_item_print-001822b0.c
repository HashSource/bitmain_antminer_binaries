
/* WARNING: Type propagation algorithm not settling */

int ASN1_item_print(BIO *out,ASN1_VALUE *ifld,int indent,ASN1_ITEM *it,ASN1_PCTX *pctx)

{
  int iVar1;
  ASN1_VALUE **ppAVar2;
  int iVar3;
  ASN1_TEMPLATE *tt;
  ASN1_OBJECT *o;
  code *pcVar4;
  uint uVar5;
  code *pcVar6;
  ASN1_TEMPLATE *pAVar7;
  ASN1_GENERALIZEDTIME *a;
  char *pcVar8;
  int *piVar9;
  ASN1_GENERALIZEDTIME *local_8c [2];
  BIO *local_84;
  int local_80;
  ASN1_PCTX *local_7c;
  char acStack_78 [84];
  
  if (pctx == (ASN1_PCTX *)0x0) {
    pctx = (ASN1_PCTX *)&default_pctx;
  }
  pcVar6 = (code *)it->funcs;
  if (*(int *)pctx << 0x17 < 0) {
    pcVar8 = (char *)0x0;
  }
  else {
    pcVar8 = it->sname;
  }
  pcVar4 = pcVar6;
  if ((pcVar6 != (code *)0x0) && (pcVar4 = *(code **)(pcVar6 + 0x10), pcVar4 != (code *)0x0)) {
    local_84 = out;
    local_80 = indent;
    local_7c = pctx;
  }
  local_8c[0] = (ASN1_GENERALIZEDTIME *)ifld;
  if (it->itype != '\0') {
    if (ifld != (ASN1_VALUE *)0x0) {
      switch(it->itype) {
      case '\x01':
      case '\x06':
        iVar1 = asn1_print_fsname_isra_0(out,indent,0,pcVar8,pctx);
        if (iVar1 == 0) {
          return 0;
        }
        if (pcVar8 != (char *)0x0) {
          if (*(int *)pctx << 0x1e < 0) {
            iVar1 = BIO_puts(out," {\n");
          }
          else {
            iVar1 = BIO_puts(out,"\n");
          }
          if (iVar1 < 1) {
            return 0;
          }
        }
        if (pcVar4 != (code *)0x0) {
          iVar1 = (*pcVar4)(8,local_8c,it,&local_84);
          if (iVar1 == 0) {
            return 0;
          }
          if (iVar1 == 2) {
            return 1;
          }
        }
        pAVar7 = it->templates;
        if (0 < it->tcount) {
          iVar1 = 0;
          do {
            iVar1 = iVar1 + 1;
            tt = asn1_do_adb((ASN1_VALUE **)local_8c,pAVar7,1);
            pAVar7 = pAVar7 + 1;
            if (tt == (ASN1_TEMPLATE *)0x0) {
              return 0;
            }
            ppAVar2 = asn1_get_field_ptr((ASN1_VALUE **)local_8c,tt);
            iVar3 = asn1_template_print_ctx(out,ppAVar2,indent + 2,tt,pctx);
            if (iVar3 == 0) {
              return 0;
            }
          } while (iVar1 < it->tcount);
        }
        if ((*(int *)pctx << 0x1e < 0) && (iVar1 = BIO_printf(out,"%*s}\n",indent,""), iVar1 < 0)) {
          return 0;
        }
        if (pcVar4 == (code *)0x0) {
          return 1;
        }
        iVar1 = (*pcVar4)(9,local_8c,it,&local_84);
        if (iVar1 == 0) {
          return 0;
        }
        return 1;
      case '\x02':
        iVar1 = asn1_get_choice_selector((ASN1_VALUE **)local_8c,it);
        if ((-1 < iVar1) && (iVar1 < it->tcount)) {
          pAVar7 = it->templates;
          ppAVar2 = asn1_get_field_ptr((ASN1_VALUE **)local_8c,pAVar7 + iVar1);
          iVar1 = asn1_template_print_ctx(out,ppAVar2,indent,pAVar7 + iVar1,pctx);
          if (iVar1 == 0) {
            return 0;
          }
          return 1;
        }
        iVar1 = BIO_printf(out,"ERROR: selector [%d] invalid\n");
        return (uint)(0 < iVar1);
      default:
        BIO_printf(out,"Unprocessed type %d\n");
        return 0;
      case '\x04':
        iVar1 = asn1_print_fsname_isra_0(out,indent,0,pcVar8,pctx);
        if (iVar1 == 0) {
          return 0;
        }
        if ((it->funcs == (void *)0x0) ||
           (pcVar6 = *(code **)((int)it->funcs + 0x18), pcVar6 == (code *)0x0)) {
          if (pcVar8 == (char *)0x0) {
            return 1;
          }
          iVar1 = BIO_printf(out,":EXTERNAL TYPE %s\n",pcVar8);
          return (uint)(0 < iVar1);
        }
        iVar1 = (*pcVar6)(out,local_8c,indent,"",pctx);
        if (iVar1 == 0) {
          return 0;
        }
        if (iVar1 != 2) {
          return 1;
        }
        iVar1 = BIO_puts(out,"\n");
        return (uint)(0 < iVar1);
      case '\x05':
        goto switchD_0018233c_caseD_5;
      }
    }
LAB_001822fe:
    if (-1 < *(int *)pctx << 0x1f) {
      return 1;
    }
    iVar1 = asn1_print_fsname_isra_0(out,indent,0,pcVar8,pctx);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = BIO_puts(out,"<ABSENT>\n");
    return (uint)(0 < iVar1);
  }
  if ((it->utype != 1) && (ifld == (ASN1_VALUE *)0x0)) goto LAB_001822fe;
  if (it->templates != (ASN1_TEMPLATE *)0x0) {
    iVar1 = asn1_template_print_ctx(out,local_8c,indent,it->templates,pctx);
    if (iVar1 == 0) {
      return 0;
    }
    return 1;
  }
switchD_0018233c_caseD_5:
  iVar1 = asn1_print_fsname_isra_0(out,indent,0,pcVar8,pctx);
  if (iVar1 == 0) {
    return 0;
  }
  if ((pcVar6 != (code *)0x0) && (*(code **)(pcVar6 + 0x1c) != (code *)0x0)) {
    iVar1 = (**(code **)(pcVar6 + 0x1c))(out,local_8c,it,indent,pctx);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  if (it->itype != '\x05') {
    uVar5 = it->utype;
    if (uVar5 != 1) goto LAB_00182528;
    if (*(int *)pctx << 0x1c < 0) {
      a = (ASN1_GENERALIZEDTIME *)0x0;
      goto LAB_0018278a;
    }
    piVar9 = (int *)local_8c;
switchD_001825f2_caseD_1:
    iVar1 = *piVar9;
    if (iVar1 == -1) {
      iVar1 = it->size;
      pcVar8 = "BOOL ABSENT";
      if (iVar1 != -1) goto LAB_001827ac;
    }
    else {
LAB_001827ac:
      if (iVar1 == 0) {
        pcVar8 = "FALSE";
      }
      else {
        pcVar8 = "TRUE";
      }
    }
    iVar1 = BIO_puts(out,pcVar8);
    if (iVar1 < 1) {
      return 0;
    }
    goto LAB_00182674;
  }
  uVar5 = local_8c[0]->type & 0xfffffeff;
LAB_00182528:
  if (uVar5 == 0xfffffffc) {
    piVar9 = &local_8c[0]->type;
    uVar5 = local_8c[0]->length;
    a = (ASN1_GENERALIZEDTIME *)local_8c[0]->type;
    if (-1 < *(int *)pctx << 0x1b) {
      pcVar8 = ASN1_tag2str(uVar5);
      goto LAB_001825ba;
    }
LAB_0018253c:
    if (uVar5 != 5) goto LAB_001825de;
LAB_00182542:
    iVar1 = BIO_puts(out,"NULL\n");
    goto joined_r0x00182724;
  }
  a = local_8c[0];
  if (-1 < *(int *)pctx << 0x1c) {
    piVar9 = (int *)local_8c;
    goto LAB_0018253c;
  }
LAB_0018278a:
  piVar9 = (int *)local_8c;
  pcVar8 = ASN1_tag2str(uVar5);
LAB_001825ba:
  if (uVar5 == 5) goto LAB_00182542;
  if (pcVar8 != (char *)0x0) {
    iVar1 = BIO_puts(out,pcVar8);
    if (iVar1 < 1) {
      return 0;
    }
    iVar1 = BIO_puts(out,":");
    if (iVar1 < 1) {
      return 0;
    }
  }
LAB_001825de:
  switch(uVar5) {
  case 1:
    goto switchD_001825f2_caseD_1;
  case 2:
  case 10:
    pcVar8 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,a);
    if (pcVar8 == (char *)0x0) {
      return 0;
    }
    iVar1 = BIO_puts(out,pcVar8);
    uVar5 = (uint)(0 < iVar1);
    CRYPTO_free(pcVar8);
    break;
  case 3:
  case 4:
    if (a->type == 3) {
      iVar1 = BIO_printf(out," (%ld unused bits)\n",a->flags & 7);
    }
    else {
      iVar1 = BIO_puts(out,"\n");
    }
    if (iVar1 < 1) {
      return 0;
    }
    if (a->length < 1) {
      return 1;
    }
    iVar1 = BIO_dump_indent(out,(char *)a->data,a->length,indent + 2);
    goto joined_r0x00182724;
  case 6:
    o = (ASN1_OBJECT *)*piVar9;
    iVar1 = OBJ_obj2nid(o);
    pcVar8 = OBJ_nid2ln(iVar1);
    if (pcVar8 == (char *)0x0) {
      pcVar8 = "";
    }
    OBJ_obj2txt(acStack_78,0x50,o,1);
    iVar1 = BIO_printf(out,"%s (%s)",pcVar8,acStack_78);
    uVar5 = (uint)(0 < iVar1);
    break;
  case 0x17:
    uVar5 = ASN1_UTCTIME_print(out,a);
    break;
  case 0x18:
    uVar5 = ASN1_GENERALIZEDTIME_print(out,a);
    break;
  case 0xfffffffd:
  case 0x10:
  case 0x11:
    iVar1 = BIO_puts(out,"\n");
    if (iVar1 < 1) {
      return 0;
    }
    iVar1 = ASN1_parse_dump(out,a->data,a->length,indent,0);
    goto joined_r0x00182724;
  default:
    uVar5 = ASN1_STRING_print_ex(out,a,*(ulong *)(pctx + 0x10));
  }
  if (uVar5 != 0) {
LAB_00182674:
    iVar1 = BIO_puts(out,"\n");
joined_r0x00182724:
    if (0 < iVar1) {
      return 1;
    }
  }
  return 0;
}

