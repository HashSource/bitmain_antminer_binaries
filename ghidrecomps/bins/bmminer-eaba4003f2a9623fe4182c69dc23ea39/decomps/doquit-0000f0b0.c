
void doquit(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  
  if (isjson) {
    io_put(io_data,"{\"STATUS\":\"BYE\"");
  }
  else {
    io_put(io_data,"BYE");
  }
  bye = true;
  do_a_quit = true;
  return;
}

