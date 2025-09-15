
PKCS7_ISSUER_AND_SERIAL * PKCS7_get_issuer_and_serial(PKCS7 *p7,int idx)

{
  int iVar1;
  void *pvVar2;
  _STACK *p_Var3;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if (((iVar1 == 0x18) && ((p7->d).signed_and_enveloped != (PKCS7_SIGN_ENVELOPE *)0x0)) &&
     (p_Var3 = &((p7->d).signed_and_enveloped)->recipientinfo->stack, p_Var3 != (_STACK *)0x0)) {
    sk_value(p_Var3,0);
    iVar1 = sk_num(p_Var3);
    if (idx < iVar1) {
      pvVar2 = sk_value(p_Var3,idx);
      return *(PKCS7_ISSUER_AND_SERIAL **)((int)pvVar2 + 4);
    }
  }
  return (PKCS7_ISSUER_AND_SERIAL *)0x0;
}

