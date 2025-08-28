
int X509_REQ_extension_nid(int nid)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *ext_nids;
  piVar1 = ext_nids;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    do {
      if (nid == iVar2) {
        return 1;
      }
      piVar1 = piVar1 + 1;
      iVar2 = *piVar1;
    } while (iVar2 != 0);
  }
  return iVar2;
}

