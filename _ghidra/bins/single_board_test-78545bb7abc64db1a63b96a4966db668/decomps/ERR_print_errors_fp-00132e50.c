
void ERR_print_errors_fp(FILE *fp)

{
  BIO *a;
  
  a = BIO_new_fp(fp,0);
  if (a != (BIO *)0x0) {
    ERR_print_errors_cb((cb *)0x132d99,a);
    BIO_free(a);
    return;
  }
  return;
}

