
char * DSO_get_loaded_filename(DSO *dso)

{
  char *pcVar1;
  
  if (dso == (DSO *)0x0) {
    ERR_put_error(0x25,0x80,0x43,DAT_00101944,0x1a3);
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = dso->loaded_filename;
  }
  return pcVar1;
}

