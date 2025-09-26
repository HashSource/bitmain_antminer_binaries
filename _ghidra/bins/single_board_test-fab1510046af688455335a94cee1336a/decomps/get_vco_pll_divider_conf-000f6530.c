
void get_vco_pll_divider_conf
               (pllparameter_t target_pll_parameter,pll_divider_conf_t *pll_divider_conf,
               uint32_t *pll_divider_conf_count)

{
  uint32_t *pll_divider_conf_count_local;
  pll_divider_conf_t *pll_divider_conf_local;
  pllparameter_t target_pll_parameter_local;
  uint32_t index;
  uint8_t user_div;
  uint8_t post_div2;
  uint8_t post_div1;
  uint32_t pll_divider_conf_id;
  
  pll_divider_conf_id = 0;
  target_pll_parameter_local.postdiv1 = target_pll_parameter.postdiv1;
  for (post_div1 = target_pll_parameter_local.postdiv1; post_div1 < 8;
      post_div1 = post_div1 + '\x01') {
    target_pll_parameter_local.postdiv2 = target_pll_parameter.postdiv2;
    for (post_div2 = target_pll_parameter_local.postdiv2; post_div2 <= post_div1;
        post_div2 = post_div2 + '\x01') {
      for (user_div = '\x01'; user_div < 2; user_div = user_div + '\x01') {
        pll_divider_conf[pll_divider_conf_id].post_div1 = post_div1;
        pll_divider_conf[pll_divider_conf_id].post_div2 = post_div2;
        pll_divider_conf[pll_divider_conf_id].div_ret =
             (uint)user_div * (uint)post_div2 * (uint)post_div1;
        pll_divider_conf_id = pll_divider_conf_id + 1;
      }
    }
  }
  *pll_divider_conf_count = pll_divider_conf_id;
  qsort(pll_divider_conf,*pll_divider_conf_count,8,(__compar_fn_t)0xf6509);
  return;
}

