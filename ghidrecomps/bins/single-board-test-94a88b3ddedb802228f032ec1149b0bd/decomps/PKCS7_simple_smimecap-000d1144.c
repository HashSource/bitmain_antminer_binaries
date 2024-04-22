
int PKCS7_simple_smimecap(stack_st_X509_ALGOR *sk,int nid,int arg)

{
  X509_ALGOR *data;
  ASN1_OBJECT *pAVar1;
  ASN1_TYPE *pAVar2;
  ASN1_INTEGER *a;
  int iVar3;
  
  data = X509_ALGOR_new();
  if (data == (X509_ALGOR *)0x0) {
    ERR_put_error(0x21,0x77,0x41,DAT_000d11e0,0x68);
    return 0;
  }
  ASN1_OBJECT_free(data->algorithm);
  pAVar1 = OBJ_nid2obj(nid);
  data->algorithm = pAVar1;
  if (arg < 1) {
LAB_000d1194:
    sk_push(&sk->stack,data);
    pAVar2 = (ASN1_TYPE *)0x1;
  }
  else {
    pAVar2 = ASN1_TYPE_new();
    iVar3 = 0x70;
    data->parameter = pAVar2;
    if (pAVar2 != (ASN1_TYPE *)0x0) {
      a = ASN1_INTEGER_new();
      if (a == (ASN1_INTEGER *)0x0) {
        ERR_put_error(0x21,0x77,0x41,DAT_000d11e0,0x74);
        return 0;
      }
      iVar3 = ASN1_INTEGER_set(a,arg);
      if (iVar3 != 0) {
        pAVar2 = data->parameter;
        pAVar2->type = 2;
        (pAVar2->value).integer = a;
        goto LAB_000d1194;
      }
      iVar3 = 0x78;
      pAVar2 = (ASN1_TYPE *)0x0;
    }
    ERR_put_error(0x21,0x77,0x41,DAT_000d11e0,iVar3);
  }
  return (int)pAVar2;
}

