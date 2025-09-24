
int PKCS5_v2_PBE_keyivgen
              (EVP_CIPHER_CTX *ctx,char *pass,int passlen,ASN1_TYPE *param,EVP_CIPHER *cipher,
              EVP_MD *md,int en_de)

{
  PBE2PARAM *a;
  int iVar1;
  char *name;
  EVP_CIPHER *cipher_00;
  code *local_24 [2];
  
  a = (PBE2PARAM *)ASN1_TYPE_unpack_sequence(PBE2PARAM_it,param,passlen,&_GLOBAL_OFFSET_TABLE_);
  if (a == (PBE2PARAM *)0x0) {
    ERR_put_error(6,0x76,0x72,"crypto/evp/p5_crpt2.c",0x96);
    PBE2PARAM_free((PBE2PARAM *)0x0);
    return 0;
  }
  iVar1 = OBJ_obj2nid(a->keyfunc->algorithm);
  iVar1 = EVP_PBE_find(2,iVar1,(int *)0x0,(int *)0x0,local_24);
  if (iVar1 != 0) {
    iVar1 = OBJ_obj2nid(a->encryption->algorithm);
    name = OBJ_nid2sn(iVar1);
    cipher_00 = EVP_get_cipherbyname(name);
    if (cipher_00 == (EVP_CIPHER *)0x0) {
      ERR_put_error(6,0x76,0x6b,"crypto/evp/p5_crpt2.c",0xa9);
      iVar1 = 0;
    }
    else {
      iVar1 = EVP_CipherInit_ex(ctx,cipher_00,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,en_de);
      if (iVar1 != 0) {
        iVar1 = EVP_CIPHER_asn1_to_param(ctx,a->encryption->parameter);
        if (-1 < iVar1) {
          iVar1 = (*local_24[0])(ctx,pass,passlen,a->keyfunc->parameter,0,0,en_de);
          PBE2PARAM_free(a);
          return iVar1;
        }
        iVar1 = 0;
        ERR_put_error(6,0x76,0x7a,"crypto/evp/p5_crpt2.c",0xb1);
      }
    }
    PBE2PARAM_free(a);
    return iVar1;
  }
  ERR_put_error(6,0x76,0x7c,"crypto/evp/p5_crpt2.c",0x9e);
  PBE2PARAM_free(a);
  return 0;
}

