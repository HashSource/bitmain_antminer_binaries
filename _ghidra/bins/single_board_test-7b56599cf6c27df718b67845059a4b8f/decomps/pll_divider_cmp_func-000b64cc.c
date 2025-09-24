
int32_t pll_divider_cmp_func(void *pll_divider1,void *pll_divider2)

{
  void *pll_divider2_local;
  void *pll_divider1_local;
  pll_divider_conf_t *conf2;
  pll_divider_conf_t *conf1;
  
  return *(int *)((int)pll_divider2 + 4) - *(int *)((int)pll_divider1 + 4);
}

