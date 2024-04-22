
char * DSO_get_filename(DSO *dso)

{
  char *pcVar1;
  
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x7f,0x43,DAT_001016c4,0x151);
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = dso->filename;
  }
  return pcVar1;
}

