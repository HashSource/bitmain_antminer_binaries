
stack_st_X509_EXTENSION * X509_REQ_get_extensions(X509_REQ *req)

{
  int *piVar1;
  stack_st_X509_EXTENSION *psVar2;
  X509_ATTRIBUTE *attr;
  ASN1_TYPE *pAVar3;
  ASN1_VALUE *pAVar4;
  int iVar5;
  uchar *local_14;
  
  if ((req == (X509_REQ *)0x0) || (ext_nids == (int *)0x0)) {
    return (stack_st_X509_EXTENSION *)0x0;
  }
  iVar5 = *ext_nids;
  piVar1 = ext_nids;
  do {
    if (iVar5 == 0) {
LAB_001c674a:
      psVar2 = (stack_st_X509_EXTENSION *)OPENSSL_sk_new_null();
      return psVar2;
    }
    iVar5 = X509_REQ_get_attr_by_NID(req,iVar5,-1);
    if (iVar5 != -1) {
      attr = X509_REQ_get_attr(req,iVar5);
      pAVar3 = X509_ATTRIBUTE_get0_type(attr,0);
      if (pAVar3 != (ASN1_TYPE *)0x0) {
        if (pAVar3->type == 0x10) {
          local_14 = ((pAVar3->value).asn1_string)->data;
          pAVar4 = ASN1_item_d2i((ASN1_VALUE **)0x0,&local_14,((pAVar3->value).asn1_string)->length,
                                 (ASN1_ITEM *)&X509_EXTENSIONS_it);
          return (stack_st_X509_EXTENSION *)pAVar4;
        }
        return (stack_st_X509_EXTENSION *)0x0;
      }
      goto LAB_001c674a;
    }
    piVar1 = piVar1 + 1;
    iVar5 = *piVar1;
  } while( true );
}

