
X509_ATTRIBUTE * EVP_PKEY_delete_attr(EVP_PKEY *key,int loc)

{
  X509_ATTRIBUTE *pXVar1;
  
  pXVar1 = X509at_delete_attr((stack_st_X509_ATTRIBUTE *)key[1].type,loc);
  return pXVar1;
}

