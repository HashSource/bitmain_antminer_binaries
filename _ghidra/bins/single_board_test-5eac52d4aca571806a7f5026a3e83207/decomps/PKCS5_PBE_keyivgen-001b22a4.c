
int PKCS5_PBE_keyivgen(EVP_CIPHER_CTX *ctx,char *pass,int passlen,ASN1_TYPE *param,
                      EVP_CIPHER *cipher,EVP_MD *md,int en_de)

{
  PBEPARAM *a;
  uint __n;
  uint __n_00;
  EVP_MD_CTX *ctx_00;
  int iVar1;
  int iVar2;
  uchar *d;
  size_t sVar3;
  long lVar4;
  uchar auStack_b8 [16];
  uchar auStack_a8 [16];
  uchar auStack_98 [48];
  uchar auStack_68 [68];
  
  if (((param == (ASN1_TYPE *)0x0) || (param->type != 0x10)) || ((param->value).ptr == (char *)0x0))
  {
    ERR_put_error(6,0x75,0x72,"crypto/evp/p5_crpt.c",0x29);
  }
  else {
    a = (PBEPARAM *)ASN1_TYPE_unpack_sequence(&PBEPARAM_it,param);
    if (a != (PBEPARAM *)0x0) {
      __n = EVP_CIPHER_iv_length(cipher);
      if (__n < 0x11) {
        __n_00 = EVP_CIPHER_key_length(cipher);
        if (__n_00 < 0x41) {
          lVar4 = 1;
          if (a->iter != (ASN1_INTEGER *)0x0) {
            lVar4 = ASN1_INTEGER_get(a->iter);
          }
          d = a->salt->data;
          sVar3 = a->salt->length;
          if (pass == (char *)0x0) {
            passlen = 0;
          }
          else if (passlen == -1) {
            passlen = strlen(pass);
          }
          ctx_00 = (EVP_MD_CTX *)EVP_MD_CTX_new();
          if (ctx_00 == (EVP_MD_CTX *)0x0) {
            ERR_put_error(6,0x75,0x41,"crypto/evp/p5_crpt.c",0x4e);
            iVar1 = 0;
          }
          else {
            iVar1 = EVP_DigestInit_ex(ctx_00,md,(ENGINE *)0x0);
            if (((iVar1 != 0) && (iVar1 = EVP_DigestUpdate(ctx_00,pass,passlen), iVar1 != 0)) &&
               (iVar1 = EVP_DigestUpdate(ctx_00,d,sVar3), iVar1 != 0)) {
              PBEPARAM_free(a);
              iVar1 = EVP_DigestFinal_ex(ctx_00,auStack_a8,(uint *)0x0);
              if (iVar1 != 0) {
                sVar3 = EVP_MD_size(md);
                if ((int)sVar3 < 0) {
                  return 0;
                }
                if (1 < lVar4) {
                  iVar1 = 1;
                  do {
                    iVar1 = iVar1 + 1;
                    iVar2 = EVP_DigestInit_ex(ctx_00,md,(ENGINE *)0x0);
                    if (((iVar2 == 0) ||
                        (iVar2 = EVP_DigestUpdate(ctx_00,auStack_a8,sVar3), iVar2 == 0)) ||
                       (iVar2 = EVP_DigestFinal_ex(ctx_00,auStack_a8,(uint *)0x0), iVar2 == 0))
                    goto LAB_001b239e;
                  } while (lVar4 != iVar1);
                }
                memcpy(auStack_68,auStack_a8,__n_00);
                memcpy(auStack_b8,auStack_a8 + (0x10 - __n),__n);
                iVar1 = EVP_CipherInit_ex(ctx,cipher,(ENGINE *)0x0,auStack_68,auStack_b8,en_de);
                if (iVar1 != 0) {
                  OPENSSL_cleanse(auStack_a8,0x40);
                  OPENSSL_cleanse(auStack_68,0x40);
                  OPENSSL_cleanse(auStack_b8,0x10);
                  iVar1 = 1;
                  a = (PBEPARAM *)0x0;
                  goto LAB_001b233a;
                }
              }
LAB_001b239e:
              iVar1 = 0;
              a = (PBEPARAM *)0x0;
            }
          }
LAB_001b233a:
          PBEPARAM_free(a);
          EVP_MD_CTX_free(ctx_00);
          return iVar1;
        }
        iVar2 = 0x3b;
        iVar1 = 0x82;
      }
      else {
        iVar2 = 0x35;
        iVar1 = 0xc2;
      }
      ERR_put_error(6,0x75,iVar1,"crypto/evp/p5_crpt.c",iVar2);
      PBEPARAM_free(a);
      return 0;
    }
    ERR_put_error(6,0x75,0x72,"crypto/evp/p5_crpt.c",0x2f);
  }
  return 0;
}

