
X509_REQ * d2i_X509_REQ_fp(FILE *fp,X509_REQ **req)

{
  X509_REQ *pXVar1;
  
  pXVar1 = (X509_REQ *)ASN1_item_d2i_fp((ASN1_ITEM *)X509_REQ_it,fp,req);
  return pXVar1;
}

