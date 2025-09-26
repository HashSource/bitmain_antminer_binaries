
/* WARNING: Type propagation algorithm not settling */

undefined4
asn1_template_noexp_d2i
          (int *******param_1,undefined4 *param_2,int param_3,uint *param_4,undefined1 param_5,
          undefined4 param_6,int param_7)

{
  uchar *puVar1;
  uchar *puVar2;
  int iVar3;
  ASN1_TEMPLATE *pAVar4;
  ASN1_VALUE **ppAVar5;
  ulong uVar6;
  uint uVar7;
  uint uVar8;
  int ******ppppppiVar9;
  ASN1_TEMPLATE *pAVar10;
  void *pvVar11;
  ASN1_ITEM *it;
  char cVar12;
  int *******pppppppiVar13;
  int iVar14;
  code *local_74;
  uchar **local_6c;
  ASN1_VALUE **local_64;
  int local_4c [2];
  char local_44;
  char local_43;
  char local_42;
  char local_41;
  int *******local_40;
  uchar *local_3c;
  ASN1_VALUE *local_38;
  int local_34;
  uchar *local_30;
  ASN1_VALUE *local_2c [2];
  
  if (param_1 == (int *******)0x0) {
    return 0;
  }
  uVar8 = *param_4;
  local_3c = (uchar *)*param_2;
  uVar7 = uVar8 & 0xc0;
  pppppppiVar13 = param_1;
  if ((int)(uVar8 << 0x13) < 0) {
    pppppppiVar13 = (int *******)&local_40;
    local_40 = param_1;
  }
  local_4c[0] = param_3;
  if ((uVar8 & 6) == 0) {
    if ((uVar8 & 8) == 0) {
      iVar3 = asn1_item_embed_d2i(pppppppiVar13,&local_3c,param_3,param_4[4],0xffffffff,0,param_5,
                                  param_6,param_7);
      if (iVar3 == 0) {
        iVar3 = 0x286;
        goto LAB_001110f8;
      }
    }
    else {
      iVar3 = asn1_item_embed_d2i(pppppppiVar13,&local_3c,param_3,param_4[4],param_4[1],uVar7,
                                  param_5,param_6,param_7);
      if (iVar3 == 0) {
        iVar3 = 0x27d;
LAB_001110f8:
        ERR_put_error(0xd,0x83,0x3a,"crypto/asn1/tasn_dec.c",iVar3);
        return 0;
      }
    }
    if (iVar3 == -1) {
      return 0xffffffff;
    }
  }
  else {
    if ((uVar8 & 8) == 0) {
      if ((uVar8 & 2) == 0) {
        uVar8 = 0x10;
      }
      else {
        uVar8 = 0x11;
      }
      uVar7 = 0;
    }
    else {
      uVar8 = param_4[1];
    }
    iVar3 = asn1_check_tlen(local_4c,0,0,&local_44,0,&local_3c,param_3,uVar8,uVar7,param_5,param_6);
    if (iVar3 == 0) {
      iVar3 = 0x23c;
      goto LAB_001110f8;
    }
    if (iVar3 == -1) {
      return 0xffffffff;
    }
    ppppppiVar9 = *pppppppiVar13;
    if (ppppppiVar9 == (int ******)0x0) {
      ppppppiVar9 = (int ******)OPENSSL_sk_new_null();
      *pppppppiVar13 = ppppppiVar9;
    }
    else {
      while (iVar3 = OPENSSL_sk_num(ppppppiVar9), 0 < iVar3) {
        local_2c[0] = (ASN1_VALUE *)OPENSSL_sk_pop(ppppppiVar9);
        ASN1_item_ex_free(local_2c,(ASN1_ITEM *)param_4[4]);
      }
      ppppppiVar9 = *pppppppiVar13;
    }
    if (ppppppiVar9 == (int ******)0x0) {
      ERR_put_error(0xd,0x83,0x41,"crypto/asn1/tasn_dec.c",0x24f);
      return 0;
    }
    if (0 < local_4c[0]) {
      param_7 = param_7 + 1;
      do {
        puVar1 = local_3c;
        iVar3 = local_4c[0];
        if (((local_4c[0] != 1) && (*local_3c == '\0')) && (local_3c[1] == '\0')) {
          local_3c = local_3c + 2;
          if (local_44 == '\0') {
            ERR_put_error(0xd,0x83,0x9f,"crypto/asn1/tasn_dec.c",0x25b);
            return 0;
          }
          goto LAB_00110d1e;
        }
        it = (ASN1_ITEM *)param_4[4];
        local_38 = (ASN1_VALUE *)0x0;
        local_34 = local_4c[0];
        pvVar11 = it->funcs;
        local_30 = (uchar *)0x0;
        if (pvVar11 == (void *)0x0) {
          local_74 = (code *)0x0;
        }
        else {
          local_74 = *(code **)((int)pvVar11 + 0x10);
        }
        if (0x1e < param_7) {
          ERR_put_error(0xd,0x78,0xc9,"crypto/asn1/tasn_dec.c",0xa0);
          goto LAB_00110fba;
        }
        switch(it->itype) {
        case '\0':
          if (it->templates == (ASN1_TEMPLATE *)0x0) {
            iVar3 = asn1_d2i_ex_primitive(&local_38,&local_3c,local_4c[0],it,0xffffffff,0,0,param_6)
            ;
          }
          else {
            iVar3 = asn1_template_ex_d2i
                              (&local_38,&local_3c,local_4c[0],it->templates,0,param_6,param_7);
          }
          break;
        case '\x01':
        case '\x06':
          local_30 = local_3c;
          iVar14 = asn1_check_tlen(&local_34,0,0,&local_42,&local_41,&local_30,local_4c[0],0x10,0,0,
                                   param_6);
          if (iVar14 == 0) {
            iVar3 = 0x135;
LAB_00111138:
            ERR_put_error(0xd,0x78,0x3a,"crypto/asn1/tasn_dec.c",iVar3);
            goto LAB_00110fba;
          }
          if (iVar14 != -1) {
            cVar12 = local_42;
            if ((pvVar11 != (void *)0x0) && (*(int *)((int)pvVar11 + 4) << 0x1d < 0)) {
              local_34 = iVar3 - ((int)local_30 - (int)local_3c);
              cVar12 = '\x01';
            }
            if (local_41 == '\0') {
              ERR_put_error(0xd,0x78,0x95,"crypto/asn1/tasn_dec.c",0x141);
              goto LAB_00110fba;
            }
            if ((local_38 == (ASN1_VALUE *)0x0) &&
               (iVar3 = ASN1_item_ex_new(&local_38,it), iVar3 == 0)) {
              iVar3 = 0x146;
              goto LAB_00111138;
            }
            local_6c = &local_30;
            if ((local_74 != (code *)0x0) && (iVar3 = (*local_74)(4,&local_38,it,0), iVar3 == 0))
            goto LAB_00110fa0;
            iVar3 = it->tcount;
            pAVar10 = it->templates;
            if (iVar3 < 1) {
              iVar14 = 0;
            }
            else {
              pAVar10 = pAVar10 + 4;
              iVar14 = 0;
              do {
                HintPreloadData(pAVar10);
                if ((pAVar10[-4].flags & 0x300) != 0) {
                  pAVar4 = asn1_do_adb(&local_38,pAVar10 + -4,0);
                  if (pAVar4 != (ASN1_TEMPLATE *)0x0) {
                    ppAVar5 = asn1_get_field_ptr(&local_38,pAVar4);
                    asn1_template_free(ppAVar5,pAVar4);
                  }
                  iVar3 = it->tcount;
                }
                iVar14 = iVar14 + 1;
                pAVar10 = pAVar10 + 1;
              } while (iVar14 < iVar3);
              pAVar10 = it->templates;
              iVar14 = 0;
              if (0 < iVar3) {
                do {
                  pAVar4 = asn1_do_adb(&local_38,pAVar10,1);
                  if (pAVar4 == (ASN1_TEMPLATE *)0x0) goto LAB_00110fba;
                  ppAVar5 = asn1_get_field_ptr(&local_38,pAVar4);
                  puVar2 = local_30;
                  if (local_34 == 0) {
                    if (local_42 == '\0') goto LAB_0011123c;
                    goto LAB_00111340;
                  }
                  if (((1 < local_34) && (*local_30 == '\0')) && (local_30[1] == '\0')) {
                    local_30 = local_30 + 2;
                    if (local_42 == '\0') {
                      ERR_put_error(0xd,0x78,0x9f,"crypto/asn1/tasn_dec.c",0x168);
                      goto LAB_00110fba;
                    }
                    local_34 = local_34 + -2;
                    local_42 = '\0';
                    goto LAB_0011122e;
                  }
                  if (iVar14 == it->tcount + -1) {
                    uVar7 = 0;
                  }
                  else {
                    uVar7 = pAVar4->flags & 1;
                  }
                  iVar3 = asn1_template_ex_d2i
                                    (ppAVar5,local_6c,local_34,pAVar4,uVar7,param_6,param_7);
                  if (iVar3 == 0) goto LAB_001110a8;
                  if (iVar3 == -1) {
                    asn1_template_free(ppAVar5,pAVar4);
                  }
                  else {
                    local_34 = local_34 - ((int)local_30 - (int)puVar2);
                  }
                  iVar14 = iVar14 + 1;
                  pAVar10 = pAVar10 + 1;
                } while (iVar14 < it->tcount);
              }
            }
            if (local_42 != '\0') {
              if (((local_34 < 2) || (*local_30 != '\0')) || (local_30[1] != '\0')) {
LAB_00111340:
                ERR_put_error(0xd,0x78,0x89,"crypto/asn1/tasn_dec.c",400);
                goto LAB_00110fba;
              }
              local_30 = local_30 + 2;
            }
LAB_0011122e:
            if ((cVar12 == '\0') && (local_34 != 0)) {
              ERR_put_error(0xd,0x78,0x94,"crypto/asn1/tasn_dec.c",0x195);
              goto LAB_00110fba;
            }
LAB_0011123c:
            local_64 = &local_38;
            if (iVar14 < it->tcount) {
LAB_00111266:
              iVar14 = iVar14 + 1;
              pAVar4 = asn1_do_adb(local_64,pAVar10,1);
              pAVar10 = pAVar10 + 1;
              if (pAVar4 != (ASN1_TEMPLATE *)0x0) {
                if ((int)(pAVar4->flags << 0x1f) < 0) goto code_r0x00111256;
                ERR_put_error(0xd,0x78,0x79,"crypto/asn1/tasn_dec.c",0x1a9);
LAB_001110a8:
                ERR_add_error_data(4,"Field=",pAVar4->field_name,", Type=",it->sname);
                goto LAB_00110fca;
              }
              goto LAB_00110fba;
            }
LAB_001112b6:
            iVar3 = asn1_enc_save(local_64,local_3c,(int)local_30 - (int)local_3c,it);
            if (iVar3 == 0) goto LAB_00110fa0;
joined_r0x00110f8a:
            if (local_74 != (code *)0x0) {
              local_64 = &local_38;
              iVar3 = (*local_74)(5,local_64,it,0);
              if (iVar3 == 0) goto LAB_00110fa0;
            }
            local_3c = local_30;
          }
          goto LAB_00110da0;
        case '\x02':
          if (local_74 == (code *)0x0) {
LAB_0011111a:
            local_64 = &local_38;
            iVar3 = ASN1_item_ex_new(local_64,it);
            if (iVar3 == 0) {
              iVar3 = 0xf9;
              goto LAB_00111138;
            }
            iVar14 = it->tcount;
LAB_00110e20:
            local_64 = &local_38;
            pAVar4 = it->templates;
            iVar3 = 0;
            local_30 = local_3c;
            if (0 < iVar14) {
              do {
                ppAVar5 = asn1_get_field_ptr(local_64,pAVar4);
                iVar14 = asn1_template_ex_d2i(ppAVar5,&local_30,local_34,pAVar4,1,param_6,param_7);
                if (iVar14 != -1) {
                  if (iVar14 < 1) {
                    asn1_template_free(ppAVar5,pAVar4);
                    ERR_put_error(0xd,0x78,0x3a,"crypto/asn1/tasn_dec.c",0x110);
                    if (pAVar4 == (ASN1_TEMPLATE *)0x0) goto LAB_00110fba;
                    goto LAB_001110a8;
                  }
                  iVar14 = it->tcount;
                  break;
                }
                iVar14 = it->tcount;
                iVar3 = iVar3 + 1;
                pAVar4 = pAVar4 + 1;
              } while (iVar3 < iVar14);
            }
            if (iVar3 != iVar14) {
              asn1_set_choice_selector(local_64,iVar3,it);
              goto joined_r0x00110f8a;
            }
            ERR_put_error(0xd,0x78,0x8f,"crypto/asn1/tasn_dec.c",0x11c);
          }
          else {
            iVar3 = (*local_74)(4,&local_38,it,0);
            if (iVar3 != 0) {
              if (local_38 == (ASN1_VALUE *)0x0) goto LAB_0011111a;
              iVar3 = asn1_get_choice_selector(&local_38,it);
              iVar14 = it->tcount;
              if ((-1 < iVar3) && (iVar3 < iVar14)) {
                pAVar4 = it->templates;
                ppAVar5 = asn1_get_field_ptr(&local_38,pAVar4 + iVar3);
                asn1_template_free(ppAVar5,pAVar4 + iVar3);
                asn1_set_choice_selector(&local_38,-1,it);
                iVar14 = it->tcount;
              }
              goto LAB_00110e20;
            }
LAB_00110fa0:
            ERR_put_error(0xd,0x78,100,"crypto/asn1/tasn_dec.c",0x1b9);
          }
          goto LAB_00110fba;
        default:
          goto switchD_00110cd6_caseD_3;
        case '\x04':
          iVar3 = (**(code **)((int)pvVar11 + 0x10))
                            (&local_38,&local_3c,local_4c[0],it,0xffffffff,0,0,param_6);
          break;
        case '\x05':
          local_30 = local_3c;
          iVar3 = asn1_check_tlen_constprop_1
                            (0,local_2c,&local_43,0,0,&local_30,local_4c[0],1,param_6);
          if (iVar3 == 0) {
            iVar3 = 199;
            goto LAB_00111138;
          }
          if (local_43 == '\0') {
            uVar6 = ASN1_tag2bit((int)local_2c[0]);
            if ((uVar6 & it->utype) != 0) {
              iVar3 = asn1_d2i_ex_primitive(&local_38,&local_3c,local_34,it,local_2c[0],0,0,param_6)
              ;
              break;
            }
            ERR_put_error(0xd,0x78,0x8c,"crypto/asn1/tasn_dec.c",0xd9);
          }
          else {
            ERR_put_error(0xd,0x78,0x8b,"crypto/asn1/tasn_dec.c",0xd0);
          }
LAB_00110fba:
          ERR_add_error_data(2,"Type=",it->sname);
          goto LAB_00110fca;
        }
        if (iVar3 == 0) {
switchD_00110cd6_caseD_3:
LAB_00110fca:
          iVar14 = 0x267;
          iVar3 = 0x3a;
LAB_00110fd8:
          ERR_put_error(0xd,0x83,iVar3,"crypto/asn1/tasn_dec.c",iVar14);
          ASN1_item_free(local_38,(ASN1_ITEM *)param_4[4]);
          return 0;
        }
LAB_00110da0:
        local_4c[0] = local_4c[0] - ((int)local_3c - (int)puVar1);
        iVar3 = OPENSSL_sk_push(*pppppppiVar13,local_38);
        if (iVar3 == 0) {
          iVar14 = 0x26e;
          iVar3 = 0x41;
          goto LAB_00110fd8;
        }
      } while (0 < local_4c[0]);
    }
    if (local_44 != '\0') {
      ERR_put_error(0xd,0x83,0x89,"crypto/asn1/tasn_dec.c",0x274);
      return 0;
    }
  }
LAB_00110d1e:
  *param_2 = local_3c;
  return 1;
code_r0x00111256:
  ppAVar5 = asn1_get_field_ptr(local_64,pAVar4);
  asn1_template_free(ppAVar5,pAVar4);
  if (it->tcount <= iVar14) goto LAB_001112b6;
  goto LAB_00111266;
}

