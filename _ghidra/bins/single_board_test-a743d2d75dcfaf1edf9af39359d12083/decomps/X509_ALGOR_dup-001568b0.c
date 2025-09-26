
X509_ALGOR * X509_ALGOR_dup(X509_ALGOR *xn)

{
  X509_ALGOR *pXVar1;
  
  pXVar1 = (X509_ALGOR *)ASN1_item_dup((ASN1_ITEM *)&X509_ALGOR_it,xn);
  return pXVar1;
}

