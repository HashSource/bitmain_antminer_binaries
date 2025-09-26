
int EVP_add_digest(EVP_MD *digest)

{
  char *name;
  int iVar1;
  char *pcVar2;
  int n;
  
  OPENSSL_init();
  name = OBJ_nid2sn(digest->type);
  iVar1 = OBJ_NAME_add(name,1,(char *)digest);
  if (iVar1 != 0) {
    check_defer(digest->type);
    pcVar2 = OBJ_nid2ln(digest->type);
    iVar1 = OBJ_NAME_add(pcVar2,1,(char *)digest);
    if (iVar1 != 0) {
      n = digest->pkey_type;
      if ((n == 0) || (n == digest->type)) {
        return iVar1;
      }
      pcVar2 = OBJ_nid2sn(n);
      iVar1 = OBJ_NAME_add(pcVar2,0x8001,name);
      if (iVar1 != 0) {
        check_defer(digest->pkey_type);
        pcVar2 = OBJ_nid2ln(digest->pkey_type);
        iVar1 = OBJ_NAME_add(pcVar2,0x8001,name);
        return iVar1;
      }
    }
  }
  return 0;
}

