
PKCS7_RECIP_INFO * PKCS7_add_recipient(PKCS7 *p7,X509 *x509)

{
  PKCS7_RECIP_INFO *p7i;
  int iVar1;
  _STACK *st;
  
  p7i = PKCS7_RECIP_INFO_new();
  if (p7i == (PKCS7_RECIP_INFO *)0x0) {
    return (PKCS7_RECIP_INFO *)0x0;
  }
  iVar1 = PKCS7_RECIP_INFO_set(p7i,x509);
  if (iVar1 != 0) {
    iVar1 = OBJ_obj2nid(p7->type);
    if (iVar1 == 0x17) {
      st = &((p7->d).sign)->md_algs->stack;
    }
    else {
      if (iVar1 != 0x18) {
        ERR_put_error(0x21,0x66,0x71,DAT_000cf960,0x1fb);
        goto LAB_000cf918;
      }
      st = &((p7->d).signed_and_enveloped)->recipientinfo->stack;
    }
    iVar1 = sk_push(st,p7i);
    if (iVar1 != 0) {
      return p7i;
    }
  }
LAB_000cf918:
  PKCS7_RECIP_INFO_free(p7i);
  return (PKCS7_RECIP_INFO *)0x0;
}

