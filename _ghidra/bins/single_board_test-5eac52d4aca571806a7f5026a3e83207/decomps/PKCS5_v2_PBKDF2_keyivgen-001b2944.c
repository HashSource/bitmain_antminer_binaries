
int PKCS5_v2_PBKDF2_keyivgen
              (EVP_CIPHER_CTX *param_1,char *param_2,int param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,int param_7)

{
  EVP_CIPHER *pEVar1;
  size_t len;
  PBKDF2PARAM *a;
  uint uVar2;
  char *name;
  EVP_MD *digest;
  long iter;
  int iVar3;
  uchar *salt;
  int iVar4;
  ASN1_STRING *pAVar5;
  int local_6c;
  uchar auStack_68 [68];
  
  pEVar1 = EVP_CIPHER_CTX_cipher(param_1);
  if (pEVar1 == (EVP_CIPHER *)0x0) {
    ERR_put_error(6,0xa4,0x83,"crypto/evp/p5_crpt2.c",199);
    a = (PBKDF2PARAM *)0x0;
    iVar3 = 0;
    len = 0;
  }
  else {
    len = EVP_CIPHER_CTX_key_length(param_1);
    if (0x40 < len) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: keylen <= sizeof(key)","crypto/evp/p5_crpt2.c",0xcb);
    }
    a = (PBKDF2PARAM *)ASN1_TYPE_unpack_sequence(&PBKDF2PARAM_it,param_4);
    if (a == (PBKDF2PARAM *)0x0) {
      iVar4 = 0xd2;
      iVar3 = 0x72;
    }
    else {
      len = EVP_CIPHER_CTX_key_length(param_1);
      if ((a->keylength == (ASN1_INTEGER *)0x0) ||
         (uVar2 = ASN1_INTEGER_get(a->keylength), len == uVar2)) {
        iVar3 = 0xa3;
        if (a->prf != (X509_ALGOR *)0x0) {
          iVar3 = OBJ_obj2nid(a->prf->algorithm);
        }
        iVar3 = EVP_PBE_find(1,iVar3,(int *)0x0,&local_6c,(undefined1 **)0x0);
        if (iVar3 == 0) {
          iVar4 = 0xe5;
        }
        else {
          name = OBJ_nid2sn(local_6c);
          digest = EVP_get_digestbyname(name);
          if (digest != (EVP_MD *)0x0) {
            if (a->salt->type == 4) {
              pAVar5 = (a->salt->value).asn1_string;
              salt = pAVar5->data;
              iVar3 = pAVar5->length;
              iter = ASN1_INTEGER_get(a->iter);
              iVar3 = PKCS5_PBKDF2_HMAC(param_2,param_3,salt,iVar3,iter,digest,len,auStack_68);
              if (iVar3 != 0) {
                iVar3 = EVP_CipherInit_ex(param_1,(EVP_CIPHER *)0x0,(ENGINE *)0x0,auStack_68,
                                          (uchar *)0x0,param_7);
              }
            }
            else {
              iVar3 = 0;
              ERR_put_error(6,0xa4,0x7e,"crypto/evp/p5_crpt2.c",0xf0);
            }
            goto LAB_001b29e8;
          }
          iVar4 = 0xeb;
        }
        iVar3 = 0;
        ERR_put_error(6,0xa4,0x7d,"crypto/evp/p5_crpt2.c",iVar4);
        goto LAB_001b29e8;
      }
      iVar4 = 0xdb;
      iVar3 = 0x7b;
    }
    ERR_put_error(6,0xa4,iVar3,"crypto/evp/p5_crpt2.c",iVar4);
    iVar3 = 0;
  }
LAB_001b29e8:
  OPENSSL_cleanse(auStack_68,len);
  PBKDF2PARAM_free(a);
  return iVar3;
}

