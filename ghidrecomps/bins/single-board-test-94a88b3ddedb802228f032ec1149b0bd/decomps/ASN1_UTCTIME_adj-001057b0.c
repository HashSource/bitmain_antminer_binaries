
ASN1_UTCTIME * ASN1_UTCTIME_adj(ASN1_UTCTIME *s,time_t t,int offset_day,long offset_sec)

{
  bool bVar1;
  undefined4 *puVar2;
  size_t sVar3;
  int iVar4;
  uchar *buf;
  time_t local_4c [2];
  undefined auStack_44 [44];
  
  local_4c[0] = t;
  if (s == (ASN1_UTCTIME *)0x0) {
    s = ASN1_STRING_type_new(0x17);
    if (s == (ASN1_STRING *)0x0) {
      return (ASN1_UTCTIME *)0x0;
    }
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  puVar2 = (undefined4 *)OPENSSL_gmtime(local_4c,auStack_44);
  if ((puVar2 != (undefined4 *)0x0) &&
     (((offset_day == 0 && offset_sec == 0 ||
       (iVar4 = OPENSSL_gmtime_adj(puVar2,offset_day,offset_sec), iVar4 != 0)) &&
      (iVar4 = puVar2[5], iVar4 - 0x32U < 100)))) {
    buf = s->data;
    if ((buf == (uchar *)0x0) || ((uint)s->length < 0x14)) {
      buf = (uchar *)CRYPTO_malloc(0x14,DAT_001058a8,0x108);
      if (buf == (uchar *)0x0) {
        ERR_put_error(0xd,0xda,0x41,DAT_001058a8,0x10a);
        goto joined_r0x0010586c;
      }
      if (s->data != (uchar *)0x0) {
        CRYPTO_free(s->data);
      }
      iVar4 = puVar2[5];
      s->data = buf;
    }
    BIO_snprintf((char *)buf,0x14,DAT_001058ac,iVar4 % 100,puVar2[4] + 1,puVar2[3],puVar2[2],
                 puVar2[1],*puVar2);
    sVar3 = strlen((char *)buf);
    s->length = sVar3;
    s->type = 0x17;
    return s;
  }
joined_r0x0010586c:
  if (!bVar1) {
    return (ASN1_UTCTIME *)0x0;
  }
  ASN1_STRING_free(s);
  return (ASN1_UTCTIME *)0x0;
}

