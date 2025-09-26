
char * DSO_get_filename(DSO *dso)

{
  if (dso != (DSO *)0x0) {
    return (char *)dso->merger;
  }
  ERR_put_error(0x25,0x7f,0x43,"crypto/dso/dso_lib.c",0xea);
  return (char *)0x0;
}

