
int ASN1_item_ex_new(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  int iVar1;
  ASN1_VALUE *pAVar2;
  ASN1_VALUE *pAVar3;
  uint uVar4;
  int iVar5;
  ASN1_TEMPLATE *pAVar6;
  void *pvVar7;
  code *pcVar8;
  bool bVar9;
  ASN1_VALUE *local_2c [2];
  
  pvVar7 = it->funcs;
  if ((pvVar7 == (void *)0x0) || (pcVar8 = *(code **)((int)pvVar7 + 0x10), pcVar8 == (code *)0x0)) {
    switch(it->itype) {
    case '\0':
      goto switchD_00109ba0_caseD_0;
    case '\x01':
    case '\x06':
      pcVar8 = (code *)0x0;
      goto LAB_00109cc0;
    case '\x02':
      pAVar2 = (ASN1_VALUE *)CRYPTO_zalloc(it->size,"crypto/asn1/tasn_new.c",0x61);
      *pval = pAVar2;
      if (pAVar2 != (ASN1_VALUE *)0x0) {
        asn1_set_choice_selector(pval,-1,it);
        return 1;
      }
      goto LAB_00109c1a;
    default:
      goto switchD_00109ba0_caseD_3;
    case '\x04':
      if (pvVar7 == (void *)0x0) {
        return 1;
      }
      goto switchD_00109ba0_caseD_4;
    case '\x05':
      goto switchD_00109ba0_caseD_5;
    }
  }
  switch(it->itype) {
  case '\0':
    goto switchD_00109ba0_caseD_0;
  case '\x01':
  case '\x06':
    iVar1 = (*pcVar8)(0,pval,it);
    if (iVar1 == 0) goto LAB_00109c90;
    if (iVar1 == 2) {
      return 1;
    }
LAB_00109cc0:
    pAVar2 = (ASN1_VALUE *)CRYPTO_zalloc(it->size,"crypto/asn1/tasn_new.c",0x7a);
    *pval = pAVar2;
    if (pAVar2 == (ASN1_VALUE *)0x0) goto LAB_00109c1a;
    iVar1 = asn1_do_lock(pval,0,it);
    if (iVar1 < 0) {
      CRYPTO_free(*pval);
      *pval = (ASN1_VALUE *)0x0;
      goto LAB_00109c1a;
    }
    asn1_enc_init(pval,it);
    if (0 < it->tcount) {
      iVar1 = 0;
      pAVar6 = it->templates + 3;
      do {
        pAVar3 = (ASN1_VALUE *)asn1_get_field_ptr(pval,pAVar6 + -3);
        uVar4 = pAVar6[-3].flags;
        HintPreloadData(pAVar6);
        pAVar2 = pAVar3;
        if ((uVar4 & 0x1000) != 0) {
          pAVar2 = (ASN1_VALUE *)local_2c;
          local_2c[0] = pAVar3;
        }
        if ((uVar4 & 1) == 0) {
          if ((uVar4 & 0x300) == 0) {
            if ((uVar4 & 6) == 0) {
              iVar5 = asn1_item_embed_new(pAVar2);
              if (iVar5 == 0) goto LAB_00109dba;
            }
            else {
              pAVar3 = (ASN1_VALUE *)OPENSSL_sk_new_null();
              if (pAVar3 == (ASN1_VALUE *)0x0) {
                ERR_put_error(0xd,0x85,0x41,"crypto/asn1/tasn_new.c",0xe7);
LAB_00109dba:
                asn1_item_embed_free(pval,it,0);
                goto LAB_00109c1a;
              }
              *(ASN1_VALUE **)pAVar2 = pAVar3;
            }
          }
          else {
            *(ASN1_VALUE **)pAVar2 = (ASN1_VALUE *)0x0;
          }
        }
        else if ((uVar4 & 0x306) == 0) {
          asn1_item_clear(pAVar2,pAVar6[-3].item);
        }
        else {
          *(ASN1_VALUE **)pAVar2 = (ASN1_VALUE *)0x0;
        }
        iVar1 = iVar1 + 1;
        pAVar6 = pAVar6 + 1;
      } while (iVar1 < it->tcount);
    }
    if (pcVar8 == (code *)0x0) {
      return 1;
    }
    goto LAB_00109c78;
  case '\x02':
    iVar1 = (*pcVar8)(0,pval,it);
    if (iVar1 == 0) goto LAB_00109c90;
    if (iVar1 == 2) {
      return 1;
    }
    pAVar2 = (ASN1_VALUE *)CRYPTO_zalloc(it->size,"crypto/asn1/tasn_new.c",0x61);
    *pval = pAVar2;
    if (pAVar2 == (ASN1_VALUE *)0x0) goto LAB_00109c1a;
    asn1_set_choice_selector(pval,-1,it);
LAB_00109c78:
    iVar1 = (*pcVar8)(1,pval,it,0);
    if (iVar1 != 0) {
      return 1;
    }
    asn1_item_embed_free(pval,it,0);
LAB_00109c90:
    ERR_put_error(0xd,0x79,100,"crypto/asn1/tasn_new.c",0xa1);
    return 0;
  default:
    goto switchD_00109ba0_caseD_3;
  case '\x04':
switchD_00109ba0_caseD_4:
    if (*(code **)((int)pvVar7 + 4) == (code *)0x0) {
      return 1;
    }
    iVar1 = (**(code **)((int)pvVar7 + 4))(pval,it);
    break;
  case '\x05':
switchD_00109ba0_caseD_5:
    iVar1 = asn1_primitive_new(pval,it,0);
  }
joined_r0x00109c46:
  if (iVar1 != 0) {
switchD_00109ba0_caseD_3:
    return 1;
  }
LAB_00109c1a:
  ERR_put_error(0xd,0x79,0x41,"crypto/asn1/tasn_new.c",0x98);
  return 0;
switchD_00109ba0_caseD_0:
  pAVar6 = it->templates;
  if (pAVar6 != (ASN1_TEMPLATE *)0x0) {
    uVar4 = pAVar6->flags;
    bVar9 = (uVar4 & 0x1000) != 0;
    if (bVar9) {
      local_2c[0] = (ASN1_VALUE *)pval;
    }
    if (bVar9) {
      pval = local_2c;
    }
    if ((uVar4 & 1) != 0) {
      if ((uVar4 & 0x306) != 0) {
        *pval = (ASN1_VALUE *)0x0;
        return 1;
      }
      asn1_item_clear(pval);
      return 1;
    }
    pAVar2 = (ASN1_VALUE *)0x0;
    if ((uVar4 & 0x300) != 0) {
LAB_00109d9c:
      *pval = pAVar2;
      return 1;
    }
    if ((uVar4 & 6) == 0) {
      iVar1 = asn1_item_embed_new(pval,pAVar6->item);
      if (iVar1 != 0) {
        return 1;
      }
    }
    else {
      pAVar2 = (ASN1_VALUE *)OPENSSL_sk_new_null();
      if (pAVar2 != (ASN1_VALUE *)0x0) goto LAB_00109d9c;
      ERR_put_error(0xd,0x85,0x41,"crypto/asn1/tasn_new.c",0xe7);
    }
    goto LAB_00109c1a;
  }
  iVar1 = asn1_primitive_new(pval,it);
  goto joined_r0x00109c46;
}

