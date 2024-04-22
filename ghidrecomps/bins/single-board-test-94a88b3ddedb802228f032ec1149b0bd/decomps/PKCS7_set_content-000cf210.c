
int PKCS7_set_content(PKCS7 *p7,PKCS7 *p7_data)

{
  int iVar1;
  PKCS7_SIGNED *pPVar2;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if (iVar1 == 0x16) {
    pPVar2 = (p7->d).sign;
    if (pPVar2->contents != (PKCS7 *)0x0) {
      PKCS7_free(pPVar2->contents);
      pPVar2 = (p7->d).sign;
    }
    pPVar2->contents = p7_data;
    iVar1 = 1;
  }
  else if (iVar1 == 0x19) {
    pPVar2 = (p7->d).sign;
    if ((PKCS7 *)pPVar2->cert != (PKCS7 *)0x0) {
      PKCS7_free((PKCS7 *)pPVar2->cert);
      pPVar2 = (p7->d).sign;
    }
    pPVar2->cert = (stack_st_X509 *)p7_data;
    iVar1 = 1;
  }
  else {
    ERR_put_error(0x21,0x6d,0x70,DAT_000cf260,0x96);
    iVar1 = 0;
  }
  return iVar1;
}

