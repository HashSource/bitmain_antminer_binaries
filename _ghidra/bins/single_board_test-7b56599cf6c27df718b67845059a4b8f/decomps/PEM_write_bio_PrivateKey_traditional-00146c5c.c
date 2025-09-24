
int PEM_write_bio_PrivateKey_traditional
              (BIO *param_1,void *param_2,EVP_CIPHER *param_3,uchar *param_4,int param_5,
              undefined1 *param_6,void *param_7)

{
  int iVar1;
  char acStack_70 [84];
  
  iVar1 = *(int *)((int)param_2 + 0xc);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 100) != 0)) {
    BIO_snprintf(acStack_70,0x50,"%s PRIVATE KEY",*(undefined4 *)(iVar1 + 0xc));
    iVar1 = PEM_ASN1_write_bio((undefined1 *)0x185509,acStack_70,param_1,param_2,param_3,param_4,
                               param_5,param_6,param_7);
    return iVar1;
  }
  ERR_put_error(9,0x93,0x6e,"crypto/pem/pem_pkey.c",0x72);
  return 0;
}

