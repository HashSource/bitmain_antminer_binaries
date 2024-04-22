
/* WARNING: Unknown calling convention */

int16_t get_remote(int16_t remote)

{
  double dVar1;
  float t_re_re;
  char tmp42 [2048];
  
  dVar1 = ((double)(longlong)(int)(short)(remote + -0x40) * DAT_000329a0 - DAT_000329a8) /
          DAT_000329b0;
  if ((*DAT_000329b8 != '\0') &&
     (((*DAT_000329bc != '\0' || (*DAT_000329c0 != '\0')) || (6 < *DAT_000329c4)))) {
    snprintf(tmp42,0x800,DAT_000329c8,(int)(short)(remote + -0x40),(double)(float)dVar1);
    _applog(7,tmp42,false);
  }
  return (int16_t)(int)dVar1;
}

