
int getIndices(uint8_t *hash,size_t len,size_t lenIndices,size_t cBitLen,uint8_t *data,size_t maxLen
              )

{
  uint out_len;
  size_t cBitLen_local;
  size_t lenIndices_local;
  size_t len_local;
  uint8_t *hash_local;
  size_t bytePad;
  size_t minLen;
  
  if (cBitLen + 8 < 0x28) {
    out_len = lenIndices * (cBitLen + 1) >> 5;
    if (maxLen < out_len) {
      out_len = 0xffffffff;
    }
    else if (data != (uint8_t *)0x0) {
      compressArray(hash + len,lenIndices,data,out_len,cBitLen + 1,4 - (cBitLen + 8 >> 3));
    }
    return out_len;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("((cBitLen + 1) + 7) / 8 <= sizeof(uint32_t)","bm174x/equihash-verify.c",0x6c,
                "getIndices");
}

