
void compressArray(int param_1,int param_2,int param_3,uint param_4,uint param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  uint local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  
  if (param_5 < 8) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("bit_len >= 8","bm1744/driver/sort-verify.c",0x15,"compressArray");
  }
  if (0x20 < param_5 + 7) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("8 * sizeof(uint32_t) >= 7 + bit_len","bm1744/driver/sort-verify.c",0x16,
                  "compressArray");
  }
  uVar2 = param_6 + (param_5 + 7 >> 3);
  uVar1 = __udivsi3(param_2 * param_5,uVar2 * 8);
  if (uVar1 != param_4) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("out_len == bit_len * in_len / (8 * in_width)","bm1744/driver/sort-verify.c",0x19,
                  "compressArray");
  }
  local_c = 0;
  local_10 = 0;
  local_14 = 0;
  for (local_18 = 0; local_18 < param_4; local_18 = local_18 + 1) {
    if (local_c < 8) {
      local_10 = local_10 << (param_5 & 0xff);
      for (local_1c = param_6; local_1c < uVar2; local_1c = local_1c + 1) {
        local_10 = ((1 << (param_5 & 0xff)) - 1U >> (((uVar2 - local_1c) + 0x1fffffff) * 8 & 0xff) &
                   (uint)*(byte *)(local_1c + local_14 + param_1)) <<
                   (((uVar2 - local_1c) + 0x1fffffff) * 8 & 0xff) | local_10;
      }
      local_14 = uVar2 + local_14;
      local_c = param_5 + local_c;
    }
    local_c = local_c - 8;
    *(char *)(local_18 + param_3) = (char)(local_10 >> (local_c & 0xff));
  }
  return;
}

