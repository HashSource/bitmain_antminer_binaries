
UDItype share_ndiff(int param_1)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  undefined4 extraout_s0;
  undefined4 extraout_s1;
  double dVar2;
  double dVar3;
  double dVar4;
  UDItype UVar5;
  
  if (param_1 != 0) {
    dVar4 = (double)__floatundidf(*(undefined4 *)(param_1 + 0xd8),*(undefined4 *)(param_1 + 0xdc));
    dVar2 = (double)__floatundidf(*(undefined4 *)(param_1 + 0xd0),*(undefined4 *)(param_1 + 0xd4));
    dVar3 = (double)__floatundidf(*(undefined4 *)(param_1 + 200),*(undefined4 *)(param_1 + 0xcc));
    uVar1 = __floatundidf(*(undefined4 *)(param_1 + 0xc0),*(undefined4 *)(param_1 + 0xc4));
    if (dVar4 * 6.277101735386681e+57 + dVar2 * 3.402823669209385e+38 +
        dVar3 * 1.8446744073709552e+19 + (double)CONCAT44(extraout_r1,uVar1) == 0.0) {
      UVar5 = 0;
    }
    else {
      UVar5 = __fixunsdfdi((DFtype)CONCAT44(extraout_s1,extraout_s0));
    }
    return UVar5;
  }
  return 0;
}

