
void * two_way_short_needle(uchar *haystack,size_t haystack_len,uchar *needle,size_t needle_len)

{
  size_t sVar1;
  int iVar2;
  uint uVar3;
  size_t needle_len_local;
  uchar *needle_local;
  size_t haystack_len_local;
  uchar *haystack_local;
  size_t period;
  size_t suffix;
  size_t memory;
  size_t j;
  size_t i;
  
  suffix = critical_factorization(needle,needle_len,&period);
  iVar2 = memcmp(needle,needle + period,suffix);
  if (iVar2 == 0) {
    memory = 0;
    j = 0;
    while (j <= haystack_len - needle_len) {
      i = suffix;
      if (suffix < memory) {
        i = memory;
      }
      for (; (i < needle_len && (needle[i] == haystack[i + j])); i = i + 1) {
      }
      sVar1 = suffix;
      if (i < needle_len) {
        j = (i - suffix) + j + 1;
        memory = 0;
      }
      else {
        do {
          uVar3 = sVar1;
          i = uVar3 - 1;
          if (uVar3 <= memory) break;
          sVar1 = i;
        } while (needle[i] == haystack[i + j]);
        if (uVar3 < memory + 1) {
          return haystack + j;
        }
        j = j + period;
        memory = needle_len - period;
      }
    }
  }
  else {
    uVar3 = needle_len - suffix;
    if (uVar3 < suffix) {
      uVar3 = suffix;
    }
    j = 0;
    while (j <= haystack_len - needle_len) {
      for (i = suffix; (i < needle_len && (needle[i] == haystack[i + j])); i = i + 1) {
      }
      sVar1 = suffix;
      if (i < needle_len) {
        j = (i - suffix) + j + 1;
      }
      else {
        do {
          i = sVar1 - 1;
          if (i == 0xffffffff) break;
          sVar1 = i;
        } while (needle[i] == haystack[i + j]);
        if (i == 0xffffffff) {
          return haystack + j;
        }
        j = j + uVar3 + 1;
      }
    }
  }
  return (void *)0x0;
}

