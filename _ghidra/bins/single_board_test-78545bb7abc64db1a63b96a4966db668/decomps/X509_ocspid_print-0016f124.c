
int X509_ocspid_print(BIO *bp,X509 *x)

{
  int iVar1;
  X509_NAME *a;
  size_t sVar2;
  uchar *data;
  EVP_MD *pEVar3;
  ASN1_BIT_STRING *x_00;
  void *data_00;
  byte *pbVar4;
  uchar *local_40;
  byte abStack_3c [20];
  byte abStack_28 [4];
  byte *pbVar5;
  
  iVar1 = BIO_printf(bp,"        Subject OCSP hash: ");
  if (0 < iVar1) {
    a = X509_get_subject_name(x);
    sVar2 = i2d_X509_NAME(a,(uchar **)0x0);
    data = (uchar *)CRYPTO_malloc(sVar2,"crypto/x509/t_x509.c",0xee);
    local_40 = data;
    if (data != (uchar *)0x0) {
      i2d_X509_NAME(a,&local_40);
      pEVar3 = EVP_sha1();
      iVar1 = EVP_Digest(data,sVar2,abStack_3c,(uint *)0x0,pEVar3,(ENGINE *)0x0);
      if (iVar1 == 0) goto LAB_0016f20c;
      pbVar5 = abStack_3c;
      do {
        pbVar4 = pbVar5 + 1;
        iVar1 = BIO_printf(bp,"%02X",(uint)*pbVar5);
        if (iVar1 < 1) goto LAB_0016f20c;
        pbVar5 = pbVar4;
      } while (pbVar4 != abStack_28);
      CRYPTO_free(data);
      iVar1 = BIO_printf(bp,"\n        Public key OCSP hash: ");
      if ((0 < iVar1) && (x_00 = X509_get0_pubkey_bitstr(x), x_00 != (ASN1_BIT_STRING *)0x0)) {
        data_00 = (void *)ASN1_STRING_get0_data();
        sVar2 = ASN1_STRING_length(x_00);
        pEVar3 = EVP_sha1();
        iVar1 = EVP_Digest(data_00,sVar2,abStack_3c,(uint *)0x0,pEVar3,(ENGINE *)0x0);
        pbVar5 = abStack_3c;
        if (iVar1 != 0) {
          while( true ) {
            pbVar4 = pbVar5 + 1;
            iVar1 = BIO_printf(bp,"%02X",(uint)*pbVar5);
            if (iVar1 < 1) break;
            pbVar5 = pbVar4;
            if (pbVar4 == abStack_28) {
              BIO_printf(bp,"\n");
              return 1;
            }
          }
        }
      }
    }
  }
  data = (uchar *)0x0;
LAB_0016f20c:
  CRYPTO_free(data);
  return 0;
}

