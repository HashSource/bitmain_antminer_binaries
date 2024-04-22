
/* WARNING: Unknown calling convention */

uchar erase_PIC16F1704_app_flash(uint which_i2c,uchar which_chain)

{
  int iVar1;
  
  iVar1 = 0x4c;
  set_PIC16F1704_flash_pointer(which_i2c,which_chain,'\x06','\0');
  printf("%s: erase_loop = %d\n",DAT_00023530,0x4c);
  do {
    erase_PIC16F1704_flash(which_i2c,which_chain);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return 0xff;
}

