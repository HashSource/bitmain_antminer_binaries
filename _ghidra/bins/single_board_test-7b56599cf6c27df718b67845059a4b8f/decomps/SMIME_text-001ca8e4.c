
int SMIME_text(BIO *in,BIO *out)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char *local_1020;
  undefined4 uStack_101c;
  undefined4 local_1018;
  
  iVar1 = mime_parse_hdr();
  if (iVar1 == 0) {
    ERR_put_error(0xd,0xd5,0xcf,"crypto/asn1/asn_mime.c",0x21d);
    return 0;
  }
  local_1018 = 0;
  local_1020 = "content-type";
  uStack_101c = 0;
  uVar2 = OPENSSL_sk_find(iVar1,&local_1020);
  iVar3 = OPENSSL_sk_value(iVar1,uVar2);
  if ((iVar3 != 0) && (*(char **)(iVar3 + 4) != (char *)0x0)) {
    iVar4 = strcmp(*(char **)(iVar3 + 4),"text/plain");
    if (iVar4 != 0) {
      ERR_put_error(0xd,0xd5,0xcd,"crypto/asn1/asn_mime.c",0x227);
      ERR_add_error_data(2,"type: ",*(undefined4 *)(iVar3 + 4));
      OPENSSL_sk_pop_free(iVar1,0x1c9399);
      return 0;
    }
    OPENSSL_sk_pop_free(iVar1,0x1c9399);
    while( true ) {
      iVar1 = BIO_read(in,&local_1020,0x1000);
      if (iVar1 < 1) break;
      BIO_write(out,&local_1020,iVar1);
    }
    return (uint)(iVar1 == 0);
  }
  ERR_put_error(0xd,0xd5,0xce,"crypto/asn1/asn_mime.c",0x222);
  OPENSSL_sk_pop_free(iVar1,0x1c9399);
  return 0;
}

