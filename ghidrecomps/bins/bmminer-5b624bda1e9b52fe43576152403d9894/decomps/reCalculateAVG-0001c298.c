
/* WARNING: Unknown calling convention */

void reCalculateAVG(void)

{
  double dVar1;
  
  dVar1 = *DAT_0001c2cc;
  *DAT_0001c2d4 = *DAT_0001c2d0;
  if (dVar1 != 0.0 && dVar1 < 0.0 == NAN(dVar1)) {
    *DAT_0001c2d8 = dVar1 - 1.0;
    return;
  }
  *DAT_0001c2d8 = dVar1;
  return;
}

