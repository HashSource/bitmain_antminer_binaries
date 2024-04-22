
void expandArray(int param_1,uint param_2,int param_3,int param_4,uint param_5,uint param_6)

{
  int iVar1;
  uint uVar2;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  
  if (param_5 < 8) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("bit_len >= 8","bm1740/sort-verify.c",0x3f,"expandArray");
  }
  if (0x20 < param_5 + 7) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("8 * sizeof(uint32_t) >= 7 + bit_len","bm1740/sort-verify.c",0x40,"expandArray");
  }
  uVar2 = (param_5 + 7 >> 3) + param_6;
  iVar1 = __udivsi3(param_2 * uVar2 * 8,param_5);
  if (iVar1 != param_4) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("out_len == 8 * out_width * in_len / bit_len","bm1740/sort-verify.c",0x43,
                  "expandArray");
  }
  local_c = 0;
  local_10 = 0;
  local_14 = 0;
  for (local_18 = 0; local_18 < param_2; local_18 = local_18 + 1) {
    local_10 = (uint)*(byte *)(param_1 + local_18) | local_10 << 8;
    local_c = local_c + 8;
    if (param_5 <= local_c) {
      local_c = local_c - param_5;
      for (local_1c = 0; local_1c < param_6; local_1c = local_1c + 1) {
        *(undefined *)(param_3 + local_14 + local_1c) = 0;
      }
      for (local_20 = param_6; local_20 < uVar2; local_20 = local_20 + 1) {
        *(byte *)(param_3 + local_14 + local_20) =
             (byte)((1 << (param_5 & 0xff)) - 1U >> (((uVar2 - local_20) + 0x1fffffff) * 8 & 0xff))
             & (byte)(local_10 >> (((uVar2 - local_20) + 0x1fffffff) * 8 + local_c & 0xff));
      }
      local_14 = local_14 + uVar2;
    }
  }
  return;
}

