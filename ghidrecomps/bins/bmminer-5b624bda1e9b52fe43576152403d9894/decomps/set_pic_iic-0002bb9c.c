
/* WARNING: Unknown calling convention */

uchar set_pic_iic(uint data)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  uint in_stack_fffff7e0;
  undefined4 in_stack_fffff7e4;
  char tmp42 [2048];
  
  pcVar5 = DAT_0002bc40;
  uVar6 = data & 0x7fffffff;
  cVar1 = *DAT_0002bc40;
  *(uint *)(*(int *)(DAT_0002bc3c + 0x8d4) + 0x30) = uVar6;
  piVar2 = DAT_0002bc58;
  pcVar3 = DAT_0002bc48;
  pcVar4 = DAT_0002bc44;
  if ((cVar1 != '\0') &&
     (((*DAT_0002bc44 != '\0' || (*DAT_0002bc48 != '\0')) || (6 < *DAT_0002bc58)))) {
    snprintf(tmp42,0x800,DAT_0002bc4c,DAT_0002bc50);
    _applog(7,tmp42,false);
    in_stack_fffff7e0 = uVar6;
    piVar2 = DAT_0002bc58;
    pcVar3 = DAT_0002bc48;
    pcVar4 = DAT_0002bc44;
  }
  while (uVar6 = get_pic_iic(), -1 < (int)uVar6) {
    if ((*pcVar5 != '\0') && (((*pcVar4 != '\0' || (*pcVar3 != '\0')) || (6 < *piVar2)))) {
      snprintf(tmp42,0x800,DAT_0002bc54,DAT_0002bc50);
      _applog(7,tmp42,false);
    }
    cgsleep_us(CONCAT44(in_stack_fffff7e4,in_stack_fffff7e0));
  }
  return (uchar)uVar6;
}

