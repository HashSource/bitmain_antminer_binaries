
int ASN1_item_ex_d2i(ASN1_VALUE **pval,uchar **in,long len,ASN1_ITEM *it,int tag,int aclass,char opt
                    ,ASN1_TLC *ctx)

{
  char cVar1;
  uchar *puVar2;
  ASN1_TEMPLATE *pAVar3;
  ASN1_VALUE **ppAVar4;
  ulong uVar5;
  uint uVar6;
  int iVar7;
  ASN1_TEMPLATE *pAVar8;
  code *pcVar9;
  int iVar10;
  code *pcVar11;
  char local_37;
  char local_36;
  char local_35;
  long local_34;
  uchar *local_30;
  int local_2c [2];
  
  pcVar9 = (code *)it->funcs;
  local_30 = (uchar *)0x0;
  local_34 = len;
  if (pval == (ASN1_VALUE **)0x0) {
    iVar7 = 0;
    goto LAB_00103fe0;
  }
  pcVar11 = pcVar9;
  if (pcVar9 != (code *)0x0) {
    pcVar11 = *(code **)(pcVar9 + 0x10);
  }
  switch(it->itype) {
  case '\0':
    if (it->templates == (ASN1_TEMPLATE *)0x0) {
      iVar7 = asn1_d2i_ex_primitive(pval,in,len,it,tag,aclass,opt,ctx);
    }
    else {
      if (opt != '\0' || tag != -1) {
        ERR_put_error(0xd,0x78,0xaa,"crypto/asn1/tasn_dec.c",0xaf);
        goto LAB_00103fd0;
      }
      iVar7 = asn1_template_ex_d2i(pval,in,len,it->templates,0,ctx,1);
    }
    break;
  case '\x01':
  case '\x06':
    local_30 = *in;
    if (tag == -1) {
      aclass = 0;
      tag = 0x10;
    }
    iVar7 = asn1_check_tlen(&local_34,0,0,&local_36,&local_35,&local_30,len,tag,aclass,opt,ctx);
    if (iVar7 == 0) {
      iVar7 = 0x135;
LAB_001041fe:
      ERR_put_error(0xd,0x78,0x3a,"crypto/asn1/tasn_dec.c",iVar7);
    }
    else {
      if (iVar7 == -1) goto LAB_0010454a;
      cVar1 = local_36;
      if ((pcVar9 != (code *)0x0) && (*(int *)(pcVar9 + 4) << 0x1d < 0)) {
        local_34 = len - ((int)local_30 - (int)*in);
        cVar1 = '\x01';
      }
      if (local_35 == '\0') {
        ERR_put_error(0xd,0x78,0x95,"crypto/asn1/tasn_dec.c",0x141);
      }
      else {
        if ((*pval == (ASN1_VALUE *)0x0) && (iVar7 = ASN1_item_ex_new(pval,it), iVar7 == 0)) {
          iVar7 = 0x146;
          goto LAB_001041fe;
        }
        if ((pcVar11 != (code *)0x0) && (iVar7 = (*pcVar11)(4,pval,it,0), iVar7 == 0))
        goto LAB_00104246;
        iVar7 = it->tcount;
        pAVar8 = it->templates;
        if (iVar7 < 1) {
          iVar10 = 0;
        }
        else {
          pAVar8 = pAVar8 + 4;
          iVar10 = 0;
          do {
            HintPreloadData(pAVar8);
            if ((pAVar8[-4].flags & 0x300) != 0) {
              pAVar3 = asn1_do_adb(pval,pAVar8 + -4,0);
              if (pAVar3 != (ASN1_TEMPLATE *)0x0) {
                ppAVar4 = asn1_get_field_ptr(pval,pAVar3);
                asn1_template_free(ppAVar4,pAVar3);
              }
              iVar7 = it->tcount;
            }
            iVar10 = iVar10 + 1;
            pAVar8 = pAVar8 + 1;
          } while (iVar10 < iVar7);
          pAVar8 = it->templates;
          iVar10 = 0;
          if (0 < iVar7) {
            do {
              pAVar3 = asn1_do_adb(pval,pAVar8,1);
              if (pAVar3 == (ASN1_TEMPLATE *)0x0) goto LAB_00103fd0;
              ppAVar4 = asn1_get_field_ptr(pval,pAVar3);
              puVar2 = local_30;
              if (local_34 == 0) {
                if (local_36 == '\0') goto LAB_001043a4;
                goto LAB_00104488;
              }
              if (((1 < local_34) && (*local_30 == '\0')) && (local_30[1] == '\0')) {
                local_30 = local_30 + 2;
                if (local_36 == '\0') {
                  ERR_put_error(0xd,0x78,0x9f,"crypto/asn1/tasn_dec.c",0x168);
                  goto LAB_00103fd0;
                }
                local_34 = local_34 + -2;
                local_36 = '\0';
                goto LAB_00104398;
              }
              if (iVar10 == it->tcount + -1) {
                uVar6 = 0;
              }
              else {
                uVar6 = pAVar3->flags & 1;
              }
              iVar7 = asn1_template_ex_d2i(ppAVar4,&local_30,local_34,pAVar3,uVar6,ctx,1);
              if (iVar7 == 0) goto LAB_0010422e;
              if (iVar7 == -1) {
                asn1_template_free(ppAVar4,pAVar3);
              }
              else {
                local_34 = local_34 - ((int)local_30 - (int)puVar2);
              }
              iVar10 = iVar10 + 1;
              pAVar8 = pAVar8 + 1;
            } while (iVar10 < it->tcount);
          }
        }
        if (local_36 != '\0') {
          if (((local_34 < 2) || (*local_30 != '\0')) || (local_30[1] != '\0')) {
LAB_00104488:
            ERR_put_error(0xd,0x78,0x89,"crypto/asn1/tasn_dec.c",400);
            goto LAB_00103fd0;
          }
          local_30 = local_30 + 2;
        }
LAB_00104398:
        if ((cVar1 != '\0') || (local_34 == 0)) {
LAB_001043a4:
          if (iVar10 < it->tcount) {
            do {
              iVar10 = iVar10 + 1;
              pAVar3 = asn1_do_adb(pval,pAVar8,1);
              pAVar8 = pAVar8 + 1;
              if (pAVar3 == (ASN1_TEMPLATE *)0x0) goto LAB_00103fd0;
              if (-1 < (int)(pAVar3->flags << 0x1f)) {
                ERR_put_error(0xd,0x78,0x79,"crypto/asn1/tasn_dec.c",0x1a9);
LAB_0010422e:
                iVar7 = 0;
                ERR_add_error_data(4,"Field=",pAVar3->field_name,", Type=",it->sname);
                goto LAB_00103fe0;
              }
              ppAVar4 = asn1_get_field_ptr(pval,pAVar3);
              asn1_template_free(ppAVar4,pAVar3);
            } while (iVar10 < it->tcount);
          }
          iVar7 = asn1_enc_save(pval,*in,(int)local_30 - (int)*in,it);
          if (iVar7 != 0) goto joined_r0x0010441a;
          goto LAB_00104246;
        }
        ERR_put_error(0xd,0x78,0x94,"crypto/asn1/tasn_dec.c",0x195);
      }
    }
    goto LAB_00103fd0;
  case '\x02':
    if (tag == -1) {
      if ((pcVar11 == (code *)0x0) || (iVar7 = (*pcVar11)(4,pval,it,0), iVar7 != 0)) {
        if (*pval == (ASN1_VALUE *)0x0) {
          iVar7 = ASN1_item_ex_new(pval,it);
          if (iVar7 == 0) {
            iVar7 = 0xf9;
            goto LAB_001041fe;
          }
          iVar7 = it->tcount;
        }
        else {
          iVar10 = asn1_get_choice_selector(pval,it);
          iVar7 = it->tcount;
          if ((-1 < iVar10) && (iVar10 < iVar7)) {
            pAVar3 = it->templates;
            ppAVar4 = asn1_get_field_ptr(pval,pAVar3 + iVar10);
            asn1_template_free(ppAVar4,pAVar3 + iVar10);
            asn1_set_choice_selector(pval,-1,it);
            iVar7 = it->tcount;
          }
        }
        local_30 = *in;
        pAVar3 = it->templates;
        iVar10 = 0;
        if (0 < iVar7) {
          do {
            ppAVar4 = asn1_get_field_ptr(pval,pAVar3);
            iVar7 = asn1_template_ex_d2i(ppAVar4,&local_30,local_34,pAVar3,1,ctx,1);
            if (iVar7 != -1) {
              if (iVar7 < 1) {
                asn1_template_free(ppAVar4,pAVar3);
                ERR_put_error(0xd,0x78,0x3a,"crypto/asn1/tasn_dec.c",0x110);
                if (pAVar3 == (ASN1_TEMPLATE *)0x0) goto LAB_00103fd0;
                goto LAB_0010422e;
              }
              iVar7 = it->tcount;
              break;
            }
            iVar7 = it->tcount;
            iVar10 = iVar10 + 1;
            pAVar3 = pAVar3 + 1;
          } while (iVar10 < iVar7);
        }
        if (iVar10 == iVar7) {
          if (opt != '\0') {
            ASN1_item_ex_free(pval,it);
            goto LAB_0010454a;
          }
          ERR_put_error(0xd,0x78,0x8f,"crypto/asn1/tasn_dec.c",0x11c);
          goto LAB_00103fd0;
        }
        asn1_set_choice_selector(pval,iVar10,it);
joined_r0x0010441a:
        if ((pcVar11 == (code *)0x0) || (iVar7 = (*pcVar11)(5,pval,it,0), iVar7 != 0)) {
          *in = local_30;
          return 1;
        }
      }
LAB_00104246:
      ERR_put_error(0xd,0x78,100,"crypto/asn1/tasn_dec.c",0x1b9);
      goto LAB_00103fd0;
    }
    iVar7 = 0xe9;
    goto LAB_00103fc4;
  default:
    iVar7 = 0;
    goto LAB_00103fe0;
  case '\x04':
    iVar7 = (**(code **)(pcVar9 + 0x10))(pval,in,len,it,tag,aclass,opt,ctx);
    break;
  case '\x05':
    if (tag == -1) {
      local_30 = *in;
      iVar7 = asn1_check_tlen_constprop_1(0,local_2c,&local_37,0,0,&local_30,len,1,ctx);
      if (iVar7 != 0) {
        if (local_37 == '\0') {
          uVar5 = ASN1_tag2bit(local_2c[0]);
          if ((uVar5 & it->utype) != 0) {
            iVar7 = asn1_d2i_ex_primitive(pval,in,local_34,it,local_2c[0],0,0,ctx);
            break;
          }
          if (opt != '\0') goto LAB_0010454a;
          ERR_put_error(0xd,0x78,0x8c,"crypto/asn1/tasn_dec.c",0xd9);
        }
        else {
          if (opt != '\0') {
LAB_0010454a:
            iVar7 = -1;
            goto LAB_00103fe0;
          }
          ERR_put_error(0xd,0x78,0x8b,"crypto/asn1/tasn_dec.c",0xd0);
        }
        goto LAB_00103fd0;
      }
      iVar7 = 199;
      goto LAB_001041fe;
    }
    iVar7 = 0xbe;
LAB_00103fc4:
    ERR_put_error(0xd,0x78,0xe6,"crypto/asn1/tasn_dec.c",iVar7);
LAB_00103fd0:
    iVar7 = 0;
    ERR_add_error_data(2,"Type=",it->sname);
    goto LAB_00103fe0;
  }
  if (0 < iVar7) {
    return iVar7;
  }
LAB_00103fe0:
  ASN1_item_ex_free(pval,it);
  return iVar7;
}

