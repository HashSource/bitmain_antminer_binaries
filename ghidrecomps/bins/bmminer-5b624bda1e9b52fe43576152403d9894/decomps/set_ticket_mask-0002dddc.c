
/* WARNING: Unknown calling convention */

void set_ticket_mask(uint value)

{
  char cVar1;
  char tmp42 [2048];
  
  cVar1 = *DAT_0002de30;
  *(uint *)(*(int *)(DAT_0002de2c + 0x8d4) + 0x8c) = value;
  if ((cVar1 != '\0') &&
     (((*DAT_0002de34 != '\0' || (*DAT_0002de38 != '\0')) || (6 < *DAT_0002de3c)))) {
    snprintf(tmp42,0x800,DAT_0002de40,DAT_0002de44,value);
    _applog(7,tmp42,false);
  }
  get_ticket_mask();
  return;
}

