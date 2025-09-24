
int SMIME_crlf_copy(BIO *in,BIO *out,int flags)

{
  char cVar1;
  bool bVar2;
  BIO_METHOD *type;
  BIO *b;
  BIO *b_00;
  int len;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char acStack_428 [1028];
  
  type = BIO_f_buffer();
  b = BIO_new(type);
  if (b != (BIO *)0x0) {
    b_00 = BIO_push(b,out);
    if (flags << 0x18 < 0) {
      while (iVar6 = BIO_read(in,acStack_428,0x400), 0 < iVar6) {
        BIO_write(b_00,acStack_428,iVar6);
      }
    }
    else {
      if (flags << 0x1f < 0) {
        BIO_printf(b_00,"Content-Type: text/plain\r\n\r\n");
      }
      uVar5 = flags & 0x80000;
      iVar6 = 0;
LAB_001ca104:
      len = BIO_gets(in,acStack_428,0x400);
      if (0 < len) {
        pcVar4 = acStack_428 + len;
        bVar2 = false;
LAB_001ca132:
        pcVar4 = pcVar4 + -1;
        cVar1 = *pcVar4;
        if (cVar1 == '\n') {
LAB_001ca13a:
          bVar2 = true;
        }
        else {
          uVar3 = uVar5;
          if (uVar5 != 0) {
            uVar3 = 1;
          }
          if (cVar1 != ' ') {
            uVar3 = 0;
          }
          if ((bVar2) && (uVar3 != 0)) goto LAB_001ca13a;
          if (cVar1 != '\r') {
            if (uVar5 != 0) {
              if (iVar6 != 0) {
                iVar7 = 0;
                do {
                  iVar7 = iVar7 + 1;
                  BIO_write(b_00,"\r\n",2);
                } while (iVar6 != iVar7);
              }
              iVar6 = 0;
            }
            BIO_write(b_00,acStack_428,len);
            if (bVar2) {
              BIO_write(b_00,"\r\n",2);
            }
            goto LAB_001ca104;
          }
        }
        len = len + -1;
        if (len == 0) goto LAB_001ca142;
        goto LAB_001ca132;
      }
    }
    BIO_ctrl(b_00,0xb,0,(void *)0x0);
    BIO_pop(b_00);
    BIO_free(b);
    b = (BIO *)0x1;
  }
  return (int)b;
LAB_001ca142:
  if (uVar5 == 0) {
    if (bVar2) {
      BIO_write(b_00,"\r\n",2);
    }
  }
  else {
    iVar6 = iVar6 + 1;
  }
  goto LAB_001ca104;
}

