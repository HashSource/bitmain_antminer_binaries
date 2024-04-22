
int ENGINE_set_name(ENGINE *e,char *name)

{
  if (name == (char *)0x0) {
    ERR_put_error(0x26,0x82,0x43,DAT_000a6434,0xfe);
  }
  else {
    *(char **)(e + 4) = name;
  }
  return (uint)(name != (char *)0x0);
}

