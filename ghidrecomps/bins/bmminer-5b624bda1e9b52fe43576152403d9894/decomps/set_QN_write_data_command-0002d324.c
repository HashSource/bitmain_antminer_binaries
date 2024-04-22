
/* WARNING: Unknown calling convention */

void set_QN_write_data_command(uint value)

{
  char cVar1;
  char tmp42 [2048];
  
  cVar1 = *DAT_0002d378;
  *(uint *)(*(int *)(DAT_0002d374 + 0x8d4) + 0x80) = value;
  if ((cVar1 != '\0') &&
     (((*DAT_0002d37c != '\0' || (*DAT_0002d380 != '\0')) || (6 < *DAT_0002d384)))) {
    snprintf(tmp42,0x800,DAT_0002d388,DAT_0002d38c,value);
    _applog(7,tmp42,false);
  }
  get_QN_write_data_command();
  return;
}

