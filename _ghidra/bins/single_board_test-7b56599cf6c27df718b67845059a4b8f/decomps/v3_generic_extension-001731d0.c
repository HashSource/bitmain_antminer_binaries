
X509_EXTENSION *
v3_generic_extension(char *param_1,char *param_2,int param_3,int param_4,X509V3_CTX *param_5)

{
  ASN1_OBJECT *obj;
  ASN1_TYPE *a;
  ASN1_STRING *data;
  X509_EXTENSION *pXVar1;
  uchar *ptr;
  int local_28;
  uchar *local_24 [2];
  
  local_28 = 0;
  obj = OBJ_txt2obj(param_1,0);
  if (obj == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0x22,0x74,0x73,"crypto/x509v3/v3_conf.c",0xea);
    ERR_add_error_data(2,"name=",param_1);
    data = (ASN1_STRING *)0x0;
    pXVar1 = (X509_EXTENSION *)0x0;
    ptr = (uchar *)0x0;
    goto LAB_0017321a;
  }
  if (param_4 == 1) {
    ptr = (uchar *)OPENSSL_hexstr2buf(param_2,&local_28);
LAB_00173246:
    if (ptr != (uchar *)0x0) {
      data = ASN1_OCTET_STRING_new();
      if (data == (ASN1_OCTET_STRING *)0x0) {
        ERR_put_error(0x22,0x74,0x41,"crypto/x509v3/v3_conf.c",0xfc);
        pXVar1 = (X509_EXTENSION *)0x0;
      }
      else {
        data->data = ptr;
        ptr = (uchar *)0x0;
        data->length = local_28;
        pXVar1 = X509_EXTENSION_create_by_OBJ((X509_EXTENSION **)0x0,obj,param_3,data);
      }
      goto LAB_0017321a;
    }
  }
  else if (param_4 == 2) {
    local_24[0] = (uchar *)0x0;
    a = ASN1_generate_v3(param_2,param_5);
    if (a != (ASN1_TYPE *)0x0) {
      local_28 = i2d_ASN1_TYPE(a,local_24);
      ASN1_TYPE_free(a);
      ptr = local_24[0];
      goto LAB_00173246;
    }
  }
  pXVar1 = (X509_EXTENSION *)0x0;
  data = (ASN1_STRING *)0x0;
  ptr = (uchar *)0x0;
  ERR_put_error(0x22,0x74,0x74,"crypto/x509v3/v3_conf.c",0xf6);
  ERR_add_error_data(2,"value=",param_2);
LAB_0017321a:
  ASN1_OBJECT_free(obj);
  ASN1_OCTET_STRING_free(data);
  CRYPTO_free(ptr);
  return pXVar1;
}

