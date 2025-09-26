
void change_level_cofig_base_comp(int comp)

{
  int comp_local;
  char tmp42 [256];
  int k;
  
  for (k = 0; k < (g_rt.config)->test_levels; k = k + 1) {
    (g_rt.config)->sweeped_res_index = k;
    (g_rt.config)->tests[(g_rt.config)->sweeped_res_index].voltage =
         (g_rt.config)->tests[(g_rt.config)->sweeped_res_index].voltage + comp;
    (g_rt.config)->tests[(g_rt.config)->sweeped_res_index].level =
         (g_rt.config)->tests[(g_rt.config)->sweeped_res_index].level + (comp * 3) / 0x14;
    snprintf(tmp42,0x100,"matched index:[%d] level:%d,freq:%d",(g_rt.config)->sweeped_res_index,
             (g_rt.config)->tests[(g_rt.config)->sweeped_res_index].level,
             (g_rt.config)->tests[(g_rt.config)->sweeped_res_index].freq);
    puts(tmp42);
  }
  return;
}

