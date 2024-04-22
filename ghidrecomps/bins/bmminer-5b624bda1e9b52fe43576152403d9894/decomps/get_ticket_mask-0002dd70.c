
/* WARNING: Unknown calling convention */

int get_ticket_mask(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = *(int *)(*(int *)(DAT_0002ddc0 + 0x8d4) + 0x8c);
  if ((*DAT_0002ddc4 != '\0') &&
     (((*DAT_0002ddc8 != '\0' || (*DAT_0002ddcc != '\0')) || (6 < *DAT_0002ddd0)))) {
    snprintf(tmp42,0x800,DAT_0002ddd4,DAT_0002ddd8,iVar1);
    _applog(7,tmp42,false);
  }
  return iVar1;
}

