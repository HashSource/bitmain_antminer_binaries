
ASN1_GENERALIZEDTIME * ASN1_TIME_to_generalizedtime(ASN1_TIME *t,ASN1_GENERALIZEDTIME **out)

{
  int iVar1;
  char *src;
  ASN1_GENERALIZEDTIME *str;
  size_t siz;
  uchar *dst;
  
  if (t->type == 0x18) {
    iVar1 = ASN1_GENERALIZEDTIME_check(t);
  }
  else {
    if (t->type != 0x17) {
      return (ASN1_GENERALIZEDTIME *)0x0;
    }
    iVar1 = ASN1_UTCTIME_check(t);
  }
  if (iVar1 != 0) {
    if (out == (ASN1_GENERALIZEDTIME **)0x0) {
      str = ASN1_GENERALIZEDTIME_new();
      if (str == (ASN1_GENERALIZEDTIME *)0x0) {
        return (ASN1_GENERALIZEDTIME *)0x0;
      }
    }
    else {
      str = *out;
      if (str == (ASN1_GENERALIZEDTIME *)0x0) {
        str = ASN1_GENERALIZEDTIME_new();
        if (str == (ASN1_GENERALIZEDTIME *)0x0) {
          return (ASN1_GENERALIZEDTIME *)0x0;
        }
        *out = str;
      }
    }
    if (t->type == 0x18) {
      iVar1 = ASN1_STRING_set(str,t->data,t->length);
      if (iVar1 != 0) {
        return str;
      }
    }
    else {
      iVar1 = ASN1_STRING_set(str,(void *)0x0,t->length + 2);
      if (iVar1 != 0) {
        dst = str->data;
        siz = t->length + 3;
        src = DAT_00105e34;
        if (*t->data < 0x35) {
          src = DAT_00105e38;
        }
        BUF_strlcpy((char *)dst,src,siz);
        BUF_strlcat((char *)dst,(char *)t->data,siz);
        return str;
      }
    }
  }
  return (ASN1_GENERALIZEDTIME *)0x0;
}

