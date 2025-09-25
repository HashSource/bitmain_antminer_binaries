
int X509V3_EXT_add_list(X509V3_EXT_METHOD *extlist)

{
  int iVar1;
  
  if (extlist->ext_nid == -1) {
    return 1;
  }
  do {
    iVar1 = X509V3_EXT_add(extlist);
    if (iVar1 == 0) {
      return 0;
    }
    extlist = extlist + 1;
  } while (extlist->ext_nid != -1);
  return 1;
}

