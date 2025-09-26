
int DSO_set_filename(DSO *dso,char *filename)

{
  DSO_MERGER_FUNC pDVar1;
  
  if (filename == (char *)0x0 || dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x81,0x43,"crypto/dso/dso_lib.c",0xf5);
    return 0;
  }
  if (dso->filename == (char *)0x0) {
    pDVar1 = (DSO_MERGER_FUNC)CRYPTO_strdup(filename,"crypto/dso/dso_lib.c",0xfd);
    if (pDVar1 != (DSO_MERGER_FUNC)0x0) {
      CRYPTO_free(dso->merger);
      dso->merger = pDVar1;
      return 1;
    }
    ERR_put_error(0x25,0x81,0x41,"crypto/dso/dso_lib.c",0xff);
  }
  else {
    ERR_put_error(0x25,0x81,0x6e,"crypto/dso/dso_lib.c",0xf9);
  }
  return 0;
}

