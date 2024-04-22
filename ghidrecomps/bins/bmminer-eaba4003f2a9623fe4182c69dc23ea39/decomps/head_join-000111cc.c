
void head_join(io_data *io_data,char *cmdptr,_Bool isjson,_Bool *firstjoin)

{
  char *buf;
  _Bool *firstjoin_local;
  _Bool isjson_local;
  char *cmdptr_local;
  io_data *io_data_local;
  char *ptr;
  
  if (*firstjoin == false) {
    if (isjson) {
      io_add(io_data,",");
    }
  }
  else {
    if (isjson) {
      io_add(io_data,"{");
    }
    *firstjoin = false;
  }
  buf = escape_string(cmdptr,isjson);
  if (isjson) {
    io_add(io_data,"\"");
    io_add(io_data,buf);
    io_add(io_data,"\":[");
  }
  else {
    io_add(io_data,"CMD=");
    io_add(io_data,buf);
    io_add(io_data,(char *)&DAT_0006d29c);
  }
  if (buf != cmdptr) {
    free(buf);
  }
  return;
}

