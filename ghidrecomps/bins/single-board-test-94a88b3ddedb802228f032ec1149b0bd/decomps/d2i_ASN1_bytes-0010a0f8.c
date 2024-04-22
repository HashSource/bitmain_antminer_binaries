
ASN1_STRING * d2i_ASN1_bytes(ASN1_STRING **a,uchar **pp,long length,int Ptag,int Pclass)

{
  uint uVar1;
  ASN1_STRING *pAVar2;
  int iVar3;
  int iVar4;
  uchar *__dest;
  ASN1_STRING *a_00;
  uchar *local_6c;
  uchar *local_68;
  int local_64;
  int iStack_60;
  ASN1_STRING *local_5c;
  BUF_MEM local_58;
  ASN1_const_CTX local_4c;
  
  if (((a == (ASN1_STRING **)0x0) || (a_00 = *a, a_00 == (ASN1_STRING *)0x0)) &&
     (a_00 = ASN1_STRING_new(), a_00 == (ASN1_STRING *)0x0)) {
    return (ASN1_STRING *)0x0;
  }
  local_6c = *pp;
  uVar1 = ASN1_get_object(&local_6c,(long *)&local_68,&local_64,&iStack_60,length);
  if ((int)(uVar1 << 0x18) < 0) {
    iVar4 = 0x66;
    goto LAB_0010a266;
  }
  if (local_64 != Ptag) {
    iVar4 = 0xa8;
    goto LAB_0010a266;
  }
  if ((int)(uVar1 << 0x1a) < 0) {
    local_4c.slen = (long)local_68;
    local_4c.max = local_6c + length;
    local_4c.xclass = Pclass;
    local_4c.p = local_6c;
    if (length == 0) {
      local_4c.max = (uchar *)0x0;
    }
    iVar4 = 0;
    local_5c = (ASN1_STRING *)0x0;
    local_58.length = 0;
    local_58.max = 0;
    local_58.data = (char *)0x0;
    local_4c.inf = uVar1;
    local_4c.tag = Ptag;
    local_4c.pp = pp;
    if ((uVar1 & 1) != 0) goto LAB_0010a1d2;
    while (0 < local_4c.slen) {
      while( true ) {
        local_4c.q = local_4c.p;
        pAVar2 = d2i_ASN1_bytes(&local_5c,&local_4c.p,(int)local_4c.max - (int)local_4c.p,
                                local_4c.tag,local_4c.xclass);
        if (pAVar2 == (ASN1_STRING *)0x0) {
          local_4c.error = 0xd;
          goto LAB_0010a2ac;
        }
        iVar3 = BUF_MEM_grow_clean(&local_58,iVar4 + local_5c->length);
        if (iVar3 == 0) {
          local_4c.error = 7;
          goto LAB_0010a2ac;
        }
        memcpy(local_58.data + iVar4,local_5c->data,local_5c->length);
        if ((local_4c.inf & 1U) == 0) {
          local_4c.slen = (long)(local_4c.q + (local_4c.slen - (int)local_4c.p));
        }
        iVar4 = iVar4 + local_5c->length;
        if ((local_4c.inf & 1U) == 0) break;
LAB_0010a1d2:
        local_4c.eos = ASN1_const_check_infinite_end
                                 (&local_4c.p,(int)local_4c.max - (int)local_4c.p);
        if (local_4c.eos != 0) goto LAB_0010a1e4;
      }
    }
LAB_0010a1e4:
    iVar3 = asn1_const_Finish(&local_4c);
    if (iVar3 == 0) {
LAB_0010a2ac:
      ERR_put_error(0xd,0x69,local_4c.error,DAT_0010a2e4,300);
      if (local_5c != (ASN1_STRING *)0x0) {
        ASN1_STRING_free(local_5c);
      }
      if ((uchar *)local_58.data != (uchar *)0x0) {
        CRYPTO_free(local_58.data);
      }
      iVar4 = 0;
      goto LAB_0010a266;
    }
    a_00->length = iVar4;
    if (a_00->data != (uchar *)0x0) {
      CRYPTO_free(a_00->data);
    }
    a_00->data = (uchar *)local_58.data;
    if (local_5c != (ASN1_STRING *)0x0) {
      ASN1_STRING_free(local_5c);
    }
    goto LAB_0010a206;
  }
  if (local_68 == (uchar *)0x0) {
    if (a_00->data == (uchar *)0x0) {
      local_68 = (uchar *)0x0;
      __dest = (uchar *)0x0;
      local_4c.p = local_6c;
    }
    else {
      CRYPTO_free(a_00->data);
      __dest = (uchar *)0x0;
      local_4c.p = local_6c;
    }
  }
  else {
    if (a_00->length < (int)local_68) {
      if (a_00->data != (uchar *)0x0) {
        CRYPTO_free(a_00->data);
      }
LAB_0010a292:
      __dest = (uchar *)CRYPTO_malloc((int)(local_68 + 1),DAT_0010a2e4,0xcd);
      if (__dest == (uchar *)0x0) {
        iVar4 = 0x41;
LAB_0010a266:
        if ((a == (ASN1_STRING **)0x0) || (*a != a_00)) {
          ASN1_STRING_free(a_00);
        }
        ERR_put_error(0xd,0x8f,iVar4,DAT_0010a2e4,0xe9);
        return (ASN1_STRING *)0x0;
      }
    }
    else {
      __dest = a_00->data;
      if (__dest == (uchar *)0x0) goto LAB_0010a292;
    }
    memcpy(__dest,local_6c,(size_t)local_68);
    __dest[(int)local_68] = '\0';
    local_4c.p = local_6c + (int)local_68;
  }
  a_00->length = (int)local_68;
  a_00->data = __dest;
  a_00->type = local_64;
LAB_0010a206:
  if (a != (ASN1_STRING **)0x0) {
    *a = a_00;
  }
  *pp = local_4c.p;
  return a_00;
}

