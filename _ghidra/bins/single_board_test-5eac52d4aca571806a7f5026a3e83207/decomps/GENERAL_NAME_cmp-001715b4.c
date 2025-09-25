
int GENERAL_NAME_cmp(GENERAL_NAME *a,GENERAL_NAME *b)

{
  int iVar1;
  ASN1_STRING *a_00;
  ASN1_STRING *b_00;
  EDIPARTYNAME *pEVar2;
  EDIPARTYNAME *pEVar3;
  
  if (b == (GENERAL_NAME *)0x0 || a == (GENERAL_NAME *)0x0) {
    return -1;
  }
  if (a->type == b->type) {
    switch(a->type) {
    case 0:
      iVar1 = OTHERNAME_cmp((a->d).otherName,(b->d).otherName);
      return iVar1;
    case 1:
    case 2:
    case 6:
      b_00 = (ASN1_STRING *)(b->d).otherName;
      a_00 = (ASN1_STRING *)(a->d).otherName;
LAB_001715f4:
      iVar1 = ASN1_STRING_cmp(a_00,b_00);
      return iVar1;
    case 3:
      iVar1 = ASN1_TYPE_cmp((a->d).x400Address,(b->d).x400Address);
      return iVar1;
    case 4:
      iVar1 = X509_NAME_cmp((a->d).directoryName,(b->d).directoryName);
      return iVar1;
    case 5:
      pEVar2 = (a->d).ediPartyName;
      pEVar3 = (b->d).ediPartyName;
      if (pEVar3 != (EDIPARTYNAME *)0x0 && pEVar2 != (EDIPARTYNAME *)0x0) {
        if (pEVar2->nameAssigner == (ASN1_STRING *)0x0) {
          if (pEVar3->nameAssigner != (ASN1_STRING *)0x0) {
            return -1;
          }
        }
        else {
          if (pEVar3->nameAssigner == (ASN1_STRING *)0x0) {
            return 1;
          }
          iVar1 = ASN1_STRING_cmp(pEVar2->nameAssigner,pEVar3->nameAssigner);
          if (iVar1 != 0) {
            return iVar1;
          }
        }
        a_00 = pEVar2->partyName;
        if ((a_00 != (ASN1_STRING *)0x0) && (b_00 = pEVar3->partyName, b_00 != (ASN1_STRING *)0x0))
        goto LAB_001715f4;
      }
      break;
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

