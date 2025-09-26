
int SMIME_crlf_copy(BIO *in,BIO *out,int flags)

{
  bool bVar1;
  bool bVar2;
  BIO_METHOD *type;
  BIO *b;
  BIO *b_00;
  int iVar3;
  char acStack_421 [1029];
  
  type = BIO_f_buffer();
  b = BIO_new(type);
  if (b != (BIO *)0x0) {
    b_00 = BIO_push(b,out);
    if (flags << 0x18 < 0) {
      while (iVar3 = BIO_read(in,acStack_421 + 1,0x400), 0 < iVar3) {
        BIO_write(b_00,acStack_421 + 1,iVar3);
      }
    }
    else {
      if (flags << 0x1f < 0) {
        BIO_printf(b_00,"Content-Type: text/plain\r\n\r\n");
      }
LAB_001c1818:
      iVar3 = BIO_gets(in,acStack_421 + 1,0x400);
      if (0 < iVar3) {
        bVar1 = false;
        do {
          while (acStack_421[iVar3] == '\n') {
            iVar3 = iVar3 + -1;
            bVar1 = true;
            bVar2 = true;
            if (iVar3 == 0) goto LAB_001c1848;
          }
          if (acStack_421[iVar3] != '\r') {
            BIO_write(b_00,acStack_421 + 1,iVar3);
            if (bVar1) goto LAB_001c184e;
            goto LAB_001c1818;
          }
          iVar3 = iVar3 + -1;
          bVar2 = bVar1;
        } while (iVar3 != 0);
LAB_001c1848:
        if (bVar2) {
LAB_001c184e:
          BIO_write(b_00,"\r\n",2);
        }
        goto LAB_001c1818;
      }
    }
    BIO_ctrl(b_00,0xb,0,(void *)0x0);
    BIO_pop(b_00);
    BIO_free(b);
    b = (BIO *)0x1;
  }
  return (int)b;
}

