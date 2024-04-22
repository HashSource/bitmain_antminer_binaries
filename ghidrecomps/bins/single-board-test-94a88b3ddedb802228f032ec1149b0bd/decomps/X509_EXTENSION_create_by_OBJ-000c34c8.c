
X509_EXTENSION *
X509_EXTENSION_create_by_OBJ(X509_EXTENSION **ex,ASN1_OBJECT *obj,int crit,ASN1_OCTET_STRING *data)

{
  ASN1_OBJECT *pAVar1;
  int iVar2;
  uchar *data_00;
  ASN1_BOOLEAN AVar3;
  X509_EXTENSION *a;
  
  if (((ex == (X509_EXTENSION **)0x0) || (a = *ex, a == (X509_EXTENSION *)0x0)) &&
     (a = X509_EXTENSION_new(), a == (X509_EXTENSION *)0x0)) {
    ERR_put_error(0xb,0x6d,0x41,DAT_000c3554,0xd4);
  }
  else {
    if (obj != (ASN1_OBJECT *)0x0) {
      ASN1_OBJECT_free(a->object);
      pAVar1 = OBJ_dup(obj);
      if (crit == 0) {
        AVar3 = -1;
      }
      else {
        AVar3 = 0xff;
      }
      data_00 = data->data;
      a->object = pAVar1;
      a->critical = AVar3;
      iVar2 = ASN1_STRING_set(a->value,data_00,data->length);
      if (iVar2 != 0) {
        if (ex == (X509_EXTENSION **)0x0) {
          return a;
        }
        if (*ex == (X509_EXTENSION *)0x0) {
          *ex = a;
          return a;
        }
        return a;
      }
    }
    if ((ex == (X509_EXTENSION **)0x0) || (*ex != a)) {
      X509_EXTENSION_free(a);
    }
  }
  return (X509_EXTENSION *)0x0;
}

