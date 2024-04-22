
char * DSO_convert_filename(DSO *dso,char *filename)

{
  size_t sVar1;
  char *dst;
  DSO_NAME_CONVERTER_FUNC pDVar2;
  
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x7e,0x43,DAT_0010191c,0x186);
    dst = (char *)0x0;
  }
  else if ((filename == (char *)0x0) && (filename = dso->filename, filename == (char *)0x0)) {
    ERR_put_error(0x25,0x7e,0x6f,DAT_0010191c,0x18c);
    dst = (char *)0x0;
  }
  else if ((dso->flags << 0x1f < 0) ||
          (((pDVar2 = dso->name_converter, pDVar2 == (DSO_NAME_CONVERTER_FUNC)0x0 &&
            (pDVar2 = dso->meth->dso_name_converter, pDVar2 == (DSO_NAME_CONVERTER_FUNC)0x0)) ||
           (dst = (*pDVar2)(dso,filename), dst == (char *)0x0)))) {
    sVar1 = strlen(filename);
    dst = (char *)CRYPTO_malloc(sVar1 + 1,DAT_0010191c,0x196);
    if (dst == (char *)0x0) {
      ERR_put_error(0x25,0x7e,0x41,DAT_0010191c,0x198);
    }
    else {
      sVar1 = strlen(filename);
      BUF_strlcpy(dst,filename,sVar1 + 1);
    }
  }
  return dst;
}

