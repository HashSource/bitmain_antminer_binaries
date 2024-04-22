
int PKCS7_add_recipient_info(PKCS7 *p7,PKCS7_RECIP_INFO *ri)

{
  int iVar1;
  _STACK *st;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if (iVar1 == 0x17) {
    st = &((p7->d).sign)->md_algs->stack;
  }
  else {
    if (iVar1 != 0x18) {
      ERR_put_error(0x21,0x66,0x71,DAT_000cf824,0x1fb);
      return 0;
    }
    st = &((p7->d).signed_and_enveloped)->recipientinfo->stack;
  }
  iVar1 = sk_push(st,ri);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

