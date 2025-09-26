
int param_cmp(EVP_PKEY *a,EVP_PKEY *b)

{
  int iVar1;
  
  iVar1 = strcmp(*(char **)a->type,*(char **)b->type);
  return iVar1;
}

