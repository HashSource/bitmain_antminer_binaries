
undefined4 SSL_export_keying_material_early(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 != 0x304) {
    return 0;
  }
  uVar1 = tls13_export_keying_material_early();
  return uVar1;
}

