
int ENGINE_up_ref(ENGINE *e)

{
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0xbe,0x43,DAT_000a69c4,399);
  }
  else {
    CRYPTO_add_lock((int *)(e + 0x58),1,0x1e,DAT_000a69c4,0x192);
  }
  return (uint)(e != (ENGINE *)0x0);
}

