
int isZero(uint8_t *hash,size_t len)

{
  size_t len_local;
  uint8_t *hash_local;
  size_t i;
  
  i = 0;
  while( true ) {
    if (len <= i) {
      return 1;
    }
    if (hash[i] != '\0') break;
    i = i + 1;
  }
  return 0;
}

