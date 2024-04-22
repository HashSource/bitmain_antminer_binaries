
int PKCS12_PBE_keyivgen(EVP_CIPHER_CTX *ctx,char *pass,int passlen,ASN1_TYPE *param,
                       EVP_CIPHER *cipher,EVP_MD *md_type,int en_de)

{
  PBEPARAM *a;
  ASN1_STRING *pAVar1;
  int iVar2;
  int saltlen;
  uchar *salt;
  long local_84;
  uchar *local_7c;
  uchar auStack_78 [16];
  uchar auStack_68 [68];
  
  if (((param == (ASN1_TYPE *)0x0) || (param->type != 0x10)) ||
     (pAVar1 = (param->value).asn1_string, pAVar1 == (ASN1_STRING *)0x0)) {
    iVar2 = 0;
    ERR_put_error(0x23,0x78,0x65,DAT_000d1488,0x53);
  }
  else {
    local_7c = pAVar1->data;
    a = d2i_PBEPARAM((PBEPARAM **)0x0,&local_7c,pAVar1->length);
    if (a == (PBEPARAM *)0x0) {
      ERR_put_error(0x23,0x78,0x65,DAT_000d1488,0x59);
      iVar2 = 0;
    }
    else {
      if (a->iter == (ASN1_INTEGER *)0x0) {
        local_84 = 1;
      }
      else {
        local_84 = ASN1_INTEGER_get(a->iter);
      }
      salt = a->salt->data;
      saltlen = a->salt->length;
      iVar2 = EVP_CIPHER_key_length(cipher);
      iVar2 = PKCS12_key_gen_asc(pass,passlen,salt,saltlen,1,local_84,iVar2,auStack_68,md_type);
      if (iVar2 == 0) {
        ERR_put_error(0x23,0x78,0x6b,DAT_000d1488,0x65);
        PBEPARAM_free(a);
        iVar2 = 0;
      }
      else {
        iVar2 = EVP_CIPHER_iv_length(cipher);
        iVar2 = PKCS12_key_gen_asc(pass,passlen,salt,saltlen,2,local_84,iVar2,auStack_78,md_type);
        if (iVar2 == 0) {
          ERR_put_error(0x23,0x78,0x6a,DAT_000d1488,0x6b);
          PBEPARAM_free(a);
          iVar2 = 0;
        }
        else {
          PBEPARAM_free(a);
          iVar2 = EVP_CipherInit_ex(ctx,cipher,(ENGINE *)0x0,auStack_68,auStack_78,en_de);
          OPENSSL_cleanse(auStack_68,0x40);
          OPENSSL_cleanse(auStack_78,0x10);
        }
      }
    }
  }
  return iVar2;
}

