
void sort_pair(uint32_t *a,uint32_t len)

{
  bool bVar1;
  uint32_t uVar2;
  uint32_t len_local;
  uint32_t *a_local;
  uint32_t tmp;
  uint32_t *b;
  uint32_t i;
  uint32_t need_sorting;
  
  bVar1 = false;
  i = 0;
  do {
    if (len <= i) {
      return;
    }
    if ((bVar1) || (a[len + i] < a[i])) {
      bVar1 = true;
      uVar2 = a[i];
      a[i] = a[len + i];
      a[len + i] = uVar2;
    }
    else if (a[i] < a[len + i]) {
      return;
    }
    i = i + 1;
  } while( true );
}

