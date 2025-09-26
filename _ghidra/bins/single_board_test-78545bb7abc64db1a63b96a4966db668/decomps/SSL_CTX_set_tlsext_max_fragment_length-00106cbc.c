
undefined4 SSL_CTX_set_tlsext_max_fragment_length(int param_1,uint param_2)

{
  if (param_2 < 5) {
    *(char *)(param_1 + 0x15c) = (char)param_2;
    return 1;
  }
  ERR_put_error(0x14,0x227,0xe8,"ssl/t1_lib.c",0xb53);
  return 0;
}

