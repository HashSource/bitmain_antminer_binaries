
int X509_NAME_entry_count(X509_NAME *name)

{
  int iVar1;
  
  if (name != (X509_NAME *)0x0) {
    iVar1 = sk_num(&name->entries->stack);
    return iVar1;
  }
  return 0;
}

