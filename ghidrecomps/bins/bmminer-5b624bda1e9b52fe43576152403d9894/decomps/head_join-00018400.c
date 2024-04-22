
/* WARNING: Unknown calling convention */

void head_join(io_data *io_data,char *cmdptr,_Bool isjson,_Bool *firstjoin)

{
  char *buf;
  char *ptr;
  
  if (*firstjoin == false) {
    if (isjson) {
      io_add(io_data,DAT_00018498);
      buf = escape_string(cmdptr,true);
      goto LAB_00018476;
    }
  }
  else {
    if (isjson) {
      io_add(io_data,DAT_0001849c);
      *firstjoin = false;
      buf = escape_string(cmdptr,true);
LAB_00018476:
      io_add(io_data,DAT_000184a0);
      io_add(io_data,buf);
      io_add(io_data,DAT_000184a4);
      goto LAB_00018434;
    }
    *firstjoin = isjson;
  }
  buf = escape_string(cmdptr,isjson);
  io_add(io_data,DAT_00018490);
  io_add(io_data,buf);
  io_add(io_data,DAT_00018494);
LAB_00018434:
  if (buf == cmdptr) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0000a260. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f208)(buf);
  return;
}

