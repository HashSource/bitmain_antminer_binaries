
X509 * X509_find_by_issuer_and_serial(stack_st_X509 *sk,X509_NAME *name,ASN1_INTEGER *serial)

{
  int iVar1;
  int iVar2;
  X509 *a;
  X509 XStack_e8;
  
  if (sk == (stack_st_X509 *)0x0) {
LAB_00166686:
    a = (X509 *)0x0;
  }
  else {
    XStack_e8.sig_alg = (X509_ALGOR *)serial->length;
    XStack_e8.signature = (ASN1_BIT_STRING *)serial->type;
    XStack_e8.valid = (int)serial->data;
    XStack_e8.references = serial->flags;
    iVar2 = 0;
    XStack_e8.ex_data.dummy = (int)name;
    do {
      iVar1 = OPENSSL_sk_num(sk);
      if (iVar1 <= iVar2) goto LAB_00166686;
      a = (X509 *)OPENSSL_sk_value(sk,iVar2);
      iVar1 = X509_issuer_and_serial_cmp(a,&XStack_e8);
      iVar2 = iVar2 + 1;
    } while (iVar1 != 0);
  }
  return a;
}

