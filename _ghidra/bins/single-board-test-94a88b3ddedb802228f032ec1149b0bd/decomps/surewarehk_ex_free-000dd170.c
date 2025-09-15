
void surewarehk_ex_free(undefined4 param_1,undefined4 param_2)

{
  if (p_surewarehk_Free != (code *)0x0) {
    (*p_surewarehk_Free)(param_2,0);
    return;
  }
  if (SUREWARE_lib_error_code == 0) {
    SUREWARE_lib_error_code = ERR_get_next_error_library();
  }
  ERR_put_error(SUREWARE_lib_error_code,0x66,0x75,"e_sureware.c",0x36d);
  return;
}

