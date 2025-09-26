
undefined4 openssl_destroy(void)

{
  EVP_MD_meth_free(sha1_md);
  sha1_md = 0;
  EVP_CIPHER_meth_free(r4_cipher);
  r4_cipher = 0;
  EVP_CIPHER_meth_free(r4_40_cipher);
  r4_40_cipher = 0;
  return 1;
}

