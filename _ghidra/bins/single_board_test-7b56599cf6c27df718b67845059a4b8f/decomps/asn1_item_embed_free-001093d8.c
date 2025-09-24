
void asn1_item_embed_free(ASN1_VALUE **param_1,ASN1_ITEM *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  ASN1_TEMPLATE *tt;
  ASN1_VALUE **ppAVar3;
  void *pvVar4;
  ASN1_TEMPLATE *pAVar5;
  code *pcVar6;
  
  pvVar4 = param_2->funcs;
  if (param_1 == (ASN1_VALUE **)0x0) {
    return;
  }
  cVar1 = param_2->itype;
  if (cVar1 != '\0') {
    if (*param_1 == (ASN1_VALUE *)0x0) {
      return;
    }
    if (pvVar4 != (void *)0x0) goto LAB_001093ee;
    switch(cVar1) {
    case '\x01':
    case '\x06':
switchD_0010953a_caseD_1:
      iVar2 = asn1_do_lock(param_1,-1,param_2);
      if (iVar2 != 0) {
        return;
      }
      asn1_enc_free(param_1,param_2);
      if (param_2->tcount < 1) goto LAB_00109518;
      pAVar5 = param_2->templates + param_2->tcount;
      pcVar6 = (code *)0x0;
LAB_001094da:
      iVar2 = 0;
      do {
        pAVar5 = pAVar5 + -1;
        tt = asn1_do_adb(param_1,pAVar5,0);
        iVar2 = iVar2 + 1;
        if (tt != (ASN1_TEMPLATE *)0x0) {
          ppAVar3 = asn1_get_field_ptr(param_1,tt);
          asn1_template_free(ppAVar3,tt);
        }
      } while (iVar2 < param_2->tcount);
      if (pcVar6 == (code *)0x0) goto LAB_00109518;
      break;
    case '\x02':
switchD_0010953a_caseD_2:
      iVar2 = asn1_get_choice_selector(param_1,param_2);
      if ((-1 < iVar2) && (iVar2 < param_2->tcount)) {
        pcVar6 = (code *)0x0;
LAB_001095b2:
        pAVar5 = param_2->templates;
        ppAVar3 = asn1_get_field_ptr(param_1,pAVar5 + iVar2);
        asn1_template_free(ppAVar3,pAVar5 + iVar2);
        if (pcVar6 != (code *)0x0) goto LAB_0010942e;
      }
joined_r0x001095d4:
      if (param_3 == 0) {
        CRYPTO_free(*param_1);
        *param_1 = (ASN1_VALUE *)0x0;
        return;
      }
    default:
      goto switchD_001093fe_caseD_3;
    case '\x05':
      goto switchD_001093fe_caseD_5;
    }
LAB_0010950e:
    (*pcVar6)(3,param_1,param_2,0);
LAB_00109518:
    if (param_3 != 0) {
      return;
    }
    CRYPTO_free(*param_1);
    *param_1 = (ASN1_VALUE *)0x0;
    return;
  }
  if (pvVar4 == (void *)0x0) {
switchD_001093fe_caseD_0:
    if (param_2->templates != (ASN1_TEMPLATE *)0x0) {
      asn1_template_free(param_1);
      return;
    }
switchD_001093fe_caseD_5:
    asn1_primitive_free(param_1,param_2,param_3);
    return;
  }
LAB_001093ee:
  pcVar6 = *(code **)((int)pvVar4 + 0x10);
  if (pcVar6 != (code *)0x0) {
    switch(cVar1) {
    case '\0':
      goto switchD_001093fe_caseD_0;
    case '\x01':
    case '\x06':
      iVar2 = asn1_do_lock(param_1,-1,param_2);
      if (iVar2 != 0) {
        return;
      }
      iVar2 = (*pcVar6)(2,param_1,param_2,0);
      if (iVar2 == 2) {
        return;
      }
      asn1_enc_free(param_1,param_2);
      pAVar5 = param_2->templates + param_2->tcount;
      if (0 < param_2->tcount) goto LAB_001094da;
      goto LAB_0010950e;
    case '\x02':
      iVar2 = (*pcVar6)(2,param_1,param_2,0);
      if (iVar2 == 2) {
        return;
      }
      iVar2 = asn1_get_choice_selector(param_1,param_2);
      if ((-1 < iVar2) && (iVar2 < param_2->tcount)) goto LAB_001095b2;
LAB_0010942e:
      (*pcVar6)(3,param_1,param_2,0);
      goto joined_r0x001095d4;
    default:
      goto switchD_001093fe_caseD_3;
    case '\x04':
switchD_001093fe_caseD_4:
      if (*(code **)((int)pvVar4 + 8) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001094a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)((int)pvVar4 + 8))(param_1,param_2);
        return;
      }
switchD_001093fe_caseD_3:
      return;
    case '\x05':
      goto switchD_001093fe_caseD_5;
    }
  }
  switch(cVar1) {
  case '\0':
    goto switchD_001093fe_caseD_0;
  case '\x01':
  case '\x06':
    goto switchD_0010953a_caseD_1;
  case '\x02':
    goto switchD_0010953a_caseD_2;
  default:
    goto switchD_001093fe_caseD_3;
  case '\x04':
    goto switchD_001093fe_caseD_4;
  case '\x05':
    goto switchD_001093fe_caseD_5;
  }
}

