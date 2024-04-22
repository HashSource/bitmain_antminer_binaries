
int DSO_up_ref(DSO *dso)

{
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x72,0x43,DAT_0010153c,0xb5);
  }
  else {
    CRYPTO_add_lock(&dso->references,1,0x1c,DAT_0010153c,0xb9);
  }
  return (uint)(dso != (DSO *)0x0);
}

