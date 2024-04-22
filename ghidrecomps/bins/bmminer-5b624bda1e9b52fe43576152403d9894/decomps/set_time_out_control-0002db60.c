
/* WARNING: Unknown calling convention */

void set_time_out_control(uint value)

{
  char cVar1;
  char tmp42 [2048];
  
  cVar1 = *DAT_0002dbb4;
  *(uint *)(*(int *)(DAT_0002dbb0 + 0x8d4) + 0x88) = value;
  if ((cVar1 != '\0') &&
     (((*DAT_0002dbb8 != '\0' || (*DAT_0002dbbc != '\0')) || (6 < *DAT_0002dbc0)))) {
    snprintf(tmp42,0x800,DAT_0002dbc4,DAT_0002dbc8,value);
    _applog(7,tmp42,false);
  }
  get_time_out_control();
  return;
}

