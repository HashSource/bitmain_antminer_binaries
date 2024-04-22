
/* WARNING: Unknown calling convention */

int get_hash_on_plug(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = *(int *)(*(int *)(DAT_0002d990 + 0x8d4) + 8);
  if ((*DAT_0002d994 != '\0') &&
     (((*DAT_0002d998 != '\0' || (*DAT_0002d99c != '\0')) || (6 < *DAT_0002d9a0)))) {
    snprintf(tmp42,0x800,DAT_0002d9a4,DAT_0002d9a8,iVar1);
    _applog(7,tmp42,false);
  }
  return iVar1;
}

