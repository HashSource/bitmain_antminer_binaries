
void dosave(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  FILE *fcfg_00;
  char *pcVar1;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  char filename [4096];
  char *ptr;
  FILE *fcfg;
  
  if ((param == (char *)0x0) || (param_local = param, *param == '\0')) {
    default_save_file(filename);
    param_local = filename;
  }
  fcfg_00 = fopen(param_local,"w");
  if (fcfg_00 == (FILE *)0x0) {
    pcVar1 = escape_string(param_local,isjson);
    message(io_data,0x2b,0,pcVar1,isjson);
    if (pcVar1 != param_local) {
      free(pcVar1);
    }
  }
  else {
    write_config((FILE *)fcfg_00);
    fclose(fcfg_00);
    pcVar1 = escape_string(param_local,isjson);
    message(io_data,0x2c,0,pcVar1,isjson);
    if (pcVar1 != param_local) {
      free(pcVar1);
    }
  }
  return;
}

