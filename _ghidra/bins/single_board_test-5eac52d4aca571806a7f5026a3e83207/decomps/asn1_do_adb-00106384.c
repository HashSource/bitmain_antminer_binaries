
ASN1_TEMPLATE * asn1_do_adb(ASN1_VALUE **pval,ASN1_TEMPLATE *tt,int nullerr)

{
  ASN1_OBJECT *o;
  int iVar1;
  ASN1_TEMPLATE *pAVar2;
  int *piVar3;
  void *pvVar4;
  ASN1_ITEM_EXP *pAVar5;
  int local_14;
  
  if ((tt->flags & 0x300) == 0) {
    return tt;
  }
  pAVar5 = tt->item;
  o = *(ASN1_OBJECT **)(*pval + pAVar5->utype);
  if (o == (ASN1_OBJECT *)0x0) {
    pAVar2 = (ASN1_TEMPLATE *)pAVar5->sname;
  }
  else {
    if ((int)(tt->flags << 0x17) < 0) {
      local_14 = OBJ_obj2nid(o);
    }
    else {
      local_14 = ASN1_INTEGER_get((ASN1_INTEGER *)o);
    }
    if ((pAVar5->templates != (ASN1_TEMPLATE *)0x0) &&
       (iVar1 = (*(code *)pAVar5->templates)(&local_14), iVar1 == 0)) {
      ERR_put_error(0xd,0x6e,0xa4,"crypto/asn1/tasn_utl.c",0xe2);
      return (ASN1_TEMPLATE *)0x0;
    }
    piVar3 = (int *)pAVar5->tcount;
    if (0 < (int)pAVar5->funcs) {
      if (*piVar3 != local_14) {
        pvVar4 = (void *)0x0;
        do {
          pvVar4 = (void *)((int)pvVar4 + 1);
          piVar3 = piVar3 + 6;
          if (pvVar4 == pAVar5->funcs) goto LAB_001063d6;
        } while (*piVar3 != local_14);
      }
      return (ASN1_TEMPLATE *)(piVar3 + 1);
    }
LAB_001063d6:
    pAVar2 = (ASN1_TEMPLATE *)pAVar5->size;
  }
  if ((pAVar2 == (ASN1_TEMPLATE *)0x0) && (pAVar2 = (ASN1_TEMPLATE *)nullerr, nullerr != 0)) {
    ERR_put_error(0xd,0x6e,0xa4,"crypto/asn1/tasn_utl.c",0xfb);
    pAVar2 = (ASN1_TEMPLATE *)0x0;
  }
  return pAVar2;
}

