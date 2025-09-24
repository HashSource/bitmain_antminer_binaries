
X509_EXTENSION *
X509_EXTENSION_create_by_OBJ(X509_EXTENSION **ex,ASN1_OBJECT *obj,int crit,ASN1_OCTET_STRING *data)

{
  int iVar1;
  X509_EXTENSION *ex_00;
  
  if ((ex == (X509_EXTENSION **)0x0) || (ex_00 = *ex, ex_00 == (X509_EXTENSION *)0x0)) {
    ex_00 = X509_EXTENSION_new();
    if (ex_00 == (X509_EXTENSION *)0x0) {
      ERR_put_error(0xb,0x6d,0x41,"crypto/x509/x509_v3.c",0xa3);
      return (X509_EXTENSION *)0x0;
    }
    iVar1 = X509_EXTENSION_set_object(ex_00,obj);
    if ((iVar1 != 0) && (iVar1 = X509_EXTENSION_set_critical(ex_00,crit), iVar1 != 0))
    goto LAB_001682c4;
joined_r0x001682fc:
    if (ex == (X509_EXTENSION **)0x0) goto LAB_001682aa;
  }
  else {
    iVar1 = X509_EXTENSION_set_object(ex_00,obj);
    if ((iVar1 != 0) && (iVar1 = X509_EXTENSION_set_critical(ex_00,crit), iVar1 != 0)) {
LAB_001682c4:
      iVar1 = X509_EXTENSION_set_data(ex_00,data);
      if (iVar1 != 0) {
        if (ex == (X509_EXTENSION **)0x0) {
          return ex_00;
        }
        if (*ex != (X509_EXTENSION *)0x0) {
          return ex_00;
        }
        *ex = ex_00;
        return ex_00;
      }
      goto joined_r0x001682fc;
    }
  }
  if (*ex == ex_00) {
    return (X509_EXTENSION *)0x0;
  }
LAB_001682aa:
  X509_EXTENSION_free(ex_00);
  return (X509_EXTENSION *)0x0;
}

