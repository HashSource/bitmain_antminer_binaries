
uint getIndices(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)

{
  uint uVar1;
  
  if (param_4 + 8U < 0x28) {
    uVar1 = (uint)(param_3 * (param_4 + 1)) >> 5;
    if (param_6 < uVar1) {
      uVar1 = 0xffffffff;
    }
    else if (param_5 != 0) {
      compressArray(param_1 + param_2,param_3,param_5,uVar1,param_4 + 1,4 - (param_4 + 8U >> 3));
    }
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("((cBitLen + 1) + 7) / 8 <= sizeof(uint32_t)","bm1740/sort-verify.c",0x6d,
                "getIndices");
}

