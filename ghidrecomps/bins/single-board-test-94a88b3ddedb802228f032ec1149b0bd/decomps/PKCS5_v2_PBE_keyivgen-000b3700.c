
int PKCS5_v2_PBE_keyivgen
              (EVP_CIPHER_CTX *ctx,char *pass,int passlen,ASN1_TYPE *param,EVP_CIPHER *cipher,
              EVP_MD *md,int en_de)

{
  char *name;
  EVP_CIPHER *cipher_00;
  int iVar1;
  ASN1_STRING *pAVar2;
  PBE2PARAM *a;
  int iVar3;
  uchar *local_1c;
  
  if (((param == (ASN1_TYPE *)0x0) || (param->type != 0x10)) ||
     (pAVar2 = (param->value).asn1_string, pAVar2 == (ASN1_STRING *)0x0)) {
    iVar3 = 0;
    a = (PBE2PARAM *)0x0;
    ERR_put_error(6,0x76,0x72,DAT_000b380c,0xcb);
  }
  else {
    local_1c = pAVar2->data;
    a = d2i_PBE2PARAM((PBE2PARAM **)0x0,&local_1c,pAVar2->length);
    if (a == (PBE2PARAM *)0x0) {
      ERR_put_error(6,0x76,0x72,DAT_000b380c,0xd2);
      iVar3 = 0;
    }
    else {
      iVar3 = OBJ_obj2nid(a->keyfunc->algorithm);
      if (iVar3 == 0x45) {
        iVar3 = OBJ_obj2nid(a->encryption->algorithm);
        name = OBJ_nid2sn(iVar3);
        cipher_00 = EVP_get_cipherbyname(name);
        if (cipher_00 == (EVP_CIPHER *)0x0) {
          ERR_put_error(6,0x76,0x6b,DAT_000b380c,0xe5);
          iVar3 = 0;
        }
        else {
          iVar3 = 0;
          iVar1 = EVP_CipherInit_ex(ctx,cipher_00,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,en_de);
          if (iVar1 == 0) {
            iVar3 = 0;
          }
          else {
            iVar1 = EVP_CIPHER_asn1_to_param(ctx,a->encryption->parameter);
            if (iVar1 < 0) {
              ERR_put_error(6,0x76,0x7a,DAT_000b380c,0xed);
            }
            else {
              iVar3 = PKCS5_v2_PBKDF2_keyivgen
                                (ctx,pass,passlen,a->keyfunc->parameter,cipher,md,en_de);
            }
          }
        }
      }
      else {
        ERR_put_error(6,0x76,0x7c,DAT_000b380c,0xda);
        iVar3 = 0;
      }
    }
  }
  PBE2PARAM_free(a);
  return iVar3;
}

