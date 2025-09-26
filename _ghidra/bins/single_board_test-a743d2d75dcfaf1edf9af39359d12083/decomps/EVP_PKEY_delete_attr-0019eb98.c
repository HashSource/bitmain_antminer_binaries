
X509_ATTRIBUTE * EVP_PKEY_delete_attr(EVP_PKEY *key,int loc)

{
  X509_ATTRIBUTE *pXVar1;
  
  pXVar1 = X509at_delete_attr(key->attributes,loc);
  return pXVar1;
}

