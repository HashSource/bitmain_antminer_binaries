
int DSO_set_filename(DSO *dso,char *filename)

{
  size_t sVar1;
  char *dst;
  int iVar2;
  
  if (dso == (DSO *)0x0 || filename == (char *)0x0) {
    ERR_put_error(0x25,0x81,0x43,DAT_0010175c,0x15c);
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    if (dso->loaded_filename == (char *)0x0) {
      sVar1 = strlen(filename);
      dst = (char *)CRYPTO_malloc(sVar1 + 1,DAT_0010175c,0x164);
      if (dst == (char *)0x0) {
        ERR_put_error(0x25,0x81,0x41,DAT_0010175c,0x166);
        iVar2 = 0;
      }
      else {
        sVar1 = strlen(filename);
        BUF_strlcpy(dst,filename,sVar1 + 1);
        if (dso->filename != (char *)0x0) {
          CRYPTO_free(dso->filename);
        }
        iVar2 = 1;
        dso->filename = dst;
      }
    }
    else {
      ERR_put_error(0x25,0x81,0x6e,DAT_0010175c,0x160);
    }
  }
  return iVar2;
}

