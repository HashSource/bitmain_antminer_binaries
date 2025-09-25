
undefined4 md_free(int param_1)

{
  if (param_1 != 0) {
    BIO_get_data();
    EVP_MD_CTX_free();
    BIO_set_data(param_1,0);
    BIO_set_init(param_1,0);
    return 1;
  }
  return 0;
}

