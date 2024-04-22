
uint lex_get_save(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  if (uVar1 == 0) {
    uVar1 = stream_get_part_3();
  }
  if (1 < uVar1 + 2) {
    strbuffer_append_byte(param_1 + 0x28,uVar1 & 0xff,param_3,uVar1 + 2,param_4);
  }
  return uVar1;
}

