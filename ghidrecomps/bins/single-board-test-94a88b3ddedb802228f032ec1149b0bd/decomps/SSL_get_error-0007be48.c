
int SSL_get_error(SSL *s,int ret_code)

{
  ulong uVar1;
  int iVar2;
  BIO *b;
  
  if (0 < ret_code) {
    return 0;
  }
  uVar1 = ERR_peek_error();
  if (uVar1 != 0) {
    if (uVar1 >> 0x18 == 2) {
      iVar2 = 5;
    }
    else {
      iVar2 = 1;
    }
    return iVar2;
  }
  if (ret_code == 0) {
    if (s->version != 2) {
      if (-1 < s->shutdown << 0x1e) {
        return 5;
      }
      if (s->s3->warn_alert != 0) {
        return 5;
      }
    }
    return 6;
  }
  iVar2 = s->rwstate;
  if (iVar2 == 3) {
    b = s->rbio;
    iVar2 = BIO_test_flags(b,1);
    if (iVar2 != 0) {
      return 2;
    }
    iVar2 = BIO_test_flags(b,2);
    if (iVar2 != 0) {
      return 3;
    }
    iVar2 = BIO_test_flags(b,4);
    if (iVar2 == 0) {
      iVar2 = s->rwstate;
      goto LAB_0007be8c;
    }
LAB_0007beea:
    iVar2 = BIO_get_retry_reason(b);
    if (iVar2 == 2) {
      return 7;
    }
    if (iVar2 == 3) {
      return 8;
    }
  }
  else {
LAB_0007be8c:
    if (iVar2 == 2) {
      b = s->wbio;
      iVar2 = BIO_test_flags(b,2);
      if (iVar2 != 0) {
        return 3;
      }
      iVar2 = BIO_test_flags(b,1);
      if (iVar2 != 0) {
        return 2;
      }
      iVar2 = BIO_test_flags(b,4);
      if (iVar2 != 0) goto LAB_0007beea;
      iVar2 = s->rwstate;
    }
    if (iVar2 == 4) {
      return 4;
    }
  }
  return 5;
}

