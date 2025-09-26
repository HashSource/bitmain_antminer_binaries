
undefined1 * tls1_get_client_method(int param_1)

{
  undefined1 *puVar1;
  
  if (param_1 == 0x303) {
    return &TLSv1_2_client_method_data_18536;
  }
  if (param_1 == 0x302) {
    return TLSv1_1_client_method_data_18540;
  }
  if (param_1 == 0x301) {
    puVar1 = TLSv1_client_method_data_18544;
  }
  else {
    puVar1 = (undefined1 *)0x0;
  }
  return puVar1;
}

