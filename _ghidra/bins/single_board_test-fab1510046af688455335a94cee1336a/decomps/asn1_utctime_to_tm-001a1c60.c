
undefined4 asn1_utctime_to_tm(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_2 + 4) != 0x17) {
    return 0;
  }
  uVar1 = asn1_utctime_to_tm_part_0();
  return uVar1;
}

