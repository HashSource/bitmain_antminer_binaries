
undefined1 * dtls1_get_method(int param_1)

{
  undefined1 *puVar1;
  
  if (param_1 == 0xfeff) {
    return &DTLSv1_method_data_18473;
  }
  if (param_1 == 0xfefd) {
    puVar1 = DTLSv1_2_method_data_18477;
  }
  else {
    puVar1 = (undefined1 *)0x0;
  }
  return puVar1;
}

