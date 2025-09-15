
int GENERAL_NAME_cmp(GENERAL_NAME *a,GENERAL_NAME *b)

{
  int iVar1;
  OTHERNAME *pOVar2;
  OTHERNAME *pOVar3;
  
  if ((a != (GENERAL_NAME *)0x0 && b != (GENERAL_NAME *)0x0) && (a->type == b->type)) {
    switch(a->type) {
    case 0:
      pOVar3 = (a->d).otherName;
      pOVar2 = (b->d).otherName;
      if (pOVar3 != (OTHERNAME *)0x0 && pOVar2 != (OTHERNAME *)0x0) {
        iVar1 = OBJ_cmp(pOVar3->type_id,pOVar2->type_id);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = ASN1_TYPE_cmp(pOVar3->value,pOVar2->value);
        return iVar1;
      }
      break;
    case 1:
    case 2:
    case 6:
      iVar1 = ASN1_STRING_cmp((ASN1_STRING *)(a->d).otherName,(ASN1_STRING *)(b->d).otherName);
      return iVar1;
    case 3:
    case 5:
      iVar1 = ASN1_TYPE_cmp((a->d).x400Address,(b->d).x400Address);
      return iVar1;
    case 4:
      iVar1 = X509_NAME_cmp((a->d).directoryName,(b->d).directoryName);
      return iVar1;
    case 7:
      iVar1 = ASN1_OCTET_STRING_cmp((ASN1_STRING *)(a->d).otherName,(ASN1_STRING *)(b->d).otherName)
      ;
      return iVar1;
    case 8:
      iVar1 = OBJ_cmp((a->d).registeredID,(b->d).registeredID);
      return iVar1;
    }
  }
  return -1;
}

