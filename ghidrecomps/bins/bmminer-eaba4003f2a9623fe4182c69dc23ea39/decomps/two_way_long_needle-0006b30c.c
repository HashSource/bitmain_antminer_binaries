
void * two_way_long_needle(uchar *haystack,size_t haystack_len,uchar *needle,size_t needle_len)

{
  int iVar1;
  size_t sVar2;
  size_t needle_len_local;
  uchar *needle_local;
  size_t haystack_len_local;
  uchar *haystack_local;
  size_t shift_table [256];
  size_t period;
  size_t shift_1;
  size_t suffix;
  size_t shift;
  size_t memory;
  size_t j;
  size_t i;
  
  suffix = critical_factorization(needle,needle_len,&period);
  for (i = 0; i < 0x100; i = i + 1) {
    shift_table[i] = needle_len;
  }
  for (i = 0; i < needle_len; i = i + 1) {
    shift_table[needle[i]] = (needle_len - i) - 1;
  }
  iVar1 = memcmp(needle,needle + period,suffix);
  if (iVar1 == 0) {
    memory = 0;
    j = 0;
    while (j <= haystack_len - needle_len) {
      shift = shift_table[haystack[j + needle_len + -1]];
      if (shift == 0) {
        i = memory;
        if (memory <= suffix) {
          i = suffix;
        }
        for (; (i < needle_len - 1 && (needle[i] == haystack[i + j])); i = i + 1) {
        }
        if (i < needle_len - 1) {
          j = (i - suffix) + j + 1;
          memory = 0;
        }
        else {
          for (i = suffix - 1; (memory < i + 1 && (needle[i] == haystack[i + j])); i = i - 1) {
          }
          if (i + 1 < memory + 1) {
            return haystack + j;
          }
          j = j + period;
          memory = needle_len - period;
        }
      }
      else {
        if ((memory != 0) && (shift < period)) {
          shift = needle_len - period;
        }
        memory = 0;
        j = j + shift;
      }
    }
  }
  else {
    sVar2 = suffix;
    if (suffix <= needle_len - suffix) {
      sVar2 = needle_len - suffix;
    }
    period = sVar2 + 1;
    j = 0;
    while (j <= haystack_len - needle_len) {
      shift_1 = shift_table[haystack[j + needle_len + -1]];
      if (shift_1 == 0) {
        for (i = suffix; (i < needle_len - 1 && (needle[i] == haystack[i + j])); i = i + 1) {
        }
        if (i < needle_len - 1) {
          j = (i - suffix) + j + 1;
        }
        else {
          for (i = suffix - 1; (i != 0xffffffff && (needle[i] == haystack[i + j])); i = i - 1) {
          }
          if (i == 0xffffffff) {
            return haystack + j;
          }
          j = j + sVar2 + 1;
        }
      }
      else {
        j = j + shift_1;
      }
    }
  }
  return (void *)0x0;
}

