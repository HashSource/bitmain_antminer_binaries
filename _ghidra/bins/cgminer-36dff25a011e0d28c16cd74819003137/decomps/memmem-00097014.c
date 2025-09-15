
void * memmem(void *__haystack,size_t __haystacklen,void *__needle,size_t __needlelen)

{
  uchar *haystack_00;
  uint haystack_len;
  size_t needle_len_local;
  void *needle_start_local;
  size_t haystack_len_local;
  void *haystack_start_local;
  uchar *needle;
  uchar *haystack;
  
  haystack_00 = (uchar *)__haystack;
  if (__needlelen != 0) {
    if (__haystacklen < __needlelen) {
      haystack_00 = (uchar *)0x0;
    }
    else if (__needlelen < 0x20) {
                    /* WARNING: Load size is inaccurate */
      haystack_00 = (uchar *)rpl_memchr(__haystack,(uint)*__needle,__haystacklen);
      if ((haystack_00 != (uchar *)0x0) && (__needlelen != 1)) {
        haystack_len = __haystacklen - ((int)haystack_00 - (int)__haystack);
        if (haystack_len < __needlelen) {
          haystack_00 = (uchar *)0x0;
        }
        else {
          haystack_00 = (uchar *)two_way_short_needle
                                           (haystack_00,haystack_len,(uchar *)__needle,__needlelen);
        }
      }
    }
    else {
      haystack_00 = (uchar *)two_way_long_needle((uchar *)__haystack,__haystacklen,(uchar *)__needle
                                                 ,__needlelen);
    }
  }
  return haystack_00;
}

