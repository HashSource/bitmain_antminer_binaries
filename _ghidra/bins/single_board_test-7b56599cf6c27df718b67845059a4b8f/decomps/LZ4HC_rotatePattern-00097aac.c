
U32 LZ4HC_rotatePattern(size_t rotate,U32 pattern)

{
  uint uVar1;
  U32 pattern_local;
  size_t rotate_local;
  size_t bitsToRotate;
  
  if ((rotate & 3) != 0) {
    uVar1 = (rotate & 3) * -8 + 0x20 & 0x1f;
    pattern = pattern >> uVar1 | pattern << 0x20 - uVar1;
  }
  return pattern;
}

