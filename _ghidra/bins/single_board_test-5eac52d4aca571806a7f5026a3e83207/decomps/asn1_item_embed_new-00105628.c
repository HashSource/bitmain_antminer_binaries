
undefined4 asn1_item_embed_new(ASN1_VALUE *param_1,ASN1_ITEM *param_2,ASN1_VALUE *param_3)

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
  
  pvVar7 = param_2->funcs;
  if (pvVar7 == (void *)0x0) {
    switch(param_2->itype) {
    case '\0':
      goto switchD_0010564a_caseD_0;
    case '\x01':
    case '\x06':
      pcVar8 = (code *)0x0;
      if (param_3 == (ASN1_VALUE *)0x0) goto LAB_00105746;
LAB_00105874:
      memset(*(ASN1_VALUE **)param_1,0,param_2->size);
      iVar1 = asn1_do_lock((ASN1_VALUE **)param_1,0,param_2);
      if (iVar1 < 0) goto LAB_00105694;
LAB_0010576a:
      asn1_enc_init((ASN1_VALUE **)param_1,param_2);
      if (0 < param_2->tcount) {
        iVar1 = 0;
        pAVar6 = param_2->templates + 3;
        do {
          pAVar3 = (ASN1_VALUE *)asn1_get_field_ptr((ASN1_VALUE **)param_1,pAVar6 + -3);
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
                if (iVar5 == 0) goto LAB_001058b4;
              }
              else {
                pAVar3 = (ASN1_VALUE *)OPENSSL_sk_new_null();
                if (pAVar3 == (ASN1_VALUE *)0x0) {
                  ERR_put_error(0xd,0x85,0x41,"crypto/asn1/tasn_new.c",0xe7);
LAB_001058b4:
                  asn1_item_embed_free(param_1,param_2,param_3);
                  goto LAB_00105694;
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
        } while (iVar1 < param_2->tcount);
      }
      break;
    case '\x02':
      pcVar8 = (code *)0x0;
      if (param_3 == (ASN1_VALUE *)0x0) goto LAB_001056d8;
LAB_00105868:
      memset(*(ASN1_VALUE **)param_1,0,param_2->size);
LAB_001056ea:
      asn1_set_choice_selector((ASN1_VALUE **)param_1,-1,param_2);
      break;
    default:
      return 1;
    case '\x05':
      goto switchD_0010564a_caseD_5;
    }
    if (pcVar8 == (code *)0x0) {
      return 1;
    }
    iVar1 = (*pcVar8)(1,param_1,param_2,0);
    if (iVar1 != 0) {
      return 1;
    }
    asn1_item_embed_free(param_1,param_2,param_3);
LAB_00105712:
    ERR_put_error(0xd,0x79,100,"crypto/asn1/tasn_new.c",0xa1);
    return 0;
  }
  pcVar8 = *(code **)((int)pvVar7 + 0x10);
  if (pcVar8 == (code *)0x0) {
    switch(param_2->itype) {
    case '\0':
      goto switchD_0010564a_caseD_0;
    case '\x01':
    case '\x06':
      goto switchD_00105830_caseD_1;
    case '\x02':
      goto switchD_00105830_caseD_2;
    default:
      goto switchD_0010564a_caseD_3;
    case '\x04':
      goto switchD_0010564a_caseD_4;
    case '\x05':
      goto switchD_0010564a_caseD_5;
    }
  }
  switch(param_2->itype) {
  case '\0':
switchD_0010564a_caseD_0:
    pAVar6 = param_2->templates;
    if (pAVar6 != (ASN1_TEMPLATE *)0x0) {
      uVar4 = pAVar6->flags;
      bVar9 = (uVar4 & 0x1000) != 0;
      if (bVar9) {
        local_2c[0] = param_1;
      }
      if (bVar9) {
        param_1 = (ASN1_VALUE *)local_2c;
      }
      if ((uVar4 & 1) != 0) {
        if ((uVar4 & 0x306) != 0) {
          *(ASN1_VALUE **)param_1 = (ASN1_VALUE *)0x0;
          return 1;
        }
        asn1_item_clear(param_1);
        return 1;
      }
      pAVar2 = (ASN1_VALUE *)0x0;
      if ((uVar4 & 0x300) != 0) {
LAB_00105864:
        *(ASN1_VALUE **)param_1 = pAVar2;
        return 1;
      }
      if ((uVar4 & 6) == 0) {
        iVar1 = asn1_item_embed_new(param_1,pAVar6->item);
        if (iVar1 != 0) {
          return 1;
        }
      }
      else {
        pAVar2 = (ASN1_VALUE *)OPENSSL_sk_new_null();
        if (pAVar2 != (ASN1_VALUE *)0x0) goto LAB_00105864;
        ERR_put_error(0xd,0x85,0x41,"crypto/asn1/tasn_new.c",0xe7);
      }
      goto LAB_00105694;
    }
  case '\x05':
switchD_0010564a_caseD_5:
    iVar1 = asn1_primitive_new(param_1,param_2,param_3);
    break;
  case '\x01':
  case '\x06':
    iVar1 = (*pcVar8)(0,param_1,param_2);
    if (iVar1 == 0) goto LAB_00105712;
    if (iVar1 == 2) {
      return 1;
    }
switchD_00105830_caseD_1:
    if (param_3 != (ASN1_VALUE *)0x0) goto LAB_00105874;
LAB_00105746:
    pAVar2 = (ASN1_VALUE *)CRYPTO_zalloc(param_2->size,"crypto/asn1/tasn_new.c",0x7a);
    *(ASN1_VALUE **)param_1 = pAVar2;
    if (pAVar2 == (ASN1_VALUE *)0x0) goto LAB_00105694;
    iVar1 = asn1_do_lock((ASN1_VALUE **)param_1,(int)param_3,param_2);
    if (iVar1 < 0) {
      CRYPTO_free(*(ASN1_VALUE **)param_1);
      *(ASN1_VALUE **)param_1 = param_3;
      goto LAB_00105694;
    }
    goto LAB_0010576a;
  case '\x02':
    iVar1 = (*pcVar8)(0,param_1,param_2);
    if (iVar1 == 0) goto LAB_00105712;
    if (iVar1 == 2) {
      return 1;
    }
switchD_00105830_caseD_2:
    if (param_3 != (ASN1_VALUE *)0x0) goto LAB_00105868;
LAB_001056d8:
    pAVar2 = (ASN1_VALUE *)CRYPTO_zalloc(param_2->size,"crypto/asn1/tasn_new.c",0x61);
    *(ASN1_VALUE **)param_1 = pAVar2;
    if (pAVar2 == (ASN1_VALUE *)0x0) goto LAB_00105694;
    goto LAB_001056ea;
  default:
    goto switchD_0010564a_caseD_3;
  case '\x04':
switchD_0010564a_caseD_4:
    if (*(code **)((int)pvVar7 + 4) == (code *)0x0) {
      return 1;
    }
    iVar1 = (**(code **)((int)pvVar7 + 4))(param_1,param_2);
  }
  if (iVar1 != 0) {
switchD_0010564a_caseD_3:
    return 1;
  }
LAB_00105694:
  ERR_put_error(0xd,0x79,0x41,"crypto/asn1/tasn_new.c",0x98);
  return 0;
}

