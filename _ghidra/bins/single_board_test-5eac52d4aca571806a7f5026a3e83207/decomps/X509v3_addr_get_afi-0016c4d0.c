
int * X509v3_addr_get_afi(int *param_1)

{
  undefined1 *puVar1;
  
  if ((param_1 != (int *)0x0) && (param_1 = (int *)*param_1, param_1 != (int *)0x0)) {
    puVar1 = (undefined1 *)param_1[2];
    if (puVar1 == (undefined1 *)0x0) {
      return (int *)0x0;
    }
    if (1 < *param_1) {
      return (int *)(uint)CONCAT11(*puVar1,puVar1[1]);
    }
    param_1 = (int *)0x0;
  }
  return param_1;
}

