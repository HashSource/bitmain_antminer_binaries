
X509_EXTENSION *
v3_generic_extension(char *param_1,char *param_2,int param_3,int param_4,X509V3_CTX *param_5)

{
  ASN1_OBJECT *a;
  uchar *ptr;
  ASN1_TYPE *a_00;
  ASN1_STRING *data;
  X509_EXTENSION *pXVar1;
  int local_20;
  uchar *local_1c;
  
  a = OBJ_txt2obj(param_1,0);
  if (a == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0x22,0x74,0x73,DAT_0010c504,0x111);
    ERR_add_error_data(2,DAT_0010c50c,param_1);
    data = (ASN1_STRING *)0x0;
    pXVar1 = (X509_EXTENSION *)0x0;
    goto LAB_0010c44e;
  }
  if (param_4 == 1) {
    ptr = string_to_hex(param_2,&local_20);
LAB_0010c46c:
    if (ptr != (uchar *)0x0) {
      data = ASN1_STRING_type_new(4);
      if (data == (ASN1_STRING *)0x0) {
        ERR_put_error(0x22,0x74,0x41,DAT_0010c504,0x123);
        ASN1_OBJECT_free(a);
        ASN1_STRING_free((ASN1_STRING *)0x0);
        CRYPTO_free(ptr);
        return (X509_EXTENSION *)0x0;
      }
      data->data = ptr;
      data->length = local_20;
      pXVar1 = X509_EXTENSION_create_by_OBJ((X509_EXTENSION **)0x0,a,param_3,data);
      goto LAB_0010c44e;
    }
  }
  else if (param_4 == 2) {
    local_1c = (uchar *)0x0;
    a_00 = ASN1_generate_v3(param_2,param_5);
    if (a_00 != (ASN1_TYPE *)0x0) {
      local_20 = i2d_ASN1_TYPE(a_00,&local_1c);
      ASN1_TYPE_free(a_00);
      ptr = local_1c;
      goto LAB_0010c46c;
    }
  }
  pXVar1 = (X509_EXTENSION *)0x0;
  data = (ASN1_STRING *)0x0;
  ERR_put_error(0x22,0x74,0x74,DAT_0010c504,0x11d);
  ERR_add_error_data(2,DAT_0010c508,param_2);
LAB_0010c44e:
  ASN1_OBJECT_free(a);
  ASN1_STRING_free(data);
  return pXVar1;
}

