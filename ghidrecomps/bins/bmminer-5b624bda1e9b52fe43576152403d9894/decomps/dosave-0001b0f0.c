
/* WARNING: Unknown calling convention */

void dosave(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  FILE *fcfg_00;
  FILE *fcfg;
  char *pcVar1;
  char *ptr;
  char filename [4096];
  
  if ((param == (char *)0x0) || (*param == '\0')) {
    default_save_file(filename);
    param = filename;
  }
  fcfg_00 = fopen(param,DAT_0001b178);
  if (fcfg_00 == (FILE *)0x0) {
    pcVar1 = escape_string(param,isjson);
    message(io_data,0x2b,0,pcVar1,isjson);
    if (pcVar1 != param) {
      free(pcVar1);
    }
  }
  else {
    write_config((FILE *)fcfg_00);
    fclose(fcfg_00);
    pcVar1 = escape_string(param,isjson);
    message(io_data,0x2c,0,pcVar1,isjson);
    if (pcVar1 != param) {
      free(pcVar1);
    }
  }
  return;
}

