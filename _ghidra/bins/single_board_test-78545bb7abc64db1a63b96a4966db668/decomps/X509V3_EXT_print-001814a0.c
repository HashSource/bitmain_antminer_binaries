
int X509V3_EXT_print(BIO *out,X509_EXTENSION *ext,ulong flag,int indent)

{
  ASN1_OCTET_STRING *x;
  int iVar1;
  X509V3_EXT_METHOD *method;
  ASN1_VALUE *val;
  char *ptr;
  uint uVar2;
  stack_st_CONF_VALUE *val_00;
  uchar *local_2c [2];
  
  x = X509_EXTENSION_get_data(ext);
  local_2c[0] = (uchar *)ASN1_STRING_get0_data();
  iVar1 = ASN1_STRING_length(x);
  method = X509V3_EXT_get(ext);
  if (method == (X509V3_EXT_METHOD *)0x0) {
    uVar2 = flag & 0xf0000;
    if (uVar2 == 0x10000) {
      BIO_printf(out,"%*s<Not Supported>",indent,"");
      return 1;
    }
    if (0x10000 < uVar2) goto joined_r0x001815ba;
  }
  else {
    if (method->it == (ASN1_ITEM *)0x0) {
      val = (ASN1_VALUE *)(*method->d2i)((void *)0x0,local_2c,iVar1);
    }
    else {
      val = ASN1_item_d2i((ASN1_VALUE **)0x0,local_2c,iVar1,method->it);
    }
    if (val != (ASN1_VALUE *)0x0) {
      if (method->i2s == (X509V3_EXT_I2S)0x0) {
        if (method->i2v == (X509V3_EXT_I2V)0x0) {
          if (method->i2r == (X509V3_EXT_I2R)0x0) {
            ptr = (char *)0x0;
            iVar1 = 0;
            val_00 = (stack_st_CONF_VALUE *)0x0;
          }
          else {
            iVar1 = (*method->i2r)(method,val,out,indent);
            if (iVar1 != 0) {
              iVar1 = 1;
            }
            ptr = (char *)0x0;
            val_00 = (stack_st_CONF_VALUE *)0x0;
          }
        }
        else {
          val_00 = (*method->i2v)(method,val,(stack_st_CONF_VALUE *)0x0);
          if (val_00 == (stack_st_CONF_VALUE *)0x0) {
            ptr = (char *)0x0;
            iVar1 = 0;
          }
          else {
            iVar1 = 1;
            X509V3_EXT_val_prn(out,val_00,indent,method->ext_flags & 4);
            ptr = (char *)0x0;
          }
        }
      }
      else {
        ptr = (*method->i2s)(method,val);
        if (ptr == (char *)0x0) {
          iVar1 = 0;
          val_00 = (stack_st_CONF_VALUE *)0x0;
        }
        else {
          iVar1 = 1;
          val_00 = (stack_st_CONF_VALUE *)0x0;
          BIO_printf(out,"%*s%s",indent,"",ptr);
        }
      }
      OPENSSL_sk_pop_free(val_00,0x1830d1);
      CRYPTO_free(ptr);
      if (method->it == (ASN1_ITEM *)0x0) {
        (*method->ext_free)(val);
        return iVar1;
      }
      ASN1_item_free(val,method->it);
      return iVar1;
    }
    if ((flag & 0xf0000) == 0x10000) {
      BIO_printf(out,"%*s<Parse Error>",indent,"");
      return 1;
    }
    if (0x10000 < (flag & 0xf0000)) {
joined_r0x001815ba:
      if ((flag & 0xf0000) == 0x20000) {
        iVar1 = ASN1_parse_dump(out,local_2c[0],iVar1,indent,-1);
        return iVar1;
      }
      if ((flag & 0xf0000) != 0x30000) {
        return 1;
      }
      iVar1 = BIO_dump_indent(out,(char *)local_2c[0],iVar1,indent);
      return iVar1;
    }
    uVar2 = 0;
  }
  if ((flag & 0xf0000) != 0) {
    return 1;
  }
  return uVar2;
}

