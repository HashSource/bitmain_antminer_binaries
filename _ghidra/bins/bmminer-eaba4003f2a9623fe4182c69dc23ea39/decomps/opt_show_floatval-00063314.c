
void opt_show_floatval(char *buf,float *f)

{
  float *f_local;
  char *buf_local;
  
  snprintf(buf,0x50,"%.1f",f,(double)*f);
  return;
}

