
void * two_way_short_needle(uchar *haystack,size_t haystack_len,uchar *needle,size_t needle_len)

{
  uint uVar1;
  size_t sVar2;
  int iVar3;
  size_t sVar4;
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
  iVar3 = memcmp(needle,needle + period,suffix);
  if (iVar3 == 0) {
    memory = 0;
    j = 0;
    while (j <= haystack_len - needle_len) {
      i = memory;
      if (memory < suffix) {
        i = suffix;
      }
      for (; (i < needle_len && (needle[i] == haystack[j + i])); i = i + 1) {
      }
      sVar4 = suffix;
      if (i < needle_len) {
        j = j + (i - suffix) + 1;
        memory = 0;
      }
      else {
        do {
          uVar1 = sVar4;
          i = uVar1 - 1;
          if (uVar1 <= memory) break;
          sVar4 = i;
        } while (needle[i] == haystack[j + i]);
        if (uVar1 < memory + 1) {
          return haystack + j;
        }
        j = period + j;
        memory = needle_len - period;
      }
    }
  }
  else {
    sVar4 = suffix;
    if (suffix < needle_len - suffix) {
      sVar4 = needle_len - suffix;
    }
    j = 0;
    while (j <= haystack_len - needle_len) {
      for (i = suffix; (i < needle_len && (needle[i] == haystack[j + i])); i = i + 1) {
      }
      sVar2 = suffix;
      if (i < needle_len) {
        j = j + (i - suffix) + 1;
      }
      else {
        do {
          i = sVar2 - 1;
          if (i == 0xffffffff) break;
          sVar2 = i;
        } while (needle[i] == haystack[j + i]);
        if (i == 0xffffffff) {
          return haystack + j;
        }
        j = sVar4 + 1 + j;
      }
    }
  }
  return (void *)0x0;
}

