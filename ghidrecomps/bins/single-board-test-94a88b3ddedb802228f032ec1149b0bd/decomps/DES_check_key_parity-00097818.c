
int DES_check_key_parity(const_DES_cblock *key)

{
  if (((((uint)*(byte *)(DAT_00097864 + (uint)(*key)[0]) == (uint)(*key)[0]) &&
       ((uint)*(byte *)(DAT_00097864 + (uint)(*key)[1]) == (uint)(*key)[1])) &&
      ((uint)*(byte *)(DAT_00097864 + (uint)(*key)[2]) == (uint)(*key)[2])) &&
     ((((uint)*(byte *)(DAT_00097864 + (uint)(*key)[3]) == (uint)(*key)[3] &&
       ((uint)*(byte *)(DAT_00097864 + (uint)(*key)[4]) == (uint)(*key)[4])) &&
      (((uint)*(byte *)(DAT_00097864 + (uint)(*key)[5]) == (uint)(*key)[5] &&
       ((uint)*(byte *)(DAT_00097864 + (uint)(*key)[6]) == (uint)(*key)[6])))))) {
    return (uint)((uint)*(byte *)(DAT_00097864 + (uint)(*key)[7]) == (uint)(*key)[7]);
  }
  return 0;
}

