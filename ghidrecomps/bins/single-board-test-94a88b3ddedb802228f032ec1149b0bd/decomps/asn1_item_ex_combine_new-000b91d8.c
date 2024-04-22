
/* WARNING: Type propagation algorithm not settling */

undefined4 asn1_item_ex_combine_new(_STACK **param_1,ASN1_ITEM *param_2,int param_3)

{
  int iVar1;
  _STACK *p_Var2;
  _STACK **pp_Var3;
  int iVar4;
  uint uVar5;
  code **ppcVar6;
  ASN1_TEMPLATE *pAVar7;
  code **ppcVar8;
  
  ppcVar6 = (code **)param_2->funcs;
  ppcVar8 = ppcVar6;
  if (ppcVar6 != (code **)0x0) {
    ppcVar8 = (code **)ppcVar6[4];
  }
  switch(param_2->itype) {
  case '\0':
    pAVar7 = param_2->templates;
    if (pAVar7 == (ASN1_TEMPLATE *)0x0) goto switchD_000b91f4_caseD_5;
    uVar5 = pAVar7->flags;
    if ((uVar5 & 1) != 0) {
      if ((uVar5 & 0x306) != 0) {
        *param_1 = (_STACK *)0x0;
        return 1;
      }
      asn1_item_clear(param_1,pAVar7->item);
      return 1;
    }
    if ((uVar5 & 0x300) != 0) {
      *param_1 = (_STACK *)0x0;
      return 1;
    }
    if ((uVar5 & 6) != 0) {
      p_Var2 = sk_new_null();
      if (p_Var2 != (_STACK *)0x0) {
        *param_1 = p_Var2;
        return 1;
      }
LAB_000b93f4:
      ERR_put_error(0xd,0x85,0x41,DAT_000b9410,0x115);
      goto LAB_000b922a;
    }
    p_Var2 = (_STACK *)asn1_item_ex_combine_new(param_1,pAVar7->item,uVar5 & 0x400);
    break;
  case '\x01':
  case '\x06':
    if (ppcVar8 != (code **)0x0) {
      iVar1 = (*(code *)ppcVar8)(0,param_1,param_2,0);
      if (iVar1 == 0) goto LAB_000b932a;
      if (iVar1 == 2) {
        return 1;
      }
    }
    if (param_3 == 0) {
      p_Var2 = (_STACK *)CRYPTO_malloc(param_2->size,DAT_000b9410,0xb3);
      *param_1 = p_Var2;
      if (p_Var2 == (_STACK *)0x0) goto LAB_000b922a;
      memset(p_Var2,0,param_2->size);
      asn1_do_lock((ASN1_VALUE **)param_1,0,param_2);
      asn1_enc_init((ASN1_VALUE **)param_1,param_2);
    }
    pAVar7 = param_2->templates;
    if (0 < param_2->tcount) {
      iVar1 = 0;
      do {
        pp_Var3 = (_STACK **)asn1_get_field_ptr((ASN1_VALUE **)param_1,pAVar7);
        uVar5 = pAVar7->flags;
        HintPreloadData(&pAVar7[3].item);
        if ((uVar5 & 1) == 0) {
          if ((uVar5 & 0x300) == 0) {
            if ((uVar5 & 6) == 0) {
              iVar4 = asn1_item_ex_combine_new(pp_Var3,pAVar7->item,uVar5 & 0x400);
              if (iVar4 == 0) goto LAB_000b922a;
            }
            else {
              p_Var2 = sk_new_null();
              if (p_Var2 == (_STACK *)0x0) goto LAB_000b93f4;
              *pp_Var3 = p_Var2;
            }
          }
          else {
            *pp_Var3 = (_STACK *)0x0;
          }
        }
        else if ((uVar5 & 0x306) == 0) {
          asn1_item_clear(pp_Var3,pAVar7->item);
        }
        else {
          *pp_Var3 = (_STACK *)0x0;
        }
        iVar1 = iVar1 + 1;
        pAVar7 = pAVar7 + 1;
      } while (iVar1 < param_2->tcount);
    }
    goto joined_r0x000b9316;
  case '\x02':
    if (ppcVar8 != (code **)0x0) {
      iVar1 = (*(code *)ppcVar8)(0,param_1,param_2,0);
      if (iVar1 == 0) goto LAB_000b932a;
      if (iVar1 == 2) {
        return 1;
      }
    }
    if (param_3 == 0) {
      p_Var2 = (_STACK *)CRYPTO_malloc(param_2->size,DAT_000b9410,0x9a);
      *param_1 = p_Var2;
      if (p_Var2 == (_STACK *)0x0) goto LAB_000b922a;
      memset(p_Var2,0,param_2->size);
    }
    asn1_set_choice_selector((ASN1_VALUE **)param_1,-1,param_2);
joined_r0x000b9316:
    if (ppcVar8 == (code **)0x0) {
      return 1;
    }
    iVar1 = (*(code *)ppcVar8)(1,param_1,param_2,0);
    if (iVar1 != 0) {
      return 1;
    }
LAB_000b932a:
    ERR_put_error(0xd,0x79,100,DAT_000b9410,0xd2);
    ASN1_item_ex_free((ASN1_VALUE **)param_1,param_2);
    return 0;
  case '\x03':
    if (ppcVar6 == (code **)0x0) {
      return 1;
    }
    if (*ppcVar6 == (code *)0x0) {
      return 1;
    }
    p_Var2 = (_STACK *)(**ppcVar6)();
    *param_1 = p_Var2;
    break;
  case '\x04':
    if (ppcVar6 == (code **)0x0) {
      return 1;
    }
    if (ppcVar6[1] == (code *)0x0) {
      return 1;
    }
    p_Var2 = (_STACK *)(*ppcVar6[1])(param_1,param_2);
    break;
  case '\x05':
switchD_000b91f4_caseD_5:
    p_Var2 = (_STACK *)ASN1_primitive_new((ASN1_VALUE **)param_1,param_2);
    break;
  default:
    goto switchD_000b91f4_caseD_7;
  }
  if (p_Var2 == (_STACK *)0x0) {
LAB_000b922a:
    ERR_put_error(0xd,0x79,0x41,DAT_000b9410,0xca);
    return 0;
  }
switchD_000b91f4_caseD_7:
  return 1;
}

