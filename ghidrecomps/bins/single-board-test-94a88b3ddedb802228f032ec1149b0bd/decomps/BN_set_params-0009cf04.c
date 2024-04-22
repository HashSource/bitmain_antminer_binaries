
void BN_set_params(int mul,int high,int low,int mont)

{
  int *piVar1;
  
  piVar1 = DAT_0009cf68;
  if (-1 < mul) {
    if (0x1e < mul) {
      mul = 0x1f;
    }
    *DAT_0009cf64 = mul;
    *piVar1 = 1 << (mul & 0xffU);
  }
  piVar1 = DAT_0009cf68;
  if (-1 < high) {
    if (0x1e < high) {
      high = 0x1f;
    }
    DAT_0009cf64[1] = high;
    piVar1[1] = 1 << (high & 0xffU);
  }
  piVar1 = DAT_0009cf68;
  if (-1 < low) {
    if (0x1e < low) {
      low = 0x1f;
    }
    DAT_0009cf64[2] = low;
    piVar1[2] = 1 << (low & 0xffU);
  }
  piVar1 = DAT_0009cf68;
  if (-1 < mont) {
    if (0x1e < mont) {
      mont = 0x1f;
    }
    DAT_0009cf64[3] = mont;
    piVar1[3] = 1 << (mont & 0xffU);
  }
  return;
}

