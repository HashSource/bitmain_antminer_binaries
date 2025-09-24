
int PKCS12_PBE_keyivgen(EVP_CIPHER_CTX *ctx,char *pass,int passlen,ASN1_TYPE *param,
                       EVP_CIPHER *cipher,EVP_MD *md_type,int en_de)

{
  PBEPARAM *a;
  int iVar1;
  uchar *puVar2;
  int iVar3;
  long lVar4;
  uchar auStack_78 [16];
  uchar auStack_68 [68];
  
  if (cipher == (EVP_CIPHER *)0x0) {
    return 0;
  }
  a = (PBEPARAM *)ASN1_TYPE_unpack_sequence(&PBEPARAM_it,param);
  if (a == (PBEPARAM *)0x0) {
    ERR_put_error(0x23,0x78,0x65,"crypto/pkcs12/p12_crpt.c",0x2b);
    return 0;
  }
  lVar4 = 1;
  if (a->iter != (ASN1_INTEGER *)0x0) {
    lVar4 = ASN1_INTEGER_get(a->iter);
  }
  puVar2 = a->salt->data;
  iVar3 = a->salt->length;
  iVar1 = EVP_CIPHER_key_length(cipher);
  iVar1 = PKCS12_key_gen_utf8(pass,passlen,puVar2,iVar3,1,lVar4,iVar1,auStack_68,md_type);
  if (iVar1 == 0) {
    iVar3 = 0x37;
    iVar1 = 0x6b;
  }
  else {
    iVar1 = EVP_CIPHER_iv_length(cipher);
    iVar1 = PKCS12_key_gen_utf8(pass,passlen,puVar2,iVar3,2,lVar4,iVar1,auStack_78,md_type);
    if (iVar1 != 0) {
      PBEPARAM_free(a);
      iVar1 = EVP_CipherInit_ex(ctx,cipher,(ENGINE *)0x0,auStack_68,auStack_78,en_de);
      OPENSSL_cleanse(auStack_68,0x40);
      OPENSSL_cleanse(auStack_78,0x10);
      return iVar1;
    }
    iVar3 = 0x3d;
    iVar1 = 0x6a;
  }
  ERR_put_error(0x23,0x78,iVar1,"crypto/pkcs12/p12_crpt.c",iVar3);
  PBEPARAM_free(a);
  return 0;
}

