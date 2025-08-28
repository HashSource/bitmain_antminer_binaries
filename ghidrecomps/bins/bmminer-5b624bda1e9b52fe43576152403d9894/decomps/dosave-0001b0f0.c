
/* WARNING: Unknown calling convention */

void dosave(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  FILE *fcfg;
  char *pcVar1;
  char filename [4096];
  
  if ((param == (char *)0x0) || (*param == '\0')) {
    default_save_file(filename);
    param = filename;
  }
  fcfg = fopen(param,"w");
  if (fcfg == (FILE *)0x0) {
    pcVar1 = escape_string(param,isjson);
    message(io_data,0x2b,0,pcVar1,isjson);
    if (pcVar1 != param) {
      free(pcVar1);
    }
  }
  else {
    write_config((FILE *)fcfg);
    fclose(fcfg);
    pcVar1 = escape_string(param,isjson);
    message(io_data,0x2c,0,pcVar1,isjson);
    if (pcVar1 != param) {
      free(pcVar1);
    }
  }
  return;
}

