
int PKCS5_v2_PBKDF2_keyivgen
              (EVP_CIPHER_CTX *param_1,char *param_2,int param_3,int *param_4,undefined4 param_5,
              undefined4 param_6,int param_7)

{
  EVP_CIPHER *pEVar1;
  size_t len;
  size_t sVar2;
  char *name;
  EVP_MD *digest;
  long iter;
  int iVar3;
  uchar *salt;
  ASN1_STRING *pAVar4;
  PBKDF2PARAM *a;
  int iVar5;
  uchar *local_70;
  int local_6c;
  uchar auStack_68 [68];
  
  pEVar1 = EVP_CIPHER_CTX_cipher(param_1);
  if (pEVar1 == (EVP_CIPHER *)0x0) {
    ERR_put_error(6,0xa4,0x83,DAT_000b36f8,0x105);
    a = (PBKDF2PARAM *)0x0;
    len = 0;
    iVar5 = 0;
  }
  else {
    len = EVP_CIPHER_CTX_key_length(param_1);
    if (0x40 < len) {
      OpenSSLDie(DAT_000b36f8,0x109,DAT_000b36fc);
    }
    if ((param_4 == (int *)0x0) || (*param_4 != 0x10)) {
      a = (PBKDF2PARAM *)0x0;
      iVar5 = 0;
      ERR_put_error(6,0xa4,0x72,DAT_000b36f8,0x10e);
    }
    else {
      local_70 = (uchar *)((long *)param_4[1])[2];
      a = d2i_PBKDF2PARAM((PBKDF2PARAM **)0x0,&local_70,*(long *)param_4[1]);
      if (a == (PBKDF2PARAM *)0x0) {
        ERR_put_error(6,0xa4,0x72,DAT_000b36f8,0x116);
        iVar5 = 0;
      }
      else {
        len = EVP_CIPHER_CTX_key_length(param_1);
        if ((a->keylength == (ASN1_INTEGER *)0x0) ||
           (sVar2 = ASN1_INTEGER_get(a->keylength), len == sVar2)) {
          iVar3 = 0xa3;
          if (a->prf != (X509_ALGOR *)0x0) {
            iVar3 = OBJ_obj2nid(a->prf->algorithm);
          }
          iVar5 = 0;
          iVar3 = EVP_PBE_find(1,iVar3,(int *)0x0,&local_6c,(undefined1 **)0x0);
          if (iVar3 == 0) {
            ERR_put_error(6,0xa4,0x7d,DAT_000b36f8,0x129);
            iVar5 = 0;
          }
          else {
            name = OBJ_nid2sn(local_6c);
            digest = EVP_get_digestbyname(name);
            if (digest == (EVP_MD *)0x0) {
              ERR_put_error(6,0xa4,0x7d,DAT_000b36f8,0x12f);
              iVar5 = 0;
            }
            else if (a->salt->type == 4) {
              pAVar4 = (a->salt->value).asn1_string;
              salt = pAVar4->data;
              iVar5 = pAVar4->length;
              iter = ASN1_INTEGER_get(a->iter);
              iVar5 = PKCS5_PBKDF2_HMAC(param_2,param_3,salt,iVar5,iter,digest,len,auStack_68);
              if (iVar5 == 0) {
                iVar5 = 0;
              }
              else {
                iVar5 = EVP_CipherInit_ex(param_1,(EVP_CIPHER *)0x0,(ENGINE *)0x0,auStack_68,
                                          (uchar *)0x0,param_7);
              }
            }
            else {
              ERR_put_error(6,0xa4,0x7e,DAT_000b36f8,0x134);
            }
          }
        }
        else {
          ERR_put_error(6,0xa4,0x7b,DAT_000b36f8,0x11f);
          iVar5 = 0;
        }
      }
    }
  }
  OPENSSL_cleanse(auStack_68,len);
  PBKDF2PARAM_free(a);
  return iVar5;
}

