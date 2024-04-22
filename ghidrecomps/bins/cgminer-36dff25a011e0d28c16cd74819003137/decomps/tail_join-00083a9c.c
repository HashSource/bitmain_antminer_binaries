
void tail_join(io_data *io_data,_Bool isjson)

{
  _Bool isjson_local;
  io_data *io_data_local;
  
  if (io_data->close != false) {
    io_add(io_data,(char *)&DAT_000adb74);
    io_data->close = false;
  }
  if (isjson) {
    io_add(io_data,(char *)&DAT_000ae5a0);
    io_add(io_data,(char *)&DAT_000adb74);
  }
  return;
}

