
void rev(uchar *s,size_t l)

{
  uchar uVar1;
  size_t l_local;
  uchar *s_local;
  uchar t;
  size_t j;
  size_t i;
  
  j = l - 1;
  for (i = 0; i < j; i = i + 1) {
    uVar1 = s[i];
    s[i] = s[j];
    s[j] = uVar1;
    j = j - 1;
  }
  return;
}

