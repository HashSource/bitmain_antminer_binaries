
int PEM_bytes_read_bio(uchar **pdata,long *plen,char **pnm,char *name,BIO *bp,undefined1 *cb,void *u
                      )

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  EVP_PKEY_ASN1_METHOD *pEVar6;
  char *__s1;
  char *pcVar7;
  char *local_50;
  char *local_4c;
  uchar *local_48;
  long local_44;
  ENGINE *local_40;
  EVP_CIPHER_INFO EStack_3c;
  
  local_50 = (char *)0x0;
  local_4c = (char *)0x0;
  local_48 = (uchar *)0x0;
  while( true ) {
    iVar1 = PEM_read_bio(bp,&local_50,&local_4c,&local_48,&local_44);
    __s1 = local_50;
    if (iVar1 == 0) {
      uVar5 = ERR_peek_error();
      if ((uVar5 & 0xfff) == 0x6c) {
        ERR_add_error_data(2,DAT_000becd0,name);
      }
      return 0;
    }
    iVar1 = strcmp(local_50,name);
    if (iVar1 == 0) break;
    iVar1 = strcmp(name,DAT_000bec9c);
    if (iVar1 == 0) {
      iVar1 = strcmp(__s1,DAT_000beca0);
      if ((iVar1 == 0) || (iVar1 = strcmp(__s1,DAT_000beca4), iVar1 == 0)) break;
      sVar2 = strlen(__s1);
      if (0xc < (int)sVar2) {
        pcVar7 = __s1 + (sVar2 - 0xb);
        iVar1 = strcmp(pcVar7,DAT_000beca4);
        if (((iVar1 == 0) && (pcVar7[-1] == ' ')) &&
           ((0 < (int)(pcVar7 + (-1 - (int)__s1)) &&
            (pEVar6 = EVP_PKEY_asn1_find_str((ENGINE **)0x0,__s1,(int)(pcVar7 + (-1 - (int)__s1))),
            __s1 = local_50, pEVar6 != (EVP_PKEY_ASN1_METHOD *)0x0)))) {
          iVar1 = *(int *)(pEVar6 + 0x5c);
joined_r0x000beafe:
          __s1 = local_50;
          if (iVar1 != 0) break;
        }
      }
    }
    else {
      iVar1 = strcmp(name,DAT_000beca8);
      if (iVar1 != 0) {
        iVar1 = strcmp(__s1,DAT_000becac);
        if ((((((iVar1 != 0) || (iVar1 = strcmp(name,DAT_000becb0), iVar1 != 0)) &&
              ((iVar1 = strcmp(__s1,DAT_000becb4), iVar1 != 0 ||
               (iVar3 = strcmp(name,DAT_000becb8), iVar3 != 0)))) &&
             ((iVar3 = strcmp(__s1,DAT_000becbc), iVar3 != 0 ||
              (iVar3 = strcmp(name,DAT_000becc0), iVar3 != 0)))) &&
            ((iVar3 = strcmp(__s1,DAT_000becb8), iVar3 != 0 ||
             (iVar4 = strcmp(name,DAT_000becc4), iVar4 != 0)))) &&
           ((iVar1 != 0 || (iVar1 = strcmp(name,DAT_000becc4), iVar1 != 0)))) {
          if ((iVar3 == 0) && (iVar1 = strcmp(name,DAT_000beccc), iVar1 == 0)) {
            iVar1 = PEM_get_EVP_CIPHER_INFO(local_4c,&EStack_3c);
            goto joined_r0x000bec30;
          }
          iVar1 = strcmp(__s1,DAT_000becc8);
          if ((((iVar1 != 0) || (iVar1 = strcmp(name,DAT_000beccc), iVar1 != 0)) &&
              ((iVar3 != 0 ||
               ((((*name != 'C' || (name[1] != 'M')) || (name[2] != 'S')) || (name[3] != '\0'))))))
             && (((iVar1 = strcmp(__s1,DAT_000beccc), iVar1 != 0 || (*name != 'C')) ||
                 ((name[1] != 'M' || ((name[2] != 'S' || (name[3] != '\0')))))))) goto LAB_000bea94;
        }
        break;
      }
      sVar2 = strlen(__s1);
      if (0xb < (int)sVar2) {
        pcVar7 = __s1 + (sVar2 - 10);
        iVar1 = strcmp(pcVar7,DAT_000beca8);
        if ((((iVar1 == 0) && (pcVar7[-1] == ' ')) && (0 < (int)(pcVar7 + (-1 - (int)__s1)))) &&
           (pEVar6 = EVP_PKEY_asn1_find_str(&local_40,__s1,(int)(pcVar7 + (-1 - (int)__s1))),
           __s1 = local_50, pEVar6 != (EVP_PKEY_ASN1_METHOD *)0x0)) {
          iVar1 = *(int *)(pEVar6 + 0x38);
          if (local_40 != (ENGINE *)0x0) {
            ENGINE_finish(local_40);
          }
          goto joined_r0x000beafe;
        }
      }
    }
LAB_000bea94:
    CRYPTO_free(__s1);
    CRYPTO_free(local_4c);
    CRYPTO_free(local_48);
  }
  iVar1 = PEM_get_EVP_CIPHER_INFO(local_4c,&EStack_3c);
joined_r0x000bec30:
  if ((iVar1 != 0) && (iVar1 = PEM_do_header(&EStack_3c,local_48,&local_44,cb,u), iVar1 != 0)) {
    *pdata = local_48;
    *plen = local_44;
    if (pnm != (char **)0x0) {
      *pnm = local_50;
      CRYPTO_free(local_4c);
      return 1;
    }
    CRYPTO_free(local_50);
    CRYPTO_free(local_4c);
    return 1;
  }
  CRYPTO_free(local_50);
  CRYPTO_free(local_4c);
  CRYPTO_free(local_48);
  return 0;
}

