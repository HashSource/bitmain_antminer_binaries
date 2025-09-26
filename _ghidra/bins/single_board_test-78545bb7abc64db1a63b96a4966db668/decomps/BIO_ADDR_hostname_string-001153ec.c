
undefined4 BIO_ADDR_hostname_string(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_14;
  
  local_14 = 0;
  iVar1 = BIO_sock_init();
  if ((iVar1 == 1) && (iVar1 = addr_strings_part_2(param_1,param_2,&local_14,0), iVar1 != 0)) {
    return local_14;
  }
  return 0;
}

