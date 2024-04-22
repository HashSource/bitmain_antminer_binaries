
int ENGINE_set_id(ENGINE *e,char *id)

{
  if (id == (char *)0x0) {
    ERR_put_error(0x26,0x81,0x43,DAT_000a6408,0xf4);
  }
  else {
    *(char **)e = id;
  }
  return (uint)(id != (char *)0x0);
}

