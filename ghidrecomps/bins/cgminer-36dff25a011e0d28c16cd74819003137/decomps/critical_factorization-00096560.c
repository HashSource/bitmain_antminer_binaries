
size_t critical_factorization(uchar *needle,size_t needle_len,size_t *period)

{
  size_t sVar1;
  size_t *period_local;
  size_t needle_len_local;
  uchar *needle_local;
  uchar b;
  uchar a;
  size_t p;
  size_t k;
  size_t j;
  size_t max_suffix_rev;
  size_t max_suffix;
  
  if (needle_len < 3) {
    *period = 1;
    sVar1 = needle_len - 1;
  }
  else {
    max_suffix = 0xffffffff;
    j = 0;
    p = 1;
    k = 1;
    while (j + k < needle_len) {
      if (needle[j + k] < needle[max_suffix + k]) {
        j = j + k;
        k = 1;
        p = j - max_suffix;
      }
      else if (needle[j + k] == needle[max_suffix + k]) {
        if (k == p) {
          k = 1;
          j = j + p;
        }
        else {
          k = k + 1;
        }
      }
      else {
        max_suffix = j;
        p = 1;
        k = 1;
        j = j + 1;
      }
    }
    *period = p;
    max_suffix_rev = 0xffffffff;
    j = 0;
    p = 1;
    k = 1;
    while (j + k < needle_len) {
      if (needle[max_suffix_rev + k] < needle[j + k]) {
        j = j + k;
        k = 1;
        p = j - max_suffix_rev;
      }
      else if (needle[j + k] == needle[max_suffix_rev + k]) {
        if (k == p) {
          k = 1;
          j = j + p;
        }
        else {
          k = k + 1;
        }
      }
      else {
        max_suffix_rev = j;
        p = 1;
        k = 1;
        j = j + 1;
      }
    }
    if (max_suffix_rev + 1 < max_suffix + 1) {
      sVar1 = max_suffix + 1;
    }
    else {
      *period = p;
      sVar1 = max_suffix_rev + 1;
    }
  }
  return sVar1;
}

