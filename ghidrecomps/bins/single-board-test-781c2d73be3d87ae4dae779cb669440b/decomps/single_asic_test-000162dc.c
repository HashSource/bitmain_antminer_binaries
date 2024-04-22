
/* WARNING: Unknown calling convention */

void single_asic_test(void)

{
  undefined4 in_r3;
  
  if (Conf.AsicType == 0x569) {
    puts("\nBegin singleAsicTest_BM1385\n");
    singleAsicTest_BM1385();
    return;
  }
  if (Conf.AsicType - 0x3657 < 2) {
    puts("\nBegin singleAsicTest_BM1391\n");
    singleAsicTest_BM1391();
    return;
  }
  if (Conf.AsicType == 0x575) {
    puts("\nBegin singleAsicTest_BM1397\n");
    singleAsicTest_BM1397();
    return;
  }
  (*(code *)PTR_printf_00030118)
            ("Single ASIC test: Can\'t find ASIC type!!! AsicType = %d\n",Conf.AsicType,0x569,in_r3)
  ;
  return;
}

