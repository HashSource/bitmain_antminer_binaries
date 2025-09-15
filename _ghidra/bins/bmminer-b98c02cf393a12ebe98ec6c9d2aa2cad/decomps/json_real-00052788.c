
undefined4 * json_real(void)

{
  int iVar1;
  undefined4 *puVar2;
  double in_d0;
  
  iVar1 = __isnan(in_d0);
  if (iVar1 != 0) {
    return (undefined4 *)0x0;
  }
  iVar1 = __isinf(in_d0);
  if (iVar1 != 0) {
    return (undefined4 *)0x0;
  }
  puVar2 = (undefined4 *)jsonp_malloc(0x10);
  if (puVar2 != (undefined4 *)0x0) {
    *(double *)(puVar2 + 2) = in_d0;
    *puVar2 = 4;
    puVar2[1] = 1;
  }
  return puVar2;
}

