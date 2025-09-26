
/* WARNING: Type propagation algorithm not settling */

undefined1
asn1_template_print_ctx(BIO *param_1,int *param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  ASN1_VALUE **ppAVar3;
  int iVar4;
  ASN1_TEMPLATE *pAVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  ASN1_ITEM *pAVar9;
  int iVar10;
  uint uVar11;
  ASN1_GENERALIZEDTIME *a;
  uint uVar12;
  void *pvVar13;
  ASN1_TEMPLATE *pAVar14;
  int *piVar15;
  code *pcVar16;
  ASN1_OBJECT *pAVar17;
  ASN1_UTCTIME *a_00;
  ASN1_VALUE *pAVar18;
  bool bVar19;
  code *local_b4;
  code *local_a8;
  char *local_94;
  int *local_8c;
  ASN1_UTCTIME *local_88;
  BIO *local_84;
  int local_80;
  uint *local_7c;
  char acStack_78 [84];
  
  uVar6 = *param_4;
  uVar7 = *param_5;
  uVar11 = uVar7 & 0x80;
  if (uVar11 != 0) {
    uVar11 = *(uint *)(param_4[4] + 0x18);
  }
  if ((int)(uVar7 << 0x19) < 0) {
    uVar12 = 0;
  }
  else {
    uVar12 = param_4[3];
  }
  bVar19 = (int)(uVar6 << 0x13) < 0;
  if (bVar19) {
    local_8c = param_2;
  }
  if (bVar19) {
    param_2 = (int *)&local_8c;
  }
  if ((uVar6 & 6) != 0) {
    if (uVar12 != 0) {
      if ((int)(uVar7 << 0x1d) < 0) {
        if ((int)(uVar6 << 0x1e) < 0) {
          pcVar8 = "SET";
        }
        else {
          pcVar8 = "SEQUENCE";
        }
        iVar1 = BIO_printf(param_1,"%*s%s OF %s {\n",param_3,"",pcVar8,param_4[3]);
      }
      else {
        iVar1 = BIO_printf(param_1,"%*s%s:\n",param_3,"",uVar12);
      }
      if (iVar1 < 1) {
        return 0;
      }
    }
    pAVar18 = (ASN1_VALUE *)*param_2;
    iVar10 = 0;
    local_94 = "FALSE";
    iVar1 = OPENSSL_sk_num(pAVar18);
    if (0 < iVar1) {
      do {
        if ((0 < iVar10) && (iVar1 = BIO_puts(param_1,"\n"), iVar1 < 1)) {
          return 0;
        }
        local_88 = (ASN1_UTCTIME *)OPENSSL_sk_value(pAVar18,iVar10);
        pAVar9 = (ASN1_ITEM *)param_4[4];
        pvVar13 = pAVar9->funcs;
        iVar1 = param_3 + 2;
        if (pvVar13 == (void *)0x0) {
          local_a8 = (code *)0x0;
        }
        else {
          local_a8 = *(code **)((int)pvVar13 + 0x10);
          if (local_a8 != (code *)0x0) {
            local_7c = param_5;
            local_84 = param_1;
            local_80 = iVar1;
          }
        }
        if (pAVar9->itype != '\0') {
          if (local_88 == (ASN1_UTCTIME *)0x0) goto LAB_0018f56a;
          switch(pAVar9->itype) {
          case '\x01':
          case '\x06':
            if (local_a8 != (code *)0x0) {
              iVar2 = (*local_a8)(8,&local_88,pAVar9,&local_84);
              if (iVar2 == 0) {
                return 0;
              }
              if (iVar2 == 2) break;
            }
            pAVar14 = pAVar9->templates;
            if (0 < pAVar9->tcount) {
              iVar2 = 0;
              do {
                iVar2 = iVar2 + 1;
                pAVar5 = asn1_do_adb((ASN1_VALUE **)&local_88,pAVar14,1);
                pAVar14 = pAVar14 + 1;
                if (pAVar5 == (ASN1_TEMPLATE *)0x0) {
                  return 0;
                }
                ppAVar3 = asn1_get_field_ptr((ASN1_VALUE **)&local_88,pAVar5);
                iVar4 = asn1_template_print_ctx(param_1,ppAVar3,param_3 + 4,pAVar5,param_5);
                if (iVar4 == 0) {
                  return 0;
                }
              } while (iVar2 < pAVar9->tcount);
            }
            if (((int)(*param_5 << 0x1e) < 0) &&
               (iVar1 = BIO_printf(param_1,"%*s}\n",iVar1,""), iVar1 < 0)) {
              return 0;
            }
            if (local_a8 != (code *)0x0) {
              iVar1 = (*local_a8)(9,&local_88,pAVar9,&local_84);
              goto joined_r0x0018f830;
            }
            break;
          case '\x02':
            iVar2 = asn1_get_choice_selector((ASN1_VALUE **)&local_88,pAVar9);
            if ((-1 < iVar2) && (iVar2 < pAVar9->tcount)) {
              pAVar14 = pAVar9->templates;
              ppAVar3 = asn1_get_field_ptr((ASN1_VALUE **)&local_88,pAVar14 + iVar2);
              iVar1 = asn1_template_print_ctx(param_1,ppAVar3,iVar1,pAVar14 + iVar2,param_5);
              goto joined_r0x0018f830;
            }
            iVar1 = BIO_printf(param_1,"ERROR: selector [%d] invalid\n");
            goto joined_r0x0018f682;
          default:
            BIO_printf(param_1,"Unprocessed type %d\n");
            return 0;
          case '\x04':
            if ((pvVar13 != (void *)0x0) && (*(code **)((int)pvVar13 + 0x18) != (code *)0x0)) {
              iVar1 = (**(code **)((int)pvVar13 + 0x18))(param_1,&local_88,iVar1,"",param_5);
              if (iVar1 == 0) {
                return 0;
              }
              if (iVar1 == 2) {
                iVar1 = BIO_puts(param_1,"\n");
                goto joined_r0x0018f682;
              }
            }
            break;
          case '\x05':
            goto switchD_0018f5fa_caseD_5;
          }
          goto LAB_0018f584;
        }
        if ((pAVar9->utype != 1) && (local_88 == (ASN1_UTCTIME *)0x0)) {
LAB_0018f56a:
          if (-1 < (int)(*param_5 << 0x1f)) goto LAB_0018f584;
          iVar1 = BIO_puts(param_1,"<ABSENT>\n");
          goto joined_r0x0018f580;
        }
        if (pAVar9->templates != (ASN1_TEMPLATE *)0x0) {
          iVar1 = asn1_template_print_ctx(param_1,&local_88,iVar1,pAVar9->templates,param_5);
joined_r0x0018f830:
          if (iVar1 == 0) {
            return 0;
          }
          goto LAB_0018f584;
        }
switchD_0018f5fa_caseD_5:
        iVar2 = asn1_print_fsname_isra_0(param_1,iVar1,0,0,param_5);
        a_00 = local_88;
        if (iVar2 == 0) {
          return 0;
        }
        if ((pvVar13 != (void *)0x0) && (*(code **)((int)pvVar13 + 0x1c) != (code *)0x0)) {
          iVar1 = (**(code **)((int)pvVar13 + 0x1c))(param_1,&local_88,pAVar9,iVar1,param_5);
          goto joined_r0x0018f830;
        }
        if (pAVar9->itype != '\x05') {
          uVar6 = pAVar9->utype;
          if (uVar6 != 1) goto LAB_0018f768;
          if (((int)(*param_5 << 0x1c) < 0) && (pcVar8 = ASN1_tag2str(1), pcVar8 != (char *)0x0)) {
            iVar1 = BIO_puts(param_1,pcVar8);
            if (iVar1 < 1) {
              return 0;
            }
            iVar1 = BIO_puts(param_1,":");
            if (iVar1 < 1) {
              return 0;
            }
          }
          piVar15 = (int *)&local_88;
switchD_0018f8e6_caseD_1:
          iVar1 = *piVar15;
          if (iVar1 == -1) {
            iVar1 = pAVar9->size;
            pcVar8 = "BOOL ABSENT";
            if (iVar1 != -1) goto LAB_0018f9d6;
          }
          else {
LAB_0018f9d6:
            pcVar8 = local_94;
            if (iVar1 != 0) {
              pcVar8 = "TRUE";
            }
          }
          iVar1 = BIO_puts(param_1,pcVar8);
          goto joined_r0x0018fbe4;
        }
        uVar6 = local_88->type & 0xfffffeff;
LAB_0018f768:
        if (uVar6 == 0xfffffffc) {
          piVar15 = &local_88->type;
          uVar6 = local_88->length;
          a_00 = (ASN1_UTCTIME *)local_88->type;
          if ((int)(*param_5 << 0x1b) < 0) goto LAB_0018f77e;
          pcVar8 = ASN1_tag2str(uVar6);
LAB_0018f8b2:
          if (uVar6 == 5) goto LAB_0018f786;
          if (pcVar8 != (char *)0x0) {
            iVar2 = BIO_puts(param_1,pcVar8);
            if (iVar2 < 1) {
              return 0;
            }
            iVar2 = BIO_puts(param_1,":");
            if (iVar2 < 1) {
              return 0;
            }
          }
        }
        else {
          piVar15 = (int *)&local_88;
          if ((int)(*param_5 << 0x1c) < 0) {
            piVar15 = (int *)&local_88;
            pcVar8 = ASN1_tag2str(uVar6);
            goto LAB_0018f8b2;
          }
LAB_0018f77e:
          if (uVar6 == 5) {
LAB_0018f786:
            iVar1 = BIO_puts(param_1,"NULL\n");
            goto joined_r0x0018f580;
          }
        }
        switch(uVar6) {
        case 1:
          goto switchD_0018f8e6_caseD_1;
        case 2:
        case 10:
          pcVar8 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,a_00);
          if (pcVar8 == (char *)0x0) {
            return 0;
          }
          iVar1 = BIO_puts(param_1,pcVar8);
          CRYPTO_free(pcVar8);
          goto joined_r0x0018fbe4;
        case 3:
        case 4:
          if (a_00->type == 3) {
            iVar1 = BIO_printf(param_1," (%ld unused bits)\n",a_00->flags & 7);
          }
          else {
            iVar1 = BIO_puts(param_1,"\n");
          }
          if (iVar1 < 1) {
            return 0;
          }
          if (a_00->length < 1) goto LAB_0018f584;
          iVar1 = BIO_dump_indent(param_1,(char *)a_00->data,a_00->length,param_3 + 4);
joined_r0x0018f682:
          if (iVar1 < 1) {
            return 0;
          }
          goto LAB_0018f584;
        case 6:
          pAVar17 = (ASN1_OBJECT *)*piVar15;
          iVar1 = OBJ_obj2nid(pAVar17);
          pcVar8 = OBJ_nid2ln(iVar1);
          if (pcVar8 == (char *)0x0) {
            pcVar8 = "";
          }
          OBJ_obj2txt(acStack_78,0x50,pAVar17,1);
          iVar1 = BIO_printf(param_1,"%s (%s)",pcVar8,acStack_78);
joined_r0x0018fbe4:
          if (iVar1 < 1) {
            return 0;
          }
          goto LAB_0018f9ee;
        case 0x17:
          iVar1 = ASN1_UTCTIME_print(param_1,a_00);
          break;
        case 0x18:
          iVar1 = ASN1_GENERALIZEDTIME_print(param_1,a_00);
          break;
        case 0xfffffffd:
        case 0x10:
        case 0x11:
          iVar2 = BIO_puts(param_1,"\n");
          if (iVar2 < 1) {
            return 0;
          }
          iVar1 = ASN1_parse_dump(param_1,a_00->data,a_00->length,iVar1,0);
          goto joined_r0x0018f682;
        default:
          iVar1 = ASN1_STRING_print_ex(param_1,a_00,param_5[4]);
        }
        if (iVar1 == 0) {
          return 0;
        }
LAB_0018f9ee:
        iVar1 = BIO_puts(param_1,"\n");
joined_r0x0018f580:
        if (iVar1 < 1) {
          return 0;
        }
LAB_0018f584:
        iVar10 = iVar10 + 1;
        iVar1 = OPENSSL_sk_num(pAVar18);
      } while (iVar10 < iVar1);
    }
    if (iVar10 == 0) {
      if (pAVar18 == (ASN1_VALUE *)0x0) {
        pcVar8 = "ABSENT";
      }
      else {
        pcVar8 = "EMPTY";
      }
      iVar1 = BIO_printf(param_1,"%*s<%s>\n",param_3 + 2,"",pcVar8);
      if (iVar1 < 1) {
        return 0;
      }
    }
    if ((int)(*param_5 << 0x1e) < 0) {
      iVar1 = BIO_printf(param_1,"%*s}\n",param_3,"");
      return 0 < iVar1;
    }
    return 1;
  }
  pAVar9 = (ASN1_ITEM *)param_4[4];
  pvVar13 = pAVar9->funcs;
  if (pvVar13 == (void *)0x0) {
    local_b4 = (code *)0x0;
  }
  else {
    local_b4 = *(code **)((int)pvVar13 + 0x10);
    if (local_b4 != (code *)0x0) {
      local_84 = param_1;
      local_7c = param_5;
      local_80 = param_3;
    }
  }
  if (pAVar9->itype != '\0') {
    if ((ASN1_VALUE *)*param_2 != (ASN1_VALUE *)0x0) {
      switch(pAVar9->itype) {
      case '\x01':
      case '\x06':
        iVar1 = asn1_print_fsname_isra_0(param_1,param_3,uVar12,uVar11,param_5);
        if (iVar1 == 0) {
          return 0;
        }
        if (uVar11 != 0 || uVar12 != 0) {
          if ((int)(*param_5 << 0x1e) < 0) {
            iVar1 = BIO_puts(param_1," {\n");
          }
          else {
            iVar1 = BIO_puts(param_1,"\n");
          }
          if (iVar1 < 1) {
            return 0;
          }
        }
        if (local_b4 != (code *)0x0) {
          iVar1 = (*local_b4)(8,param_2,pAVar9,&local_84);
          if (iVar1 == 0) {
            return 0;
          }
          if (iVar1 == 2) {
            return 1;
          }
        }
        pAVar14 = pAVar9->templates;
        if (0 < pAVar9->tcount) {
          iVar1 = 0;
          do {
            iVar1 = iVar1 + 1;
            pAVar5 = asn1_do_adb((ASN1_VALUE **)param_2,pAVar14,1);
            pAVar14 = pAVar14 + 1;
            if (pAVar5 == (ASN1_TEMPLATE *)0x0) {
              return 0;
            }
            ppAVar3 = asn1_get_field_ptr((ASN1_VALUE **)param_2,pAVar5);
            iVar10 = asn1_template_print_ctx(param_1,ppAVar3,param_3 + 2,pAVar5,param_5);
            if (iVar10 == 0) {
              return 0;
            }
          } while (iVar1 < pAVar9->tcount);
        }
        if (((int)(*param_5 << 0x1e) < 0) &&
           (iVar1 = BIO_printf(param_1,"%*s}\n",param_3,""), iVar1 < 0)) {
          return 0;
        }
        if (local_b4 == (code *)0x0) {
          return 1;
        }
        uVar6 = (*local_b4)(9,param_2,pAVar9,&local_84);
        if (uVar6 != 0) {
          return 1;
        }
        return 0;
      case '\x02':
        iVar1 = asn1_get_choice_selector((ASN1_VALUE **)param_2,pAVar9);
        if ((-1 < iVar1) && (iVar1 < pAVar9->tcount)) {
          pAVar14 = pAVar9->templates;
          ppAVar3 = asn1_get_field_ptr((ASN1_VALUE **)param_2,pAVar14 + iVar1);
          uVar6 = asn1_template_print_ctx(param_1,ppAVar3,param_3,pAVar14 + iVar1,param_5);
          if (uVar6 != 0) {
            return 1;
          }
          return 0;
        }
        iVar1 = BIO_printf(param_1,"ERROR: selector [%d] invalid\n");
        return 0 < iVar1;
      default:
        BIO_printf(param_1,"Unprocessed type %d\n");
        return 0;
      case '\x04':
        iVar1 = asn1_print_fsname_isra_0(param_1,param_3,uVar12,uVar11,param_5);
        if (iVar1 == 0) {
          return 0;
        }
        if ((pAVar9->funcs == (void *)0x0) ||
           (pcVar16 = *(code **)((int)pAVar9->funcs + 0x18), pcVar16 == (code *)0x0)) {
          if (uVar11 == 0) {
            return 1;
          }
          iVar1 = BIO_printf(param_1,":EXTERNAL TYPE %s\n",uVar11);
          return 0 < iVar1;
        }
        iVar1 = (*pcVar16)(param_1,param_2,param_3,"",param_5);
        if (iVar1 == 0) {
          return 0;
        }
        if (iVar1 != 2) {
          return 1;
        }
        iVar1 = BIO_puts(param_1,"\n");
        return 0 < iVar1;
      case '\x05':
        goto switchD_0018f898_caseD_5;
      }
    }
LAB_0018f7da:
    if (-1 < (int)(uVar7 << 0x1f)) {
      return 1;
    }
    iVar1 = asn1_print_fsname_isra_0(param_1,param_3,uVar12,uVar11,param_5);
    if (iVar1 != 0) {
      iVar1 = BIO_puts(param_1,"<ABSENT>\n");
      return 0 < iVar1;
    }
    return 0;
  }
  if ((pAVar9->utype != 1) && ((ASN1_VALUE *)*param_2 == (ASN1_VALUE *)0x0)) goto LAB_0018f7da;
  if (pAVar9->templates != (ASN1_TEMPLATE *)0x0) {
    uVar6 = asn1_template_print_ctx(param_1,param_2,param_3,pAVar9->templates,param_5);
    if (uVar6 != 0) {
      return 1;
    }
    return 0;
  }
switchD_0018f898_caseD_5:
  iVar1 = asn1_print_fsname_isra_0(param_1,param_3,uVar12,uVar11,param_5);
  if (iVar1 == 0) {
    return 0;
  }
  if ((pvVar13 != (void *)0x0) && (*(code **)((int)pvVar13 + 0x1c) != (code *)0x0)) {
    uVar6 = (**(code **)((int)pvVar13 + 0x1c))(param_1,param_2,pAVar9,param_3,param_5);
    if (uVar6 != 0) {
      return 1;
    }
    return 0;
  }
  if (pAVar9->itype != '\x05') {
    uVar6 = pAVar9->utype;
    if (uVar6 != 1) {
      a = (ASN1_GENERALIZEDTIME *)*param_2;
      goto LAB_0018fcda;
    }
    if ((int)(*param_5 << 0x1c) < 0) {
      a = (ASN1_GENERALIZEDTIME *)0x0;
      goto LAB_0018fd66;
    }
switchD_0018fd98_caseD_1:
    pAVar18 = (ASN1_VALUE *)*param_2;
    if ((pAVar18 == (ASN1_VALUE *)0xffffffff) &&
       (pAVar18 = (ASN1_VALUE *)pAVar9->size, pAVar18 == (ASN1_VALUE *)0xffffffff)) {
      pcVar8 = "BOOL ABSENT";
    }
    else if (pAVar18 == (ASN1_VALUE *)0x0) {
      pcVar8 = "FALSE";
    }
    else {
      pcVar8 = "TRUE";
    }
    iVar1 = BIO_puts(param_1,pcVar8);
    if (iVar1 < 1) {
      return 0;
    }
    goto LAB_0018fdc8;
  }
  a = (ASN1_GENERALIZEDTIME *)*param_2;
  uVar6 = a->type & 0xfffffeff;
LAB_0018fcda:
  if (uVar6 != 0xfffffffc) {
    if ((int)(*param_5 << 0x1c) < 0) goto LAB_0018fd66;
LAB_0018fce8:
    if (uVar6 != 5) goto LAB_0018fd90;
LAB_0018fcec:
    iVar1 = BIO_puts(param_1,"NULL\n");
    goto joined_r0x0018fdd4;
  }
  param_2 = &a->type;
  uVar6 = a->length;
  a = (ASN1_GENERALIZEDTIME *)a->type;
  if ((int)(*param_5 << 0x1b) < 0) goto LAB_0018fce8;
LAB_0018fd66:
  pcVar8 = ASN1_tag2str(uVar6);
  if (uVar6 == 5) goto LAB_0018fcec;
  if (pcVar8 != (char *)0x0) {
    iVar1 = BIO_puts(param_1,pcVar8);
    if (iVar1 < 1) {
      return 0;
    }
    iVar1 = BIO_puts(param_1,":");
    if (iVar1 < 1) {
      return 0;
    }
  }
LAB_0018fd90:
  switch(uVar6) {
  case 1:
    goto switchD_0018fd98_caseD_1;
  case 2:
  case 10:
    pcVar8 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,a);
    if (pcVar8 == (char *)0x0) {
      return 0;
    }
    iVar1 = BIO_puts(param_1,pcVar8);
    uVar6 = (uint)(0 < iVar1);
    CRYPTO_free(pcVar8);
    break;
  case 3:
  case 4:
    if (a->type == 3) {
      iVar1 = BIO_printf(param_1," (%ld unused bits)\n",a->flags & 7);
    }
    else {
      iVar1 = BIO_puts(param_1,"\n");
    }
    if (iVar1 < 1) {
      return 0;
    }
    if (a->length < 1) {
      return 1;
    }
    iVar1 = BIO_dump_indent(param_1,(char *)a->data,a->length,param_3 + 2);
    goto joined_r0x0018fdd4;
  case 6:
    pAVar17 = (ASN1_OBJECT *)*param_2;
    iVar1 = OBJ_obj2nid(pAVar17);
    pcVar8 = OBJ_nid2ln(iVar1);
    if (pcVar8 == (char *)0x0) {
      pcVar8 = "";
    }
    OBJ_obj2txt(acStack_78,0x50,pAVar17,1);
    iVar1 = BIO_printf(param_1,"%s (%s)",pcVar8,acStack_78);
    uVar6 = (uint)(0 < iVar1);
    break;
  case 0x17:
    uVar6 = ASN1_UTCTIME_print(param_1,a);
    break;
  case 0x18:
    uVar6 = ASN1_GENERALIZEDTIME_print(param_1,a);
    break;
  case 0xfffffffd:
  case 0x10:
  case 0x11:
    iVar1 = BIO_puts(param_1,"\n");
    if (iVar1 < 1) {
      return 0;
    }
    iVar1 = ASN1_parse_dump(param_1,a->data,a->length,param_3,0);
    goto joined_r0x0018fdd4;
  default:
    uVar6 = ASN1_STRING_print_ex(param_1,a,param_5[4]);
  }
  if (uVar6 != 0) {
LAB_0018fdc8:
    iVar1 = BIO_puts(param_1,"\n");
joined_r0x0018fdd4:
    if (0 < iVar1) {
      return 1;
    }
  }
  return 0;
}

