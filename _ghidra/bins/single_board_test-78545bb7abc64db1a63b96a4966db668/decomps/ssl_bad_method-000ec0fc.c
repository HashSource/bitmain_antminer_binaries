
undefined4 ssl_bad_method(void)

{
  ERR_put_error(0x14,0xa0,0x42,"ssl/ssl_lib.c",0xec0);
  return 0;
}

