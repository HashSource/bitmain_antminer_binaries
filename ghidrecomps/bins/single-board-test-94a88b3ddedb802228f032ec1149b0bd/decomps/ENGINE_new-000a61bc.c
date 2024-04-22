
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ENGINE * ENGINE_new(void)

{
  ENGINE *__s;
  
  __s = (ENGINE *)CRYPTO_malloc(0x70,DAT_000a6200,0x45);
  if (__s == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x7a,0x41,DAT_000a6200,0x47);
  }
  else {
    memset(__s,0,0x70);
    *(undefined4 *)(__s + 0x58) = 1;
    CRYPTO_new_ex_data(9,__s,(CRYPTO_EX_DATA *)(__s + 0x60));
  }
  return __s;
}

