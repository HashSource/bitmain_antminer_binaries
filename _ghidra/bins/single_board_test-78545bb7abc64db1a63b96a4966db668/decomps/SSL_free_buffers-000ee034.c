
undefined4 SSL_free_buffers(int param_1)

{
  int iVar1;
  
  param_1 = param_1 + 0x650;
  iVar1 = RECORD_LAYER_read_pending(param_1);
  if ((iVar1 == 0) && (iVar1 = RECORD_LAYER_write_pending(param_1), iVar1 == 0)) {
    RECORD_LAYER_release(param_1);
    return 1;
  }
  return 0;
}

