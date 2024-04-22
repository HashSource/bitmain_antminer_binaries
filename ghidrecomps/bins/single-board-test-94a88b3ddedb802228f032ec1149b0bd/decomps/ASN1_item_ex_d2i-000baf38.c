
/* WARNING: Type propagation algorithm not settling */

int ASN1_item_ex_d2i(ASN1_VALUE **pval,uchar **in,long len,ASN1_ITEM *it,int tag,int aclass,char opt
                    ,ASN1_TLC *ctx)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  ASN1_VALUE **ppAVar4;
  ASN1_TEMPLATE *pAVar5;
  long lVar6;
  int iVar7;
  uint uVar8;
  ASN1_TEMPLATE *tt;
  byte *pbVar9;
  code *pcVar10;
  code *pcVar11;
  byte *local_4c;
  char local_48 [8];
  char local_40 [8];
  char local_38 [8];
  byte *local_30;
  uint local_2c [2];
  
  pcVar10 = (code *)it->funcs;
  local_30 = (byte *)0x0;
  if (pval == (ASN1_VALUE **)0x0) {
    return 0;
  }
  pcVar11 = pcVar10;
  if (pcVar10 != (code *)0x0) {
    pcVar11 = *(code **)(pcVar10 + 0x10);
  }
  local_4c = (byte *)len;
  switch(it->itype) {
  case '\0':
    if (it->templates == (ASN1_TEMPLATE *)0x0) {
      iVar7 = asn1_d2i_ex_primitive(pval,in,len,it,tag,aclass,opt,ctx);
      return iVar7;
    }
    if (tag == -1 && opt == '\0') {
      iVar7 = asn1_template_ex_d2i(pval,in,len,it->templates,0,ctx);
      return iVar7;
    }
    ERR_put_error(0xd,0x78,0xaa,DAT_000bb224,0xc9);
    goto LAB_000bb002;
  case '\x01':
  case '\x06':
    local_30 = *in;
    if (tag == -1) {
      tag = 0x10;
      aclass = 0;
    }
    iVar3 = asn1_check_tlen(&local_4c,0,0,local_40,local_38,&local_30,len,tag,aclass,opt,ctx);
    iVar7 = 0x174;
    if (iVar3 != 0) {
      if (iVar3 == -1) {
        return -1;
      }
      cVar2 = local_40[0];
      if ((pcVar10 != (code *)0x0) && (*(int *)(pcVar10 + 4) << 0x1d < 0)) {
        local_4c = *in + (len - (int)local_30);
        cVar2 = '\x01';
      }
      if (local_38[0] == '\0') {
        ERR_put_error(0xd,0x78,0x95,DAT_000bb510,0x180);
        goto LAB_000bb002;
      }
      if ((*pval != (ASN1_VALUE *)0x0) || (iVar7 = ASN1_item_ex_new(pval,it), iVar7 != 0)) {
        if ((pcVar11 == (code *)0x0) || (iVar7 = (*pcVar11)(4,pval,it,0), iVar7 != 0)) {
          iVar7 = it->tcount;
          iVar3 = 0;
          tt = it->templates;
          if (0 < iVar7) {
            do {
              iVar3 = iVar3 + 1;
              HintPreloadData(tt + 5);
              if ((tt->flags & 0x300) != 0) {
                pAVar5 = asn1_do_adb(pval,tt,1);
                ppAVar4 = asn1_get_field_ptr(pval,pAVar5);
                ASN1_template_free(ppAVar4,pAVar5);
                iVar7 = it->tcount;
              }
              tt = tt + 1;
            } while (iVar3 < iVar7);
            tt = it->templates;
            iVar3 = 0;
            if (0 < iVar7) {
              do {
                pAVar5 = asn1_do_adb(pval,tt,1);
                if (pAVar5 == (ASN1_TEMPLATE *)0x0) goto LAB_000bb002;
                ppAVar4 = asn1_get_field_ptr(pval,pAVar5);
                pbVar9 = local_30;
                if (local_4c == (byte *)0x0) break;
                if (((1 < (int)local_4c) && (*local_30 == 0)) && (local_30[1] == 0)) {
                  local_30 = local_30 + 2;
                  if (local_40[0] != '\0') {
                    local_4c = local_4c + -2;
                    local_40[0] = '\0';
                    goto LAB_000bb386;
                  }
                  ERR_put_error(0xd,0x78,0x9f,DAT_000bb5a4,0x1a5);
                  goto LAB_000bb002;
                }
                if (it->tcount + -1 == iVar3) {
                  uVar8 = 0;
                }
                else {
                  uVar8 = pAVar5->flags & 1;
                }
                iVar7 = asn1_template_ex_d2i(ppAVar4,&local_30,local_4c,pAVar5,uVar8,ctx);
                if (iVar7 == 0) goto LAB_000bb3e6;
                if (iVar7 == -1) {
                  ASN1_template_free(ppAVar4,pAVar5);
                }
                else {
                  local_4c = pbVar9 + ((int)local_4c - (int)local_30);
                }
                iVar3 = iVar3 + 1;
                tt = tt + 1;
              } while (iVar3 < it->tcount);
            }
          }
          if (local_40[0] != '\0') {
            if ((((int)local_4c < 2) || (*local_30 != 0)) || (local_30[1] != 0)) {
              ERR_put_error(0xd,0x78,0x89,DAT_000bb510,0x1cc);
              goto LAB_000bb002;
            }
            local_30 = local_30 + 2;
          }
LAB_000bb386:
          if ((cVar2 == '\0') && (local_4c != (byte *)0x0)) {
            ERR_put_error(0xd,0x78,0x94,DAT_000bb5a4,0x1d1);
            goto LAB_000bb002;
          }
          if (iVar3 < it->tcount) {
            do {
              iVar3 = iVar3 + 1;
              pAVar5 = asn1_do_adb(pval,tt,1);
              if (pAVar5 == (ASN1_TEMPLATE *)0x0) goto LAB_000bb002;
              tt = tt + 1;
              if (-1 < (int)(pAVar5->flags << 0x1f)) {
                ERR_put_error(0xd,0x78,0x79,DAT_000bb510,0x1e5);
LAB_000bb3e6:
                ASN1_item_ex_free(pval,it);
LAB_000bb3ee:
                ERR_add_error_data(4,DAT_000bb514,pAVar5->field_name,DAT_000bb518,it->sname);
                return 0;
              }
              ppAVar4 = asn1_get_field_ptr(pval,pAVar5);
              ASN1_template_free(ppAVar4,pAVar5);
            } while (iVar3 < it->tcount);
          }
          iVar7 = asn1_enc_save(pval,*in,(int)local_30 - (int)*in,it);
          if (iVar7 != 0) {
            *in = local_30;
            goto joined_r0x000bb174;
          }
        }
        goto LAB_000bb184;
      }
      iVar7 = 0x185;
    }
    break;
  case '\x02':
    if ((pcVar11 != (code *)0x0) && (iVar7 = (*pcVar11)(4,pval,it,0), iVar7 == 0))
    goto LAB_000bb184;
    if (*pval == (ASN1_VALUE *)0x0) {
      iVar7 = ASN1_item_ex_new(pval,it);
      if (iVar7 == 0) {
        iVar7 = 0x13d;
        break;
      }
      iVar7 = it->tcount;
    }
    else {
      iVar3 = asn1_get_choice_selector(pval,it);
      iVar7 = it->tcount;
      if ((-1 < iVar3) && (iVar3 < iVar7)) {
        pAVar5 = it->templates;
        ppAVar4 = asn1_get_field_ptr(pval,pAVar5 + iVar3);
        ASN1_template_free(ppAVar4,pAVar5 + iVar3);
        asn1_set_choice_selector(pval,-1,it);
        iVar7 = it->tcount;
      }
    }
    local_30 = *in;
    pAVar5 = it->templates;
    iVar3 = 0;
    if (0 < iVar7) {
      do {
        ppAVar4 = asn1_get_field_ptr(pval,pAVar5);
        iVar7 = asn1_template_ex_d2i(ppAVar4,&local_30,local_4c,pAVar5,1,ctx);
        if (iVar7 != -1) {
          if (iVar7 < 1) {
            ERR_put_error(0xd,0x78,0x3a,DAT_000bb510,0x150);
            ASN1_item_ex_free(pval,it);
            if (pAVar5 != (ASN1_TEMPLATE *)0x0) goto LAB_000bb3ee;
            goto LAB_000bb00a;
          }
          iVar7 = it->tcount;
          break;
        }
        iVar7 = it->tcount;
        iVar3 = iVar3 + 1;
        pAVar5 = pAVar5 + 1;
      } while (iVar3 < iVar7);
    }
    if (iVar3 == iVar7) {
      if (opt != '\0') {
        ASN1_item_ex_free(pval,it);
        return -1;
      }
      ERR_put_error(0xd,0x78,0x8f,DAT_000bb510,0x15c);
      goto LAB_000bb002;
    }
    asn1_set_choice_selector(pval,iVar3,it);
    *in = local_30;
joined_r0x000bb174:
    if (pcVar11 == (code *)0x0) {
      return 1;
    }
    iVar7 = (*pcVar11)(5,pval,it,0);
    if (iVar7 != 0) {
      return 1;
    }
LAB_000bb184:
    ERR_put_error(0xd,0x78,100,DAT_000bb224,0x1f5);
    goto LAB_000bb002;
  case '\x03':
    if (opt != '\0') {
      local_30 = *in;
      lVar6 = tag;
      if (tag == -1) {
        lVar6 = it->utype;
      }
      iVar3 = asn1_check_tlen(0,0,0,0,0,&local_30,len,lVar6,aclass,1,ctx);
      iVar7 = 0x107;
      if (iVar3 == 0) break;
      if (iVar3 == -1) {
        return -1;
      }
    }
    if (tag == -1) {
      iVar7 = (**(code **)(pcVar10 + 8))(pval,in,local_4c);
    }
    else {
      pbVar9 = *in;
      bVar1 = *pbVar9;
      if (local_30 == (byte *)0x0) {
        iVar7 = 0x11e;
        break;
      }
      *pbVar9 = (byte)it->utype | *local_30 & 0x20;
      iVar7 = (**(code **)(pcVar10 + 8))(pval,in,local_4c);
      *pbVar9 = bVar1;
    }
    if (iVar7 != 0) {
      return 1;
    }
    iVar7 = 0x12d;
    break;
  case '\x04':
    iVar7 = (**(code **)(pcVar10 + 0x10))(pval,in,len,it,tag,aclass,opt,ctx);
    return iVar7;
  case '\x05':
    local_30 = *in;
    iVar3 = asn1_check_tlen_constprop_1(0,local_2c,local_48,0,0,&local_30,len,1,ctx);
    iVar7 = 0xd9;
    if (iVar3 != 0) {
      if (local_48[0] == '\0') {
        if ((local_2c[0] < 0x1f) && ((*(uint *)(DAT_000bb50c + local_2c[0] * 4) & it->utype) != 0))
        {
          iVar7 = asn1_d2i_ex_primitive(pval,in,local_4c,it,local_2c[0],0,0,ctx);
          return iVar7;
        }
        if (opt != '\0') {
          return -1;
        }
        ERR_put_error(0xd,0x78,0x8c,DAT_000bb510,0xea);
      }
      else {
        if (opt != '\0') {
          return -1;
        }
        ERR_put_error(0xd,0x78,0x8b,DAT_000bb224,0xe2);
      }
      goto LAB_000bb002;
    }
    break;
  default:
    return 0;
  }
  ERR_put_error(0xd,0x78,0x3a,DAT_000bb224,iVar7);
LAB_000bb002:
  ASN1_item_ex_free(pval,it);
LAB_000bb00a:
  ERR_add_error_data(2,DAT_000bb228,it->sname);
  return 0;
}

