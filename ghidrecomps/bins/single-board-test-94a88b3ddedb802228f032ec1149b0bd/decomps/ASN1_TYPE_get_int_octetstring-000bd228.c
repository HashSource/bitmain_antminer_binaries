
int ASN1_TYPE_get_int_octetstring(ASN1_TYPE *a,long *num,uchar *data,int max_len)

{
  uchar *puVar1;
  int iVar2;
  ASN1_INTEGER *a_00;
  ASN1_OCTET_STRING *a_01;
  long lVar3;
  ASN1_STRING *pAVar4;
  size_t sVar5;
  uchar *local_54;
  int local_50;
  ASN1_const_CTX local_4c;
  
  if ((a->type == 0x10) && (pAVar4 = (a->value).asn1_string, pAVar4 != (ASN1_STRING *)0x0)) {
    local_50 = pAVar4->length;
    local_54 = pAVar4->data;
    local_4c.pp = &local_54;
    local_4c.max = local_54 + local_50;
    local_4c.error = 0x6d;
    local_4c.p = local_54;
    iVar2 = asn1_GetSequence(&local_4c,&local_50);
    if (iVar2 == 0) {
      local_4c.line = 0xa3;
      a_00 = (ASN1_INTEGER *)0x0;
    }
    else {
      local_4c.q = local_4c.p;
      a_00 = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_4c.p,local_4c.slen);
      puVar1 = local_4c.q;
      if (a_00 == (ASN1_INTEGER *)0x0) goto LAB_000bd2fc;
      local_4c.q = local_4c.p;
      local_4c.slen = (long)(puVar1 + (local_4c.slen - (int)local_4c.p));
      a_01 = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_4c.p,local_4c.slen);
      if (a_01 != (ASN1_OCTET_STRING *)0x0) {
        local_4c.slen = (long)(local_4c.q + (local_4c.slen - (int)local_4c.p));
        if (local_4c.inf << 0x1f < 0) {
          local_4c.eos = ASN1_const_check_infinite_end(&local_4c.p,local_4c.slen);
          iVar2 = 1 - local_4c.eos;
          if (1 < (uint)local_4c.eos) {
            iVar2 = 0;
          }
        }
        else if (local_4c.slen < 1) {
          iVar2 = 0;
        }
        else {
          iVar2 = 1;
        }
        if (iVar2 == 0) {
          if (num != (long *)0x0) {
            lVar3 = ASN1_INTEGER_get(a_00);
            *num = lVar3;
          }
          sVar5 = a_01->length;
          if (data != (uchar *)0x0) {
            if ((int)sVar5 <= max_len) {
              max_len = sVar5;
            }
            memcpy(data,a_01->data,max_len);
          }
        }
        else {
          ERR_put_error(0xd,0x86,0x6d,DAT_000bd338,0xbc);
          sVar5 = 0xffffffff;
        }
        ASN1_STRING_free(a_01);
        goto LAB_000bd2dc;
      }
    }
  }
  else {
LAB_000bd2fc:
    a_00 = (ASN1_INTEGER *)0x0;
  }
  ERR_put_error(0xd,0x86,0x6d,DAT_000bd338,0xbc);
  sVar5 = 0xffffffff;
  if (a_00 == (ASN1_INTEGER *)0x0) {
    return -1;
  }
LAB_000bd2dc:
  ASN1_STRING_free(a_00);
  return sVar5;
}

