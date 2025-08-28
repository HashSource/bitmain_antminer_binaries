
int ENGINE_up_ref(ENGINE *e)

{
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0xbe,0x43,"eng_list.c",399);
  }
  else {
    CRYPTO_add_lock((int *)(e + 0x58),1,0x1e,"eng_list.c",0x192);
  }
  return (uint)(e != (ENGINE *)0x0);
}

