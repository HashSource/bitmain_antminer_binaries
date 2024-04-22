
int ASN1_primitive_new(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_STRING *pAVar3;
  code *pcVar4;
  
  if (it == (ASN1_ITEM *)0x0) {
    return 0;
  }
  if ((it->funcs != (void *)0x0) && (pcVar4 = *(code **)((int)it->funcs + 8), pcVar4 != (code *)0x0)
     ) {
    iVar1 = (*pcVar4)();
    return iVar1;
  }
  if (it->itype == '\x05') {
    iVar1 = -1;
switchD_000b9162_caseD_fffffffd:
    pAVar3 = ASN1_STRING_type_new(iVar1);
    if ((it->itype == '\x05') && (pAVar3 != (ASN1_STRING *)0x0)) {
      pAVar3->flags = pAVar3->flags | 0x40;
    }
    *pval = (ASN1_VALUE *)pAVar3;
LAB_000b91a6:
    if (pAVar3 != (ASN1_STRING *)0x0) {
      pAVar3 = (ASN1_STRING *)0x1;
    }
    return (int)pAVar3;
  }
  iVar1 = it->utype;
  switch(iVar1) {
  case 1:
    *pval = (ASN1_VALUE *)it->size;
    break;
  case 5:
    *pval = (ASN1_VALUE *)0x1;
    break;
  case 6:
    pAVar2 = OBJ_nid2obj(0);
    *pval = (ASN1_VALUE *)pAVar2;
    break;
  case -4:
    pAVar3 = (ASN1_STRING *)CRYPTO_malloc(8,DAT_000b91d4,0x156);
    if (pAVar3 == (ASN1_STRING *)0x0) {
      return 0;
    }
    pAVar3->length = -1;
    pAVar3->type = 0;
    *pval = (ASN1_VALUE *)pAVar3;
    goto LAB_000b91a6;
  default:
    goto switchD_000b9162_caseD_fffffffd;
  }
  return 1;
}

