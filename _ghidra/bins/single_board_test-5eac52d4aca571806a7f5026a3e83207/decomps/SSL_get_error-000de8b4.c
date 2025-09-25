
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
      return 5;
    }
    return 1;
  }
  iVar2 = SSL_want(s);
  if (iVar2 == 3) {
    b = SSL_get_rbio(s);
    iVar2 = BIO_test_flags(b,1);
    if (iVar2 != 0) {
      return 2;
    }
    iVar2 = BIO_test_flags(b,2);
    if (iVar2 != 0) {
      return 3;
    }
    iVar2 = BIO_test_flags(b,4);
    if (iVar2 != 0) goto LAB_000de94c;
  }
  iVar2 = SSL_want(s);
  if (iVar2 == 2) {
    b = s->rbio;
    iVar2 = BIO_test_flags(b,2);
    if (iVar2 != 0) {
      return 3;
    }
    iVar2 = BIO_test_flags(b,1);
    if (iVar2 != 0) {
      return 2;
    }
    iVar2 = BIO_test_flags(b,4);
    if (iVar2 != 0) {
LAB_000de94c:
      iVar2 = BIO_get_retry_reason(b);
      if (iVar2 == 2) {
        return 7;
      }
      if (iVar2 != 3) {
        return 5;
      }
      return 8;
    }
  }
  iVar2 = SSL_want(s);
  if (iVar2 != 4) {
    iVar2 = SSL_want(s);
    if (iVar2 == 5) {
      return 9;
    }
    iVar2 = SSL_want(s);
    if (iVar2 == 6) {
      return 10;
    }
    iVar2 = SSL_want(s);
    if (iVar2 != 7) {
      if (-1 < s->new_session << 0x1e) {
        return 5;
      }
      if (*(int *)(s->mac_flags + 0xe0) != 0) {
        return 5;
      }
      return 6;
    }
    iVar2 = 0xb;
  }
  return iVar2;
}

