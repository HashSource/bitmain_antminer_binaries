
long PKCS7_ctrl(PKCS7 *p7,int cmd,long larg,char *parg)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if (cmd == 1) {
    if (iVar1 == 0x16) {
      p7->detached = larg;
      if (larg == 0) {
        return 0;
      }
      iVar1 = OBJ_obj2nid(((p7->d).sign)->contents->type);
      if (iVar1 != 0x15) {
        return larg;
      }
      ASN1_OCTET_STRING_free((((p7->d).sign)->contents->d).data);
      (((p7->d).sign)->contents->d).ptr = (char *)0x0;
      return larg;
    }
    iVar1 = 0x55;
  }
  else {
    if (cmd != 2) {
      ERR_put_error(0x21,0x68,0x6e,DAT_000cf20c,0x69);
      return 0;
    }
    if (iVar1 == 0x16) {
      if ((p7->d).sign == (PKCS7_SIGNED *)0x0) {
        iVar1 = 1;
      }
      else {
        pcVar2 = (((p7->d).sign)->contents->d).ptr;
        iVar1 = 1 - (int)pcVar2;
        if ((char *)0x1 < pcVar2) {
          iVar1 = 0;
        }
      }
      p7->detached = iVar1;
      return iVar1;
    }
    iVar1 = 99;
  }
  ERR_put_error(0x21,0x68,0x68,DAT_000cf20c,iVar1);
  return 0;
}

