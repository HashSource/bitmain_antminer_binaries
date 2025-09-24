
undefined4
asn1_item_embed_d2i(ASN1_VALUE **param_1,int *param_2,int param_3,ASN1_ITEM *param_4,int param_5,
                   undefined4 param_6,char param_7,undefined4 param_8,int param_9)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  ASN1_TEMPLATE *pAVar4;
  ASN1_VALUE **ppAVar5;
  ulong uVar6;
  undefined4 uVar7;
  uint uVar8;
  void *pvVar9;
  ASN1_TEMPLATE *pAVar10;
  int iVar11;
  code *local_4c;
  int local_3c [2];
  char local_33;
  char local_32;
  char local_31;
  char *local_30;
  int local_2c [2];
  
  pvVar9 = param_4->funcs;
  local_30 = (char *)0x0;
  if (param_1 == (ASN1_VALUE **)0x0) {
    return 0;
  }
  if (pvVar9 == (void *)0x0) {
    local_4c = (code *)0x0;
  }
  else {
    local_4c = *(code **)((int)pvVar9 + 0x10);
  }
  param_9 = param_9 + 1;
  local_3c[0] = param_3;
  if (param_9 < 0x1f) {
    switch(param_4->itype) {
    case '\0':
      if (param_4->templates == (ASN1_TEMPLATE *)0x0) {
        uVar7 = asn1_d2i_ex_primitive
                          (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
        return uVar7;
      }
      if (param_7 == '\0' && param_5 == -1) {
        uVar7 = asn1_template_ex_d2i(param_1,param_2,param_3,param_4->templates,0,param_8,param_9);
        return uVar7;
      }
      ERR_put_error(0xd,0x78,0xaa,"crypto/asn1/tasn_dec.c",0xaf);
      break;
    case '\x01':
    case '\x06':
      local_30 = (char *)*param_2;
      if (param_5 == -1) {
        param_6 = 0;
        param_5 = 0x10;
      }
      iVar3 = asn1_check_tlen(local_3c,0,0,&local_32,&local_31,&local_30,param_3,param_5,param_6,
                              param_7,param_8);
      if (iVar3 == 0) {
        iVar3 = 0x135;
LAB_00107dd8:
        ERR_put_error(0xd,0x78,0x3a,"crypto/asn1/tasn_dec.c",iVar3);
      }
      else {
        if (iVar3 == -1) {
          return 0xffffffff;
        }
        cVar1 = local_32;
        if ((pvVar9 != (void *)0x0) && (*(int *)((int)pvVar9 + 4) << 0x1d < 0)) {
          local_3c[0] = param_3 - ((int)local_30 - *param_2);
          cVar1 = '\x01';
        }
        if (local_31 == '\0') {
          ERR_put_error(0xd,0x78,0x95,"crypto/asn1/tasn_dec.c",0x141);
        }
        else {
          if ((*param_1 == (ASN1_VALUE *)0x0) &&
             (iVar3 = ASN1_item_ex_new(param_1,param_4), iVar3 == 0)) {
            iVar3 = 0x146;
            goto LAB_00107dd8;
          }
          if ((local_4c != (code *)0x0) && (iVar3 = (*local_4c)(4,param_1,param_4,0), iVar3 == 0))
          goto LAB_00107da8;
          iVar3 = param_4->tcount;
          pAVar10 = param_4->templates;
          if (iVar3 < 1) {
            iVar11 = 0;
          }
          else {
            pAVar10 = pAVar10 + 4;
            iVar11 = 0;
            do {
              HintPreloadData(pAVar10);
              if ((pAVar10[-4].flags & 0x300) != 0) {
                pAVar4 = asn1_do_adb(param_1,pAVar10 + -4,0);
                if (pAVar4 != (ASN1_TEMPLATE *)0x0) {
                  ppAVar5 = asn1_get_field_ptr(param_1,pAVar4);
                  asn1_template_free(ppAVar5,pAVar4);
                }
                iVar3 = param_4->tcount;
              }
              iVar11 = iVar11 + 1;
              pAVar10 = pAVar10 + 1;
            } while (iVar11 < iVar3);
            pAVar10 = param_4->templates;
            iVar11 = 0;
            if (0 < iVar3) {
              do {
                pAVar4 = asn1_do_adb(param_1,pAVar10,1);
                if (pAVar4 == (ASN1_TEMPLATE *)0x0) goto LAB_00107b6e;
                ppAVar5 = asn1_get_field_ptr(param_1,pAVar4);
                pcVar2 = local_30;
                if (local_3c[0] == 0) {
                  if (local_32 != '\0') goto LAB_00108010;
                  goto LAB_00107f06;
                }
                if (((1 < local_3c[0]) && (*local_30 == '\0')) && (local_30[1] == '\0')) {
                  local_30 = local_30 + 2;
                  if (local_32 != '\0') {
                    local_3c[0] = local_3c[0] + -2;
                    local_32 = '\0';
                    goto LAB_00107efa;
                  }
                  ERR_put_error(0xd,0x78,0x9f,"crypto/asn1/tasn_dec.c",0x168);
                  goto LAB_00107b6e;
                }
                if (param_4->tcount + -1 == iVar11) {
                  uVar8 = 0;
                }
                else {
                  uVar8 = pAVar4->flags & 1;
                }
                iVar3 = asn1_template_ex_d2i
                                  (ppAVar5,&local_30,local_3c[0],pAVar4,uVar8,param_8,param_9);
                if (iVar3 == 0) goto LAB_00107f60;
                if (iVar3 == -1) {
                  asn1_template_free(ppAVar5,pAVar4);
                }
                else {
                  local_3c[0] = local_3c[0] - ((int)local_30 - (int)pcVar2);
                }
                iVar11 = iVar11 + 1;
                pAVar10 = pAVar10 + 1;
              } while (iVar11 < param_4->tcount);
            }
          }
          if (local_32 != '\0') {
            if (((local_3c[0] < 2) || (*local_30 != '\0')) || (local_30[1] != '\0')) {
LAB_00108010:
              ERR_put_error(0xd,0x78,0x89,"crypto/asn1/tasn_dec.c",400);
              break;
            }
            local_30 = local_30 + 2;
          }
LAB_00107efa:
          if ((cVar1 != '\0') || (local_3c[0] == 0)) {
LAB_00107f06:
            if (iVar11 < param_4->tcount) {
              do {
                iVar11 = iVar11 + 1;
                pAVar4 = asn1_do_adb(param_1,pAVar10,1);
                pAVar10 = pAVar10 + 1;
                if (pAVar4 == (ASN1_TEMPLATE *)0x0) goto LAB_00107b6e;
                if (-1 < (int)(pAVar4->flags << 0x1f)) {
                  ERR_put_error(0xd,0x78,0x79,"crypto/asn1/tasn_dec.c",0x1a9);
LAB_00107f60:
                  ERR_add_error_data(4,"Field=",pAVar4->field_name,", Type=",param_4->sname);
                  return 0;
                }
                ppAVar5 = asn1_get_field_ptr(param_1,pAVar4);
                asn1_template_free(ppAVar5,pAVar4);
              } while (iVar11 < param_4->tcount);
            }
            iVar3 = asn1_enc_save(param_1,(uchar *)*param_2,(int)local_30 - *param_2,param_4);
            if (iVar3 != 0) goto joined_r0x00107fa0;
            goto LAB_00107da8;
          }
          ERR_put_error(0xd,0x78,0x94,"crypto/asn1/tasn_dec.c",0x195);
        }
      }
      break;
    case '\x02':
      if (param_5 == -1) {
        if ((local_4c == (code *)0x0) || (iVar3 = (*local_4c)(4,param_1,param_4,0), iVar3 != 0)) {
          if (*param_1 == (ASN1_VALUE *)0x0) {
            iVar3 = ASN1_item_ex_new(param_1,param_4);
            if (iVar3 == 0) {
              iVar3 = 0xf9;
              goto LAB_00107dd8;
            }
            iVar3 = param_4->tcount;
          }
          else {
            iVar11 = asn1_get_choice_selector(param_1,param_4);
            iVar3 = param_4->tcount;
            if ((-1 < iVar11) && (iVar11 < iVar3)) {
              pAVar4 = param_4->templates;
              ppAVar5 = asn1_get_field_ptr(param_1,pAVar4 + iVar11);
              asn1_template_free(ppAVar5,pAVar4 + iVar11);
              asn1_set_choice_selector(param_1,-1,param_4);
              iVar3 = param_4->tcount;
            }
          }
          local_30 = (char *)*param_2;
          pAVar4 = param_4->templates;
          iVar11 = 0;
          if (0 < iVar3) {
            do {
              ppAVar5 = asn1_get_field_ptr(param_1,pAVar4);
              iVar3 = asn1_template_ex_d2i(ppAVar5,&local_30,local_3c[0],pAVar4,1,param_8,param_9);
              if (iVar3 != -1) {
                if (iVar3 < 1) {
                  asn1_template_free(ppAVar5,pAVar4);
                  ERR_put_error(0xd,0x78,0x3a,"crypto/asn1/tasn_dec.c",0x110);
                  if (pAVar4 == (ASN1_TEMPLATE *)0x0) goto LAB_00107b6e;
                  goto LAB_00107f60;
                }
                iVar3 = param_4->tcount;
                break;
              }
              iVar3 = param_4->tcount;
              iVar11 = iVar11 + 1;
              pAVar4 = pAVar4 + 1;
            } while (iVar11 < iVar3);
          }
          if (iVar11 == iVar3) {
            if (param_7 != '\0') {
              ASN1_item_ex_free(param_1,param_4);
              return 0xffffffff;
            }
            ERR_put_error(0xd,0x78,0x8f,"crypto/asn1/tasn_dec.c",0x11c);
            break;
          }
          asn1_set_choice_selector(param_1,iVar11,param_4);
joined_r0x00107fa0:
          if ((local_4c == (code *)0x0) || (iVar3 = (*local_4c)(5,param_1,param_4,0), iVar3 != 0)) {
            *param_2 = (int)local_30;
            return 1;
          }
        }
LAB_00107da8:
        ERR_put_error(0xd,0x78,100,"crypto/asn1/tasn_dec.c",0x1b9);
      }
      else {
        iVar3 = 0xe9;
LAB_00107b94:
        ERR_put_error(0xd,0x78,0xe6,"crypto/asn1/tasn_dec.c",iVar3);
      }
      break;
    default:
      goto LAB_00107b7e;
    case '\x04':
      uVar7 = (**(code **)((int)pvVar9 + 0x10))
                        (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
      return uVar7;
    case '\x05':
      if (param_5 != -1) {
        iVar3 = 0xbe;
        goto LAB_00107b94;
      }
      local_30 = (char *)*param_2;
      iVar3 = asn1_check_tlen_constprop_1(0,local_2c,&local_33,0,0,&local_30,param_3,1,param_8);
      if (iVar3 == 0) {
        iVar3 = 199;
        goto LAB_00107dd8;
      }
      if (local_33 == '\0') {
        uVar6 = ASN1_tag2bit(local_2c[0]);
        if ((uVar6 & param_4->utype) != 0) {
          uVar7 = asn1_d2i_ex_primitive(param_1,param_2,local_3c[0],param_4,local_2c[0],0,0,param_8)
          ;
          return uVar7;
        }
        if (param_7 != '\0') {
          return 0xffffffff;
        }
        ERR_put_error(0xd,0x78,0x8c,"crypto/asn1/tasn_dec.c",0xd9);
      }
      else {
        if (param_7 != '\0') {
          return 0xffffffff;
        }
        ERR_put_error(0xd,0x78,0x8b,"crypto/asn1/tasn_dec.c",0xd0);
      }
    }
  }
  else {
    ERR_put_error(0xd,0x78,0xc9,"crypto/asn1/tasn_dec.c",0xa0);
  }
LAB_00107b6e:
  ERR_add_error_data(2,"Type=",param_4->sname);
LAB_00107b7e:
  return 0;
}

