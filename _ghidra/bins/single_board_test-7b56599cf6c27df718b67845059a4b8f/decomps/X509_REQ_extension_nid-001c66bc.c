
int X509_REQ_extension_nid(int nid)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *ext_nids;
  piVar1 = ext_nids;
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    if (nid == iVar2) break;
    piVar1 = piVar1 + 1;
    iVar2 = *piVar1;
  }
  return 1;
}

