
ASN1_OBJECT * c2i_ASN1_OBJECT(ASN1_OBJECT **a,uchar **pp,long length)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  uchar *puVar3;
  uchar *__src;
  bool bVar4;
  ASN1_OBJECT AStack_38;
  
  bVar4 = (int)pp < 0;
  if (pp != (uchar **)0x0) {
    bVar4 = length < 0;
  }
  if ((((pp == (uchar **)0x0 || length == 0) || bVar4) || (puVar3 = *pp, puVar3 == (uchar *)0x0)) ||
     ((char)puVar3[length + -1] < '\0')) {
    iVar1 = 0xfe;
LAB_0017bad2:
    ERR_put_error(0xd,0xc4,0xd8,"crypto/asn1/a_object.c",iVar1);
  }
  else {
    AStack_38.nid = 0;
    AStack_38.flags = 0;
    AStack_38.length = length;
    AStack_38.data = puVar3;
    iVar1 = OBJ_obj2nid(&AStack_38);
    puVar3 = puVar3 + -1;
    if (iVar1 != 0) {
      pAVar2 = OBJ_nid2obj(iVar1);
      if (a != (ASN1_OBJECT **)0x0) {
        ASN1_OBJECT_free(*a);
        *a = pAVar2;
      }
      *pp = *pp + length;
      return pAVar2;
    }
    do {
      if ((puVar3[1] == 0x80) && ((iVar1 == 0 || (-1 < (char)*puVar3)))) {
        iVar1 = 0x11c;
        goto LAB_0017bad2;
      }
      iVar1 = iVar1 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar1 < length);
    if ((((a != (ASN1_OBJECT **)0x0) && (pAVar2 = *a, pAVar2 != (ASN1_OBJECT *)0x0)) &&
        (pAVar2->flags << 0x1f < 0)) || (pAVar2 = ASN1_OBJECT_new(), pAVar2 != (ASN1_OBJECT *)0x0))
    {
      puVar3 = pAVar2->data;
      __src = *pp;
      pAVar2->data = (uchar *)0x0;
      if ((puVar3 == (uchar *)0x0) || (pAVar2->length < length)) {
        pAVar2->length = 0;
        CRYPTO_free(puVar3);
        puVar3 = (uchar *)CRYPTO_malloc(length,"crypto/asn1/a_object.c",0x131);
        if (puVar3 == (uchar *)0x0) {
          ERR_put_error(0xd,0xc4,0x41,"crypto/asn1/a_object.c",0x14c);
          if ((a != (ASN1_OBJECT **)0x0) && (pAVar2 == *a)) {
            return (ASN1_OBJECT *)0x0;
          }
          ASN1_OBJECT_free(pAVar2);
          return (ASN1_OBJECT *)0x0;
        }
        pAVar2->flags = pAVar2->flags | 8;
      }
      memcpy(puVar3,__src,length);
      if (pAVar2->flags << 0x1d < 0) {
        CRYPTO_free(pAVar2->sn);
        CRYPTO_free(pAVar2->ln);
        pAVar2->flags = pAVar2->flags & 0xfffffffb;
      }
      pAVar2->length = length;
      pAVar2->data = puVar3;
      pAVar2->sn = (char *)0x0;
      pAVar2->ln = (char **)0x0;
      if (a != (ASN1_OBJECT **)0x0) {
        *a = pAVar2;
      }
      *pp = __src + length;
      return pAVar2;
    }
  }
  return (ASN1_OBJECT *)0x0;
}

