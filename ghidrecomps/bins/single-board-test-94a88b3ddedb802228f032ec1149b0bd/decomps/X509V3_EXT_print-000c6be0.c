
int X509V3_EXT_print(BIO *out,X509_EXTENSION *ext,ulong flag,int indent)

{
  X509V3_EXT_METHOD *method;
  ASN1_VALUE *val;
  char *ptr;
  int iVar1;
  ASN1_OCTET_STRING *pAVar2;
  ASN1_ITEM *it;
  int iVar3;
  uint uVar4;
  _STACK *st;
  uchar *local_24 [2];
  
  method = X509V3_EXT_get(ext);
  if (method == (X509V3_EXT_METHOD *)0x0) {
    uVar4 = flag & 0xf0000;
    if (uVar4 == 0x10000) {
      BIO_printf(out,DAT_000c6d48,indent,DAT_000c6d3c);
      return 1;
    }
    if (uVar4 < 0x10001) {
      if (uVar4 != 0) {
        return 1;
      }
      return 0;
    }
LAB_000c6ce6:
    if ((flag & 0xf0000) == 0x20000) {
      iVar3 = ASN1_parse_dump(out,ext->value->data,ext->value->length,indent,-1);
      return iVar3;
    }
    if ((flag & 0xf0000) != 0x30000) {
      return 1;
    }
    iVar3 = BIO_dump_indent(out,ext->value->data,ext->value->length,indent);
    return iVar3;
  }
  pAVar2 = ext->value;
  local_24[0] = pAVar2->data;
  if (method->it == (ASN1_ITEM *)0x0) {
    val = (ASN1_VALUE *)(*method->d2i)((void *)0x0,local_24,pAVar2->length);
  }
  else {
    val = ASN1_item_d2i((ASN1_VALUE **)0x0,local_24,pAVar2->length,method->it);
  }
  if (val == (ASN1_VALUE *)0x0) {
    uVar4 = flag & 0xf0000;
    if (uVar4 == 0x10000) {
      BIO_printf(out,DAT_000c6d4c,indent,DAT_000c6d3c);
      return 1;
    }
    if (uVar4 < 0x10001) {
      if (uVar4 != 0) {
        return 1;
      }
      return 0;
    }
    goto LAB_000c6ce6;
  }
  if (method->i2s == (X509V3_EXT_I2S)0x0) {
    if (method->i2v == (X509V3_EXT_I2V)0x0) {
      if (method->i2r == (X509V3_EXT_I2R)0x0) goto LAB_000c6c56;
      iVar1 = (*method->i2r)(method,val,out,indent);
      iVar3 = 1;
      st = (_STACK *)0x0;
      if (iVar1 == 0) {
        iVar3 = 0;
        st = (_STACK *)0x0;
      }
    }
    else {
      st = &(*method->i2v)(method,val,(stack_st_CONF_VALUE *)0x0)->stack;
      if (st == (_STACK *)0x0) goto LAB_000c6c56;
      iVar3 = 1;
      X509V3_EXT_val_prn(out,(stack_st_CONF_VALUE *)st,indent,method->ext_flags & 4);
    }
  }
  else {
    ptr = (*method->i2s)(method,val);
    if (ptr != (char *)0x0) {
      iVar3 = 1;
      BIO_printf(out,DAT_000c6d40,indent,DAT_000c6d3c,ptr);
      sk_pop_free((_STACK *)0x0,DAT_000c6d44);
      CRYPTO_free(ptr);
      it = method->it;
      goto joined_r0x000c6c66;
    }
LAB_000c6c56:
    iVar3 = 0;
    st = (_STACK *)0x0;
  }
  sk_pop_free(st,DAT_000c6d44);
  it = method->it;
joined_r0x000c6c66:
  if (it == (ASN1_ITEM *)0x0) {
    (*method->ext_free)(val);
    return iVar3;
  }
  ASN1_item_free(val,it);
  return iVar3;
}

