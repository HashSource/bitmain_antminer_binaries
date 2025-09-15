
/* WARNING: Unknown calling convention */

uchar erase_pic_flash_all(uchar chain)

{
  uchar uVar1;
  int iVar2;
  
  iVar2 = 100;
  set_pic_iic_flash_addr_pointer(chain,'\x03','\0');
  do {
    uVar1 = erase_pic_flash(chain);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return uVar1;
}

