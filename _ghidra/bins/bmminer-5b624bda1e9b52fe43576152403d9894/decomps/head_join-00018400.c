
/* WARNING: Unknown calling convention */

void head_join(io_data *io_data,char *cmdptr,_Bool isjson,_Bool *firstjoin)

{
  char *buf;
  
  if (*firstjoin == false) {
    if (isjson) {
      io_add(io_data,",");
      buf = escape_string(cmdptr,true);
      goto LAB_00018476;
    }
  }
  else {
    if (isjson) {
      io_add(io_data,"{");
      *firstjoin = false;
      buf = escape_string(cmdptr,true);
LAB_00018476:
      io_add(io_data,"\"");
      io_add(io_data,buf);
      io_add(io_data,"\":[");
      goto LAB_00018434;
    }
    *firstjoin = isjson;
  }
  buf = escape_string(cmdptr,isjson);
  io_add(io_data,"CMD=");
  io_add(io_data,buf);
  io_add(io_data,"|");
LAB_00018434:
  if (buf == cmdptr) {
    return;
  }
  (*(code *)(undefined *)0x0)(buf);
  return;
}

