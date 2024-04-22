
int X509_ocspid_print(BIO *bp,X509 *x)

{
  int iVar1;
  size_t sVar2;
  uchar *puVar3;
  EVP_MD *pEVar4;
  ASN1_BIT_STRING *pAVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined4 local_38;
  byte local_34 [24];
  
  iVar1 = BIO_printf(bp,DAT_000b81a4);
  if (0 < iVar1) {
    sVar2 = i2d_X509_NAME(x->cert_info->subject,(uchar **)0x0);
    puVar3 = (uchar *)CRYPTO_malloc(sVar2,DAT_000b81a8,0x117);
    if (puVar3 != (uchar *)0x0) {
      local_38 = puVar3;
      i2d_X509_NAME(x->cert_info->subject,(uchar **)&local_38);
      pEVar4 = EVP_sha1();
      iVar1 = EVP_Digest(puVar3,sVar2,local_34,(uint *)0x0,pEVar4,(ENGINE *)0x0);
      if (iVar1 == 0) {
LAB_000b817a:
        CRYPTO_free(puVar3);
        return 0;
      }
      pbVar7 = (byte *)((int)&local_38 + 3);
      pbVar6 = pbVar7;
      do {
        pbVar6 = pbVar6 + 1;
        iVar1 = BIO_printf(bp,DAT_000b81ac,(uint)*pbVar6);
        if (iVar1 < 1) goto LAB_000b817a;
      } while (pbVar6 != local_34 + 0x13);
      CRYPTO_free(puVar3);
      iVar1 = BIO_printf(bp,DAT_000b81b0);
      if (0 < iVar1) {
        pAVar5 = x->cert_info->key->public_key;
        puVar3 = pAVar5->data;
        sVar2 = pAVar5->length;
        pEVar4 = EVP_sha1();
        iVar1 = EVP_Digest(puVar3,sVar2,local_34,(uint *)0x0,pEVar4,(ENGINE *)0x0);
        if (iVar1 != 0) {
          while( true ) {
            pbVar7 = pbVar7 + 1;
            iVar1 = BIO_printf(bp,DAT_000b81ac,(uint)*pbVar7);
            if (iVar1 < 1) break;
            if (local_34 + 0x13 == pbVar7) {
              BIO_printf(bp,DAT_000b81b4);
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

