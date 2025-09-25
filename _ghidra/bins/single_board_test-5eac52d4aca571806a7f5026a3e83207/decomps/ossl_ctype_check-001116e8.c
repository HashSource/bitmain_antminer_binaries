
bool ossl_ctype_check(uint param_1,ushort param_2)

{
  if (0x7f < param_1) {
    return false;
  }
  return (*(ushort *)(&ctype_char_map + param_1 * 2) & param_2) != 0;
}

