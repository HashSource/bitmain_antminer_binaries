
X509_PKEY * d2i_X509_PKEY(X509_PKEY **a,uchar **pp,long length)

{
  uchar *puVar1;
  int iVar2;
  X509_ALGOR *pXVar3;
  ASN1_OCTET_STRING *pAVar4;
  char *name;
  EVP_CIPHER *pEVar5;
  size_t __n;
  ASN1_TYPE *pAVar6;
  ASN1_STRING *pAVar7;
  X509_PKEY *ptr;
  uchar *local_4c [2];
  ASN1_const_CTX local_44;
  
  local_44.p = *pp;
  local_44.error = 0x3a;
  local_4c[0] = (uchar *)length;
  local_44.q = local_44.p;
  local_44.pp = pp;
  if ((a == (X509_PKEY **)0x0) || (ptr = *a, ptr == (X509_PKEY *)0x0)) {
    ptr = (X509_PKEY *)CRYPTO_malloc(0x34,DAT_00108ff8,0x6d);
    if (ptr == (X509_PKEY *)0x0) {
      ERR_put_error(0xd,0xad,0x41,DAT_00108ff8,0x6d);
LAB_00108fce:
      local_44.line = 0x4b;
      ERR_put_error(0xd,0x9f,local_44.error,DAT_00108ff8,0x4b);
      asn1_add_error(*pp,(int)local_44.q - (int)*pp);
      return (X509_PKEY *)0x0;
    }
    ptr->version = 0;
    pXVar3 = X509_ALGOR_new();
    ptr->enc_algor = pXVar3;
    if (pXVar3 == (X509_ALGOR *)0x0) goto LAB_00108fce;
    pAVar7 = ASN1_STRING_type_new(4);
    ptr->enc_pkey = pAVar7;
    if (pAVar7 == (ASN1_STRING *)0x0) goto LAB_00108fce;
    ptr->dec_pkey = (EVP_PKEY *)0x0;
    ptr->key_length = 0;
    ptr->key_data = (char *)0x0;
    ptr->key_free = 0;
    (ptr->cipher).cipher = (EVP_CIPHER *)0x0;
    memset((ptr->cipher).iv,0,0x10);
    local_44.p = *pp;
    ptr->references = 1;
  }
  local_44.max = local_4c[0];
  if (local_4c[0] != (uchar *)0x0) {
    local_44.max = local_44.p + (int)local_4c[0];
  }
  iVar2 = asn1_GetSequence(&local_44,(long *)local_4c);
  if (iVar2 == 0) {
    iVar2 = 0x4e;
    local_44.line = 0x4e;
  }
  else {
    local_44.q = local_44.p;
    pXVar3 = d2i_X509_ALGOR(&ptr->enc_algor,&local_44.p,local_44.slen);
    puVar1 = local_44.q;
    if (pXVar3 == (X509_ALGOR *)0x0) {
      iVar2 = 0x4f;
      local_44.line = 0x4f;
    }
    else {
      local_44.q = local_44.p;
      local_44.slen = (long)(puVar1 + (local_44.slen - (int)local_44.p));
      pAVar4 = d2i_ASN1_OCTET_STRING(&ptr->enc_pkey,&local_44.p,local_44.slen);
      if (pAVar4 == (ASN1_OCTET_STRING *)0x0) {
        iVar2 = 0x50;
        local_44.line = 0x50;
      }
      else {
        local_44.slen = (long)(local_44.q + (local_44.slen - (int)local_44.p));
        iVar2 = OBJ_obj2nid(ptr->enc_algor->algorithm);
        name = OBJ_nid2ln(iVar2);
        pEVar5 = EVP_get_cipherbyname(name);
        (ptr->cipher).cipher = pEVar5;
        if (pEVar5 == (EVP_CIPHER *)0x0) {
          iVar2 = 0x57;
          local_44.error = 0xa5;
          local_44.line = 0x57;
        }
        else {
          pAVar6 = ptr->enc_algor->parameter;
          if (pAVar6->type == 4) {
            pAVar7 = (pAVar6->value).asn1_string;
            __n = pAVar7->length;
            if (0x10 < (int)__n) {
              iVar2 = 0x5e;
              local_44.error = 0x87;
              local_44.line = 0x5e;
              goto LAB_00108e52;
            }
            memcpy((ptr->cipher).iv,pAVar7->data,__n);
          }
          else {
            memset((ptr->cipher).iv,0,0x10);
          }
          iVar2 = asn1_const_Finish(&local_44);
          if (iVar2 != 0) {
            *pp = local_44.p;
            if (a == (X509_PKEY **)0x0) {
              return ptr;
            }
            *a = ptr;
            return ptr;
          }
          iVar2 = 0x65;
          local_44.line = 0x65;
        }
      }
    }
  }
LAB_00108e52:
  ERR_put_error(0xd,0x9f,local_44.error,DAT_00108ff8,iVar2);
  asn1_add_error(*pp,(int)local_44.q - (int)*pp);
  if (((a == (X509_PKEY **)0x0) || (ptr != *a)) &&
     (iVar2 = CRYPTO_add_lock(&ptr->references,-1,5,DAT_00108ff8,0x83), iVar2 < 1)) {
    if (ptr->enc_algor != (X509_ALGOR *)0x0) {
      X509_ALGOR_free(ptr->enc_algor);
    }
    if (ptr->enc_pkey != (ASN1_STRING *)0x0) {
      ASN1_STRING_free(ptr->enc_pkey);
    }
    if (ptr->dec_pkey != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(ptr->dec_pkey);
    }
    if ((ptr->key_data != (char *)0x0) && (ptr->key_free != 0)) {
      CRYPTO_free(ptr->key_data);
    }
    CRYPTO_free(ptr);
    return (X509_PKEY *)0x0;
  }
  return (X509_PKEY *)0x0;
}

