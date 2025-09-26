
undefined1 * dtls1_get_client_method(int param_1)

{
  undefined1 *puVar1;
  
  if (param_1 == 0xfeff || param_1 == 0x100) {
    return &DTLSv1_client_method_data_18564;
  }
  if (param_1 == 0xfefd) {
    puVar1 = DTLSv1_2_client_method_data_18568;
  }
  else {
    puVar1 = (undefined1 *)0x0;
  }
  return puVar1;
}

