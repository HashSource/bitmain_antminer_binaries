
undefined4 erase_PIC16F1704_app_flash(undefined4 param_1,undefined param_2)

{
  uint local_c;
  
  set_PIC16F1704_flash_pointer(param_1,param_2,6,0);
  printf("%s: erase_loop = %d\n","erase_PIC16F1704_app_flash",0x4c);
  local_c = 0;
  while( true ) {
    if (0x4b < local_c) break;
    erase_PIC16F1704_flash(param_1,param_2);
    local_c = local_c + 1;
  }
  return 0x4c;
}

