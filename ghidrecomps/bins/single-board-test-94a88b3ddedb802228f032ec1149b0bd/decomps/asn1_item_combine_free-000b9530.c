
void asn1_item_combine_free(_STACK **param_1,ASN1_ITEM *param_2,int param_3)

{
  int iVar1;
  ASN1_TEMPLATE *pAVar2;
  _STACK **pp_Var3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  _STACK *p_Var7;
  ASN1_TEMPLATE *pAVar8;
  int unaff_r9;
  code *local_38;
  int local_34;
  void *local_2c [2];
  
  pcVar5 = (code *)param_2->funcs;
  if (param_1 == (_STACK **)0x0) {
    return;
  }
  if ((param_2->itype != '\0') && (*param_1 == (_STACK *)0x0)) {
    return;
  }
  local_38 = pcVar5;
  if (pcVar5 != (code *)0x0) {
    local_38 = *(code **)(pcVar5 + 0x10);
  }
  switch(param_2->itype) {
  case '\0':
    pAVar8 = param_2->templates;
    if (pAVar8 != (ASN1_TEMPLATE *)0x0) {
      if ((pAVar8->flags & 6) != 0) {
        p_Var7 = *param_1;
        iVar1 = 0;
        while( true ) {
          iVar4 = sk_num(p_Var7);
          if (iVar4 <= iVar1) break;
          local_2c[0] = sk_value(p_Var7,iVar1);
          asn1_item_combine_free(local_2c,pAVar8->item,0);
          iVar1 = iVar1 + 1;
        }
        sk_free(p_Var7);
        *param_1 = (_STACK *)0x0;
        return;
      }
      asn1_item_combine_free(param_1,pAVar8->item,pAVar8->flags & 0x400);
      return;
    }
  case '\x05':
    if ((pcVar5 == (code *)0x0) || (pcVar5 = *(code **)(pcVar5 + 0xc), pcVar5 == (code *)0x0)) {
      ASN1_primitive_free_part_0(param_1,param_2);
    }
    else {
LAB_000b9566:
      (*pcVar5)(param_1,param_2);
    }
    break;
  case '\x01':
  case '\x06':
    iVar1 = asn1_do_lock((ASN1_VALUE **)param_1,-1,param_2);
    if (0 < iVar1) {
      return;
    }
    if ((local_38 != (code *)0x0) && (iVar1 = (*local_38)(2,param_1,param_2,0), iVar1 == 2)) {
      return;
    }
    asn1_enc_free((ASN1_VALUE **)param_1,param_2);
    iVar1 = param_2->tcount;
    if (0 < iVar1) {
      unaff_r9 = 0;
      local_34 = param_3;
    }
    pAVar8 = param_2->templates + iVar1 + -1;
    if (0 < iVar1) {
      do {
        pAVar2 = asn1_do_adb((ASN1_VALUE **)param_1,pAVar8,0);
        if (pAVar2 != (ASN1_TEMPLATE *)0x0) {
          pp_Var3 = (_STACK **)asn1_get_field_ptr((ASN1_VALUE **)param_1,pAVar2);
          if ((pAVar2->flags & 6) == 0) {
            asn1_item_combine_free(pp_Var3,pAVar2->item,pAVar2->flags & 0x400);
          }
          else {
            p_Var7 = *pp_Var3;
            iVar1 = 0;
            while( true ) {
              iVar4 = sk_num(p_Var7);
              if (iVar4 <= iVar1) break;
              local_2c[0] = sk_value(p_Var7,iVar1);
              asn1_item_combine_free(local_2c,pAVar2->item,0);
              iVar1 = iVar1 + 1;
            }
            sk_free(p_Var7);
            *pp_Var3 = (_STACK *)0x0;
          }
        }
        unaff_r9 = unaff_r9 + 1;
        pAVar8 = pAVar8 + -1;
        param_3 = local_34;
      } while (unaff_r9 < param_2->tcount);
    }
    goto LAB_000b9698;
  case '\x02':
    if ((local_38 != (code *)0x0) && (iVar1 = (*local_38)(2,param_1,param_2,0), iVar1 == 2)) {
      return;
    }
    iVar1 = asn1_get_choice_selector((ASN1_VALUE **)param_1,param_2);
    if ((-1 < iVar1) && (iVar1 < param_2->tcount)) {
      pAVar8 = param_2->templates;
      pAVar2 = pAVar8 + iVar1;
      pp_Var3 = (_STACK **)asn1_get_field_ptr((ASN1_VALUE **)param_1,pAVar2);
      uVar6 = pAVar8[iVar1].flags;
      if ((uVar6 & 6) == 0) {
        asn1_item_combine_free(pp_Var3,pAVar2->item,uVar6 & 0x400);
      }
      else {
        p_Var7 = *pp_Var3;
        iVar1 = 0;
        while( true ) {
          iVar4 = sk_num(p_Var7);
          if (iVar4 <= iVar1) break;
          local_2c[0] = sk_value(p_Var7,iVar1);
          asn1_item_combine_free(local_2c,pAVar2->item,0);
          iVar1 = iVar1 + 1;
        }
        sk_free(p_Var7);
        *pp_Var3 = (_STACK *)0x0;
      }
    }
LAB_000b9698:
    if (local_38 != (code *)0x0) {
      (*local_38)(3,param_1,param_2,0);
    }
    if (param_3 == 0) {
      CRYPTO_free(*param_1);
      *param_1 = (_STACK *)0x0;
    }
    break;
  case '\x03':
    if (pcVar5 == (code *)0x0) {
      return;
    }
    if (*(code **)(pcVar5 + 4) == (code *)0x0) {
      return;
    }
    (**(code **)(pcVar5 + 4))(*param_1);
    return;
  case '\x04':
    if (pcVar5 == (code *)0x0) {
      return;
    }
    pcVar5 = *(code **)(pcVar5 + 8);
    if (pcVar5 == (code *)0x0) {
      return;
    }
    goto LAB_000b9566;
  default:
    break;
  }
  return;
}

