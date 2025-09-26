
/* WARNING: Type propagation algorithm not settling */

undefined4 asn1_item_ex_combine_new(ASN1_VALUE **param_1,ASN1_ITEM *param_2,int param_3)

{
  int iVar1;
  _STACK *p_Var2;
  ASN1_VALUE **ppAVar3;
  int iVar4;
  ASN1_VALUE *pAVar5;
  uint uVar6;
  code *pcVar7;
  ASN1_TEMPLATE *pAVar8;
  code *pcVar9;
  
  pcVar7 = (code *)param_2->funcs;
  pcVar9 = pcVar7;
  if (pcVar7 != (code *)0x0) {
    pcVar9 = *(code **)(pcVar7 + 0x10);
  }
  switch(param_2->itype) {
  case '\0':
    pAVar8 = param_2->templates;
    if (pAVar8 == (ASN1_TEMPLATE *)0x0) goto switchD_001580f8_caseD_5;
    uVar6 = pAVar8->flags;
    if ((uVar6 & 1) != 0) {
      if ((uVar6 & 0x306) != 0) {
        *param_1 = (ASN1_VALUE *)0x0;
        return 1;
      }
      asn1_item_clear(param_1,pAVar8->item);
      return 1;
    }
    if ((uVar6 & 0x300) != 0) {
      *param_1 = (ASN1_VALUE *)0x0;
      return 1;
    }
    if ((uVar6 & 6) != 0) {
      p_Var2 = sk_new_null();
      if (p_Var2 != (_STACK *)0x0) {
        *param_1 = (ASN1_VALUE *)p_Var2;
        return 1;
      }
LAB_001582f8:
      ERR_put_error(0xd,0x85,0x41,"tasn_new.c",0x115);
      goto LAB_0015812e;
    }
    pAVar5 = (ASN1_VALUE *)asn1_item_ex_combine_new(param_1,pAVar8->item,uVar6 & 0x400);
    break;
  case '\x01':
  case '\x06':
    if (pcVar9 != (code *)0x0) {
      iVar1 = (*pcVar9)(0,param_1,param_2,0);
      if (iVar1 == 0) goto LAB_0015822e;
      if (iVar1 == 2) {
        return 1;
      }
    }
    if (param_3 == 0) {
      pAVar5 = (ASN1_VALUE *)CRYPTO_malloc(param_2->size,"tasn_new.c",0xb3);
      *param_1 = pAVar5;
      if (pAVar5 == (ASN1_VALUE *)0x0) goto LAB_0015812e;
      memset(pAVar5,0,param_2->size);
      asn1_do_lock(param_1,0,param_2);
      asn1_enc_init(param_1,param_2);
    }
    pAVar8 = param_2->templates;
    if (0 < param_2->tcount) {
      iVar1 = 0;
      do {
        ppAVar3 = asn1_get_field_ptr(param_1,pAVar8);
        uVar6 = pAVar8->flags;
        HintPreloadData(&pAVar8[3].item);
        if ((uVar6 & 1) == 0) {
          if ((uVar6 & 0x300) == 0) {
            if ((uVar6 & 6) == 0) {
              iVar4 = asn1_item_ex_combine_new(ppAVar3,pAVar8->item,uVar6 & 0x400);
              if (iVar4 == 0) goto LAB_0015812e;
            }
            else {
              p_Var2 = sk_new_null();
              if (p_Var2 == (_STACK *)0x0) goto LAB_001582f8;
              *ppAVar3 = (ASN1_VALUE *)p_Var2;
            }
          }
          else {
            *ppAVar3 = (ASN1_VALUE *)0x0;
          }
        }
        else if ((uVar6 & 0x306) == 0) {
          asn1_item_clear(ppAVar3,pAVar8->item);
        }
        else {
          *ppAVar3 = (ASN1_VALUE *)0x0;
        }
        iVar1 = iVar1 + 1;
        pAVar8 = pAVar8 + 1;
      } while (iVar1 < param_2->tcount);
    }
    goto joined_r0x0015821a;
  case '\x02':
    if (pcVar9 != (code *)0x0) {
      iVar1 = (*pcVar9)(0,param_1,param_2,0);
      if (iVar1 == 0) goto LAB_0015822e;
      if (iVar1 == 2) {
        return 1;
      }
    }
    if (param_3 == 0) {
      pAVar5 = (ASN1_VALUE *)CRYPTO_malloc(param_2->size,"tasn_new.c",0x9a);
      *param_1 = pAVar5;
      if (pAVar5 == (ASN1_VALUE *)0x0) goto LAB_0015812e;
      memset(pAVar5,0,param_2->size);
    }
    asn1_set_choice_selector(param_1,-1,param_2);
joined_r0x0015821a:
    if (pcVar9 == (code *)0x0) {
      return 1;
    }
    iVar1 = (*pcVar9)(1,param_1,param_2,0);
    if (iVar1 != 0) {
      return 1;
    }
LAB_0015822e:
    ERR_put_error(0xd,0x79,100,"tasn_new.c",0xd2);
    ASN1_item_ex_free(param_1,param_2);
    return 0;
  case '\x03':
    if (pcVar7 == (code *)0x0) {
      return 1;
    }
    if (*(code **)pcVar7 == (code *)0x0) {
      return 1;
    }
    pAVar5 = (ASN1_VALUE *)(**(code **)pcVar7)();
    *param_1 = pAVar5;
    break;
  case '\x04':
    if (pcVar7 == (code *)0x0) {
      return 1;
    }
    if (*(code **)(pcVar7 + 4) == (code *)0x0) {
      return 1;
    }
    pAVar5 = (ASN1_VALUE *)(**(code **)(pcVar7 + 4))(param_1,param_2);
    break;
  case '\x05':
switchD_001580f8_caseD_5:
    pAVar5 = (ASN1_VALUE *)ASN1_primitive_new(param_1,param_2);
    break;
  default:
    goto LAB_0015811c;
  }
  if (pAVar5 == (ASN1_VALUE *)0x0) {
LAB_0015812e:
    ERR_put_error(0xd,0x79,0x41,"tasn_new.c",0xca);
    return 0;
  }
LAB_0015811c:
  return 1;
}

