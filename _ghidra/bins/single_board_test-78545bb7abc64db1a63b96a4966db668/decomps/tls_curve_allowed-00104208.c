
void tls_curve_allowed(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined1 local_14;
  undefined1 local_13;
  
  puVar1 = (undefined4 *)tls1_group_id_lookup(param_2);
  if (puVar1 != (undefined4 *)0x0) {
    local_13 = (undefined1)param_2;
    local_14 = (undefined1)((uint)param_2 >> 8);
    ssl_security(param_1,param_3,puVar1[1],*puVar1,&local_14);
  }
  return;
}

