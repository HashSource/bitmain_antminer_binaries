
int PEM_write_bio_ASN1_stream(BIO *out,ASN1_VALUE *val,BIO *in,int flags,char *hdr,ASN1_ITEM *it)

{
  BIO_METHOD *type;
  BIO *b;
  BIO *out_00;
  int iVar1;
  
  BIO_printf(out,"-----BEGIN %s-----\n",hdr);
  type = BIO_f_base64();
  b = BIO_new(type);
  if (b == (BIO *)0x0) {
    ERR_put_error(0xd,0xd2,0x41,"crypto/asn1/asn_mime.c",0x69);
    iVar1 = 0;
  }
  else {
    out_00 = BIO_push(b,out);
    iVar1 = i2d_ASN1_bio_stream(out_00,val,in,flags,it);
    BIO_ctrl(out_00,0xb,0,(void *)0x0);
    BIO_pop(out_00);
    BIO_free(b);
  }
  BIO_printf(out,"-----END %s-----\n",hdr);
  return iVar1;
}

