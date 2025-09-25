
void ssl_sort_cipher_list(void)

{
  qsort(&tls13_ciphers,5,0x40,(__compar_fn_t)0xd5d2d);
  qsort(ssl3_ciphers,0xa4,0x40,(__compar_fn_t)0xd5d2d);
  qsort(ssl3_scsvs,2,0x40,(__compar_fn_t)0xd5d2d);
  return;
}

