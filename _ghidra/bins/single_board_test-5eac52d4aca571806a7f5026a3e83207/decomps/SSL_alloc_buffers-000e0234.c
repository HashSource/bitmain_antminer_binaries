
int SSL_alloc_buffers(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ssl3_setup_read_buffer();
  if ((iVar1 != 0) && (iVar1 = ssl3_setup_write_buffer(param_1,1,0), iVar1 != 0)) {
    iVar1 = 1;
  }
  return iVar1;
}

